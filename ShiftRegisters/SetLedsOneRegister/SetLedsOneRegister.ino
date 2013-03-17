//Set one LED at a time
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
  
  for (byte n = 0; n < 8; n++) {   
    lightLed(n);
    delay(200);
  }
}

//Light a single LED in the range 0-7
void lightLed(byte led) {
  digitalWrite(LATCH, LOW);   
  
  //Use bit shift instead of pow() - more efficient,
  // and pow returns a float which may be truncated
  // to an unexpected integer value
  //(e.g. int n = pow(2,3); // => n = 7.
  shiftOut(DATA, CLOCK, MSBFIRST, 1 << led); 
  digitalWrite(LATCH, HIGH);
}

