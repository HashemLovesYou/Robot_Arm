#include <Servo.h>

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

void loop()
{
  if(shoulder==true){
    pushVal=analogRead(push);
    joyVal = analogRead(joyX);
    joyVal = map (joyVal, 0, 1023, 0, 180);
    servo1.write(joyVal);
    Serial.println("X");
    Serial.println(joyVal);
  
    joyVal = analogRead(joyY);
    joyVal = map (joyVal, 0, 1023, 0, 180);
    servo2.write(joyVal);
    if(pushVal==0){
      shoulder=false;
      delay(250);
      }
    delay(15);
  }
  else{
    pushVal=analogRead(push);
    joyVal = analogRead(joyX);
    joyVal = map(joyVal, 0, 1023, 0, 115);
    servo3.write(joyVal);
  
    joyVal = analogRead(joyY);
    joyVal = map (joyVal, 0, 1023, 0, 180);
    servo4.write(joyVal);
    if(pushVal==0){
      shoulder=true;
      delay(250);
      }
    delay(15);
  }
}    
