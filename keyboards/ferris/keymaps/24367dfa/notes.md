## combos

https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md

config.h
```
#define COMBO_COUNT 2
```
keymap.c
```
const uint16_t PROGMEM esc_combo[] = {KC_BSPC, KC_TAB, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_ENT, KC_SPC, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(del_combo, LT(2,KC_DEL)),
};
```

## mod tab homerow mods

https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md

```
MT(MOD_LGUI, KC_A), 
MT(MOD_LALT, KC_S), 
MT(MOD_LCTL, KC_D), 
MT(MOD_LSFT, KC_F),
MT(MOD_RSFT, KC_J),
MT(MOD_RCTL, KC_K),
MT(MOD_RALT, KC_L), 
MT(MOD_RGUI, KC_SEMICOLON), 
```

## layers

```
# base layer 0
# num layer 1
LT(1,KC_SPC)
# fun layer 2
LT(2,KC_SPC|KC_ENT)
# nav layer 3
LT(3, KC_BSPC)
```

## references

https://github.com/mattdibi/qmk_firmware/commit/4d48befa692a0dd53ec4d13123f87ff3efe0a4cd

## Flashing

```bash
qmk flash -kb ferris/sweep -km manna-harbour_miryoku -e CONVERT_TO=elite_pi -bl uf2-split-left -j 20
qmk flash -kb ferris/sweep -km manna-harbour_miryoku -e CONVERT_TO=elite_pi -bl uf2-split-right -j 20
```