#include <Nemt.h>

Nemt n(50); // timer  ( 50 = 1s+- )

void setup() {
  Serial.begin(9600);
}

void loop() {
  n.giveX(3); // return type int // arg1 is color in this case it's yellow
  n.giveRight(1); // color = red
  n.giveLeft(1); // color = red
}

