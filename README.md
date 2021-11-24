Nano 33 IoT iBeacon
===

A simple and lightweight library that makes your Arduino Nano 33 IoT boards into a Bluetooth iBeacon device.

Features
--------
  - see Apple Proximity Beacon [Specification][iBeacon]

Usage
-----

```c++
#include <Arduino.h>
#include "Beacon.h"

#define BEACON_UUID "11111111-2222-3333-4444-555555555555"
#define MAJOR 1
#define MINOR 1
#define TX 64

void setup()
{
    Beacon.init( BEACON_UUID, MAJOR, MINOR, TX );
    Beacon.start();  
}

void loop() {}
```

Limitations
-----------
- Currently no deep sleep
- Only iBeacon support

- [ibeacon]: https://developer.apple.com/ibeacon/
