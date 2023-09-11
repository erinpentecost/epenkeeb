//#include "iris.h"
//#include "action_layer.h"
//#include "eeconfig.h"

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

//define layer names
#define _COLEMAK 0
#define _COLEMAKMAC 1
#define _LOWER 2
#define _FUNL 4
#define _FUNLMAC 8
enum custom_keycodes {
  // normal keys, default layer
  COLEMAK = SAFE_RANGE,
  // normal keys for mac mode
  // get into mac mode by using LSHIFT+RSHIFT+2 (magic command feature)
  COLEMAKMAC,
  // lower layer
  LOWER,
  // fn layer
  FUNL,
  // fn layer for mac mode
  FUNLMAC,
};




#define KC_LEFTPANE LSFT(LCTL(KC_TAB))
#define KC_RIGHTPANE LCTL(KC_TAB)

#define KC_LEFTWORD LCTL(KC_LEFT)
#define KC_RIGHTWORD LCTL(KC_RIGHT)

#define KC_LEFTWORDMAC LALT(KC_LEFT)
#define KC_RIGHTWORDMAC LALT(KC_RIGHT)

#define KC_SPCFUN LT(_FUNL,KC_SPC) //space on tap, fn when held
#define KC_ENTFUN LT(_FUNL,KC_ENT) //enter on tap, fn when held
#define KC_TLTT MO(_LOWER)
#define KC_TRTT LM(_LOWER, MOD_LSFT)

#define KC_SPCFUNMAC LT(_FUNLMAC,KC_SPC) //space on tap, fn when held for mac mode
#define KC_ENTFUNMAC LT(_FUNLMAC,KC_ENT) //enter on tap, fn when held for mac mode

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
  KC_ESC, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_TAB , KC_Q  , KC_W  , KC_F  , KC_P  , KC_G  ,                KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_LGUI, KC_A  , KC_R  , KC_S  , KC_T  , KC_D  ,                KC_H  , KC_N  , KC_E  , KC_I  , KC_O  ,KC_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  , KC_SPCFUN ,KC_ENTFUN, KC_K  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       KC_TRTT,KC_TLTT,KC_SPCFUN,    KC_ENTFUN,KC_RIGHT_ALT, KC_RIGHT_CTRL
  //                  `----+----+----'        `----+----+----'
  ),

  [_COLEMAKMAC] = LAYOUT(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
  KC_ESC, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_TAB , KC_Q  , KC_W  , KC_F  , KC_P  , KC_G  ,                KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_RIGHT_CTRL, KC_A  , KC_R  , KC_S  , KC_T  , KC_D  ,                KC_H  , KC_N  , KC_E  , KC_I  , KC_O  ,KC_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  , KC_SPCFUN ,KC_ENTFUN, KC_K  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       KC_TRTT,KC_TLTT,KC_SPCFUN,    KC_ENTFUN,KC_RIGHT_ALT, KC_LGUI
  //                  `----+----+----'        `----+----+----'
  ),

    [_LOWER] = LAYOUT(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     KC_GRAVE,_______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, KC_DEL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     _______, _______, _______, _______, _______, _______ ,               KC_MINUS,KC_EQUAL,KC_LBRC,KC_RBRC,_______,_______,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     _______, _______, _______, _______ ,_______, _______,               _______ , _______, _______, _______, _______, _______,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     _______, _______, _______, _______, _______, _______, _______,       _______,_______ , _______, _______, _______, _______, _______,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       _______, _______, _______,          _______, _______, _______
  //                  `----+----+----'        `----+----+----'
  ),

    [_FUNL] = LAYOUT(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     _______ , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                 KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,KC_PSCR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     _______ ,KC_F11, KC_F12, KC_PGUP, KC_NO, KC_NO ,                  KC_NO,  KC_NO,  KC_UP, KC_NO,  KC_NO, KC_INS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     _______,KC_NO,   KC_HOME, KC_PGDN, KC_END,KC_NO,            KC_LEFTWORD,KC_LEFT,KC_DOWN,KC_RGHT,KC_RIGHTWORD,KC_NO,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     _______, _______, _______, _______, _______, _______, _______,       _______,_______ , _______, _______, _______, _______, _______,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       _______, _______, _______,          _______, _______, _______
  //                  `----+----+----'        `----+----+----'
  ),

   [_FUNLMAC] = LAYOUT(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     _______ , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                 KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,KC_PSCR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     _______ ,KC_F11, KC_F12, KC_PGUP, KC_NO, KC_NO ,                  KC_NO,  KC_NO,  KC_UP, KC_NO,  KC_NO, KC_INS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     _______,KC_NO,   KC_HOME, KC_PGDN, KC_END,KC_NO,            KC_LEFTWORDMAC,KC_LEFT,KC_DOWN,KC_RGHT,KC_RIGHTWORDMAC,KC_NO,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     _______, _______, _______, _______, _______, _______, _______,       _______,_______ , _______, _______, _______, _______, _______,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       _______, _______, _______,          _______, _______, _______
  //                  `----+----+----'        `----+----+----'
  )
};
