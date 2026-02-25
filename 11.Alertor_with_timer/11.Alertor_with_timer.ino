#define PIN_BUZZER  13
#define PIN_BUTTON  15

hw_timer_t *timer = NULL;
bool isAlerting = false;    // flag

// Changes the state of the buzzer (negation)
void IRAM_ATTR onTimer()
{
  digitalWrite(PIN_BUZZER, !digitalRead(PIN_BUZZER));
}

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  // timer configuration (one over the four available on ESP32-Wrover-E)
  timer = timerBegin(1'000'000);  // sets timer frequency (thus PWM / buzzer frequency)
  timerAttachInterrupt(timer, &onTimer);  // attachment to programmer defined funtion
}

void loop() {
  // button clicked
  if(digitalRead(PIN_BUTTON) == LOW)
  {
    if(!isAlerting)
    {
      isAlerting = true;

      // timerAlarm(timer, 1'000, true, 0);  // sets alarm: 1s, repeat ==> "Perform tasks at specific times or after specific intervals"
      timerStart(timer);
    }
    sin_alert();
  }
  // button released
  else
  {
    if(isAlerting)
    {
      isAlerting = false;

      timerStop(timer);
      digitalWrite(PIN_BUZZER, LOW);
    }
  }
}

// gives a sinusoidal flow to the buzzer tone
void sin_alert()
{
  float sinVal;
  int toneVal;
  for(int i = 0; i < 360; i += 1)
  {
    sinVal = sin(i * (PI / 180));
    toneVal = 2'000 + sinVal * 500;   // frequency
    timerAlarm(timer, 500'000 / toneVal, true, 0);    // buzzer's PWM (managed via timer)
    delay(1);
  }
}
