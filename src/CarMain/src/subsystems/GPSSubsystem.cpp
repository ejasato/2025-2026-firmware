#include "IMUSubsystem.h"
#include "DataTypes.h"

namespace BajaWildcatRacing
{

    GPSSubsystem::GPSSubsystem(CANDispatcher& canDispatcher) : gps(canDispatcher, Device::Devices::GPS) {


    }

    LatestLatLon GPSSubsystem::getLatLon(){
        return gps.getLatestLatLon();
    }

    LatestTime GPSSubsystem::getTime(){
        return gps.getLatestTime();
    }
}