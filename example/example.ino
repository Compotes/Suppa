#include <suppa.h>

Suppa suppa(50); // timer  ( 50 = 1s+- )

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(suppa.give_x(3));
  delay(100);
}

