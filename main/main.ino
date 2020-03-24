int state = 0;
/*
Info om states
0 HALT sätter stop för roboten
1 APP_PRODUCE första steget
2 RUN kör frammåt
3 THROW kastar bollar till andra sidan planen

*/

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
  
    break;

    case 4:
      for (pos = 0; pos <= 180; pos += 1) { 
        // in steps of 1 degree
        servo.write(pos);              
        delay(5);                       
     }
      for (pos = 180; pos >= 0; pos -= 1) { 
        servo.write(pos);              
        delay(5);                       
    }

    break;

    case 0:

    break;
  }
}
