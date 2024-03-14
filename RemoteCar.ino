// Author: Kaibo Huang
#include <Servo.h> 
#include <IRremote.h> 

#define IR_RECEIVE_PIN 5 // IR receiver pin

Servo leftServo;
Servo rightServo;
Servo fLeftServo;
Servo fRightServo;
// defining servo variables

const int IRreceive = 5; //Defining IR pin


void setup() {
  leftServo.attach(9);
  rightServo.attach(10);
  fLeftServo.attach(11);
  fRightServo.attach(3);
  // assigning pins to servos
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  // starting IR receiver
  leftServo.write(90);
  rightServo.write(90);
  fLeftServo.write(90);
  fRightServo.write(90);
  //setting the servos to stop
}

void loop() {
  if (IrReceiver.decode()){
    IrReceiver.resume();
    //check if IR receiver receives signal
    if (IrReceiver.decodedIRData.command == 24){
      moveForward();
    }
    else if (IrReceiver.decodedIRData.command == 82){
      moveBackward();
    }
    else if (IrReceiver.decodedIRData.command == 8){
      turnLeft();
    }
    else if (IrReceiver.decodedIRData.command == 90){
      turnRight();
    }
    else{
      stopCar();
    }
    Serial.println(IrReceiver.decodedIRData.command);
    //prints out IR remote key
  }
}
//moves robot Forward
void moveForward(){
  leftServo.write(120);
  rightServo.write(120);
  fLeftServo.write(120);
  fRightServo.write(120);

}
//moves robot backwards
void moveBackward(){
  leftServo.write(60);
  rightServo.write(60);
  fLeftServo.write(60);
  fRightServo.write(60);
}

//moves robot left
void turnLeft(){
  leftServo.write(90);
  rightServo.write(120);
  fLeftServo.write(120);
  fRightServo.write(90);
}
//moves robot right
void turnRight(){
  leftServo.write(90);
  rightServo.write(60);
  fLeftServo.write(60);
  fRightServo.write(90);
}
//stops robot
void stopCar(){
  leftServo.write(90);
  rightServo.write(90);
  fLeftServo.write(90);
  fRightServo.write(90);
}
