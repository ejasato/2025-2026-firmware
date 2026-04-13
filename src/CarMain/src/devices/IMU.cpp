/*
 *
 *  Class IMU
 *
 *         Author:  Matthew Larson & Karsten Yin
 *
 *        Purpose:  Provide an implementation of the IMU device, utilizing the
 *        CanDispatcher class to send and receive CAN commands
 *
 *  Inherits From:  None
 *
 *     Interfaces:  None
 *
 *+-----------------------------------------------------------------------
 *
 *      Constants:  
 *
 *+-----------------------------------------------------------------------
 *
 *   Constructors:  [List the names and arguments of all defined
 *                   constructors.]
 *
 *  Class Methods:  [List the names, arguments, and return types of all
 *                   public class methods.]
 *
 * Inst. Methods:  [List the names, arguments, and return types of all
 *                   public instance methods.]
 *
*/
#include "DataTypes.h"
#include "IMU.h"

namespace BajaWildcatRacing
{

    IMU::IMU(CANDispatcher& canDispatcher, byte deviceId) : CANDevice(canDispatcher, deviceId){

    }

    LatestRotationXYZ IMU::getLatestRotationXYZ(){
        sendCanRequest(0x00, &rotXYZ, sizeof(LatestRotationXYZ));
        return rotXYZ;
    }
    LatestAccelerationXYZ IMU::getLatestAccelerationXYZ(){
        sendCanRequest(0x01, &accXYZ, sizeof(LatestAccelerationXYZ));
        return accXYZ;
    }   
}


