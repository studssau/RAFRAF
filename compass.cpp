#include "compass.h"
#include <Wire.h>
#include <QMC5883LCompass.h>
static QMC5883LCompass compass;
void initCompass() {
  compass.init();
  Serial.println("Компас инициализирован");

}
void initCompass(int &varx, int &vary, int &varz) {
  compass.read();

}
