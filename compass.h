#ifndef COMPASS_H
#define COMPASS_H
#include <Arduino.h>
void initCompass(); // для инициализации магнитомтра
void readCompass(int &varx, int &vary, int &varz); // для чтения показаний

#endif
