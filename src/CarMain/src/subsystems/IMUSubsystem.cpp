#include "IMUSubsystem.h"


namespace BajaWildcatRacing
{

    IMUSubsystem::IMUSubsystem(CANDispatcher& canDispatcher) : imu(canDispatcher, Device::Devices::IMU) {


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
    IMU::LatestRotationXYZ IMUSubsystem::getRotationXYZ(){
        return imu.getLatestRotationXYZ();
    }

    IMU::LatestAccelerationXYZ IMUSubsystem::getAccelerationXYZ(){
        return imu.getLatestAccelerationX();
    }

}
