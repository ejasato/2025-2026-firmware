#ifndef GPS_H
#define GPS_H

#include "CANDevice.h"

namespace BajaWildcatRacing {

class GPS : public CANDevice {
public:
    GPS(CANDispatcher& canDispatcher)
        : CANDevice(canDispatcher, Device::Devices::GPS) {}

    void sendPosition(float lat, float lon, float altM, 
                      uint8_t siv, uint8_t fixType, uint8_t rtkStatus);

private:
    enum GPSDataType : byte {
        LAT_LON = 0x01,
        ALT_SIV = 0x02,
        STATUS  = 0x03
    };
};

} // namespace BajaWildcatRacing
#endif