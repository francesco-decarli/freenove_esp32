#define PIN_BUZZER  13
#define PIN_BUTTON  15
#define CHANNEL     0

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  ledcAttachChannel(PIN_BUZZER, 1, 10, CHANNEL);
  ledcWriteTone(PIN_BUZZER, 2'000);   // set the tone at 2kHz (for starter) + duty at 50%
}

void loop() {
  if(digitalRead(PIN_BUTTON) == LOW)
    sin_alert();
  else
    ledcWriteTone(PIN_BUZZER, 0);     // set the tone at 0 Hz ==> buzzer off
}

// gives a sinusoidal flow to the tone to make
void sin_alert()
{
  float sinVal;
  int toneVal;
  for(int i = 0; i < 360; i += 10)
  {
    sinVal = sin(i * (PI / 180));
    toneVal = 2'000 + sinVal * 500;   // frequency
    ledcWriteTone(PIN_BUZZER, toneVal);
    delay(10);
  }
}
