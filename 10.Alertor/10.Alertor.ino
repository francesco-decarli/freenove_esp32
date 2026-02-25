#define PIN_BUZZER  13
#define PIN_BUTTON  15
#define CHANNEL     0

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  ledcAttachChannel(PIN_BUZZER, 1, 10, CHANNEL);
  ledcWriteTone(PIN_BUZZER, 1'000);   // set the tone at 2kHz (for starter)
}

void loop() {
  if(digitalRead(PIN_BUTTON) == LOW)
  {
    ledcWriteTone(PIN_BUZZER, 1'000);
    delay(300);
    ledcWriteTone(PIN_BUZZER, 300);
    delay(300);
    ledcWriteTone(PIN_BUZZER, 500);
    delay(500);
  }
  else
    ledcWriteTone(PIN_BUZZER, 0);     // set the tone at 0 Hz ==> buzzer off
}
