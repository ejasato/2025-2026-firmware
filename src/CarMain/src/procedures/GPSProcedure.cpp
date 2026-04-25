#include "Procedure.h"
#include "GPUSubsystem.h"
#include "DataStorage.h"
#include "CarLogger.h"
#include "Coms.h"
#include "DataTypes.h"

#include <iomanip>

namespace BajaWildcatRacing
{

class GPUProcedure : public Procedure{
    public:
        GPUSubsystem& gpuSubsystem;
        DataStorage& dataStorage;
        Coms& coms;


        GPUProcedure(GPUSubsystem& gpuSubsystem, DataStorage& dataStorage, Coms& coms)
        : gpuSubsystem(gpuSubsystem)
        , dataStorage(dataStorage)
        , coms(coms)
        {

            this->frequency = 60;

        }
        
        void init() override {
            std::cout << "GPU procedure initialized!" << std::endl;
        }

        void execute() override {

            LatestLatLon TempLatLon = gpuSubsystem.getLatLon();
            uint32_t TempTime = gpuSubsystem.getTime();

            // dataStorage.storeData(rotation, DataTypes::LatestRotationXYZ);
            // dataStorage.storeData(acceleration, DataTypes::LatestAccelerationXYZ);
            byte rotData[sizeof(LatestLatLon)];
            memcpy(rotData, &TempLatLon, sizeof(LatestLatLon));
            coms.sendData(DataType::LATLON, rotData, sizeof(LatestLatLon));

            byte accelData[sizeof(uint32_t)];
            memcpy(accelData, &TempTime, sizeof(uint32_t));
            coms.sendData(DataType::TIME, accelData, sizeof(uint32_t));
        }

        void end() override {
            std::cout << "GPU procedure ended" << std::endl;
        }

        bool isFinished() override {
            return false;
        }

        std::string toString() override {
            return "GPU Procedure";
        }

    private:
};

}
