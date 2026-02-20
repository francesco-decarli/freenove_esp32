#define PIN_LED 2

// Runs once (reset or power on the board)
void setup() {
  pinMode(PIN_LED, OUTPUT);
}

// Runs indefinitely
void loop() {
  digitalWrite(PIN_LED, HIGH);  // turns the led ON
  delay(1000);
  digitalWrite(PIN_LED, LOW);   // turns the led OFF
  delay(1000);
}