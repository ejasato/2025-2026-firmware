#ifndef GPSSUBSYSTEM_H
#define GPSSUBSYSTEM_H

#include "DataTypes.h"
#include "GPS.h"
#include "CANDispatcher.h"

namespace BajaWildcatRacing
{

    class GPSSubsystem{
        public:

            GPSSubsystem(CANDispatcher& canDispatcher);
            
            LatestLatLon getLatLon();
            uint32_t getTime();

        private:
            GPS gps;
    };

}


#endif