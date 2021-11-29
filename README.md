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

Change Log
----------
| Date       | Version | Notes                                  	|
|------------|---------|------------------------------------    	|
| 2021-11-29 | 1.0.4   | Fixed header file                      	|
| 2021-11-29 | 1.0.3   | Fixed reference to ArduinoBLE dependency	|
| 2021-11-29 | 1.0.2   | Fixed Readme.md                        	|
| 2021-11-29 | 1.0.1   | Added examples<br>Added change log     	|
| 2021-11-29 | 1.0.0   | Initial release                        	|

[ibeacon]: https://developer.apple.com/ibeacon/
