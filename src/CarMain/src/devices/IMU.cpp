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

#include "IMU.h"

namespace BajaWildcatRacing
{

    IMU::IMU(CANDispatcher& canDispatcher, byte deviceId) : CANDevice(canDispatcher, deviceId){

    }

    IMU::LatestAccelerationXYZ IMU::getLatestAccelerationXYZ(){
        sendCanRequest(0x04, &accXYZ.accelerationx, sizeof(float));
        sendCanRequest(0x05, &accXYZ.accelerationy, sizeof(float));
        sendCanRequest(0x06, &accXYZ.accelerationz, sizeof(float));
        return accXYZ;
    }

    // float IMU::getLatestAccelerationY(){

    //     sendCanRequest(0x05, &accY, sizeof(float));
    //     return accY;

    // }

    // float IMU::getLatestAccelerationZ(){

    //     sendCanRequest(0x06, &accZ, sizeof(float));
    //     return accZ;

    // }

    IMU::LatestRotationXYZ IMU::getLatestRotationXYZ(){
        sendCanRequest(0x01, &rotXYZ.rotationx, sizeof(float));
        sendCanRequest(0x02, &rotXYZ.rotationy, sizeof(float));
        sendCanRequest(0x03, &rotXYZ.rotationz, sizeof(float));
        return rotXYZ;
    }

    // float IMU::getLatestRotationY(){
    //     sendCanRequest(0x02, &rotY, sizeof(float));
    //     return rotY;
    // }

    // float IMU::getLatestRotationZ(){
    //     sendCanRequest(0x03, &rotZ, sizeof(float));
    //     return rotZ;
    // }
}


