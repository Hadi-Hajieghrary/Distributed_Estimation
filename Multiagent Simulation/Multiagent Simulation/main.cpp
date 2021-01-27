//
//  main.cpp
//  Multiagent Simulation
//
//  Created by Hadi Hajieghrary on 1/18/21.
//

#include <iostream>
#include <Eigen/Dense>

#include "agent.hpp"
#include "world.hpp"

using namespace Eigen;
using namespace std;

int main(int argc, const char * argv[]) {
    srand(time(0));
    
    double dt = 1e-1;
    double current_time = 0;
    double end_time = 10.0;
    Vector2d x_limits(-100.0, 100.0);
    Vector2d y_limits(-100.0, 100.0);
    World world(x_limits, y_limits, current_time, dt);
    const double dRAND_MAX = static_cast<double>(RAND_MAX);
    int number_of_agents = 4;
    vector<Agent*> agents(number_of_agents);
    for (int i = 0; i<number_of_agents; i++){
        Vector3d init_pose(x_limits(0) +  rand()/dRAND_MAX*(x_limits(1) - x_limits(0)), y_limits(0) +  rand()/dRAND_MAX*(y_limits(1) - y_limits(0)), M_PI - 2.0 * rand()/dRAND_MAX * M_PI );
        auto agent = new Agent(current_time, init_pose);
        agents[i] = agent;
        world.addAgent(agent);
    }
    
    Vector2d linear_velocity_limits(-10.0, 10.0);
    Vector2d angular_velocity_limits(-M_PI, M_PI);
    while(world.getCurrentTime() < end_time){
        cout<<world.getCurrentTime()<<endl;
        for (int i = 0; i<number_of_agents; i++){
            Vector2d inputs(linear_velocity_limits(0) + rand()/dRAND_MAX * (linear_velocity_limits(1) - linear_velocity_limits(0))             ,angular_velocity_limits(0) + rand()/dRAND_MAX * (angular_velocity_limits(1) - angular_velocity_limits(0)));
            Vector3d cur_state = agents[i]->getCurrentState();
            cout<<" Agent "<<i<<": "<<"X = "<< cur_state(0)<<", Y = "<< cur_state(1)<<", theta = "<<cur_state(2)<< ", v = "<<inputs(0) << ", omega = "<<inputs(1)<<endl;
            agents[i]->setInput(inputs);
        }
        world.spinOnce();

    }
    
    
    return 0;
}
