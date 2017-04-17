#TMK Configuration for Jameco JE1015

These are the [TMK](https://github.com/tmk/tmk_keyboard) configuration files, schematics, and general notes for a vintatge 1986 keyboard that has been reverse engineered and converted to USB using a Teensy 2.0 controller. I'm sharing them here in the hopes that they will be helpful for others attempting to convert vintage keyboards.

## Compiling

Ideally, you should familiarize yourself with the basics of how TMK works. It is an extremely powerful and extendable keyboard firmware.

Before you can compile, you must have the [TMK firmware repository](https://github.com/tmk/tmk_keyboard) cloned in the same directory you cloned this repository (i.e. 'tmk\_keyboard' and 'tmk\_je1015' should both be in the same folder). If you would prefer a different directory structure, you can edit the following line in the Makefile

    # Directory common source files exist
    TMK_DIR = ../tmk_keyboard/tmk_core

to point to the 'tmk\_keyboard/tmk\_core' directory (relative to where the Makefile is).

You also need the avr-gcc tools installed. On Ubuntu, those would be the following packages

    gcc-avr binutils-avr gdb-avr avr-libc avrdude

After that's all done, you should just be able to  make the project, and copy the 'jameco\_je1015.hex' to your Teensy.
