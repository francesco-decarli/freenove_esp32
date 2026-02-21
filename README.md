This is the repository hosting all the project about the Freenove's Starterkit of ESP32-Wrover-E ([datasheet](https://documentation.espressif.com/esp32-wrover-e_esp32-wrover-ie_datasheet_en.pdf)).
I'm developing them to enhance my electronic knowledge.

# 00 - ESP32's Led Blinking
- **Goal**: a simple check on the developing environment. By making the IO2 led blinking it's possible to know that the developing system is working properly.
- **Requirements**:
  - ESP32-Wrover-E

### What I've learned
- Arduino programming system structure
  - **setup**: hosts everything needed to sustain the project (e.g. setting how the PINs will be used)
  - **loop**: hosts all the commands that will be performed over and over again in a indefinitely loop
 
# 01 - Led Blinking
- **Goal**: through the use of an external led, make it blink.
- **Requirements**:
  - ESP32-Wrover-E
  - Led
  - Resistor (to adjust led input current)
 
### What I've learned
Leds are diods and need a specific input current in order to work correctly without being damaged.

Diods allow the electric current to flow one way only, from the **anode** (positive end) to **cathode** (negative end).

# 02 - Click to light up the led
- **Goal**: driving a led through a push button switch: when the button is clicked the led should turn on, otherwise it sould stay off
- **Requirements**:
  - ESP32-Wrover-E
  - Led
  - Resistor (to adjust led input current)
  - Push button
  - 2 x Resistor (to adjust push button input current)
 
### What I've learned
Push buttons are an open contact by default. When the button in pressed, the circuit is closed, so the electric current flows through it.

# 03 - Table Lamp
- **Goal**: every push of a button should change the led state
- **Requirements**:
  - ESP32-Wrover-E
  - Led
  - Resistor (to adjust led input current)
  - Push button
  - 2 x Resistor (to adjust push button input current)
 
### What I've learned
In push buttons (and any other electrical element that has a similar structure), there's this <ins>mechanical phenomenon called **debounce**</ins>. This term refers to the change of the state of the switch (in both ways) which is not smooth, but it does change more than once before being stable the other state (like an echo, narrowing down its tone from loud to nothing, fading out).

This phenomenon is something that is not percived by human eyes as it's very fast, but it has to be dealt with in order to make the system work as expected.

# 4 - Flowing Light
- **Goal**: make the ledbar's led turning on and off sequentially.
- **Requirements**:
  - ESP32-Wrover-E
  - Led bar
  - *N* x Resistor (to adjust led input current) where *N* is the number of led that comprise the ledbar
 
### What I've learned
Arrays in Arduino.

<details>
  <summary>Personal Notes</summary>
  
  ### Pull-up & Pull-down PINs
  It simply refers to the default HIGH (*pull-up*) or LOW (*pull-down*) value (given by the resistor) of the PINs when there's no active signal.
</details>

