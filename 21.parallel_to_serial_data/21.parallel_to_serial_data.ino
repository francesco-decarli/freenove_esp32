// Shift Register (SR) pins
#define SR_UPDATE_PO  12  // Update Parallel Output   ==> ST_CP
#define SR_CLOCK      13  // Clock (of serial shift)  ==> SH_CP
#define SR_DATA       14  // Serial Data Input        ==> DS

byte mask;    // Used as a mask to operat on a single bit of a byte

void setup() {
  pinMode(SR_UPDATE_PO, OUTPUT);
  pinMode(SR_CLOCK, OUTPUT);
  pinMode(SR_DATA, OUTPUT);
}

void loop() {
  mask = 0x01;  // exadecimal value for "1" ==> 0b00000001 in binary (0b 0000 0001)

  // from right to left (the only led on will be the one where the binary "1" value is in the mask)
  for(int i = 0; i < 8; i++)
  {
    writeToShiftRegister(LSBFIRST, mask);
    mask <<= 1;   // shift mask of 1 position to the left ==> e.g. 0b00000001 ==> 0b00000010
    delay(50);
  }
  delay(100);

  mask = 0x80;  // 0b10000000 ==> specular situation of first for loop
  // from left to right (the only led on will be the one where the binary "1" value is in the mask)
  for(int i = 0; i < 8; i++)
  {
    writeToShiftRegister(LSBFIRST, mask);
    mask >>= 1;   // shift mask of 1 position to the right ==> e.g. 0b00000010 ==> 0b00000001
    delay(50);
  }
  delay(100);
}

void writeToShiftRegister(int order, byte _data)
{
  digitalWrite(SR_UPDATE_PO, LOW);            // stops parallel data output update
  shiftOut(SR_DATA, SR_CLOCK, order, _data);  // sends serial data to SR
  digitalWrite(SR_UPDATE_PO, HIGH);           // updates data to parallel output port
}
