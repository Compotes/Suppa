#include <suppa.h>

/* Set orientation 1 or -1 (normal, inverted) and delay for camera. In this case
 * we wait 30 frames without color clue.
 */
Suppa suppa(-1, 30);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // gives x coordinate of color with number 1
  Serial.println(suppa.give_x(1));
  delay(10);
}
