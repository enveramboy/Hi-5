#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Ps3Controller.h>

// SERVO SETUP
Adafruit_PWMServoDriver board = Adafruit_PWMServoDriver(0x40);
#define SERVO_MIN 125
#define SERVO_MAX 575

int angleToPulse(int ang) { return map(ang, 0, 180, SERVO_MIN, SERVO_MAX); }

#define tlt 0
#define tlf 1
#define trt 2
#define trf 3
#define blt 4
#define blf 5
#define brt 6
#define brf 7
#define hand 8

void idle() {
  for (int i = 0; i < 8; i++) board.setPWM(i, 0, angleToPulse(90));
}

void forward(unsigned long spd) {
  unsigned long delta = millis() % spd;
  if (delta < ((1*spd)/4)) {
    // Left Diagonal Raise
    board.setPWM(tlf, 0, angleToPulse(180));
    board.setPWM(brf, 0, angleToPulse(180));
    board.setPWM(tlt, 0, angleToPulse(90));
    board.setPWM(brt, 0, angleToPulse(90));

    // Right Diagonal Thrust
    board.setPWM(trt, 0, angleToPulse(55));
    board.setPWM(blt, 0, angleToPulse(125));

  }
  else if (delta < ((2*spd)/4)) {
    // Left Diagonal Lower
    board.setPWM(tlf, 0, angleToPulse(90));
    board.setPWM(brf, 0, angleToPulse(90));
    board.setPWM(tlt, 0, angleToPulse(55));
    board.setPWM(brt, 0, angleToPulse(125));
  }
  else if (delta < ((3*spd)/4)) {
    // Right Diagonal Raise

    board.setPWM(trf, 0, angleToPulse(0));
    board.setPWM(blf, 0, angleToPulse(0));
    board.setPWM(trt, 0, angleToPulse(90));
    board.setPWM(blt, 0, angleToPulse(90));

    // Left Diagonal Thrust
    board.setPWM(tlt, 0, angleToPulse(125));
    board.setPWM(brt, 0, angleToPulse(55));
  }
  else {
    // Right Diagonal Lower
    board.setPWM(trf, 0, angleToPulse(90));
    board.setPWM(blf, 0, angleToPulse(90));
    board.setPWM(trt, 0, angleToPulse(125));
    board.setPWM(blt, 0, angleToPulse(55));
    
  }
}

void backward(unsigned long spd) {
  unsigned long delta = millis() % spd;
  if (delta < ((1*spd)/4)) {
    // Left Diagonal Raise
    board.setPWM(tlf, 0, angleToPulse(180));
    board.setPWM(brf, 0, angleToPulse(180));
    board.setPWM(tlt, 0, angleToPulse(90));
    board.setPWM(brt, 0, angleToPulse(90));

    // Right Diagonal Thrust
    board.setPWM(trt, 0, angleToPulse(125));
    board.setPWM(blt, 0, angleToPulse(55));

  }
  else if (delta < ((2*spd)/4)) {
    // Left Diagonal Lower
    board.setPWM(tlf, 0, angleToPulse(90));
    board.setPWM(brf, 0, angleToPulse(90));
    board.setPWM(tlt, 0, angleToPulse(125));
    board.setPWM(brt, 0, angleToPulse(55));
  }
  else if (delta < ((3*spd)/4)) {
    // Right Diagonal Raise

    board.setPWM(trf, 0, angleToPulse(0));
    board.setPWM(blf, 0, angleToPulse(0));
    board.setPWM(trt, 0, angleToPulse(90));
    board.setPWM(blt, 0, angleToPulse(90));

    // Left Diagonal Thrust
    board.setPWM(tlt, 0, angleToPulse(55));
    board.setPWM(brt, 0, angleToPulse(125));
  }
  else {
    // Right Diagonal Lower
    board.setPWM(trf, 0, angleToPulse(90));
    board.setPWM(blf, 0, angleToPulse(90));
    board.setPWM(trt, 0, angleToPulse(55));
    board.setPWM(blt, 0, angleToPulse(125));
    
  }
}

