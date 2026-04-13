#include "Procedure.h"
#include "IMUSubsystem.h"
#include "DataStorage.h"
#include "CarLogger.h"
#include "Coms.h"

#include <iomanip>

namespace BajaWildcatRacing
{

class IMULoggingProcedure : public Procedure{
    public:
        IMUSubsystem& imuSubsystem;
        DataStorage& dataStorage;
        Coms& coms;


        IMULoggingProcedure(IMUSubsystem& imuSubsystem, DataStorage& dataStorage, Coms& coms)
        : imuSubsystem(imuSubsystem)
        , dataStorage(dataStorage)
        , coms(coms)
        {

            this->frequency = 60;

        }
        
        void init() override {
            std::cout << "IMU procedure initialized!" << std::endl;
        }

        void execute() override {

            IMU::LatestRotationXYZ rotation = imuSubsystem.getRotationXYZ();
            IMU::LatestAccelerationXYZ acceleration = imuSubsystem.getAccelerationXYZ();

            dataStorage.storeData(rotation.rotationx, DataTypes::IMU_ROTATION_X);
            dataStorage.storeData(rotation.rotationy, DataTypes::IMU_ROTATION_Y);
            dataStorage.storeData(rotation.rotationz, DataTypes::IMU_ROTATION_Z);
            dataStorage.storeData(acceleration.accelerationx, DataTypes::IMU_ACCELERATION_X);
            dataStorage.storeData(acceleration.accelerationy, DataTypes::IMU_ACCELERATION_Y);
            dataStorage.storeData(acceleration.accelerationz, DataTypes::IMU_ACCELERATION_Z);

            coms.sendData(DataTypes::IMU_ROTATION_X, rotation.rotationx);
            coms.sendData(DataTypes::IMU_ROTATION_Y, rotation.rotationy);
            coms.sendData(DataTypes::IMU_ROTATION_Z, rotation.rotationz);
            coms.sendData(DataTypes::IMU_ACCELERATION_X, acceleration.accelerationx);
            coms.sendData(DataTypes::IMU_ACCELERATION_Y, acceleration.accelerationy);
            coms.sendData(DataTypes::IMU_ACCELERATION_Z, acceleration.accelerationz);
        }

        void end() override {
            std::cout << "IMU procedure ended" << std::endl;
        }

        bool isFinished() override {
            return false;
        }

        std::string toString() override {
            return "IMU Procedure";
        }

    private:
};

}
