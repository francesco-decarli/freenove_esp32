// byte: stores unsigned 8 bit number
const byte ledPins[] = { 15, 2, 0, 4, 5, 18, 19, 21, 22, 23 };
const byte channels[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
const int dutys[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      1'023, 512, 256, 128, 64, 32, 16, 8, 4, 2,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

int ledCount;
int delay_time = 100;   // flowing speed

void setup() {
  ledCount = sizeof(ledPins);
  for(int i = 0; i < ledCount; i++)
    ledcAttachChannel(ledPins[i], 1'000, 10, channels[i]);
}

void loop() {
  // backward
  for(int i = 0; i < ledCount * 2; i++)
  {
    for(int j = 0; j < ledCount; j++)
      ledcWrite(ledPins[j], dutys[i + j]);
    delay(delay_time);
  }

  // forward
  for(int i = 0; i < ledCount * 2; i++)
  {
    for(int j = ledCount - 1; j >= 0; j--)
      ledcWrite(ledPins[j], dutys[i + (ledCount - 1 - j)]);
    delay(delay_time);
  }
}
