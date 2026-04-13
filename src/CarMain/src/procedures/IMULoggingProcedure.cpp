#include "Procedure.h"
#include "IMUSubsystem.h"
#include "DataStorage.h"
#include "CarLogger.h"
#include "Coms.h"
#include "DataTypes.h"

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

            LatestRotationXYZ rotation = imuSubsystem.getRotationXYZ();
            LatestAccelerationXYZ acceleration = imuSubsystem.getAccelerationXYZ();

            // dataStorage.storeData(rotation, DataTypes::LatestRotationXYZ);
            // dataStorage.storeData(acceleration, DataTypes::LatestAccelerationXYZ);
            byte rotData[sizeof(LatestRotationXYZ)];
            memcpy(rotData, &rotation, sizeof(LatestRotationXYZ));
            coms.sendData(DataTypes::IMU_ROTATION, rotData, sizeof(LatestRotationXYZ));

            byte accelData[sizeof(LatestAccelerationXYZ)];
            memcpy(accelData, &acceleration, sizeof(LatestAccelerationXYZ));
            coms.sendData(DataTypes::IMU_ACCELERATION, accelData, sizeof(LatestAccelerationXYZ));
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
