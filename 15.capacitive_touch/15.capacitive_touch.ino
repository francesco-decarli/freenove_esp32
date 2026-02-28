void setup() {
  Serial.begin(115'200);  // logger
}

void loop() {
  Serial.printf("Touch reading value: %d\n", touchRead(T0));  // TO ==> PIN_4 (GPIO4)
  delay(1'000);
}
