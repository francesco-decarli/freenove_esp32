const byte ledPins[] = { 4, 2, 15 };
const byte channels[] = { 0, 1, 2 };
int red, green, blue;

void setup() {
  for(int i = 0; i < 3; i++)
    ledcAttachChannel(ledPins[i], 1'000, 8, channels[i]);
}

void loop() {
  red = random(0, 256);
  green = random(0, 256);
  blue = random(0, 256);
  setColor(red, green, blue);
  delay(200);
}

void setColor(byte red, byte green, byte blue)
{
  ledcWrite(ledPins[0], 255 - red);
  ledcWrite(ledPins[1], 255 - green);
  ledcWrite(ledPins[2], 255 - blue);
}
