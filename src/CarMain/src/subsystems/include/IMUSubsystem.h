#ifndef IMUSUBSYSTEM_H
#define IMUSUBSYSTEM_H

#include "DataTypes.h"
#include "IMU.h"
#include "CANDispatcher.h"

namespace BajaWildcatRacing
{

    class IMUSubsystem{
        public:

            IMUSubsystem(CANDispatcher& canDispatcher);
            
            LatestRotationXYZ getRotationXYZ();
            LatestAccelerationXYZ getAccelerationXYZ();

        private:
            IMU imu;
    };

}


#endif