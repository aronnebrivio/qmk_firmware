#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
            KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
            KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, MO(1),        KC_SPC,      MO(2),   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
        ),
        [_LOWER] = LAYOUT_ortho_4x12_1x2uC(
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
            KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
            _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, KC_PGUP, _______,
            KC_PSCR, _______, _______, _______, _______,      _______,     _______, _______, KC_HOME, KC_PGDN, KC_END
        ),
        [_RAISE] = LAYOUT_ortho_4x12_1x2uC(
            KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
            KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
            _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), _______, KC_VOLU, _______,
            _______, _______, _______, _______, _______,      KC_MUTE,     _______,    _______,    KC_MNXT, KC_VOLD, KC_MPLY
        ),
        [_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
            QK_BOOT, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, DB_TOGG,
            _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______,
            _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, _______,  _______, _______, _______,     RGB_TOG,      _______, _______, _______, _______, _______
        )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Change caps lock key to red when caps lock is on
bool rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(50, 255, 0, 0); //capslock key
    }

    return false;
}
