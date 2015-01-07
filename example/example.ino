#include <Nemt.h>

Nemt n(3); // we set number of color 1-7

void setup() {
  
}

void loop() {
  n.giveX(); // return type = int; vrati X suradnicu objektu v momente ked sa zavola
  n.giveRight(); // return type = int; vrati Pravy bod objektu v momente ked sa zavola
  n.giveLeft(); // return type = int; vrati Lavy bod objektu v momente ked sa zavola
}

