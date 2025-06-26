# ESP32 Bluetooth Beacon and Tag System

This project includes the source code for a Bluetooth-based localization and proximity detection system using **ESP32-C3 modules**, designed to work with the **Arduino IDE**.

The system comprises two types of devices:

- **Beacons**: ESP32s that broadcast BLE advertisements.
- **Tag**: A mobile ESP32 that scans for beacons and processes their signals.

---

## 📂 Files Overview

### 1. `esp32_c3_beacon.ino`
- **Device Type**: 📡 **Beacon**
- **Purpose**: 
  - Periodically sends out Bluetooth Low Energy (BLE) advertisements.
  - Acts as a fixed-location identifier to be detected by the tag.
- **Features**:
  - Configurable broadcast name or ID.
  - Minimal resource use—ideal for battery operation.

---

### 2. `esp32_c3_tag.ino`
- **Device Type**: 📶 **Tag (Scanner)**
- **Purpose**:
  - Continuously scans for nearby BLE beacons.
  - Measures RSSI (signal strength) to estimate distance or presence.
  - Can trigger actions like logging, alerts, or communication.

---

## 🔧 Setup Instructions

### 🛠 Requirements
- ESP32-C3 development boards (e.g., NodeMCU-C3, D1 Mini ESP32-C3)
- Arduino IDE installed
- ESP32 board package installed in Arduino IDE
- BLE support via `BLEDevice` library (usually included with ESP32 core)

---

### 📥 Arduino IDE Setup

1. Open Arduino IDE
2. Go to **File > Preferences**, and add the following URL under *Additional Board Manager URLs*: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
3. Go to **Tools > Board > Boards Manager**, search for "esp32" and install it.
4. Select `ESP32C3 Dev Module` from the board list.
5. Open one of the following:
- `esp32_c3_beacon.ino` for beacon devices
- `esp32_c3_tag.ino` for the scanning tag
6. Connect your ESP32-C3 and upload the code.

---

## 📌 Deployment Notes

- You can deploy **multiple ESP32s as beacons** using `esp32_c3_beacon.ino`.
- The **tag**, running `esp32_c3_tag.ino`, listens for those beacons and can:
- Filter based on MAC addresses or advertisement data
- React to signal strength thresholds (RSSI)
- Customize the code to fit your logic:
- Beacon broadcast interval
- Scan frequency
- Filtering logic (e.g., whitelist of beacons)

---

## 📎 Related Components
This code is meant to integrate with a Raspberry Pi system that:
- Listens for the tag’s output
- Collects and transmits beacon interaction data
- Manages services related to Bluetooth communication and logging
