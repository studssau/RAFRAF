#include "compass.h"
#include "gps.h"
#include "LoRa_E220.h"
LoRa_E220 e220ttl(8, 9, 5, 7, 6);
void setup() {
  Serial.begin(9600); // Запуск последовательного порта
  initCompass(); // Функция инициализации компаса
  initGps(); //Функция инициализации GPS
  e220ttl.begin();
}

void loop() {
  int x, y, z, sat;
  float lat, lng, alt;

  readCompass(x, y, z); 
  readGps(lat, lng, alt, sat);

  Serial.print(x);
  Serial.print(",");
  Serial.print(y); 
  Serial.print(",");
  Serial.print(z);
  Serial.print(",");
  Serial.print(lat); 
  Serial.print(",");
  Serial.print(lng);
  Serial.print(",");
  Serial.print(alt); 
  Serial.print(",");
  Serial.print(sat);
  Serial.println();

  e220ttl.sendMessage("Название команды," + String(x) + "," + 
	String(y) + "," + String(z) + "," + String(lat) + "," + 
	String(lng) + "," + String(alt) + "," + String(sat) + "\n\r");
  if (e220ttl.available() > 1) { //Ждем больше одного байта
    
    ResponseContainer response = e220ttl.receiveMessage(); //Получение сообщения с радиомодуля
    
    String Message = response.data; //Запись в переменную Message типа String (строка)

  }

  delay(1000);
}
