#define PIN_LED   13
#define PWM_CHN   0
#define PWM_FRQ   1'000
#define PWM_RES   8

uint32_t touch_val;

void setup() {
  Serial.begin(115'200);  // logger
  ledcAttachChannel(PIN_LED, PWM_FRQ, PWM_RES, PWM_CHN);
}

void loop() {
  touch_val = touchRead(T0);

  // Values I'm reading are between 170 - 580, roughly ==> PWM_RES == 8 bit ==> (rough and brutal) value clipping
  touch_val = touch_val <= 255 || touch_val >= 510 ? 0 : touch_val;

  Serial.printf("Touch val: %lu\n", touchRead(T0)); // to see the actual read value
  ledcWrite(PIN_LED, touch_val);    // touch drives PWM (in a particular way)
  delay(100);
}
