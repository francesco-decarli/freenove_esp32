String inputString = "";      // will hold incoming data
bool stringComplete = false;  // flag

void setup() {
  Serial.begin(115'200);
  Serial.println("\nESP32 inizialization completed!\n")
        + String("Please input some characters and use \"newline\" to send them.\n");
}

void loop() {
  if(Serial.available())
  {
    char read_char = Serial.read();   // reads a single character from serial data
    inputString += read_char;         // attach the just read character to the buffer
    stringComplete = read_char == '\n' ? true : false;  // changes flag whenever '\n' character is met
  }
  if(stringComplete)
  {
    Serial.printf("inputString: %s\n", inputString);
    inputString = "";         // buffer flushed
    stringComplete = false;   // flag reset
  }
}
