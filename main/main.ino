#include <Servo.h>

int state = 0;
/*
Info om states
0 HALT sätter stop för roboten
1 APP_PRODUCE första steget
2 RUN kör frammåt
3 THROW kastar bollar till andra sidan planen
4 avståndsmätare
5 avståndsmätare average av 50 mätningar

*/

int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches, averagecm;

Servo servo;  
// twelve servo objects can be created on most boards

int pos = 0;    
void setup() {
  // put your setup code here, to run once:
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  
  state = 1;

  servo.attach(9);  

    //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  switch(state){

    case 1:
      state = 2;
      
    break;

    case 2:
      digitalWrite(12, HIGH); //Establishes forward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  
      delay(3000);
  
      digitalWrite(9, HIGH); //Eengage the Brake for Channel A

      delay(1000);
  
      //backward @ half speed
      digitalWrite(12, LOW); //Establishes backward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 123);   //Spins the motor on Channel A at half speed
  
      delay(3000);
  
      digitalWrite(9, HIGH); //Engage the Brake for Channel A
  
      delay(1000);
  
     // Trail
     state = 3;
    break;

    case 3:
      for (pos = 0; pos <= 180; pos += 1) { 
        // in steps of 1 degree
        servo.write(pos);              
        delay(5);                       
     }
      for (pos = 180; pos >= 0; pos -= 1) { 
        servo.write(pos);              
        delay(5);                       
    }

      //Trail
      state = 4;
    break;

    case 4:
      // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
      // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
      digitalWrite(trigPin, LOW);
      delayMicroseconds(5);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
 
      // Read the signal from the sensor: a HIGH pulse whose
      // duration is the time (in microseconds) from the sending
      // of the ping to the reception of its echo off of an object.
      pinMode(echoPin, INPUT);
      duration = pulseIn(echoPin, HIGH);
 
      // Convert the time into a distance
      cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
      inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
      Serial.print(inches);
      Serial.print("in, ");
      Serial.print(cm);
      Serial.print("cm");
      Serial.println();
  
      delay(250);

      //trail 
      state =1;
    break;

    case 5:
      
      for(int i = 0; i<50; ++i){
      digitalWrite(trigPin, LOW);
      delayMicroseconds(5);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
 
      // Read the signal from the sensor: a HIGH pulse whose
      // duration is the time (in microseconds) from the sending
      // of the ping to the reception of its echo off of an object.
      pinMode(echoPin, INPUT);
      duration = pulseIn(echoPin, HIGH);
 
      // Convert the time into a distance
      cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343

      averagecm +=cm;
      }
      averagecm=averagecm/50;
    break;
    case 0:

    break;
  }
}
