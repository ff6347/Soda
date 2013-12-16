/* Soda Demo

Uses the soda library from Qtechknow.  Counts to 9 and then goes back to 0 on 
a seven segment display.  

created 14 Apr 12
Made by Quin (Qtechknow)

Some edits by @fabiantheblind
  see:  http://www.tinkersoup.de/lcd-oled-e-paper/7-segment-anzeige-led-blue/a-1122/
  see: https://www.sparkfun.com/products/9191
  see: http://www.instructables.com/id/Seven-Segment-Display-Tutorial/step3/Testing-The-Display/
  see: http://forum.arduino.cc/index.php/topic,22413.0.html
  see Datasheet (Anode pin marking is wrong): https://www.sparkfun.com/datasheets/Components/LED/YSD-160AB3C-8.pdf
  
  
  Libraries: https://github.com/Qtechknow/Arduino-Libraries/tree/master/Soda
            my fork: https://github.com/fabiantheblind/Seven-Segment-LED-Arduino-Libraries
  
  
  on the 7 segement LED
  Anode Pins are 3 and 8
  connect them to 5V
  connect the rest of the pins to a resistor and the according pins. 
  
     7/A
      _
 9/F |_| 6/B
 1/E |_| 4/C . <-- 5/DB (The point)
 
     2/D
     
  And the center bar is the 10/G   
  
*/

#include "Soda.h"

Soda Soda;   // initialize the library

// 8 works right
// 9 works wrong
// |_
// |_|.
//


void setup() {
// Segments A, B, C, D, E, F, G, DP pin numbers
  Soda.pins(1, 2, 4, 6, 7, 9, 10, 5, HIGH);  // set high for common anode, and 
                                            // low for common cathode display
}

void loop() {

  for(int i=0; i< 9; i++) {
    Soda.write(i);        // count to 9
    delay(1000);          // delay for 1 second
  }
}
