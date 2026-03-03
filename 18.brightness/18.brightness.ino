#define PIN_POTENTIOMETER_IN  4
#define PIN_LED               13
#define CHN                   0
#define LIGHT_MIN             372
#define LIGHT_MAX             2'048

int adcVal;
int pwmVal;

void setup() {
  ledcAttachChannel(PIN_LED, 1'000, 12, CHN);
}

void loop() {
  adcVal = analogRead(PIN_POTENTIOMETER_IN);  // reading ADC
  pwmVal = map(constrain(adcVal, LIGHT_MIN, LIGHT_MAX), LIGHT_MIN, LIGHT_MAX, 0, 4'095);  // adcVal re-map to pwmVal
  ledcWrite(PIN_LED, pwmVal);
  delay(10);
}
