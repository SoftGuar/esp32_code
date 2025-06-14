#include <NimBLEDevice.h>

const char* FILTER_SERVICE_UUID = "12345678-1234-1234-1234-1234567890ab";

void onBeaconDetected(NimBLEAdvertisedDevice* device) {
  // Send structured data: address|name|RSSI
  Serial.print(device->getAddress().toString().c_str());
  Serial.print("|");
  Serial.print(device->getName().c_str());
  Serial.print("|");
  Serial.println(device->getRSSI());
}

class MyAdvertisedDeviceCallbacks : public NimBLEAdvertisedDeviceCallbacks {
  void onResult(NimBLEAdvertisedDevice* device) override {
    if (device->haveServiceUUID() &&
        device->isAdvertisingService(NimBLEUUID(FILTER_SERVICE_UUID))) {
      onBeaconDetected(device);
    }
  }
};

void setup() {
  Serial.begin(230400);  // Fast baud rate, matches Pi setting
  NimBLEDevice::init("");
  
  NimBLEScan* pScan = NimBLEDevice::getScan();
  pScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pScan->setActiveScan(true);
  pScan->setInterval(45);
  pScan->setWindow(45);
  pScan->setDuplicateFilter(false);
  pScan->start(0, nullptr, true);
}

void loop() {
  // Nothing here; scanning runs in background
}