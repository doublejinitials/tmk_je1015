/*
Copyright 2017 Jacob Jordan

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/io.h>
#include "stdint.h"
#include "led.h"
#include "action.h"

/* This function both toggles the lock light LED's, and also
 * activates/deactivates a layer when num lock is toggled that
 * changes the numpad from a standard cross nav into a T-nav.
 *
 * The LED's in the Jameco are hardwired to resistors connected to Vss,
 * and the other pins are connected to pins on the Teensy:
 *
 * Caps Lock	PB5
 * Scroll Lock	PB6
 * Num Lock	PD7
 * 
 * The LED's are switched OFF by setting the pin to INPUT mode, therefore
 * disallowing the flow of current, and are switched ON by setting the pin
 * to OUTPUT LOW.
 */
void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // Caps lock is ON, turn on LED
        DDRB |= (1<<5);
        PORTB &= ~(1<<5);
    } else {
        // Caps lock is OFF, turn off LED
        DDRB &= ~(1<<5);
    }
    
    if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
        // Scroll lock is ON, turn on LED
        DDRB |= (1<<6);
        PORTB &= ~(1<<6);
    } else {
        // Scroll lock is OFF, turn off LED
        DDRB &= ~(1<<6);
    }
    
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        // Num lock is ON, turn on LED
        DDRD |= (1<<7);
        PORTD &= ~(1<<7);

        // Deactivate numpad t-nav layer, making it a normal numpad
        layer_off(1);
    } else {
        // Num lock is OFF, turn off LED
        DDRD &= ~(1<<7);

        // Activate numpad t-nav layer, making it a nav cluster
        layer_on(1);
    }
}
