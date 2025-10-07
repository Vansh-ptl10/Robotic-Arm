#include <Servo.h>  

Servo servo1;      
Servo servo2;
Servo servo3;
Servo servo4;

char input;        
int pos1 = 0;      
int pos2 = 90;
int pos3 = 90;
int pos4 = 90;

void setup() {
  servo1.attach(6);  
  servo2.attach(9);  
  servo3.attach(10); 
  servo4.attach(11); 
  Serial.begin(9600);  

  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
}

void loop() {
  if (Serial.available() > 0) {  // Check if data is available
    input = Serial.read();       // Read the incoming byte
    input = tolower(input);      

    // Closing
    if (input == 'c') {
      Serial.println("Closing arm...");
      for (; pos1 <= 180; pos1 += 1) {
        servo1.write(pos1);
        delay(23);  // Slow motion delay

        if (Serial.available() > 0) {
          char stopCheck = tolower(Serial.read());
          if (stopCheck == 's') {
            Serial.println("Stopped closing!");
            break;
          }
        }
      }
      Serial.println("Closing complete (or stopped).");
    }

    // Opening
    else if (input == 'o') {
      Serial.println("Opening arm...");
      for (; pos1 >= 0; pos1 -= 1) {
        servo1.write(pos1);
        delay(23);  // Slow motion delay

        if (Serial.available() > 0) {
          char stopCheck = tolower(Serial.read());
          if (stopCheck == 's') {
            Serial.println("Stopped opening!");
            break;
          }
        }
      }
      Serial.println("Opening complete (or stopped).");
    }
    // rotation left
    else if (input == 'l'){
      Serial.println("rotating...");
      for (; pos2 <= 180; pos2 += 1){
        servo2.write(pos2);
        delay(23);

        if (Serial.available() > 0){
          char stopCheck = tolower(Serial.read());
          if (stopCheck == 's'){
            Serial.println("Stopped rotating!");
            break;
          }
        }
      }
      Serial.println("Rotating complete (or stopped).");
    }
    // rotation right
    else if (input == 'r'){
      Serial.println("rotating...");
      for(; pos2 >= 0; pos2 -= 1){
        servo2.write(pos2);
        delay(23);

        if (Serial.available() > 0){
          char stopCheck = tolower(Serial.read());
          if (stopCheck == 's'){
            Serial.println("Stopped rotating!");
            break;
          }
        }
      }
      Serial.println("Rotating complete (or stopped)");
    }

    // Down
    else if (input == 'd'){
      Serial.println("moving down...");
      for (; pos3 <= 180; pos3 += 1){
        servo3.write(pos3);
        delay(23);

        if (Serial.available() > 0){
          char stopCheck = tolower(Serial.read());
          if (stopCheck == 's'){
            Serial.println("Stopped moving up!");
            break;
          }
        }
      }
      Serial.println("Movement complete (or stopped).");
    }
    // Up
    else if (input == 'u'){
      Serial.println("moving up..");
      for(; pos3 >= 0; pos3 -= 1){
        servo3.write(pos3);
        delay(23);

        if (Serial.available() > 0){
          char stopCheck = tolower(Serial.read());
          if (stopCheck == 's'){
            Serial.println("Stopped rotating!");
            break;
          }
        }
      }
      Serial.println("Movement complete (or stopped)");
    }
    // Backward
    else if (input == 'b'){
      Serial.println("moving ...");
      for (; pos4 <= 180; pos4 += 1){
        servo4.write(pos4);
        delay(23);

        if (Serial.available() > 0){
          char stopCheck = tolower(Serial.read());
          if (stopCheck == 's'){
            Serial.println("Stopped moving up!");
            break;
          }
        }
      }
      Serial.println("Movement complete (or stopped).");
    }
    // Forward
    else if (input == 'f'){
      Serial.println("moving up..");
      for(; pos4 >= 0; pos4 -= 1){
        servo4.write(pos4);
        delay(23);

        if (Serial.available() > 0){
          char stopCheck = tolower(Serial.read());
          if (stopCheck == 's'){
            Serial.println("Stopped rotating!");
            break;
          }
        }
      }
      Serial.println("Movement complete (or stopped)");
    }

    // Manual stop (if idle)
    else if (input == 's') {
      Serial.println("Manual stop (no motion active).");
    }
  }
}



