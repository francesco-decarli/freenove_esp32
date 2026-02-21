#define PIN_BUTTON  13

byte ledPins[] = { 15, 2, 0, 4, 5, 18, 19, 21, 22, 23 };
int ledCounts;

void setup() {
  ledCounts = sizeof(ledPins);
  for(int i = 0; i < ledCounts; i++)
    pinMode(ledPins[i], OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

void loop() {

  if(digitalRead(PIN_BUTTON) == LOW)
  {
    // Button pressed
    delay(20);
    if(digitalRead(PIN_BUTTON) == LOW)
      flowing_light();

    // Button released
    while(digitalRead(PIN_BUTTON) == LOW);
    delay(20);
  }
}

// @Ledbar: turns led on - 300ms - turns led off (left to right and back)
void flowing_light()
{
  // from left to right
  for(int i = 0; i < ledCounts; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    delay(300);
    digitalWrite(ledPins[i], LOW);
  }

  //from right to left
  for(int i = ledCounts - 1; i >= 0; i--)
  {
    digitalWrite(ledPins[i], HIGH);
    delay(300);
    digitalWrite(ledPins[i], LOW);
  }
}
