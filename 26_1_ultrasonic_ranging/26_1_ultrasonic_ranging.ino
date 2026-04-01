#include <UltrasonicSensor.h>

UltrasonicSensor ultrasonic_sen(13, 14);  // [trigger_pin, echo_pin]

void setup() {
  Serial.begin(115'200);
  ultrasonic_sen.setTemperature(22);    // related to the ultrasonic device working ambient temperature (sound speed is different ==> to get more accurate data)
}

void loop() {
  Serial.printf("Distance: %dcm\n", ultrasonic_sen.distanceInCentimeters());
  delay(300);
}
