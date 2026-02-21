#define PIN_LED     15
#define PIN_BUTTON  13

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

void loop() {
  if(digitalRead(PIN_BUTTON) == HIGH)
  {
    delay(20);  // for debounce, waiting the signal to stabilize
    if(digitalRead(PIN_BUTTON) == HIGH) reverseGPIO(PIN_LED); // the signal is stable as button clicked => chenge PIN state

    // Dealing with debounce when the push button is released
    while(digitalRead(PIN_BUTTON) == HIGH);
    delay(20);
    // while(digitalRead(PIN_BUTTON) == HIGH);  // This line does not add anything to the logic (I can be wrong)
  }
}

// Changes pin state (like a NOT)
void reverseGPIO(int pin)
{
  digitalWrite(pin, !digitalRead(pin));
}
