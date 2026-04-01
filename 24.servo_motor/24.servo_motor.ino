#include <ESP32Servo.h>

#define ADC_MAX   4'095   // Default ADC max value on the ESP32 (12 bit ADC width)
#define SERVO_PIN   15
#define POTENTM_PIN 34

Servo servo_motor;  // object (class) to control the servo motor
int pot_val;        // to store potentiometer value

void setup() {
  servo_motor.setPeriodHertz(50);             // sets the servo motor frequency (standard servo)
  servo_motor.attach(SERVO_PIN, 500, 2'500);  // attach the object to the related PIN and gives the minimum and maximum values for writes
  Serial.begin(115'200);
}

void loop() {
  pot_val = analogRead(POTENTM_PIN);  // value between 0 - 4'095
  Serial.printf("Analog potentiometer value: %d\t", pot_val);
  pot_val = map(pot_val, 0, ADC_MAX, 0, 180);   // scale potentiometer value to servo values (0 - 180)
  servo_motor.write(pot_val);
  Serial.printf("Servo value: %d\n", pot_val);
  delay(15);  // let the servo get in position
}
