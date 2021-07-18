#include "Base.h"
#include "Motor.h"
#include "TFMini.h"
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Encoder.h>

#define LIMIT_SWITCH_1 A6
#define LIMIT_SWITCH_2 A2
#define PWM 50
#define GRIPPER_1 39
#define GRIPPER_2 37
#define THROWER_1 41
#define THROWER_2 35
#define REED_SWITCH_1 A7
#define REED_SWITCH_2 A3

Encoder gripper_encoder(3, 2);
Encoder motor_encoder(19, 18);
Motor gripper(28, 5, 4);
TFMini tfmini_x;
TFMini tfmini_y;
Base bot;
MPU6050 mpu6050(Wire);

long tim;

void setup () {
  Serial.begin(115200);
  while (!Serial);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  Serial2.begin(TFMINI_BAUDRATE);
  tfmini_x.begin(&Serial2);
  Serial3.begin(TFMINI_BAUDRATE);
  tfmini_y.begin(&Serial3);
}

void loop () {
//  Serial.print(tfmini_x.getDistance());
//  Serial.print(" ");
//  Serial.println(tfmini_y.getDistance());
  Serial.println(motor_encoder.read());
//  while(motor_encoder.read() < 2900) {
//    
//    move_bot(4, 150);
//  }
  forward_encoder(3500);
  bot.bot_brake();
  while(1);
}

void forward_encoder(long encoder_read) {
  int enc_read = encoder_read / 3;
  int temp = motor_encoder.read();
  uint8_t pwm_;
  while(motor_encoder.read() < enc_read) {
    pwm_ = map(motor_encoder.read(), temp, enc_read, 50, 150);
    move_bot(4, pwm_);
  }
  while(motor_encoder.read() < (enc_read * 2)) {
    move_bot(4, 150);
  }
  while(motor_encoder.read() < encoder_read) {
    pwm_ = map(motor_encoder.read(), enc_read * 2, encoder_read, 150, 30);
    move_bot(4, pwm_);
  }
  bot.bot_brake();
}

void move_bot(uint8_t bot_direction, uint8_t pwm) {
  mpu6050.update();
  uint8_t pwm_1, pwm_2, pwm_3, pwm_4;
  if (mpu6050.getAngleZ() > -5 && mpu6050.getAngleZ() < 5) {
    pwm_1 = pwm;
    pwm_2 = pwm;
    pwm_3 = pwm;
    pwm_4 = pwm;
  } else if (mpu6050.getAngleZ() < -5) {
    mpu6050.update();
    int offset = abs(mpu6050.getAngleZ());
    offset = pow(1.34, offset);
    if(offset > 25) {
      offset = 25;
    }
    pwm_1 = pwm + offset;
    pwm_2 = pwm + offset;
    pwm_3 = pwm - offset;
    pwm_4 = pwm - offset;
  } else {
    mpu6050.update();
    int offset = abs(mpu6050.getAngleZ());
    offset = pow(1.34, offset);
    if(offset > 25) {
      offset = 25;
    }
    pwm_1 = pwm - offset;
    pwm_2 = pwm - offset;
    pwm_3 = pwm + offset;
    pwm_4 = pwm + offset;
  }
  switch (bot_direction) {
    case 1:
      bot.forward(pwm_1, pwm_2, pwm_3, pwm_4);
      break;
    case 2:
      bot.right(pwm_2, pwm_3, pwm_1, pwm_4);
      break;
    case 3:
      bot.backward(pwm_3, pwm_4, pwm_1, pwm_2);
      break;
    case 4:
      bot.left(pwm_1, pwm_4, pwm_2, pwm_3);
      break;
    default:
      bot.bot_brake();
  }
}
