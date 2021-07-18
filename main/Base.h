/**

  Class for Base

  Header file

  Compatible with:
  1. Cytron
  2. Hercules

  ##########    ##########     ##########
  ##########    ##########     ##########
  ###           ###    ###     ###
  ###           ##########     ###
  ###  #####    ###  ###       ###
  ###  #####    ###   ###      ###
  ###    ###    ###   ###      ###
  ##########    ###    ###     ##########
  ##########    ###     ###    ##########

*/

#ifndef Base_H
#define Base_H
#include "Arduino.h"
#include "Motor.h"

class Base {
public:
  Base();
  void forward(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4);
  void backward(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4);
  void left(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4);
  void right(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4);
  void up_right(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4);
  void up_left(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4);
  void down_right(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4);
  void down_left(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4);
  void base_clockwise(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4);
  void base_anti_clockwise(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4);
  void bot_brake();
};
#endif
