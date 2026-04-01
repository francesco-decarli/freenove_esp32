#define TRIG_PIN   13
#define ECHO_PIN   14
#define MAX_DISTANCE  700   // max sensor distance at 400-500 cm
#define SOUND_SPEED   340  // m/s

float time_out = MAX_DISTANCE * 60; // time_out = 2 * MAX_DISTANCE / 340 * 10'000 = MAX_DISTANCE * 58.8 (listening window)

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(115'200);
}

void loop() {
  delay(100);   // 100ms between pings (about 20 ping/sec)
  Serial.printf("Distance: %.2fcm\n", getSonarDistance());
}

// calculates and returns the distance given by the sonar module
// transmits and receives
float getSonarDistance()
{
  unsigned long ping_time;

  // Transmitting ==> Make output high level lasting for 10us to trigger ultrasound device (HC-SR04)
  digitalWrite(TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(TRIG_PIN, LOW);

  // Receiving ==> waiting high level read and mesure the time passed
  ping_time = pulseIn(ECHO_PIN, HIGH, time_out);  // [pin, type of pulse to read, timeout for the pulse to start]
  
  return (float)ping_time * SOUND_SPEED / 2 / 10'000;   // returning calculated float distance
}
