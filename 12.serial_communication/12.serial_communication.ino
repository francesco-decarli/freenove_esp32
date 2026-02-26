void setup() {
  Serial.begin(115'200);
  Serial.println("ESP32 inizialization completed!");
}

void loop() {
  Serial.printf("Running time: %.1f s\n", millis() / 1'000.0);
  delay(5'000);
}
