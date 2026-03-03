#define PIN_THERMISTOR_IN  4

int adcVal;
double voltage, therm_res, tempK, tempC;

void setup() {
  Serial.begin(115'200);
}

void loop() {
  adcVal = analogRead(PIN_THERMISTOR_IN);
  voltage = adcVal / 4'095.0 * 3.3;
  therm_res = 10 * voltage / (3.3 - voltage);
  tempK = 1 / (1 / (273.15 + 25) + log(therm_res / 10) / 3'950.0);
  tempC = tempK - 273.15;
  Serial.printf("ADC value: %d | Voltage: %.2fV | Temp Celsius: %.2fC | Temp Kelvin: %.2fK\n", adcVal, voltage, tempC, tempK);
  delay(100);
}
