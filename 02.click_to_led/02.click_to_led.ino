#define PIN_LED     15
#define PIN_BUTTON  13

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

void loop() {
  if(digitalRead(PIN_BUTTON) == HIGH) // button clicked
  {
    digitalWrite(PIN_LED, LOW);   // external led on
  }
  else
  {
    digitalWrite(PIN_LED, HIGH);  // external led off
  }
}
