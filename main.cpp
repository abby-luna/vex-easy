#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
controller Controller1 = controller(primary);
motor Motor21 = motor(PORT21, ratio18_1, false);




// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
#pragma endregion VEXcode Generated Robot Configuration
#define MOTORS 5

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       abby LG                                                   */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
#include <vector>

// {bind, max_velocity, port} 
// Allows for easier use of the VEX Library

using namespace vex;


// log over time, APM 

/*
Theroy,

log every millisecond of ations to a csv,

PROS:
effincency, 
possinly smoother..?
*/

struct port{

  vex::motor port_id;
  char cont_id;
  int max_vel;

};

port ControllerPorts[MOTORS] = {
  {
    vex::motor(7),
    'a',
    127
  },{
    vex::motor(1),
    '1',
    127
  },{
    vex::motor(2),
    '1',
    127
  },{
    vex::motor(9),
    '2',
    127
  },{
    vex::motor(10),
    '2',
    127
  }
};

namespace controls{

  void axis1(){
    for (int i = 0; i <= MOTORS; i++) {
      if(ControllerPorts[i].cont_id == '1'){
        ControllerPorts[i].port_id.setVelocity(Controller1.Axis1.position(percent), percent);
      }
    }
      
  }

  void axis2(){
    for (int i = 0; i <= MOTORS; i++) {
      if(ControllerPorts[i].cont_id == '2'){
        ControllerPorts[i].port_id.setVelocity(Controller1.Axis2.position(percent), percent);
      }
    }
  }

  void axis3(){
    for (int i = 0; i <= MOTORS; i++) {
      if(ControllerPorts[i].cont_id == '3'){
        ControllerPorts[i].port_id.setVelocity(Controller1.Axis3.position(percent), percent);
      }
    }    
  }

  void axis4(){
    for (int i = 0; i <= MOTORS; i++) {
      if(ControllerPorts[i].cont_id == '3'){
        ControllerPorts[i].port_id.setVelocity(Controller1.Axis3.position(percent), percent);
      }
    }    
  }

  namespace upward{

    void buttonA(){
      for (int i = 0; i <= MOTORS; i++) {
        if(ControllerPorts[i].cont_id == 'a'){
          ControllerPorts[i].port_id.stop();
        }
      } 
    }
    void buttonB(){
      for (int i = 0; i <= MOTORS; i++) {
        if(ControllerPorts[i].cont_id == 'b'){
          ControllerPorts[i].port_id.stop();
        }
      } 
    }

    void buttonX(){
      for (int i = 0; i <= MOTORS; i++) {
        if(ControllerPorts[i].cont_id == 'x'){
          ControllerPorts[i].port_id.stop();
        }
      }  
    }

    void buttonY(){
      for (int i = 0; i <= MOTORS; i++) {
        if(ControllerPorts[i].cont_id == 'y'){
          ControllerPorts[i].port_id.stop();
        }
      }     
    }

  }

  namespace downward{
    void buttonA(){
      for (int i = 0; i <= MOTORS; i++) {
        if(ControllerPorts[i].cont_id == 'a'){
          ControllerPorts[i].port_id.setVelocity(ControllerPorts[i].max_vel, percent);
        }
      } 
    }
    void buttonB(){
      for (int i = 0; i <= MOTORS; i++) {
        if(ControllerPorts[i].cont_id == 'b'){
          ControllerPorts[i].port_id.setVelocity(ControllerPorts[i].max_vel, percent);
        }
      }
    }

    void buttonX(){
      for (int i = 0; i <= MOTORS; i++) {
        if(ControllerPorts[i].cont_id == 'x'){
          ControllerPorts[i].port_id.setVelocity(ControllerPorts[i].max_vel, percent);
        }
      }  
    }

    void buttonY(){
      for (int i = 0; i <= MOTORS; i++) {
        if(ControllerPorts[i].cont_id == 'y'){
          ControllerPorts[i].port_id.setVelocity(ControllerPorts[i].max_vel, percent);
        }
      }   
    }

  }
}

class cust_controller{
  public:

    /*
    vex::motor input = NULL;
    port input_raw;
    cust_controller(port x){
      this->input = vex::motor(x.id);
      this->input_raw = x;
      // a, b, x, y 
      // 1, 2, 3, 4
      // d
    }
    */
    cust_controller(){

    }

    void move(){
      Controller1.ButtonA.pressed(controls::downward::buttonA);
      Controller1.ButtonB.pressed(controls::downward::buttonB);
      Controller1.ButtonY.pressed(controls::downward::buttonX);
      Controller1.ButtonX.pressed(controls::downward::buttonY);

      Controller1.ButtonA.released(controls::upward::buttonA);
      Controller1.ButtonB.released(controls::upward::buttonB);
      Controller1.ButtonY.released(controls::upward::buttonX);
      Controller1.ButtonX.released(controls::upward::buttonY);

      Controller1.Axis1.changed(controls::axis1);
      Controller1.Axis2.changed(controls::axis2); 
      Controller1.Axis3.changed(controls::axis3);
      Controller1.Axis4.changed(controls::axis4); 

    }

};

int main() {

  cust_controller run = cust_controller();
  while(1){
    run.move(); 
  }
}
