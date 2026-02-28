#define PIN_LED             13
#define TOUCH_THRESHOLD     400 // to manage touch
#define RELEASE_THRESHOLD   500 // to manage touch

bool isProcessed = false;   // flag to manage touch
int touchVal;

void setup() {
  Serial.begin(115'200);  // logger
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  touchVal = touchRead(T0); // reading and using touch val detected at the beginning in this loop

  // Touch detected
  if(touchVal < TOUCH_THRESHOLD)
  {
    // Check if touch already managed
    if(!isProcessed)
    {
      isProcessed = true;
      Serial.printf("Read Value: %d ==> Touched!\n", touchVal);
      reverseGPIO(PIN_LED);
    }
  }

  // No touch detected
  if(touchVal > RELEASE_THRESHOLD)
  {
    if(isProcessed)
    {
      isProcessed = false;
      Serial.printf("Read Value: %d ==> Released!\n", touchVal);
    }
  }
}

// switches the status of the passed pin (on/off)
void reverseGPIO(int pin)
{
  digitalWrite(pin, !digitalRead(pin));
}
