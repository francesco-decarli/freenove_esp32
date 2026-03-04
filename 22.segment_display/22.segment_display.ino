  // Shift Register (SR) pins
#define SR_UPDATE_PO  12  // Update Parallel Output   ==> ST_CP
#define SR_CLOCK      13  // Clock (of serial shift)  ==> SH_CP
#define SR_DATA       14  // Serial Data Input        ==> DS

// Contains encoded characters for 7-segment display (could have used #define to make the code more readable)
byte display_chars[] = 
{
//   0,    1,    2,    3,    4,    5,    6,    7,
  0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
//   8,    9,    A,    B,    C,    D,    E,    F
  0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E
};

void setup() {
  pinMode(SR_UPDATE_PO, OUTPUT);
  pinMode(SR_CLOCK, OUTPUT);
  pinMode(SR_DATA, OUTPUT);
}

void loop() {
  for(int i = 0; i < 16; i++)
  {
    writeCharOnDisplay(display_chars[i]);
    delay(1'000);
    writeCharOnDisplay(0xFF);     // clears display content (turning all leds off)
  }
}

void writeCharOnDisplay(int char_to_display)
{
  digitalWrite(SR_UPDATE_PO, LOW);                          // stops parallel data output update
  shiftOut(SR_DATA, SR_CLOCK, LSBFIRST, char_to_display);   // sends serial data to SR
  digitalWrite(SR_UPDATE_PO, HIGH);                         // updates data to parallel output port
}