void left(unsigned long spd) {
  unsigned long delta = millis() % spd;
  if (delta < ((1*spd)/4)) {
    // Left Diagonal Raise
    board.setPWM(tlf, 0, angleToPulse(180));
    board.setPWM(brf, 0, angleToPulse(180));
    board.setPWM(tlt, 0, angleToPulse(90));
    board.setPWM(brt, 0, angleToPulse(90));

    // Right Diagonal Thrust
    board.setPWM(trt, 0, angleToPulse(55));
    board.setPWM(blt, 0, angleToPulse(55));

  }
  else if (delta < ((2*spd)/4)) {
    // Left Diagonal Lower
    board.setPWM(tlf, 0, angleToPulse(90));
    board.setPWM(brf, 0, angleToPulse(90));
    board.setPWM(tlt, 0, angleToPulse(125));
    board.setPWM(brt, 0, angleToPulse(125));
  }
  else if (delta < ((3*spd)/4)) {
    // Right Diagonal Raise
    board.setPWM(trf, 0, angleToPulse(0));
    board.setPWM(blf, 0, angleToPulse(0));
    board.setPWM(trt, 0, angleToPulse(90));
    board.setPWM(blt, 0, angleToPulse(90));

    // Left Diagonal Thrust
    board.setPWM(tlt, 0, angleToPulse(55));
    board.setPWM(brt, 0, angleToPulse(55));
  }
  else {
    // Right Diagonal Lower
    board.setPWM(trf, 0, angleToPulse(90));
    board.setPWM(blf, 0, angleToPulse(90));
    board.setPWM(trt, 0, angleToPulse(125));
    board.setPWM(blt, 0, angleToPulse(125));
    
  }
}

void right(unsigned long spd) {
  unsigned long delta = millis() % spd;
  if (delta < ((1*spd)/4)) {
    // Left Diagonal Raise
    board.setPWM(tlf, 0, angleToPulse(180));
    board.setPWM(brf, 0, angleToPulse(180));
    board.setPWM(tlt, 0, angleToPulse(90));
    board.setPWM(brt, 0, angleToPulse(90));

    // Right Diagonal Thrust
    board.setPWM(trt, 0, angleToPulse(125));
    board.setPWM(blt, 0, angleToPulse(125));

  }
  else if (delta < ((2*spd)/4)) {
    // Left Diagonal Lower
    board.setPWM(tlf, 0, angleToPulse(90));
    board.setPWM(brf, 0, angleToPulse(90));
    board.setPWM(tlt, 0, angleToPulse(55));
    board.setPWM(brt, 0, angleToPulse(55));
  }
  else if (delta < ((3*spd)/4)) {
    // Right Diagonal Raise
    board.setPWM(trf, 0, angleToPulse(0));
    board.setPWM(blf, 0, angleToPulse(0));
    board.setPWM(trt, 0, angleToPulse(90));
    board.setPWM(blt, 0, angleToPulse(90));

    // Left Diagonal Thrust
    board.setPWM(tlt, 0, angleToPulse(125));
    board.setPWM(brt, 0, angleToPulse(125));
  }
  else {
    // Right Diagonal Lower
    board.setPWM(trf, 0, angleToPulse(90));
    board.setPWM(blf, 0, angleToPulse(90));
    board.setPWM(trt, 0, angleToPulse(55));
    board.setPWM(blt, 0, angleToPulse(55));
    
  }
}

void notify() {
}

void onConnect() {
  Ps3.setPlayer(1);
  idle();
}

void setup() {
  // SERVO INITIALIZATION
  board.begin();
  board.setPWMFreq(60);

  pinMode(21, OUTPUT);
  pinMode(23, OUTPUT);

  // PS3 INITIALIZATION
  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("2c:81:58:3a:93:f7");
}

unsigned long start = 0;
unsigned long curr = 4096;

void loop() {
  if (!Ps3.isConnected()) return;

  if (millis() > start + 1000) {
    curr = (curr == 4096) ? 4095 : 4096;
    board.setPWM(15, 0, curr);
    start = millis();
  }

  if (Ps3.data.button.triangle > 0) { board.setPWM(14, 0, 595); }
  if (Ps3.data.button.triangle == 0) { board.setPWM(14, 0, 4096); }

  if (Ps3.data.button.r1 > 0) { board.setPWM(hand, 0, angleToPulse(0)); }
  if (Ps3.data.button.r1 == 0) { board.setPWM(hand, 0, angleToPulse(180)); }

  int y = Ps3.data.analog.stick.ly;
  int x = Ps3.data.analog.stick.lx;

  if (abs(x) > 10 || abs(y) > 10) {
    if (abs(x) > abs(y)) {
      if (x < -10) left(1000); 
      else if (x > 10) right(1000);
    }
    else {
      if (y > 10) backward(1000); 
      else if (y < -10) forward(1000);
    }
  }
  else idle();
}