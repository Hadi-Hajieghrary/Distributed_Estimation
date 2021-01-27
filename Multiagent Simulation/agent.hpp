//
//  agent.hpp
//  Multiagent Simulation
//
//  Created by Hadi Hajieghrary on 1/18/21.
//

#ifndef agent_hpp
#define agent_hpp

#include <Eigen/Dense>
 

using namespace Eigen;
using namespace std;




class Agent{
    
private:
    Vector3d state_;
    Vector2d inputs_;
    double time_step_;
    double current_time_;
    
protected:
    
public:
    Agent(){
        state_ = Vector3d(0,0,0);
        current_time_ = 0;
        inputs_ = Vector2d(0,0);
    }
    Agent(const double initial_time){
        state_ = Vector3d(0,0,0);
        current_time_ = initial_time;
        inputs_ = Vector2d(0,0);
    }
    Agent(double initial_time, Vector3d inital_state){
        state_ = inital_state;
        current_time_ = initial_time;
        inputs_ = Vector2d(0,0);
    }
    
    Agent(double initial_time, Vector3d inital_state, Vector2d initial_inputs){
        state_ = inital_state;
        current_time_ = initial_time;
        inputs_ = initial_inputs;
    }
    
    Agent(Vector3d inital_state){
        state_ = inital_state;
        current_time_ = 0;
        inputs_ = Vector2d(0,0);
    }
    
    virtual ~Agent(){}
    
    void setCurrentTime(double current_time){
        current_time_ = current_time;
    }
   
    void setInput(Vector2d inputs){
        inputs_ = inputs;
    }
    
    double getCurrentTime() const{
        return current_time_;
    }
    
    double getTimeStep() const{
        return time_step_;
    }
    
    const Vector3d& getCurrentState() const {
        return state_;
    }
    
    const Vector2d& getCurrentInputs() const {
        return inputs_;
    }
    
    // Move the State of the Agent one time_step
    void updateState(double time_step);
    // Move the State of the Agent for the time_duration, discretized by time_step
    void advanceState(double time_duration, double time_step);
    
    // Move the State of the Agent one time_step
    void updateState(double time_step, Vector2d x_limits, Vector2d y_limits );
    // Move the State of the Agent for the time_duration, discretized by time_step
    void advanceState(double time_duration, double time_step, Vector2d x_limits, Vector2d y_limits);
    
    // Move the State of the Agent one time_step
    void updateState(double time_step, Vector2d inputs);
    // Move the State of the Agent for the time_duration, discretized by time_step
    void advanceState(double time_duration, double time_step, Vector2d inputs);
    
    // Move the State of the Agent one time_step
    void updateState(double time_step, Vector2d inputs, Vector2d x_limits, Vector2d y_limits );
    // Move the State of the Agent for the time_duration, discretized by time_step
    void advanceState(double time_duration, double time_step, Vector2d inputs, Vector2d x_limits, Vector2d y_limits);
};

#endif /* agent_hpp */
