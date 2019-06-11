/*
 * File:          robot2.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/keyboard.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64
#define PI 3.141592654

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
  wb_robot_init();

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
   WbDeviceTag servo= wb_robot_get_device("servo_motor");
   WbDeviceTag frame_1 =wb_robot_get_device("motor_frame_1");
   WbDeviceTag frame_2 =wb_robot_get_device("motor_frame_2");
   WbDeviceTag frame_3 =wb_robot_get_device("motor_frame_3");

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {

    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_differential_wheels_set_speed(100.0,100.0);
     */

    wb_motor_set_position(servo,PI/4);
    wb_motor_set_position(frame_1,-PI/4);
    wb_motor_set_available_force(frame_1,50000);
    wb_motor_set_position(frame_2,-PI/6);
    wb_motor_set_available_force(frame_2,50000);
    wb_motor_set_position(frame_3,-PI/8);
    wb_motor_set_available_force(frame_3,50000);
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
