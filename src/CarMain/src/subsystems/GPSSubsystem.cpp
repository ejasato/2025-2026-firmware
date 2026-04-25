#include "IMUSubsystem.h"
#include "DataTypes.h"

namespace BajaWildcatRacing
{

    GPSSubsystem::GPSSubsystem(CANDispatcher& canDispatcher) : gps(canDispatcher, Device::Devices::GPS) {


    }

    /*
    *  Method:  getRotationX
    *
    *  Purpose: provides the IMU x value in regards to ration
    *
    *  Pre-Condition:  None
    * 
    *  Post-Condition: None
    * 
    *  Parameters:  None
    *
    *  Returns: A double of the x value of the rotaiton
    *
    */
    LatestLatLon GPSSubsystem::getLatLon(){
        return gps.getLatestLatLon();
    }

    LatestTime GPSSubsystem::getTime(){
        return gps.getLatestTime();
    }
}