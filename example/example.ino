// put Nemt file to home/(username)/sketchbook/libraries/

#include <Nemt.h>

Nemt n; //zrobime instanciu 

void setup() {
}

void loop() {
  n.giveX(); // return type = int; vrati X suradnicu objektu v momente ked sa zavola
  n.giveRight(); // return type = int; vrati Pravy bod objektu v momente ked sa zavola
  n.giveLeft(); // return type = int; vrati Lavy bod objektu v momente ked sa zavola
}




