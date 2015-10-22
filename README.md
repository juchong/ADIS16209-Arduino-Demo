# ADIS16209 Arduino Demo
### An example C++ library and Arduino project for the ADIS16209 iSensor Inclinometer/Accelerometer

This example library was written to give engineers, students, and makers a starting point for using a high-performance inclinometer/accelerometer. The code in this repository will provide the user with:
- A header file listing all of the unit's available registers
- Functions for reading output registers and writing control registers using **8-bit** frames
- Functions for performing common routines such as resetting the sensor
- Example Arduino sketches which synchronously read data from the sensor and write it to the serial port

### What do I need to get started?

In order to compile and execute the Arduino sketch, you'll need to download the "legacy" Arduino package (v1.0.6 as of this writing). You can download the IDE [here](http://arduino.cc/download.php?f=/arduino-1.0.6-windows.zip).

You'll also need an 8-bit arduino such as an [Arduino Uno](http://www.arduino.cc/en/Main/ArduinoBoardUno).

The Arduino sketches use commands which clear the terminal window. For best results, connect to your Arduino using [PuTTY](http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html), an open source terminal program.

### How do I install the library?

Once you've installed the Arduino IDE, copy the ADIS16209 folder into `My Documents > Arduino > libraries`

### How do I connect the IMU to my Arduino?

**The ADIS16209 is a 3.3V part, so your Arduino must be modified before connecting the sensor to it! A guide to modifying an Arduino Uno can be found [here](https://learn.adafruit.com/arduino-tips-tricks-and-techniques/3-3v-conversion).**

After modifying the Arduino, you'll need to build a cable to interface the sensor with the [ADIS16209/PCBZ](http://www.analog.com/en/design-center/evaluation-hardware-and-software/evaluation-boards-kits/eval-adis16209.html#eb-overview).

![ADIS16209-Arduino Cable Interface](https://raw.githubusercontent.com/juchong/ADIS16209-Arduino-Demo/master/setup_pictures/IMG_5203.JPG)

Pin assignments can be found in the Arduino sketch comments.

### How do I know it's working?

Once you have the sensor connected and have loaded the **ADIS16209_8bit_WithDR** example sketch, use PuTTY to connect to the arduino using the following settings:

![ADIS16209 Example PuTTY Config](https://raw.githubusercontent.com/juchong/ADIS16209-Arduino-Demo/master/setup_pictures/PuTTYConfig.PNG)

If everything is working, you should see a screen like this:

![ADIS16209 Example PuTTY Output](https://raw.githubusercontent.com/juchong/ADIS16209-Arduino-Demo/master/setup_pictures/SampleOutput.PNG)
