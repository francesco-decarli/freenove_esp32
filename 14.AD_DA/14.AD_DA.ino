#define PIN_POTENZIOMETER_IN  4

void setup() {
  Serial.begin(115'200);  // log (on terminal)
}

void loop() {
  int analog_val = analogRead(PIN_POTENZIOMETER_IN);
  int digital_val = map(analog_val, 0, 4'095, 0, 255);  // Values calcolated knowing the accuracy of ESP internal AD
  double volt = analog_val / 4'095.0 * 3.3;

  // Directly drives PIN25
  dacWrite(DAC1, digital_val);  // DAC1 == GPIO25 (already defined in ESP internal code) ==> drives the led like a PWM

  // Serial.printf("ADC: %d,\tDAC: %d,\tVolt: %.2fV\n", analog_val, digital_val, volt);
  // delay(200);
}
