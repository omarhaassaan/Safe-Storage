Using ATmega 16 I have created a program using 2 microcontrollers to control Safe Storage.

One to control the keypad and the LCD to display and take password from user, the other is to control the memory and store it from the first MCU using I2C. Taking into account that the communication between the MCUs is done using UART.

Also drivers for all peripherals used is written and wisely used such as: timers, LCD, keypad, I2C, Motor, UART

