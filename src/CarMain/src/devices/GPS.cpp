#include "GPS.h"

namespace BajaWildcatRacing
{
    GPS::GPS(CANDispatcher& canDispatcher, byte deviceId) : CANDevice(canDispatcher, deviceId){

    }

    LatestLatLon GPS::getLatLon()
    {
        sendCanRequest(0x01, &m_latLon, sizeof(LatestLatLon));
        return LatLon;
    }

    uint32_t GPS::getTime()
    {
        sendCanRequest(0x02, &m_time, sizeof(uint32_t));
        return Time;
    }

}