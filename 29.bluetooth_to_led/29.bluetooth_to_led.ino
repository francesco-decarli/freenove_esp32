#include "BluetoothSerial.h"
#include "string.h"

#define LED_PIN     4

BluetoothSerial SerialBT;
char char_buf[10];
static int count = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  SerialBT.begin("ESP32-Wroower-E");
  Serial.begin(115'200);
  Serial.println("\nDevice started. Now available for pairing");
}

void loop() {
  while(SerialBT.available())
  {
    char_buf[count] = SerialBT.read();
    count++;
  }
  if(count > 0)
  {
    Serial.print(char_buf);

    // "on" - "off" ==> led on - led off
    if(strncmp(char_buf, "on", 2) == 0)
      digitalWrite(LED_PIN, HIGH);
    if(strncmp(char_buf, "off", 3) == 0)
      digitalWrite(LED_PIN, LOW);

    count = 0;
    memset(char_buf, 0, 20);  // fills buffer with 0s, clearing it
  }
}
