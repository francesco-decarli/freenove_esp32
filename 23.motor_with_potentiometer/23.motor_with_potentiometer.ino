  // L293D pins
#define L2_IN1_PIN      12  // Drives a direction of the motor
#define L2_IN2_PIN      14  // Drives the other direction of the motor
#define L2_ENABLE_PIN   13  // Drives motor's PWM
#define L2_PWM_CHANNEL  0

boolean rotation_dir;
int rotation_speed;

void setup() {
  pinMode(L2_IN1_PIN, OUTPUT);
  pinMode(L2_IN2_PIN, OUTPUT);
  ledcAttachChannel(L2_ENABLE_PIN, 1'000, 11, L2_PWM_CHANNEL);  // PWM at 11 bits ==> range 0 - 2'047
}

void loop() {
  int poten_val = analogRead(A0);   // voltage of torary potentiometer (from analog to digital value)

  // Value 2'048 determins the direction of the rotation
  rotation_speed = poten_val - 2'048;
  if(poten_val > 2'048)
    rotation_dir = true;    // clockwise
  else
    rotation_dir = false;   // counter clockwise

  rotation_speed = abs(poten_val - 2'048);
  driveMotor(rotation_dir, constrain(rotation_speed, 0, 2'048));
}

void driveMotor(boolean dir, int speed)
{
  // clockwise
  if(dir)
  {
    digitalWrite(L2_IN1_PIN, HIGH);
    digitalWrite(L2_IN2_PIN, LOW);
  }
  // counter clockwise
  else
  {
    digitalWrite(L2_IN1_PIN, LOW);
    digitalWrite(L2_IN2_PIN, HIGH);
  }
  ledcWrite(L2_ENABLE_PIN, speed);  // control motor rotation
}
