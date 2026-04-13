#ifndef IMUSUBSYSTEM_H
#define IMUSUBSYSTEM_H

#include "IMU.h"
#include "CANDispatcher.h"

namespace BajaWildcatRacing
{

    class IMUSubsystem{
        public:

            IMUSubsystem(CANDispatcher& canDispatcher);
            
            IMU::LatestRotationXYZ getRotationXYZ();
            IMU::LatestAccelerationXYZ getAccelerationXYZ();

        private:
            IMU imu;
    };

}


#endif