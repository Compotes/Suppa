#include <Nemt.h>

Nemt n(3); // we set number of color 1-7 // we set counter 

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(n.giveX()); // return type = int; x point
  n.giveRight(); // return type = int; right point
  n.giveLeft(); // return type = int; left point
}

