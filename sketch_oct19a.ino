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
  int CENTER_FREQ, SAMPLE_RATE, BUF_SIZE; // Переменные для хранения данных компаса типа int (целое число)
  float F_MIN, F_MAX; // Переменные для хранения данных GPS типа float (число с плавающей точкой)
  readCompass (CENTER_FREQ, SAMPLE_RATE, BUF_SIZE) ; // Имя функции и аргументы необходимо согласовать с ответственными за написание библиотеки компаса
  readGps(F_MIN, F_MAX); // Имя функции и аргументы необходимо согласовать с ответственными за написание библиотеки GPS
  Serial.print(CENTER_FREQ); //Вывод значения переменной x
  Serial.print(",");
  Serial.print(SAMPLE_RATE); //Вывод значения переменной y
  Serial.print(",");
  Serial.print(BUF_SIZE); //Вывод значения переменной z
  Serial.println();
  Serial.print("Переменная");
  delay(1000); // Задержка 1000 милисекунд (можно поставить другую)
  e220ttl.sendMessage("Переменная");
}
