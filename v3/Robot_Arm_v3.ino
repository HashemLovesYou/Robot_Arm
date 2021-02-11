#include <Servo.h>

//define our servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int joyX =0;
int joyY =1;
int push=2;
 
int joyVal;
int pushVal;

bool shoulder=true;

void setup()
{ 
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  Serial.begin(9600);
}

void loop(){
  if(shoulder==true){
    pushVal=analogRead(push);
    joyVal=analogRead(joyX);
    int velocity=map(joyVal, 0, 1023, -30, 30);
    joyVal += velocity;
    if(joyVal>180){joyVal=180;}
    if(joyVal<0){joyVal=0;}
    servo1.write(joyVal);
    Serial.println("X");
    Serial.println(joyVal);
  }
}