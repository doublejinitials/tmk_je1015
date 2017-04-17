/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output low
        DDRB |= (1<<5);
        PORTB &= ~(1<<5);
    } else {
        // Hi-Z
        DDRB &= ~(1<<5);
        PORTB &= ~(1<<5);
    }
    
    if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
        // output low
        DDRB |= (1<<6);
        PORTB &= ~(1<<6);
    } else {
        // Hi-Z
        DDRB &= ~(1<<6);
        PORTB &= ~(1<<6);
    }
    
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        // output low
        DDRD |= (1<<7);
        PORTD &= ~(1<<7);
        // Deactivate numpad t-nav layer
        layer_off(1);
    } else {
        // Hi-Z
        DDRD &= ~(1<<7);
        PORTD &= ~(1<<7);
        // Activate numpad t-nav layer
        layer_on(1);
    }
}
