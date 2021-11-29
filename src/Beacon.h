//
// Created by Tien Duc Le on 16.11.21.
//

#ifndef NANO_33_IOT_IBEACON_BEACON_H
#define NANO_33_IOT_IBEACON_BEACON_H

#include <api/ArduinoAPI.h>

class Beacon_
{
    private:
        uint8_t _uuid[16];
        uint8_t _major[2];
        uint8_t _minor[2];
        uint8_t _tx;

        void convertShortToBytes(unsigned short source, uint8_t *target );
        void convertUuidStringToHexBytes(const char *source, uint8_t *target );

    public:
        Beacon_();
        void init(const char *uuid, unsigned short major, unsigned short minor, uint8_t tx );
        void start();
        void stop();
};

extern Beacon_ Beacon;

#endif //NANO_33_IOT_IBEACON_BEACON_H
