#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA   13
#define SCL   14

/*
NOTE: if LCD1602 uses PCF8574T ==>  I2C's address is 0x27 [this is my case]
      if LCD1602 uses PCF8574AT ==> I2C's address is 0x3F
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);   // class LCD initialization [address, n_columns, n_rows]

void setup() {
  Wire.begin(SDA, SCL);

/*
  // Test on I2C module type and switch (if needed)
  if(!i2cAddeTest(0x27))
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
*/

  lcd.init();
  lcd.backlight();                // turns it on
  lcd.setCursor(0, 0);            // set the cursor on given coordinates [column, row]
  lcd.print("Guys, I'm alive!");
}

void loop() {
  lcd.setCursor(0, 1);  // Go to second row
  lcd.print("Counter: ");
  lcd.print(millis() / 1'000);    // prints how many seconds are passed
  delay(1'000);
}

/*
// tests the passed address closing the transmission
bool i2cAddrTest(uint8_t addr)
{
  Wire.beginTransmission(addr);
  return Wire.endTransmission() == 0;
}
*/
