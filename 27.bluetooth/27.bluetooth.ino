#include <BluetoothSerial.h>  // deprecated...

BluetoothSerial Serial_bt;  // class that will deal with the communication

void setup() {
  Serial.begin(115'200);
  Serial_bt.begin("ESP32-Wroover-E");
  Serial_bt.println("\nThe device started, now you can pair it with BT!");
}

void loop() {
  if(Serial.available())
    Serial_bt.write(Serial.read());   // reads ESP terminal and send it to the paired device
  if(Serial_bt.available())
    Serial.write(Serial_bt.read());   // reads paired device and send it to the ESP terminal
  delay(20);
}
