/*
 *
 *    Source code for ArmStrong
 *    - Arduino Nano
 *
 *    ----------
 *    3D printed robot arm
 *    Copyright (C) 2021 - PRESENT  Zhengyu Peng
 *    E-mail: zpeng.me@gmail.com
 *    Website: https://zpeng.me
 *
 *    `                      `
 *    -:.                  -#:
 *    -//:.              -###:
 *    -////:.          -#####:
 *    -/:.://:.      -###++##:
 *    ..   `://:-  -###+. :##:
 *           `:/+####+.   :##:
 *    .::::::::/+###.     :##:
 *    .////-----+##:    `:###:
 *     `-//:.   :##:  `:###/.
 *       `-//:. :##:`:###/.
 *         `-//:+######/.
 *           `-/+####/.
 *             `+##+.
 *              :##:
 *              :##:
 *              :##:
 *              :##:
 *              :##:
 *               .+:
 *
 */


#include <Servo.h>

// Create servo objects:
Servo servoA; // control base 'left <-> right'
Servo servoB; // control arm 'extend <-> retreat'
Servo servoC; // control hand 'close <-> open'
Servo servoD; // control arm 'up <-> down'

// Define the servo pins:
#define servoAPin 9
#define servoBPin 10
#define servoCPin 11
#define servoDPin 12

// Define the LED pin:
#define ledPin 5 // LED pin


#define servoAMinAngle 0
#define servoAMaxAngle 180
#define servoBMinAngle 80
#define servoBMaxAngle 150
#define servoCMinAngle 36
#define servoCMaxAngle 180
#define servoDMinAngle 40
#define servoDMaxAngle 90

#define potentiometerAPin A3
#define potentiometerBPin A2
#define potentiometerCPin A0
#define potentiometerDPin A1
#define potentiometerEPin A4

// Create a variable to store the servo position:
int servoAAngle;
int servoBAngle;
int servoCAngle;
int servoDAngle;

int potentiometerA;
int potentiometerB;
int potentiometerC;
int potentiometerD;
int potentiometerE;

int servoARange;
int servoBRange;
int servoCRange;
int servoDRange;

float scaleA;
float scaleB;
float scaleC;
float scaleD;

void setup()
{
  potentiometerA = 0;
  potentiometerB = 0;
  potentiometerC = 0;
  potentiometerD = 0;
  potentiometerE = 0;

  servoARange = servoAMaxAngle - servoAMinAngle;
  servoBRange = servoBMaxAngle - servoBMinAngle;
  servoCRange = servoCMaxAngle - servoCMinAngle;
  servoDRange = servoDMaxAngle - servoDMinAngle;

  scaleA = servoARange / 1024.0;
  scaleB = servoBRange / 1024.0;
  scaleC = servoCRange / 1024.0;
  scaleD = servoDRange / 1024.0;

  Serial.begin(9600); //  setup serial
  // Attach the Servo variable to a pin:
  servoA.attach(servoAPin);

  servoB.attach(servoBPin);

  servoC.attach(servoCPin);

  servoD.attach(servoDPin);

  pinMode(ledPin, OUTPUT); // sets the pin as output
}

void loop()
{
  potentiometerA = analogRead(potentiometerAPin); // read the input pin

  potentiometerB = analogRead(potentiometerBPin); // read the input pin

  potentiometerC = analogRead(potentiometerCPin); // read the input pin

  potentiometerD = analogRead(potentiometerDPin); // read the input pin

  potentiometerE = analogRead(potentiometerEPin); // read the input pin

  servoAAngle = potentiometerA * scaleA + servoAMinAngle;
  servoA.write(servoAAngle);

  servoBAngle = potentiometerB * scaleB + servoBMinAngle;
  servoB.write(servoBAngle);

  servoCAngle = potentiometerC * scaleC + servoCMinAngle;
  servoC.write(servoCAngle);

  servoDAngle = potentiometerD * scaleD + servoDMinAngle;
  servoD.write(servoDAngle);

  analogWrite(ledPin, potentiometerE / 4);
}
