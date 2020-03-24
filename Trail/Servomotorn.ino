#include <Servo.h>

Servo servo;  
// twelve servo objects can be created on most boards

int pos = 0;    
void setup() {
  servo.attach(9);  
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    servo.write(pos);              
    delay(5);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo.write(pos);              
    delay(5);                       
  }
}
