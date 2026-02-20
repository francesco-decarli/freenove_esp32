# freenove_esp32
This is the repository hosting all the project about the Freenove's Starterkit of ESP32-Wrover-E ([datasheet](https://documentation.espressif.com/esp32-wrover-e_esp32-wrover-ie_datasheet_en.pdf)).
I'm developing them to enhance my electronic knowledge.

## 00 - ESP32's Led Blinking
- **Goal**: a simple check on the developing environment. By making the IO2 led blinking it's possible to know that the developing system is working properly.
- **Requirements**:
  - ESP32-Wrover-E

### What I've learned
- Arduino programming system structure
  - **setup**: hosts everything needed to sustain the project (e.g. setting how the PINs will be used)
  - **loop**: hosts all the commands that will be performed over and over again in a indefinitely loop
 
## 01 - Led Blinking
- **Goal**: through the use of an external led, make it blink.
- **Requirements**:
  - ESP32-Wrover-E
  - Led
  - Resistor (to adjust led input current)
 
### What I've learned
Leds are diods and need a specific input current in order to work correctly without being damaged.

Diods allow the electric current to flow one way only, from the **anode** (positive end) to **cathode** (negative end).

## 02 - Click to lit up the led
- **Goal**: driving a led through a push button switch: when the button is clicked the led should turn on, otherwise it sould stay off
- **Requirements**:
  - ESP32-Wrover-E
  - Led
  - Resistor (to adjust led input current)
  - Push button
  - 2 x Resistor (to adjust push button input current)
 
### What I've learned
Push buttons are an open contact by default. When the button in pressed, the circuit is closed, so the electric current flows through it.

<details>
  <summary>Personal Notes</summary>
  
  ### Pull-up & Pull-down PINs
  It simply refers to the default HIGH (*pull-up*) or LOW (*pull-down*) value (given by the resistor) of the PINs when there's no active signal.
</details>
