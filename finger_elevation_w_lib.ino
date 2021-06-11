#include <AccelStepper.h>
# define dirPin 4
# define stepPin 6
# define stanByPin 8
# define LED 10
# define motorInterface 1
# define Speed 2000


char val;
bool execute;
// Define a stepper and the pins it will use
AccelStepper stepper(motorInterface, stepPin, dirPin); // Step pin = 6, Dir pin = 4


void setup() {
  //Start serial port
  Serial.begin(9600);
  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(2000);
  stepper.setSpeed(Speed);
  stepper.setAcceleration(2000);
  pinMode(stanByPin, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(stanByPin, LOW);
  digitalWrite(LED, LOW);
  // Initial variable
  val = '0';
  execute = false;
}


void loop() {
  if (Serial.available()) {
    val = Serial.read();
    if (val == 'w'){
      lightUp();
      motorUpSet();
      execute = true;
    }
    else if (val == 's'){
      lightUp();
      motorDownSet();
      execute = true;
    }
    else if (val == '0'){
      lightDown();
      motorStop();
      execute = false;
    }
  }
  
  if (execute == true){
    stepper.runSpeed();
  }
}


void lightUp(){
  digitalWrite(LED, HIGH);
}

void lightDown(){
  digitalWrite(LED, LOW);
}


void motorUpSet() {
  digitalWrite(stanByPin, HIGH);
  stepper.setSpeed(2000);
}


void motorDownSet() {
  digitalWrite(stanByPin, HIGH);
  stepper.setSpeed(-2000);
}


void motorStop(){
  digitalWrite(stanByPin, LOW);
}
