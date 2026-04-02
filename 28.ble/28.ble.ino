#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// Universally Unique Identifiers
#define SERVICE_UUID              "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_RX    "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX    "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

BLECharacteristic *pBLE_characteristic;
bool device_connected = false;
uint8_t text = 0;
long last_message = 0;
String rxload = "Test\n";

class MyServerCallbacks: public BLEServerCallbacks
{
  // virtual methods ==> sets device_connected flag
  void onConnect(BLEServer *pServer) { device_connected = true; }
  void onDisconnect (BLEServer *pServer) { device_connected = false; }
};

class MyCallbacks: public BLECharacteristicCallbacks
{
  // virtual method ==> copies the received string on local string rxload
  void onWrite(BLECharacteristic *pCha)
  {
    String rx_string = pCha->getValue();
    if(rx_string.length() > 0)
    {
      rxload = "";
      for(int i = 0; i < rx_string.length(); i++)
        rxload += (char)rx_string[i];
    }
  }
};

// Gives a name to device, creates and sets up BLE service and setup
void setupBLE(String BLE_name)
{
  BLEDevice::init(BLE_name.c_str());
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pBLE_characteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
  pBLE_characteristic->addDescriptor(new BLE2902());
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
  pCharacteristic->setCallbacks(new MyCallbacks());
  pService->start();
  pServer->getAdvertising()->start();
  Serial.println("Writing a client connection to notify...");
}

void setup() {
  Serial.begin(115'200);
  setupBLE("ESP32-Wroover-E");
}

void loop() {
  long now = millis();

  // every 100 ms  print message (if present)
  if(now - last_message > 100)
  {
    if(device_connected && rxload.length() > 0)
    {
      Serial.println(rxload);
      rxload = "";
    }
    if(Serial.available() > 0)
    {
      String str = Serial.readString();
      //const char *new_val = str.c_str();
      pBLE_characteristic->setValue(str.c_str());
      pBLE_characteristic->notify();
    }
    last_message = now;
  }
}
