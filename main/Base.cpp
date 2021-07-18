/**

  Class for Base

  CPP file

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

#include "Base.h"
#include "Motor.h"
#include "Arduino.h"

Base::Base() {}

Motor motor_1(11, 8);
Motor motor_2(7, 12);
Motor motor_3(13, 6);
Motor motor_4(9, 10);

void Base::forward(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4) {
  motor_1.clockwise(pwm_1);
  motor_2.clockwise(pwm_2);
  motor_3.anti_clockwise(pwm_3);
  motor_4.anti_clockwise(pwm_4);
}

void Base::backward(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4) {
  motor_1.anti_clockwise(pwm_1);
  motor_2.anti_clockwise(pwm_2);
  motor_3.clockwise(pwm_3);
  motor_4.clockwise(pwm_4);
}
void Base::left(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4) {
  motor_1.clockwise(pwm_1);
  motor_2.anti_clockwise(pwm_2);
  motor_3.anti_clockwise(pwm_3);
  motor_4.clockwise(pwm_4);
}

void Base::right(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4) {
  motor_1.anti_clockwise(pwm_1);
  motor_2.clockwise(pwm_2);
  motor_3.clockwise(pwm_3);
  motor_4.anti_clockwise(pwm_4);
}
void Base::up_left(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4) {
  motor_1.clockwise(pwm_1);
  motor_2.brake();
  motor_3.anti_clockwise(pwm_3);
  motor_4.brake();;
}

void Base::up_right(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4) {
  motor_1.brake();
  motor_2.clockwise(pwm_2);
  motor_3.brake();
  motor_4.anti_clockwise(pwm_4);
}
void Base::down_left(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4) {
  motor_1.brake();
  motor_2.anti_clockwise(pwm_2);
  motor_3.brake();
  motor_4.clockwise(pwm_4);
}

void Base::down_right(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4) {
  motor_1.anti_clockwise(pwm_1);
  motor_2.brake();
  motor_3.clockwise(pwm_3);
  motor_4.brake();
}
void Base::base_clockwise(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4) {
  motor_1.anti_clockwise(pwm_1);
  motor_2.anti_clockwise(pwm_2);
  motor_3.anti_clockwise(pwm_3);
  motor_4.anti_clockwise(pwm_4);
}

void Base::base_anti_clockwise(uint8_t pwm_1, uint8_t pwm_2, uint8_t pwm_3, uint8_t pwm_4) {
  motor_1.clockwise(pwm_1);
  motor_2.clockwise(pwm_2);
  motor_3.clockwise(pwm_3);
  motor_4.clockwise(pwm_4);
}

void Base::bot_brake() {
  motor_1.brake();
  motor_2.brake();
  motor_3.brake();
  motor_4.brake();
}
