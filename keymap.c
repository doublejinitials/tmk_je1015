#include <stdint.h>
#include <stdbool.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default 
     *
     * Several alterations have been made to make the layout more useable on a modern computer:
     * - CapsLock is now an FN key (CapsLock can still be used by tapping the key, instead of holding it and pressing another key)
     * - Grave/Tilde is now a Super key
     * - SysReq is now a Numpad Divide key (SysReq can be accessed using Alt+PrintScreen) 
     * - Backspace and Pipe have been swapped to make backspace more reachable, and I've physically swapped the keycaps on the board as well
     */
    {
    { KC_SCROLLLOCK,    KC_KP_9,        KC_KP_MINUS,    KC_KP_6,        KC_KP_3,        KC_KP_PLUS,     KC_KP_SLASH,    KC_KP_DOT   },
    { KC_NUMLOCK,       KC_KP_7,        KC_KP_8,        KC_KP_4,        KC_KP_2,        KC_KP_5,        KC_KP_1,        KC_KP_0     },
    { KC_EQUAL,         KC_RBRACKET,    KC_BSLASH,      KC_SPACE,       KC_ENTER,       KC_RSHIFT,      KC_LGUI,        KC_KP_ASTERISK  },
    { KC_0,             KC_P,           KC_MINUS,       KC_LBRACKET,    KC_QUOTE,       KC_SLASH,       KC_SCOLON,      KC_BSPACE   },
    { KC_8,             KC_I,           KC_9,           KC_O,           KC_L,           KC_COMMA,       KC_K,           KC_DOT      },
    { KC_6,             KC_Y,           KC_7,           KC_U,           KC_J,           KC_N,           KC_H,           KC_M        },
    { KC_4,             KC_R,           KC_5,           KC_T,           KC_G,           KC_V,           KC_F,           KC_B        },
    { KC_F9,            KC_NO,          KC_NO,          KC_NO,          KC_F10,         KC_FN0,         KC_LALT,        KC_NO       },
    { KC_ESC,           KC_LCTL,        KC_1,           KC_Q,           KC_A,           KC_LSHIFT,      KC_TAB,         KC_Z        },
    { KC_F1,            KC_F3,          KC_F2,          KC_F4,          KC_F8,          KC_F6,          KC_F5,          KC_F7       },
    { KC_2,             KC_W,           KC_3,           KC_E,           KC_D,           KC_X,           KC_S,           KC_C        },
    },
    /* Layer 1: Alternate numpad T-nav layout when numlock is off
     *
     * This is a layer that converts the numpad into a more-useable T-nav, and is toggled from led.c when a request is made
     * to activate/deactivate numlock. The T-nav is on 8456, and the other nav buttons are left stock.
     *
     * This also has the function of toggling the dual Asterisk/PrintScreen key 
     */
    {
    { KC_TRNS,          KC_PGUP,        KC_NO,          KC_RIGHT,       KC_PGDN,        KC_NO,          KC_NO,          KC_DEL      },
    { KC_TRNS,          KC_HOME,        KC_UP,          KC_LEFT,        KC_NO,          KC_DOWN,        KC_END,         KC_INS      },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PSCREEN  },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    },
    /* Layer 2: FN (Caps Lock is FN key)
     * - Nav cluster on WASD
     * - Volume controls on M < >
     * - F1/F2 are F11/F12
     * - Backspace is delete
     * - Numpad 1, 2, 3 are previous track, play/pause, next track
     * - Numpad 4, 5, 6 are AL keys
     * - Numpad 7, 8, 8 are AC keys
     */
    {
    { KC_TRNS,          KC_WFWD,        KC_TRNS,        KC_MYCM,        KC_MNXT,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_TRNS,          KC_WBAK,        KC_WSCH,        KC_CALC,        KC_MPLY,        KC_MAIL,        KC_MPRV,        KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_DEL,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_GRAVE,       KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_VOLD,        KC_TRNS,        KC_VOLU     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MUTE     },
    { KC_TRNS,          KC_PGUP,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PGDOWN,      KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_HOME,        KC_LEFT,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_F11,           KC_TRNS,        KC_F12,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS     },
    { KC_TRNS,          KC_UP,          KC_TRNS,        KC_END,         KC_RIGHT,       KC_TRNS,        KC_DOWN,        KC_TRNS     },
    },
};

const action_t PROGMEM fn_actions[] = {
    /* FN0 will activate layer 2 when held down */
    [0] = ACTION_LAYER_TAP_KEY(2, KC_CAPSLOCK),
};
