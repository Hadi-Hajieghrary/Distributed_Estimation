//
//  world.hpp
//  Multiagent Simulation
//
//  Created by Hadi Hajieghrary on 1/18/21.
//

#ifndef world_hpp
#define world_hpp

#include <vector>
#include <random>
#include "agent.hpp"


class World{
    
private:
    const double time_step_;
    double current_time_;
    vector<Agent*> agents_;
    
    int number_of_agents_ = 0;
    
    double x_lower_limit_;
    double y_lower_limit_;
    
    double x_upper_limit_;
    double y_upper_limit_;
    
    Vector2d x_limits_;
    Vector2d y_limits_;
    
protected:
    
    
    
public:
    
    World(const Vector2d& x_limits, const Vector2d& y_limits, double time_step):
        time_step_(time_step){
            
        if (x_limits(0)<x_limits(1)){
            x_lower_limit_ = x_limits(0);
            x_upper_limit_ = x_limits(1);
        }
        if (y_limits(0)<y_limits(1)){
            y_lower_limit_ = y_limits(0);
            y_upper_limit_ = y_limits(1);
        }
        x_limits_ = x_limits;
        y_limits_ = y_limits;
        current_time_ = 0;
    }
    
    World(const Vector2d& x_limits, const Vector2d& y_limits, double current_time, double time_step): current_time_(current_time), time_step_(time_step){
        
        if (x_limits(0)<x_limits(1)){
            x_lower_limit_ = x_limits(0);
            x_upper_limit_ = x_limits(1);
        }
        if (y_limits(0)<y_limits(1)){
            y_lower_limit_ = y_limits(0);
            y_upper_limit_ = y_limits(1);
        }
        x_limits_ = x_limits;
        y_limits_ = y_limits;
    }
    
    virtual ~World(){};
    
    void addAgent(Agent* agent){
        agent->setCurrentTime(this->current_time_);
        agents_.push_back(agent);
        number_of_agents_++;
    }
    
    int getNemberOfAgents() const {
        return number_of_agents_;
    }
    
    void spinOnce(){
        for(auto agent: agents_){
            agent->updateState(time_step_, x_limits_, y_limits_);
        }
        current_time_ += time_step_;
    }
    
    void spinFor(double time_in_seconds){
        
        double end_time = this->getCurrentTime() + time_in_seconds;
        while(this->getCurrentTime() < end_time){
            this->spinOnce();
        }
    }
    
    double getCurrentTime(){
        return current_time_;
    }
    
};


#endif /* world_hpp */
