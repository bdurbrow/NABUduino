# NABUduino
 
# What this is:

This is a card that allows you to put an Arduino Nano onto the NABU's expansion bus. It also has ports for a PS/2 mouse and an SD card slot; as well as two prototyping areas (these are setup with traces similar to a solderless breadboard's layout).

# WARNING: PRE-BETA!

This is currently pre-beta. It could have bugs. It might not work for you. It might fry your NABU. It might turn your dog into a geranium. I really don't know. Use at your own risk.

Also note that the firmware for this is currently being written, and all that is in this repository is code for demonstrating the mouse functionality.

# Parts Required:

* An SD card slot module, such as is commonly sold for use with an Arduino. There are a couple of different module styles available, so also check the product listing against the NABUduino PCB layout before ordering.

* An SD card to fit in the module.

* The NABUduino PCB itself.

* DIP ICs:

  - 74hct165; two each
  - 74ahct138; two each
  - 74hc595; two each
  - 74hct32
  - 74hct125
  - 74hct245
  - 74hct04
  - CD4044B

* A 1N4001 or similar diode.

* Decoupling capacitors in the range of 0.1uf to 1uf; ten each.

* Although you could directly solder the ICs to the board, IC sockets are recommended for the above ICs.

* Female header sockets to put the Arduino Nano into.

* Male header pins for the PS/2 and SD card module ports, as well as the NABU expansion interface.

* A 30 pin female-to-female 0.100" "DuPont"-style cable for connecting the NABUduino to the expansion interface on the NABU motherboard.

* A 6 pin female-to-female 0.100" "DuPont"-style cable for connecting the NABUduino to the SD card slot board.

* A 4 pin cable that connects the NABUduino PCB to a 6-pin PS/2 mouse connector.

* Jumpers for the prototyping area power connections, as well as the reset and interrupt configuration pins.

# Usage:

Assemble the NABUduino and connect it to one of the NABU expansion slots. Note that the Z80 demo program included in this repository expects the NABUduino to be in the slot closest to the power supply; however this can be changed in the top of the "NABUduino.c" file. Also note that the version of NABULIB included with this repository is out-of-date; and should not be used for anything other than running the demo. The current version of NABULIB can be downloaded from DJ Sures' repository at https://github.com/DJSures/NABU-LIB

Connect a PS/2 mouse to the NABUduino board.

If you have not already installed them; download and install both the Arduino IDE (from arduino.cc) and the Z88DK toolchain (from z88dk.org).

Using the Arduino IDE, compile and upload the Arduino's firmware that is located in the AVR subdirectory.

Using the Z88DK compiler, compile and upload the demo application to your NABU Internet Adapter's homebrew directory.

Switch the NABU Internet Adapter to homebrew mode; and reset the NABU. The demo application should launch, and you should be able to drag the mouse around the screen.
