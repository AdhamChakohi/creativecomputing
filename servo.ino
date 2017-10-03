#include <Servo.h>
Servo servo;

int servoPin = 3;
int switchPin = 2;
bool forward = false;
int angle = 0;
int sped = 7;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin,INPUT);
  servo.attach(servoPin);
  
}

void loop() {
  int touch = digitalRead(switchPin);
  if (touch) {
    angle -= sped;
  } else {
    angle += sped;
  }
  Serial.println(touch,angle);
  servo.write(angle);
  delay(100);
}
