#define PIN_JOYSTICK_X_IN     13
#define PIN_JOYSTICK_Y_IN     12
#define PIN_JOYSTICK_CLICK    14

void setup() {
  Serial.begin(115'200);
  pinMode(PIN_JOYSTICK_CLICK, INPUT_PULLUP);
}

void loop() {
  Serial.printf("X: %d | Y: %d | Z: %s\n",
      analogRead(PIN_JOYSTICK_X_IN),
      analogRead(PIN_JOYSTICK_Y_IN),
      analogRead(PIN_JOYSTICK_CLICK) ? "unclicked" : "clicked");  // button output converted in text
  delay(500);
}
