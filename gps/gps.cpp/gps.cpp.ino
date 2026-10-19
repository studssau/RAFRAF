void setup() {
  #include "gps.h"// put your setup code here, to run once:
  #include <TinyGPS++.h>
  #include <SoftwareSerial.h>
static TinyGPSPlus gps;
static SoftwareSerial gpsSerial(4, 3);
void initGps() {
  gpsSerial.begin(9600);
  Serial.println("GPS инициализирован");
}
void readGps(float &num1, float &num2, float &num3) {
  gpsSerial.begin(9600);
  Serial.println("GPS инициализирован");
}
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }
   num1 = gps.location.lat(); //запись значения широты в переменную num1
   num2 = gps.altitude.meters();
   num3 = gps.satellites.value();
}

void loop() {
  // put your main code here, to run repeatedly:

}
