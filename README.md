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

# 02 - Click to Light Up the Led
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

This phenomenon is something that is not perceived by human eyes as it's very fast, but it has to be dealt with in order to make the system work as expected.

# 4 - Flowing Light
- **Goal**: make the ledbar's led turning on and off sequentially.
- **Requirements**:
  - ESP32-Wrover-E
  - Led bar
  - *N* x Resistor (to adjust led input current) where *N* is the number of led that comprise the ledbar
 
### What I've learned
Arrays in Arduino.

# 4.1 - Flowing Light by Click [extra]
- **Goal**: make the ledbar's led turning on and off sequentially when the push button is pressed.

  The schematic diagram is a blend between the previous project and the one created in [section 02](#02---click-to-light-up-the-led).
- **Requirements**:
  - ESP32-Wrover-E
  - Led bar
  - *N* x Resistor (to adjust led input current) where *N* is the number of led that comprise the ledbar
  - Push button
  - 2 x Resistor (to adjust push button input current)
 
### What I've learned: troubleshooting edition
At the beginning what I've wrote did not respond properly (at all, more precisely). I've tried the various part of the code separately and they responded correctly once I've changed the reading status of the push button to *low*, but the whole code did just not. Once I've recreated it one step at a time, it worked. I would like to know what happened.

# 05 - Breathing Led
- **Goal**: turning the led on and off by making it do it gradually.
- **Requirements**:
  - ESP32-Wrover-E
  - Led
  - Resistor (to adjust led input current)

### What I've learned
**PWM** (Pulse-Width Modulation) is a system to convert analog signals to digital ones using squared waveform signal.

To make it simple, it uses stairs to follow the smooth change of an analog signal. Those stairs have an accuracy: on the same inclination, they can be quite high (low accuracy) or they can be very low (high accuracy) following the slope.
The **duty cycle** points out as a percentage how much the squared waveform signal is on respect to the whole signal duration.

# 6 - Meteor Flowing Light
- **Goal**: make the ledbar's led turning on and off sequentially with a moving effect where the the brightest led leads. So, there'll be the brightest led moving from left to right and backward, followed by other active leds with a lower duty cycle.
- **Requirements**:
  - ESP32-Wrover-E
  - Led bar
  - *N* x Resistor (to adjust led input current) where *N* is the number of led that comprise the ledbar

# 07 - Random Colour RGB Light
- **Goal**: comprehend RGB led.
- **Requirements**:
  - ESP32-Wrover-E
  - RGB Led
  - 3 x Resistor (to adjust led input current)

# 08 - Gradient Colour RGB Light
- **Goal**: Make the colour change smooth (related to the previous project).
- **Requirements**:
  - ESP32-Wrover-E
  - RGB Led
  - 3 x Resistor (to adjust led input current)
  
### What I've learned
Operator priority exists and makes code more readable.

# 09 - Doorbell
- **Goal**: make the buzzer sound whenever the push button is clicked.
- **Requirements**:
  - ESP32-Wrover-E
  - NPN transistor (to amplify the supply current given to the buzzer)
  - Active buzzer
  - Push button
  - Resistor (to adjust transistor input current)
  - 2 x Resistor (to adjust push button current)
  
### What I've learned
There are two kind of buzzers:
  - **Active**: it have an internal active oscillator (due to this is has a more complex manufacturing and usually needs a waterproof coating) which sounds as long as there's current flowing into it. It sounds at the given by the manufacturer frequency
  - **Passive**: need an external oscillator (PWM) to work, so it's possible to make it sound at different frequencies

<details>
  <summary>Personal Notes</summary>
  
  ### Pull-up & Pull-down PINs
  It simply refers to the default HIGH (*pull-up*) or LOW (*pull-down*) value (given by the resistor) of the PINs when there's no active signal.
</details>

