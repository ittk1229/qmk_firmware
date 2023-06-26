#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include <stdio.h>


// レイヤーの定義
enum layers {
  _EUCALYN = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// マクロキーの定義
enum custom_keycodes {
  RAISE = SAFE_RANGE,
  LOWER,
  ESC_MHEN,
  ALT_TAB
};

// 複合キーを8文字までの変数に
#define HOME_A GUI_T(KC_A)
#define HOME_O ALT_T(KC_O)
#define HOME_E SFT_T(KC_E)
#define HOME_I CTL_T(KC_I)
#define HOME_T CTL_T(KC_T)
#define HOME_N SFT_T(KC_N)
#define HOME_S ALT_T(KC_S)
#define HOME_B GUI_T(KC_B)

// レイヤーごとにキーマップを定義
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_EUCALYN] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     ESC_MHEN,    KC_Q,    KC_W, JP_COMM,  JP_DOT, JP_SCLN,                         KC_M,    KC_R,    KC_D,    KC_Y,    KC_P, JP_MINS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,  HOME_A,  HOME_O,  HOME_E,  HOME_I,    KC_U,                         KC_G,  HOME_T,  HOME_N,  HOME_S,  HOME_B, JP_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ALT_TAB,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, JP_SLSH,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT,   LOWER,  KC_SPC,     KC_ENT,   RAISE, KC_BSPC\
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P0,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,                        KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   LOWER,   KC_NO,      KC_NO,   RAISE,   KC_NO\
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       JP_GRV, JP_TILD,   KC_NO,   JP_LT,   JP_GT, JP_COLN,                        KC_NO, JP_LPRN, JP_RPRN,   KC_NO,   KC_NO, JP_UNDS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, JP_AMPR,   JP_AT, JP_PLUS,  JP_EQL,   KC_NO,                      JP_CIRC, JP_LCBR, JP_RCBR,  JP_DLR, JP_EXLM, JP_DQUO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, JP_PIPE, JP_HASH, JP_ASTR, JP_PERC,   KC_NO,                        KC_NO, JP_LBRC, JP_RBRC, JP_BSLS, JP_QUES,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   LOWER,   KC_NO,      KC_NO,   RAISE,   KC_NO\
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,  KC_F11,  KC_F12,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   LOWER,   KC_NO,      KC_NO,   RAISE,   KC_NO\
                                      //`--------------------------'  `--------------------------'
  ),
};


// レイヤーごとにLEDの光り方を定義
#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM eucalyn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 6, HSV_WHITE},
  {6, 21, HSV_CYAN},
  {27, 6, HSV_WHITE},
  {33, 21, HSV_CYAN}
);

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 6, HSV_BLUE},
  {6, 21, HSV_CYAN},
  {27, 6, HSV_BLUE},
  {33, 21, HSV_CYAN}
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 6, HSV_RED},
  {6, 21, HSV_CYAN},
  {27, 6, HSV_RED},
  {33, 21, HSV_CYAN}
);

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 6, HSV_PURPLE},
  {6, 21, HSV_CYAN},
  {27, 6, HSV_PURPLE},
  {33, 21, HSV_CYAN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  eucalyn_layer,
  lower_layer,
  raise_layer,
  adjust_layer
);

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _EUCALYN));
  rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
  return state;
}
#endif //RGBLIGHT_ENABLE


// lower/raise の ime 切り替えに利用
static bool lower_pressed = false;
static bool raise_pressed = false;


// ALT_TAB
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_user(void) {
  if (is_alt_tab_active && timer_elapsed(alt_tab_timer) > 1000) {
    unregister_code(KC_LALT);
    is_alt_tab_active = false;
  }
}


// ディスプレイに表示するキーカウント
#ifdef OLED_ENABLE
  static uint16_t type_count = 0;
#endif


