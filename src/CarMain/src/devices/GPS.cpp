#include "DataTypes.h"
#include "GPS.h"

namespace BajaWildcatRacing
{
    GPS::GPS(CANDispatcher& canDispatcher, byte deviceId) : CANDevice(canDispatcher, deviceId){

    }

    GPSPosition GPS::getPosition()
    {
        sendCanRequest(0x00, &Position, sizeof(GPSPosition));
        return Position;
    }

    uint32_t GPS::getTime()
    {
        sendCanRequest(0x01, &Time, sizeof(uint32_t));
        return Time;
    }

}