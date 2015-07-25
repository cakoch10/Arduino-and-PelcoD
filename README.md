# Arduino-and-PelcoD

Arduino programs from a project that involved implementing the PelcoD protocol on an Arduino Uno in such a way that the Arduino could communicate with an M1-D infrared camera via Rs-485

The file ```M1_D_controller.ino``` utilized a series of push buttons on a breadboard to control the camera.

The file ```keyboard_controller.ino``` maps certain keys on a PS2 keyboard to certain movements of the camera.

The file ```Control_via_xbox.ino``` maps certain serial proxies to commands on the camera. Note that this file should be used in conjunction with ```mapping_xbox_to_keyboard2.pde``` which takes inputs from keyboard and turns them into a serial signal detected by the Arduino. In order to convert the Xbox inputs to keyboard inputs one can use a program such as [JoyToKey](http://joytokey.net/en/).

More details of the setup and design of the project can be found in the ```M1-d-documentation.pdf``` which also explains the other programs. 
