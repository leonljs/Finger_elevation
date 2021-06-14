#include <AccelStepper.h>
# define dirPin_1 8
# define stepPin_1 6
# define stanByPin_1 4
# define LED 10
# define dirPin_2 16
# define stepPin_2 14
# define stanByPin_2 12
# define motorInterface 1
# define Speed 2000


char val;
bool motor_1;
bool motor_2;
// Define a stepper and the pins it will use
AccelStepper stepper_1(motorInterface, stepPin_1, dirPin_1); // Step pin = 6, Dir pin = 8
AccelStepper stepper_2(motorInterface, stepPin_2, dirPin_2);

void setup() {
  //Start serial port
  Serial.begin(9600);
  // Change these to suit your stepper if you want
  stepper_1.setMaxSpeed(2000);
  stepper_1.setAcceleration(2000);
  stepper_2.setMaxSpeed(2000);
  stepper_2.setAcceleration(2000);
  pinMode(stanByPin_1, OUTPUT);
  pinMode(stanByPin_2, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(stanByPin_1, LOW);
  digitalWrite(stanByPin_2, LOW);
  digitalWrite(LED, LOW);
  // Initial variable
  val = '0';
  motor_1 = false;
  motor_2 = false;
}


void loop() {
  if (Serial.available()) {
    val = Serial.read();
    if (val == 'w') {
      lightUp();
      motor_1_UpSet();
      motor_1 = true;
    }
    if (val == 's') {
      lightUp();
      motor_1_DownSet();
      motor_1 = true;
    }
    if (val == 'e') {
      lightUp();
      motor_2_UpSet();
      motor_2 = true;
    }
    if (val == 'd') {
      lightUp();
      motor_2_DownSet();
      motor_2 = true;
    }
    if (val == '0') {
      lightDown();
      motorStop();
      motor_1 = false;
      motor_2 = false;
    }
  }

  if (motor_1 == true) {
    stepper_1.runSpeed();
  }
  
  if (motor_2 == true) {
    stepper_2.runSpeed();
  }
}


void lightUp() {
  digitalWrite(LED, HIGH);
}

void lightDown() {
  digitalWrite(LED, LOW);
}


void motor_1_UpSet() {
  digitalWrite(stanByPin_1, HIGH);
  stepper_1.setSpeed(2000);
}


void motor_1_DownSet() {
  digitalWrite(stanByPin_1, HIGH);
  stepper_1.setSpeed(-2000);
}

void motor_2_UpSet() {
  digitalWrite(stanByPin_2, HIGH);
  stepper_2.setSpeed(2000);
}


void motor_2_DownSet() {
  digitalWrite(stanByPin_2, HIGH);
  stepper_2.setSpeed(-2000);
}

void motorStop() {
  digitalWrite(stanByPin_1, LOW);
  digitalWrite(stanByPin_2, LOW);
}
