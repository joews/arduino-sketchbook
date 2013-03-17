//Simple binary count 0-255
//http://arduino.cc/en/Tutorial/ShiftOut

int LATCH = 8;
int CLOCK = 12;
int DATA = 11;

void setup() {
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop() {
  for (int n = 0; n < 256; n++) {
    
    //Don't change LEDs while we update the register
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, n);  
    digitalWrite(LATCH, HIGH);

    delay(100);
  }
}

