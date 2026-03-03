#define PIN_POTENTIOMETER_IN  4
#define PIN_LED               13
#define CHN                   0

// int adcVal;
// int pwmVal;

void setup() {
  ledcAttachChannel(PIN_LED, 1'000, 12, CHN);
}

void loop() {
  // adcVal = analogRead(PIN_POTENTIOMETER_IN);  // reading ADC
  // pwmVal = adcVal;  // I can't figure out the sense of this operation (does nothing but a copy) ==> "adcVal re-map to pwmVal"
  ledcWrite(PIN_LED, analogRead(PIN_POTENTIOMETER_IN)); // set the pulse widith with the read ADC value
  delay(10);
}
