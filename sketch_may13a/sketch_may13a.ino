#include <TM1637.h>

#define CLK 12 // К этому пину подключаем CLK
#define DIO 13 // К этому пину подключаем DIO

TM1637 disp(CLK,DIO);

void setup() // Выполняем процедуру 1 раз
{
// Устанавливаем яркость от 0 до 7
disp.set(1);
disp.init(D4056A);
}

void loop() // Повторяем в бесконечном цикле
{

}

