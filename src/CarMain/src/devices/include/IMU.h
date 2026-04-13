#ifndef IMU_H
#define IMU_H


#include "CANDevice.h"
#include "functional"
// #include "linux/can.h"
// #include "Devices.h"


#include <chrono>

namespace BajaWildcatRacing
{

    class IMU : CANDevice {

        public:
            IMU(CANDispatcher& canDispatcher, byte deviceId);

            // typedef struct LatestRotationXYZ{
            //     float rotationx;
            //     float rotationy;
            //     float rotationz;
            // }LatestRotationXYZ;

            //  typedef struct LatestAccelerationXYZ{
            //     float accelerationx;
            //     float accelerationy;
            //     float accelerationz;
            // }LatestAccelerationXYZ;

            LatestRotationXYZ getLatestRotationXYZ();
            LatestAccelerationXYZ getLatestAccelerationXYZ();

        private:

            LatestRotationXYZ rotXYZ;
            LatestAccelerationXYZ accXYZ;
    };

}



#endif