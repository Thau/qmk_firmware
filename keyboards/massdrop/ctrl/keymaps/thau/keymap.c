#include QMK_KEYBOARD_H

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

keymap_config_t keymap_config;

enum {
    TD_F9 = 0,
    TD_F10 = 1,
    TD_F11 = 2,
    TD_F12 = 3,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F9] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_MEDIA_PREV_TRACK),
    [TD_F10] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_MEDIA_STOP),
    [TD_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_MEDIA_PLAY_PAUSE),
    [TD_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_MEDIA_NEXT_TRACK)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   TD(TD_F9), TD(TD_F10),  TD(TD_F11),  TD(TD_F12),         KC_PSCR, TO(2), KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,        KC_MINS,     KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,        KC_LBRC,     KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN,     KC_QUOT,     KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,     KC_RSFT,                                  KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT,   MO(1),       KC_APP,      KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    [2] = LAYOUT(
        TO(0),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_KP_7, KC_KP_8, KC_KP_9, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_KP_4, KC_KP_5, KC_KP_6, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_KP_1, KC_KP_2, KC_KP_3, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,                              KC_KP_0, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    */
};

struct color {
    uint16_t r;
    uint16_t g;
    uint16_t b;
};

#define WHITE { 0xFF, 0xFF, 0xFF }
#define RED   { 0xFF, 0x00, 0x00 }
#define BLUE  { 0x00, 0xFF, 0x00 }
#define GREEN { 0x00, 0x00, 0xFF }
#define MEDIA { 0xD9, 0x5B, 0x43 }

const struct color ledmaps[][MATRIX_ROWS * MATRIX_COLS] = {
    [0] = {
        WHITE,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   MEDIA,   MEDIA,  MEDIA,  MEDIA,             WHITE, BLUE,  WHITE, \
        WHITE,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,     WHITE, WHITE, WHITE, \
        WHITE,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,     WHITE, WHITE, WHITE, \
        RED,    WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE, \
        WHITE,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,                            WHITE, \
        WHITE,  WHITE,   WHITE,                     WHITE,                              WHITE,   WHITE,  WHITE,  WHITE,             WHITE, WHITE, WHITE \
    },
    [1] = {
        WHITE,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   MEDIA,   MEDIA,  MEDIA,  MEDIA,             WHITE, BLUE,  WHITE, \
        WHITE,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,     WHITE, WHITE, WHITE, \
        WHITE,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,     WHITE, WHITE, WHITE, \
        RED,    WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE, \
        WHITE,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,                            WHITE, \
        WHITE,  WHITE,   WHITE,                     WHITE,                              WHITE,   WHITE,  WHITE,  WHITE,             WHITE, WHITE, WHITE \
    },
    [2] = {
        GREEN,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   MEDIA,   MEDIA,  MEDIA,  MEDIA,             BLUE,  BLUE,  BLUE, \
        WHITE,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,     BLUE,  BLUE,  BLUE, \
        WHITE,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,     BLUE,  BLUE,  BLUE, \
        RED,    WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE, \
        WHITE,  WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,  WHITE,                            WHITE, \
        WHITE,  WHITE,   WHITE,                     WHITE,                              WHITE,   WHITE,  WHITE,  WHITE,             WHITE, WHITE, WHITE \
    },
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

void rgb_matrix_indicators_user(void)
{
    // Disable the bottom lights
    rgb_matrix_set_color_all(0x00, 0x00, 0x00);

	uint16_t layer_number = biton32(layer_state);

    for(int i = 0; i < sizeof(ledmaps[layer_number]) / sizeof(struct color); i++) {
        rgb_matrix_set_color(i, ledmaps[layer_number][i].r, ledmaps[layer_number][i].g, ledmaps[layer_number][i].b);
    }
}
