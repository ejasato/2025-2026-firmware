#include <Wire.h>
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>
// SFE_UBLOX_GNSS gnss;
// void setup() {
//   Serial.begin(115200);
//   Wire.begin(21, 22, 100000); // SDA=21, SCL=22
//   if (!gnss.begin(Wire)) {
//     Serial.println("GNSS not detected!");
//     while(1);
//   }
//   // Correct v2 calls
//   gnss.enableMessage(UBX_CLASS_NAV, UBX_NAV_PVT, true);
//   gnss.enableMessage(UBX_CLASS_NAV, UBX_NAV_STATUS, true);
//   gnss.setI2COutput(COM_TYPE_UBX);
//   gnss.setAutoPVT(true);
// }
// void loop() {
//   if (gnss.getPVT()) {
//     int fix = gnss.getFixType();
//     Serial.print("Fix type: ");
//     Serial.println(fix);
//     if (fix > 0) {  // only print coordinates if valid
//       Serial.print("Lat: "); Serial.println(gnss.getLatitude(), 7);
//       Serial.print("Lon: "); Serial.println(gnss.getLongitude(), 7);
//       Serial.print("Alt: "); Serial.println(gnss.getAltitude());
//     } else {
//       Serial.println("No valid fix yet");
//     }
//   }
//   delay(500);
// }
SFE_UBLOX_GNSS myGNSS;
long lastTime = 0; //Simple local timer. Limits amount if I2C traffic to u-blox module.
void setup()
{
  Serial.begin(115200);
  while (!Serial); //Wait for user to open terminal
  Serial.println("SparkFun u-blox Example");
  Wire.begin();
  myGNSS.enableDebugging(); // Uncomment this line to enable helpful debug messages on Serial
  if (myGNSS.begin() == false) //Connect to the u-blox module using Wire port
  {
    Serial.println(F("u-blox GNSS not detected at default I2C address. Please check wiring. Freezing."));
    while (1);
  }
  myGNSS.setI2COutput(COM_TYPE_UBX); //Set the I2C port to output UBX only (turn off NMEA noise)
  myGNSS.saveConfigSelective(VAL_CFG_SUBSEC_IOPORT); //Save (only) the communications port settings to flash and BBR
}
void loop()
{
  //Query module only every second. Doing it more often will just cause I2C traffic.
  //The module only responds when a new position is available
  if (millis() - lastTime > 1000)
  {
     byte hour = myGNSS.getHour();
byte minute = myGNSS.getMinute();
byte second = myGNSS.getSecond();
uint32_t time = myGNSS.getUnixEpoch();
int ms = myGNSS.getMillisecond();
    lastTime = millis(); //Update the timer
    
    long latitude = myGNSS.getLatitude();
    Serial.print(F("Lat: "));
    Serial.print(latitude);
    long longitude = myGNSS.getLongitude();
    Serial.print(F(" Long: "));
    Serial.print(longitude);
    Serial.print(F(" (degrees * 10^-7)"));
    long altitude = myGNSS.getAltitude();
    Serial.print(F(" Alt: "));
    Serial.print(altitude);
    Serial.print(F(" (mm)"));
    byte SIV = myGNSS.getSIV();
    Serial.print(F(" SIV: "));
    Serial.print(SIV);
    Serial.println();
//     Serial.print(hour); Serial.print(":");
// Serial.print(minute); Serial.print(":");
// Serial.print(second); Serial.print(".");
// Serial.println(ms);
Serial.print("Unix Epoch: ");
Serial.println(time);
  }
}