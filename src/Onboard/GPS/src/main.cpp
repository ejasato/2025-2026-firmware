#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>
#include "CANTProtocol.h"

CANTProtocol CAN(10,2,0xA); //need to check pins
SFE_UBLOX_GNSS myGNSS;
typedef struct GPSPosition{
    float longitude;
    float latitude;
    float atltitude;
}GPSPosition;

void builder(unsigned char dataLength, byte* incomingData, unsigned long callbackID){
    GPSPosition longitude = myGNSS.getLongitude();
    GPSPosition latitude = myGNSS.getLatitude();
    GPSPosition altitude = myGNSS.getAltitude();
    uint32_t time = myGNSS.getUnixEpoch();
    CAN.registerRequestReponse(GPSPosition, callbackID);
    CAN.registerRequestReponse(time, callbackID);
}

void builder1(unsigned char dataLength, byte* incomingData, unsigned long callbackID){
    uint32_t time = myGNSS.getUnixEpoch();
    CAN.registerRequestReponse(time, callbackID);
}

void setup()
{
    Wire.begin();
  myGNSS.setI2COutput(COM_TYPE_UBX); //Set the I2C port to output UBX only (turn off NMEA noise)
  myGNSS.saveConfigSelective(VAL_CFG_SUBSEC_IOPORT); //Save (only) the communications port settings to flash and BBR
  CAN.registerRequest(0, builder);
  CAN.registerRequest(1, builder1);
  while(!CAN.begin()){
    delay(100);
  }
}

void loop(){
    CAN.execute();
}