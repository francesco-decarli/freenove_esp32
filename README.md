# freenove_esp32
This is the repository hosting all the project about the Freenove's Starterkit of ESP32-Wrover-E ([datasheet](https://documentation.espressif.com/esp32-wrover-e_esp32-wrover-ie_datasheet_en.pdf)).
I'm developing them to enhance my electronic knowledge.

## 00 - ESP32's Led Blinking
This is a simple check on the developing environment.
By making the **IO2** led blinking it's possible to know that the developing system is working properly.

### What I've learned
- Arduino programming system structure
  - **setup**: hosts everything needed to sustain the project (e.g. setting how the PINs will be used)
  - **loop**: hosts all the commands that will be performed over and over again in a indefinitely loop


<details>
  <summary>Personal Notes</summary>
  
  ### Pull-up & Pull-down PINs
  It simply refers to the default HIGH (*pull-up*) or LOW (*pull-down*) value (given by the resistor) of the PINs when there's no active signal.
</details>
