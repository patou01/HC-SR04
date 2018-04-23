#include "Ultrasonic.h"

#define TRIG_PIN 5
#define ECHO_PIN 6

Ultrasonic us(TRIG_PIN, ECHO_PIN);
float dt;
int startTime;

void setup() {

  Serial.begin(1000000);
  while(!Serial)
    ;

  startTime = millis();  
}

void loop() {


  us.measure();
  dt = millis() - startTime;
  dt /= 1000;
  Serial.print(dt, 3); Serial.print(" ");
  Serial.println(us.get_cm(), 3);
  
  delay(2);
}
