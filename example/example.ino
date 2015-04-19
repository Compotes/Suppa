#include <nemt.h>

Nemt n(50); // timer  ( 50 = 1s+- )

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Serial.print(n.give_left(3));
  //Serial.print(" ");
  Serial.println(n.give_x(3));
  //Serial.print(" ");
  //Serial.println(n.give_right(3));
  delay(100);
}

