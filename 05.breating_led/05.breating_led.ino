#define PIN_LED     15
#define PWM_CHANNEL 0
#define PWM_FREQ    1000
#define PWM_BIT     8

void setup() {
  ledcAttachChannel(PIN_LED, PWM_FREQ, PWM_BIT, PWM_CHANNEL); // link led pin to PWM
}

void loop() {
  // fade in
  for(int i = 0; i < 255; i++)
  {
    ledcWrite(PIN_LED, i);
    delay(10);
  }

  // fade out
  for(int i = 255; i >= 0; i--)
  {
    ledcWrite(PIN_LED, i);
    delay(10);
  }
}
