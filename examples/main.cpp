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