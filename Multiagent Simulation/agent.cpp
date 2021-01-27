//
//  agent.cpp
//  Multiagent Simulation
//
//  Created by Hadi Hajieghrary on 1/18/21.
//

#include "agent.hpp"

// Using Descretized Unicycle Kinematic Model
// x_{k+1} = x_{k} + v_{k}/omega_{k} * ( sin( theta_{k} + omega_{k}*dt ) - sin( theta_{k} ) )
// y_{k+1} = y_{k} - v_{k}/omega_{k} * ( cos( theta_{k} + omega_{k}*dt ) - cos( theta_{k} ) )
// thetha_{k+1} = thetha_{k} + omega_{k}*dt

void Agent::updateState(double time_step){
    time_step_ = time_step;
    
    state_(0) += inputs_(0)/inputs_(1) * ( sin(state_(2) + inputs_(1)*time_step_) - sin(state_(2)) );
    state_(1) -= inputs_(0)/inputs_(1) * ( cos(state_(2) + inputs_(1)*time_step_) - cos(state_(2)) );
    state_(2) += inputs_(1) * time_step_;
    
    current_time_ += time_step_;
}


void Agent::advanceState(double time_duration, double time_step){
    time_step_ = time_step;
    double final_time = current_time_ + time_duration;
    
    while(current_time_< final_time){
        state_(0) += inputs_(0)/inputs_(1) * ( sin(state_(2) + inputs_(1)*time_step_) - sin(state_(2)) );
        state_(1) -= inputs_(0)/inputs_(1) * ( cos(state_(2) + inputs_(1)*time_step_) - cos(state_(2)) );
        state_(2) += inputs_(1) * time_step_;
    
        current_time_ += time_step_;
    }
}

void Agent::updateState(double time_step, Vector2d x_limits, Vector2d y_limits ){
    time_step_ = time_step;
    Vector3d new_states;
    new_states(0) = state_(0) + inputs_(0)/inputs_(1) * ( sin(state_(2) + inputs_(1)*time_step_) - sin(state_(2)) );
    new_states(1) = state_(1) - inputs_(0)/inputs_(1) * ( cos(state_(2) + inputs_(1)*time_step_) - cos(state_(2)) );
    new_states(2) = state_(2) + inputs_(1) * time_step_;
    
    if(new_states(0) > x_limits(0) && new_states(0) < x_limits(1)){
        if(new_states(1) > y_limits(0) && new_states(1) < y_limits(1)){
            state_ = new_states;
        }
    }
    
    current_time_ += time_step_;
}


void Agent::advanceState(double time_duration, double time_step, Vector2d x_limits, Vector2d y_limits){
    time_step_ = time_step;
    double final_time = current_time_ + time_duration;
    
    while(current_time_< final_time){
        
        Vector3d new_states;
        new_states(1) = state_(0) + inputs_(0)/inputs_(1) * ( sin(state_(2) + inputs_(1)*time_step_) - sin(state_(2)) );
        new_states(2) = state_(1) - inputs_(0)/inputs_(1) * ( cos(state_(2) + inputs_(1)*time_step_) - cos(state_(2)) );
        new_states(3) = state_(2) + inputs_(1) * time_step_;
        
        if(new_states(0) > x_limits(0) && new_states(0) > x_limits(1)){
            if(new_states(1) > y_limits(0) && new_states(1) > y_limits(1)){
                state_ = new_states;
            }
        }
        
        current_time_ += time_step_;
    }
}





void Agent::updateState(double time_step, Vector2d inputs){
    inputs_ = inputs;
    time_step_ = time_step;
    
    state_(0) += inputs_(0)/inputs_(1) * ( sin(state_(2) + inputs_(1)*time_step_) - sin(state_(2)) );
    state_(1) -= inputs_(0)/inputs_(1) * ( cos(state_(2) + inputs_(1)*time_step_) - cos(state_(2)) );
    state_(2) += inputs_(1) * time_step_;
    
    current_time_ += time_step_;
}


void Agent::advanceState(double time_duration, double time_step, Vector2d inputs){
    inputs_ = inputs;
    time_step_ = time_step;
    double final_time = current_time_ + time_duration;
    
    while(current_time_< final_time){
        state_(0) += inputs_(0)/inputs_(1) * ( sin(state_(2) + inputs_(1)*time_step_) - sin(state_(2)) );
        state_(1) -= inputs_(0)/inputs_(1) * ( cos(state_(2) + inputs_(1)*time_step_) - cos(state_(2)) );
        state_(2) += inputs_(1) * time_step_;
    
        current_time_ += time_step_;
    }
}

void Agent::updateState(double time_step, Vector2d inputs, Vector2d x_limits, Vector2d y_limits ){
    inputs_ = inputs;
    time_step_ = time_step;
    Vector3d new_states;
    new_states(1) = state_(0) + inputs_(0)/inputs_(1) * ( sin(state_(2) + inputs_(1)*time_step_) - sin(state_(2)) );
    new_states(2) = state_(1) - inputs_(0)/inputs_(1) * ( cos(state_(2) + inputs_(1)*time_step_) - cos(state_(2)) );
    new_states(3) = state_(2) + inputs_(1) * time_step_;
    
    if(new_states(0) > x_limits(0) && new_states(0) > x_limits(1)){
        if(new_states(1) > y_limits(0) && new_states(1) > y_limits(1)){
            state_ = new_states;
        }
    }
    
    current_time_ += time_step_;
}


void Agent::advanceState(double time_duration, double time_step, Vector2d inputs, Vector2d x_limits, Vector2d y_limits){
    inputs_ = inputs;
    time_step_ = time_step;
    double final_time = current_time_ + time_duration;
    
    while(current_time_< final_time){
        
        Vector3d new_states;
        new_states(1) = state_(0) + inputs_(0)/inputs_(1) * ( sin(state_(2) + inputs_(1)*time_step_) - sin(state_(2)) );
        new_states(2) = state_(1) - inputs_(0)/inputs_(1) * ( cos(state_(2) + inputs_(1)*time_step_) - cos(state_(2)) );
        new_states(3) = state_(2) + inputs_(1) * time_step_;
        
        if(new_states(0) > x_limits(0) && new_states(0) > x_limits(1)){
            if(new_states(1) > y_limits(0) && new_states(1) > y_limits(1)){
                state_ = new_states;
            }
        }
        
        current_time_ += time_step_;
    }
}
