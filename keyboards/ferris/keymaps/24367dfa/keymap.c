#include QMK_KEYBOARD_H

enum ferris_layers {
  _BASE,
  _NUM,
  _FUN,
  _NAV,
  _SYM
};

// setup thumb cluster combos - https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
const uint16_t PROGMEM esc_combo[] = {KC_BSPC, KC_TAB, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_ENT, KC_SPC, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(del_combo, LT(2,KC_DEL)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,   KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H,   RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
    KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,   KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                              LT(3,KC_BSPC),KC_TAB, KC_ENT, LT(1,KC_SPC)
  ),
  [_NUM] = LAYOUT(
    KC_NO,        KC_7,         KC_8,         KC_9,         KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
    KC_NO,        KC_4,         KC_5,         KC_6,         KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
    KC_NO,        KC_1,         KC_2,         KC_3,         KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
                                              KC_0,         KC_NO,  KC_NO,  KC_TRNS
  ),
  [_FUN] = LAYOUT(
    KC_F12,        KC_F7,       KC_F8,        KC_F9,        KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
    KC_F11,        KC_F4,       KC_F5,        KC_F6,        KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
    KC_F10,        KC_F1,       KC_F2,        KC_F3,        KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
                                              KC_0,         KC_NO,  KC_NO,  KC_NO
  ),
  [_NAV] = LAYOUT(
    KC_F12,        KC_F7,       KC_F8,        KC_F9,        KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
    KC_F11,        KC_F4,       KC_F5,        KC_F6,        KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
    KC_F10,        KC_F1,       KC_F2,        KC_F3,        KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
                                              KC_0,         KC_NO,  KC_NO,  KC_NO
  ),
  [_SYM] = LAYOUT(
    KC_F12,        KC_F7,       KC_F8,        KC_F9,        KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
    KC_F11,        KC_F4,       KC_F5,        KC_F6,        KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
    KC_F10,        KC_F1,       KC_F2,        KC_F3,        KC_NO,  KC_NO,  KC_NO,        KC_NO,        KC_NO,        KC_NO,
                                              KC_0,         KC_NO,  KC_NO,  KC_NO
  )
};



// turn off the litaris power LED - https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED
void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}