#include <NimBLEDevice.h>

const char* BEACON_NAME = "MyESP32Beacon4"; // custom name (filterable)
const char* SERVICE_UUID = "12345678-1234-1234-1234-1234567890ab"; // unique UUID

void setup() {
  Serial.begin(115200);
  NimBLEDevice::init(BEACON_NAME);
  
  NimBLEServer *pServer = NimBLEDevice::createServer();
  NimBLEService *pService = pServer->createService(SERVICE_UUID);
  pService->start();

  NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->start();


  Serial.println("Beacon started...");


  NimBLEAddress mac = NimBLEDevice::getAddress();
  Serial.print("🔧 BLE MAC Address: ");
  Serial.println(mac.toString().c_str());


}

void loop() {
  delay(1000); // keep it running
}