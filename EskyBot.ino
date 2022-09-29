#include <SoftwareSerial.h>
#include <AFMotor.h>

SoftwareSerial BTSerial(14, 15); //RX, TX
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int val;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available() > 0){
    val = Serial.read();
    
    if (val == 'a'){ //Forwards
      Serial.println("Forward");
      motor1.setSpeed(200);
      motor2.setSpeed(200);
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
    }
    
    if (val == 'b'){ //Right
      Serial.println("Right");
      motor1.setSpeed(200);
      motor2.setSpeed(0);
      motor1.run(FORWARD);
    }
    
    if (val == 'c'){ //Backwards
      Serial.println("Backward");
      motor1.setSpeed(200);
      motor2.setSpeed(200);
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
    }
    
    if (val == 'd'){ //Left
      Serial.println("Left");
      motor1.setSpeed(0);
      motor2.setSpeed(200);
      motor2.run(BACKWARD);
    }

    else {
      Serial.println("Stopped");
      motor1.run(RELEASE);
      motor2.run(RELEASE);
    }
  }
}
