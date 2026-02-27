This is the repository hosting all the project about the **Freenove's Starterkit of ESP32-Wrover-E** ([datasheet](https://documentation.espressif.com/esp32-wrover-e_esp32-wrover-ie_datasheet_en.pdf)). All the projects are developed using **Arduino IDE 2.3.7** on Ubuntu.
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

The **duty cycle** points out as a percentage how much the squared waveform signal is on respect to the whole signal duration. It's used to represent the signal intensity of the waveform in the specific slice of time when used in PWM, representing the *pulse-width* of the *modulation*, or to the single stair of the mental image I've tried to create; while the accuracy is determined by how many stairs fits in the slice of time the analysis is performed.

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

# 10 - Alertor
- **Goal**: make the buzzer sound whenever the push button is clicked with a sinusoidal-like frequency.
- **Requirements**:
  - ESP32-Wrover-E
  - NPN transistor (to amplify the supply current given to the buzzer)
  - Passive buzzer
  - Push button
  - Resistor (to adjust transistor input current)
  - 2 x Resistor (to adjust push button current)

# 11 - Alertor With Timer
- **Goal**: make the buzzer sound (sinusoidal wave) whenever the push button is clicked. The timer controls the buzzer sound event and behaves like its PWV.
- **Requirements**:
  - ESP32-Wrover-E
  - NPN transistor (to amplify the supply current given to the buzzer)
  - Passive buzzer
  - Push button
  - Resistor (to adjust transistor input current)
  - 2 x Resistor (to adjust push button current)
  
### What I've learned
Where <ins>**prescaler**</ins> is available, it's possible <ins>to adjust clock frequency, lowering it</ins>.
General knowledge about managing timers with Arduino.

# 12 - Serial Print
- **Goal**: printing system tick every 5s on the serial monitor.
- **Requirements**:
  - ESP32-Wrover-E (with its wire)
  
### What I've learned
Serial communication usually refers to UART (Universal Asynchronous Receiver/Transmitter), where the <ins>baud rate</ins> (simply think about it as the radio frequency transmitter and receiver sync to talk over to each other) has to be the same; most used values are 96'000 and 115'200.
Thanks to an integrated serial to USB converter (UART to USB and USB to UART), ESP32 can communicate with computers, in particular with IDEs.
There's a serial monitor on Arduino IDE and it's on the top right corner. It's important to set the same baud rate.

A serial communication defined as ***8N1*** is a standard for communications with:
  - **8** bits of data
  - **N**o parity bit (used to check any error in the payload, without it there's no control but it maximize communication speed)
  - **1** bit to point out the end of the package sent

# 13 - Serial Talk
- **Goal**: receive and print data from terminal.
- **Requirements**:
  - ESP32-Wrover-E (with its wire)

# 14 - Reading Potentiometer With AD/DA
- **Goal**: through the analog data read from potentiometer, drive led brightness.
- **Requirements**:
  - ESP32-Wrover-E (with its wire)
  - Rotary potentiometer
  - Led
  - Resistor (to adjust led input current) 
  
### What I've learned
As introduced in [section 05](#05---breathing-led), as computers stores data with "0" and "1", a method to convert analog signals (which are smooth and continuous) to digital in a way that, in fact, can be stored in a computer (or, in general, processed in any way with digital things) is needed. This is referred to AD/DA conversion, which means:
  - **AD**: Analog to Digital
  - **DA**: Digital to Analog
The classic method is via PWM which uses a squared waveform as introduced before.

For a practical example think about an audio system. The microphone has as internal diaphragm which is pushed by its user voice. The movement is converted to a digital signal so that it can be processed or just simply directly sent to the speakers. Once the signal is at the speakers, the inverse process happens: the digital signal is once again converted to analog to make the speakers sound. The output sound is not the same identical sound inputted to into the microphone, but if the accuracy is right, human ears cannot spot the difference (the information that is lost in the process).

A **potentiometer** is a resistor with a fixable resistance.

<ins>**Curious note**</ins>: to observe the actual analog signal acquired from the potentiometer, I've made a little change to the electrical scheme of this project by connecting the led directly to the same pin of the potentiometer (in this case putting them together to the same breadboard column of PIN_4).

Also, I've commented out the *delay()* command and the logger, trying to spot the difference between the analog (performing the previous change to the schematic) and digital signal (by making the code change with the original electrical scheme). It's not possible to see it.

<details>
  <summary>Personal Notes</summary>
  
  ### Pull-up & Pull-down PINs
  It simply refers to the default HIGH (*pull-up*) or LOW (*pull-down*) value (given by the resistor) of the PINs when there's no active signal.
</details>

