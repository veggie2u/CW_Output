#include "Output.h"

// Output to both the OLED and Serial
Output output(true, true);

void setup() {
	// required to set everything up
  output.begin();

	// only clears oled screen
	output.clear();
  output.print("Hello ");
  output.println("World");
}

void loop() {}
