const byte ledPins[] = { 4, 2, 15 };
const byte channels[] = { 0, 1, 2 };

void setup() {
  for(int i = 0; i < 3; i++)
    ledcAttachChannel(ledPins[i], 1'000, 8, channels[i]);
}

void loop() {
  for(int i = 0; i < 256; i++)
  {
    setColour(wheel(i));
    delay(20);
  }
}

// sets given RGB values on pin outputs
// in: long variable containing RGB values per byte
void setColour(long rgb)
{
  ledcWrite(ledPins[0], 255 - (rgb >> 16) & 0xFF);
  ledcWrite(ledPins[1], 255 - (rgb >> 8) & 0xFF);
  ledcWrite(ledPins[2], 255 - rgb & 0xFF);
}

// given a number, creates RGB gradient
// out: long variable containing RBG value per byte
long wheel(int pos)
{
  long wheel_pos = pos % 0xFF;  // loop effect (it keeps the variable value between 0 and 255)
  if(wheel_pos < 85)  // 0 <= wheel_pos < 85
    return (255 - wheel_pos * 3) << 16 | (wheel_pos * 3) << 8;
  else if(wheel_pos < 170)  // 85 <= wheel_pos < 170
  {
    wheel_pos -= 85;
    return (255 - wheel_pos * 3) << 8 | wheel_pos * 3;
  }
  else  // 170 <= wheel_pos
  {
    wheel_pos -= 170;
    return (wheel_pos * 3) << 16 | 255 - wheel_pos * 3;
  }
}
