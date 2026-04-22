#include "GPS.h"
#include <cstring>

namespace BajaWildcatRacing {

void GPS::sendPosition(float lat, float lon, float altM,
                       uint8_t siv, uint8_t fixType, uint8_t rtkStatus) {

    // lat + lon as int32 degrees * 1e7
    int32_t latRaw = (int32_t)(lat * 10000000.0f);
    int32_t lonRaw = (int32_t)(lon * 10000000.0f);
    std::vector<byte> latLon(8);
    memcpy(latLon.data(),     &latRaw, 4);
    memcpy(latLon.data() + 4, &lonRaw, 4);
    sendLossyCanCommand(GPSDataType::LAT_LON, latLon);

    // alt in mm + SIV
    int32_t altMm = (int32_t)(altM * 1000.0f);
    std::vector<byte> altSiv(5);
    memcpy(altSiv.data(), &altMm, 4);
    altSiv[4] = siv;
    sendLossyCanCommand(GPSDataType::ALT_SIV, altSiv);

    // fix type + RTK status
    std::vector<byte> status = { fixType, rtkStatus };
    sendLossyCanCommand(GPSDataType::STATUS, status);
}

} // namespace BajaWildcatRacing