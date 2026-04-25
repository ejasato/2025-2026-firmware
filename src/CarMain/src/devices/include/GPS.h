#ifndef GPS_H
#define GPS_H

#include "CANDevice.h"
#include "Devices.h"
 
namespace BajaWildcatRacing
{
    class GPS : CANDevice
    {
        public:
            GPS(CANDispatcher& canDispatcher, byte deviceId);
            LatestLatLon getLatLon();
            uint32_t getTime();
            

        private:
            LatestLatLon LatLon;
            uint32_t Time;

    };

}


#endif