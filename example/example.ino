#include <nemt.h>

Nemt n(50); // timer  ( 50 = 1s+- )

void setup() {
  Serial.begin(9600);
}

void loop() {
  n.give_x(3); // return type int // arg1 is color in this case it's yellow
  n.give_right(1); // color = red
  n.give_left(1); // color = red
}

