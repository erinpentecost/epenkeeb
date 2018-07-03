#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

//keycode shorthands
#define KC____  KC_TRNS // three underscores "___" for transparent

//define layer names
#define _COLEMAK 0
#define _LOWER 1
#define _FUNL 2
enum custom_keycodes {
  // normal keys, default layer
  COLEMAK = SAFE_RANGE,
  // lower layer
  LOWER,
  // fn layer
  FUNL,
};



//Tap Dance Declarations
#define KC_CLOSEPANE LCTL(KC_F4)
enum {
  TD_ESC_CLOSETAB = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for ctrl f4
  [TD_ESC_CLOSETAB] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CLOSEPANE)
// Other declarations would go here, separated by commas, if you have them
};
#define KC_CLOSE TD(TD_ESC_CLOSETAB)


#define KC_LEFTPANE LSFT(LCTL(KC_TAB))
#define KC_RIGHTPANE LCTL(KC_TAB)

#define KC_LEFTWORD LCTL(KC_LEFT)
#define KC_RIGHTWORD LCTL(KC_RIGHT)

#define KC_SPCFUN LT(_FUNL,KC_SPC) //space on tap, fn when held
#define KC_ENTFUN LT(_FUNL,KC_ENT) //enter on tap, fn when held
#define KC_TLTT MO(_LOWER)
#define KC_TRTT LM(_LOWER, MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
  CLOSE, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , F  , P  , G  ,                J  , L  , U  , Y  ,SCLN,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LGUI, A  , R  , S  , T  , D  ,                H  , N  , E  , I  , O  ,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  , SPCFUN ,ENTFUN, K  , M  ,COMM, DOT,SLSH,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       TRTT,TLTT,SPCFUN,    ENTFUN,RALT, RCTRL
  //                  `----+----+----'        `----+----+----'
  ),

    [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRAVE,___, ___, ___, ___, ___,               ___, ___, ___, ___, ___, DEL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ___, ___, ___, ___, ___, ___ ,               MINUS,EQUAL,LBRC,RBRC,___,___,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ___, ___, ___, ___ ,___, ___,               ___ , ___, ___, ___, ___, ___,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     ___, ___, ___, ___, ___, ___, ___,       ___,___ , ___, ___, ___, ___, ___,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       ___, ___, ___,          ___, ___, ___
  //                  `----+----+----'        `----+----+----'
  ),

    [_FUNL] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ___ , F1 , F2 , F3 , F4 , F5 ,                 F6,  F7,  F8,  F9, F10,PSCR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ___ ,F11, F12, PGUP, NO, NO ,                  NO,  NO,  UP, NO,  NO, INS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
  ___,LEFTPANE,HOME,PGDN,END,RIGHTPANE,      LEFTWORD,LEFT,DOWN,RGHT,RIGHTWORD,NO,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     ___, ___, ___, ___, ___, ___, ___,       ___,___ , ___, ___, ___, ___, ___,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       ___, ___, ___,          ___, ___, ___
  //                  `----+----+----'        `----+----+----'
  ),
};
