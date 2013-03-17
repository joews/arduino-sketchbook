//Set a random combination of 3 LEDs
//Circuit: http://arduino.cc/en/Tutorial/ShiftOut
//Joe Whitfield-Seed / joeseed86 at google mail
#include <math.h>

int LATCH = 8;
int CLOCK = 12;
int DATA = 11;

void setup() {
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop() {
  
  //Light 3 random LEDs
  byte leds = 0;   //the bits for the 3 LEDs we select
  byte found = 0;  //the number of random LEDs we've chosen so far

  //Keep choosing random numbers until we have 3 distinct values
  while(found < 3) {

    //Bit shift 1 by a random number 0-8 to
    // generate a "candidate" LED byte. We will then check
    // we haven't already used this candidate.
    byte candidate = 1 << (byte)random(0, 8);

    //Reject candidates we've used in this iteration
    //We can detect this by bitwise ANDing the candidate and the 
    // values we've already chosen.
    if((candidate & leds) == 0) {

      //To accept this random candidate, bitwise OR it with the
      // existing chosen values
      leds |= candidate;
      ++ found;
    }
  }

  //Turn off the latch while we shift in bits, 
  // then re-enable to light the LEDs
  digitalWrite(LATCH, LOW); 
  shiftOut(DATA, CLOCK, MSBFIRST, leds); 
  digitalWrite(LATCH, HIGH);

  delay(1000);
}


