//
// Created by Tien Duc Le on 16.11.21.
//

#include <ArduinoBLE.h>
#include "Beacon.h"

Beacon_::Beacon_() { }

/**
 * Initializes the class with the given UUID, major and minor ID and tx value.
 * Example: init( "44444444-2222-bbbb-aaaa-111111111111", 1, 1, 200 )
 */
void Beacon_::init(const char *uuid, unsigned short major, unsigned short minor, uint8_t tx )
{
    convertUuidStringToHexBytes(uuid, _uuid);
    convertShortToBytes(major, _major);
    convertShortToBytes(minor, _minor);
    _tx = tx;
}

/**
 * Starts BLE advertising
 */
void Beacon_::start()
{
    if ( !BLE.begin() )
    {
        delay(1000);
    }

    uint8_t data[25] = {
            // skip first 4 bytes which are contained in BLE BT4.0 spec
            0x4C,      // Byte 5. Apple iBeacon Company ID
            0x00,      // Byte 6. Apple iBeacon Company ID
            0x02,      // Byte 7. Apple Proximity Beacon Type
            0x15,      // Byte 8. Apple Proximity Beacon Type
            _uuid[0],  // Byte 9. Proximity UUID (bytes 9-24)
            _uuid[1],  // 10.
            _uuid[2],  // 11.
            _uuid[3],  // 12.
            _uuid[4],  // 13.
            _uuid[5],  // 14.
            _uuid[6],  // 15.
            _uuid[7],  // 16.
            _uuid[8],  // 17.
            _uuid[9],  // 18.
            _uuid[10], // 19.
            _uuid[11], // 20.
            _uuid[12], // 21.
            _uuid[13], // 22.
            _uuid[14], // 23.
            _uuid[15], // 24.
            _major[0], // Byte 25. Major ID
            _major[1], // Byte 26.
            _minor[0], // Byte 27. Minor ID
            _minor[1], // Byte 28.
            _tx        // Byte 29. TxPower calibration value, however it doesn't seem to have the desired effect...
    };

    BLE.stopAdvertise();
    BLE.setManufacturerData( data, 25 );
    BLE.advertise();
}

/**
 * Stops BLE advertising
 */
void Beacon_::stop()
{
    BLE.stopAdvertise();
}

/**
 * Converts an unsigned short value (0-65535) into a two bytes array representation
 * @param source unsigned short value
 * @param target unsigned char array
 */
void Beacon_::convertShortToBytes(unsigned short source, uint8_t *target )
{
    uint8_t high = ( uint8_t )( ( source >> 8 ) & 0xFF );
    uint8_t low = ( uint8_t )( source & 0xFF );
    target[0] = high;
    target[1] = low;
}

/**
 * Converts a UUID string (36 characters, e.g. 44444444-2222-bbbb-aaaa-111111111111)
 * into a hexadecimal byte array (16 bytes)
 *
 * @param source UUID
 * @param target unsigned char array
 */
void Beacon_::convertUuidStringToHexBytes(const char *source, uint8_t *target)
{
    int n = 0;
    for ( unsigned int i = 0; i < 36; i += 2 )
    {
        if ( source[i] == '-' )
        {
            i -= 1;
            continue;
        }
        uint8_t highBits = ( source[i] > 57 ) ? source[i] - 55 : source[i];
        uint8_t lowBits = ( source[i+1] > 57 ) ? source[i+1] - 55 : source[i+1];
        target[n++] = ( highBits << 4 ) + ( lowBits & 0x0F );
    }
}

Beacon_ Beacon;