// マクロキー
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef OLED_ENABLE
    if (record->event.pressed) {
      type_count++;
    }
  #endif

  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (lower_pressed) {
          tap_code(KC_MHEN);
          tap_code(KC_LANG2);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (raise_pressed) {
          tap_code(KC_HENK);
          tap_code(KC_LANG1);
        }
        raise_pressed = false;
      }
      return false;
      break;
    case ESC_MHEN:
      if (record->event.pressed){
        tap_code(KC_ESC);
        tap_code(KC_MHEN);
        tap_code(KC_LANG2);
      }
      return false;
      break;
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;
      break;
    default:  // case: defaultレイヤーのことではなく、上記以外の意味 マクロキーでない他のすべてのキー
      if (record->event.pressed) {
        lower_pressed = false;
        raise_pressed = false;
      }
      break;
  }
  return true;
};


// ディスプレイの表示
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }

  return rotation;
}

void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer: "), false);

  switch (get_highest_layer(layer_state)) {
    case _EUCALYN:
      oled_write_ln_P(PSTR("Eucalyn"), false);
      break;
    case _LOWER:
      oled_write_ln_P(PSTR("Lower"), false);
      break;
    case _RAISE:
      oled_write_ln_P(PSTR("Raise"), false);
      break;
    case _ADJUST:
      oled_write_ln_P(PSTR("Adjust"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undefined"), false);
      break;
  }
}

void oled_render_type_count(void) {
  oled_write_P(PSTR("Count: "), false);
  char count_str[24];
  snprintf(count_str, sizeof(count_str), "%d", type_count);
  oled_write_ln(count_str, false);
}

void oled_render_host_led_state(void) {
  const led_t led_state = host_keyboard_led_state();
  // oled_write_P(PSTR("NL:"), false);
  // oled_write_P(led_state.num_lock ? PSTR("on") : PSTR("- "), false);
  oled_write_P(PSTR("CL:"), false);
  oled_write_P(led_state.caps_lock ? PSTR("on") : PSTR("- "), false);
  // oled_write_P(PSTR(" SL:"), false);
  // oled_write_ln_P(led_state.scroll_lock ? PSTR("on") : PSTR("-"), false);
}

void oled_render_logo(void) {
  static const char PROGMEM kasys_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0,
    0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x3f, 0x3f, 0x0f, 0x1f, 0x1f, 0x87, 0xcf, 0xcf,
    0xc7, 0xcf, 0xcf, 0x87, 0x1f, 0x1f, 0x0f, 0x3f, 0x3f, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xfc, 0xfc, 0x00, 0x00, 0xc0, 0xc0, 0x30, 0x30, 0x0c, 0x0c, 0x00, 0x00, 0xc0, 0xc0, 0x30, 0x30,
    0x0c, 0x0c, 0x30, 0x30, 0xc0, 0xc0, 0x00, 0x00, 0xf0, 0xf0, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
    0x30, 0x30, 0x00, 0x00, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x00, 0x00,
    0xf0, 0xf0, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0xff, 0xc0, 0x80, 0x00, 0x1f, 0x3f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x3f, 0x1f, 0x00, 0x80, 0xc0, 0xff, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xff, 0xff, 0x03, 0x03, 0x0c, 0x0c, 0x30, 0x30, 0xc0, 0xc0, 0x00, 0x00, 0xff, 0xff, 0x0c, 0x0c,
    0x0c, 0x0c, 0x0c, 0x0c, 0xff, 0xff, 0x00, 0x00, 0x30, 0x30, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0x3c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0xfc, 0xfc, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x30, 0x30, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x3c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0e, 0x0e, 0x0e,
    0x0e, 0x0e, 0x0e, 0x0e, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(kasys_logo, sizeof(kasys_logo));
  oled_set_cursor(0, 0);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_layer_state();
    oled_render_host_led_state();
    oled_write_P(PSTR(", "), false);
    oled_render_type_count();
    oled_write_P(PSTR("\n@ittk1229"), false);
  } else {
    oled_render_logo();
  }
  return false;
}
#endif // OLED_ENABLE
