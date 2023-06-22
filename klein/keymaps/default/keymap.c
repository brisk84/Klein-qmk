#include QMK_KEYBOARD_H

#include "features/achordion.h"

void matrix_scan_user(void) {
  achordion_task();
}

// qmk compile -kb klein -km default
// qmk flash -kb klein -km default

enum klein_keymap_layers {
    L_COLEMAK = 0,
    L_QWERTY,
    L_NAV,
    L_NUM,
    L_FUN,
    L_SYM,
    L_MEDIA,
    L_MOUSE,
};

enum custom_keycodes {
    QMK_ENG = SAFE_RANGE,
    QMK_RUS,
    QMK_SWTCH,
    LINUX,
    UNDO,
    CUT,
    COPY,
    PASTE,
    SALL,
    RELOAD,
    SAVE,
    NEWTAB,
    QUIT,
    CLOSE,
    FIND,
    PUSH,
    COMM,
    QMK_DOT,
    QMK_COMM,
    QMK_COLN,
    QMK_SCLN,
    // REDO,
};
//   // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
//          QUIT,   CLOSE,   FIND,   PUSH,   LINUX,    DF(L_COLEMAK),   KC_NO,    KC_NO,   KC_NO,   QK_BOOT,
//   // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
//          SALL, RELOAD, SAVE,  NEWTAB,      KC_NO,    DF(L_QWERTY),   KC_MPRV,  KC_VOLD, KC_VOLU, KC_MNXT,
//   // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
//         UNDO,   CUT,   COPY,   KC_NO,       PASTE,    QMK_ENG,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
//   // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
//                       KC_NO, KC_NO, KC_NO, KC_MUTE,    KC_MUTE, KC_MSTP, KC_MPLY,  KC_M

// uint8_t mod_state;
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     static uint16_t my_hash_timer;
//     static bool isLinux = false;
//     mod_state = get_mods();
//     switch (keycode) {

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (layer_state_is(L_COLEMAK)) {
    //     if (!process_achordion(keycode, record)) { return false; }
    // }

    static bool isLinux = false;
    switch (keycode) {
    case QMK_ENG:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_SPC);

            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_SPC);

            // set_single_persistent_default_layer(L_COLEMAK);
            // layer_off(L_QWERTY);
            // DF(L_COLEMAK)
            layer_clear();
            layer_on(L_COLEMAK);
            layer_on(L_NAV);


            // tap_code(<kc>);
            // tap_code(<kc>);
            // tap_code(<kc>);
            // tap_code(<kc>);

            // SS_UP();
            // SEND_STRING("QMK is the best thing ever!");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case QMK_RUS:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_SPC);

            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_SPC);

            // set_single_persistent_default_layer(L_QWERTY);
            // layer_off(L_COLEMAK);
            // DF(L_QWERTY)
            layer_clear();
            layer_on(L_QWERTY);
            layer_on(L_NAV);

            // tap_code(<kc>);
            // tap_code(<kc>);
            // tap_code(<kc>);
            // tap_code(<kc>);

            // SS_UP();
            // SEND_STRING("QMK is the best thing ever!");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case QMK_SWTCH:
        if(layer_state_is(L_QWERTY)) {
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_SPC);

                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                unregister_code(KC_SPC);

                layer_clear();
                layer_on(L_COLEMAK);
                layer_on(L_NAV);
            } else {
                // when keycode QMKBEST is released
            }
            break;
        } else {
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_SPC);

                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
                unregister_code(KC_SPC);

                layer_clear();
                layer_on(L_QWERTY);
                layer_on(L_NAV);
            } else {
                // when keycode QMKBEST is released
            }
            break;
        }
        case LINUX:
            if (record->event.pressed) {
                isLinux = !isLinux;
            }
            return false;
        case COPY:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_C));
                } else {
                    tap_code16(LGUI(KC_C));
                }
                return false;
            }
        case PASTE:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_V));
                } else {
                    tap_code16(LGUI(KC_V));
                }
            return false;
            }
        case CUT:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_X));
                } else {
                    tap_code16(LGUI(KC_X));
                }
                return false;
            }
        case UNDO:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_Z));
                } else {
                    tap_code16(LGUI(KC_Z));
                }
                return false;
            }
        // case REDO:
        //     if (record->event.pressed) {
        //         if (isLinux) {
        //             tap_code16(LCTL(KC_Y));
        //         } else {
        //             tap_code16(LSG(KC_Z));
        //         }
        //         return false;
        //     }
        case SALL:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_A));
                } else {
                    tap_code16(LGUI(KC_A));
                }
                return false;
            }
        case RELOAD:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_R));
                } else {
                    tap_code16(LGUI(KC_R));
                }
                return false;
            }
        case SAVE:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_S));
                } else {
                    tap_code16(LGUI(KC_S));
                }
                return false;
            }
        case NEWTAB:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_T));
                } else {
                    tap_code16(LGUI(KC_T));
                }
                return false;
            }
        case QUIT:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_Q));
                } else {
                    tap_code16(LGUI(KC_Q));
                }
                return false;
            }
        case CLOSE:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_W));
                } else {
                    tap_code16(LGUI(KC_W));
                }
                return false;
            }
        case FIND:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_F));
                } else {
                    tap_code16(LGUI(KC_F));
                }
                return false;
            }
        case PUSH:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_P));
                } else {
                    tap_code16(LGUI(KC_P));
                }
                return false;
            }
        case COMM:
            if (record->event.pressed) {
                if (isLinux) {
                    tap_code16(LCTL(KC_SLSH));
                } else {
                    tap_code16(LGUI(KC_SLSH));
                }
                return false;
            }
        case QMK_COMM:
            if (record->event.pressed) {
                if(layer_state_is(L_QWERTY)) {
                    tap_code16(KC_CIRC);
                } else {
                    tap_code16(KC_COMM);
                }
                return false;
            }
        case QMK_DOT:
            if (record->event.pressed) {
                if(layer_state_is(L_QWERTY)) {
                    tap_code16(KC_AMPR);
                } else {
                    tap_code16(KC_DOT);
                }
                return false;
            }
        case QMK_COLN:
            if (record->event.pressed) {
                if(layer_state_is(L_QWERTY)) {
                    tap_code16(LSFT(KC_5));
                } else {
                    tap_code16(KC_COLN);
                }
                return false;
            }
        case QMK_SCLN:
            if (record->event.pressed) {
                if(layer_state_is(L_QWERTY)) {
                    tap_code16(LSFT(KC_8));
                } else {
                    tap_code16(KC_SCLN);
                }
                return false;
            }
    }
    return true;
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//     case _RAISE:
//         rgblight_setrgb (0x00,  0x00, 0xFF);
//         break;
//     case _LOWER:
//         rgblight_setrgb (0xFF,  0x00, 0x00);
//         break;
//     case _PLOVER:
//         rgblight_setrgb (0x00,  0xFF, 0x00);
//         break;
//     case _ADJUST:
//         rgblight_setrgb (0x7A,  0x00, 0xFF);
//         break;
//     default: //  for any other layers, or the default layer
//         rgblight_setrgb (0x00,  0xFF, 0xFF);
//         break;
//     }
//   return state;
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐      [4]   [5]    ┌───┐
      *           │ 1 ├───┐           ┌───┤ 8 │
      *           └───┤ 2 ├───┐   ┌───┤ 7 ├───┘
      *               └───┤ 3 │   │ 6 ├───┘
      *                   └───┘   └───┘
      */
  [L_COLEMAK] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────────────────────╮                      ╭────────────────────────────────────────────────────────────────╮
      KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                        KC_J, KC_L,         KC_U,         KC_Y,         KC_QUOT,
  // ├─────────────────────────────────────────────────────────────┤                      ├────────────────────────────────────────────────────────────────┤
      LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,                        KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),
  // ├─────────────────────────────────────────────────────────────┤                      ├────────────────────────────────────────────────────────────────┤
      KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,                        KC_K, KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,
  // ╰─────────────────────────────────────────────────────────────╯                      ╰────────────────────────────────────────────────────────────────╯
      LT(L_MOUSE, KC_ESC), LT(L_NAV, KC_SPC), LT(L_MEDIA, KC_TAB), QK_BOOT,                QK_BOOT, LT(L_SYM, KC_ENT), LT(L_NUM, KC_BSPC), LT(L_FUN, KC_DEL)
  // ╰───────────────────────────────────────────────────────────────────╯              ╰─────────────────────────────────────────────────────────────────╯
  ),

  [L_QWERTY] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────────────────────╮                      ╭────────────────────────────────────────────────────────────────╮
      KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                        KC_Y, KC_U,         KC_I,         KC_O,         KC_P,
  // ├─────────────────────────────────────────────────────────────┤                      ├────────────────────────────────────────────────────────────────┤
      LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                        KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
  // ├─────────────────────────────────────────────────────────────┤                      ├────────────────────────────────────────────────────────────────┤
      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                        KC_N, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
  // ╰─────────────────────────────────────────────────────────────╯                      ╰────────────────────────────────────────────────────────────────╯
      LT(L_NUM, KC_ESC), LT(L_NAV, KC_SPC), LT(L_MEDIA, KC_TAB), QK_BOOT,                QK_BOOT, LT(L_SYM, KC_ENT), LT(L_NUM, KC_BSPC), LT(L_FUN, KC_DEL)
  // ╰───────────────────────────────────────────────────────────────────╯              ╰─────────────────────────────────────────────────────────────────╯
  ),

    [L_NAV] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_NO,   KC_HOME, KC_UP,   KC_END,   QMK_SWTCH,    QMK_ENG, KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,    QMK_RUS, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_NO,   KC_PGUP,   KC_ENT,   KC_PGDN,  KC_DEL,    KC_CAPS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                      KC_NO, KC_NO, KC_NO, QK_BOOT,    QK_BOOT, KC_ENT, KC_BSPC, KC_DEL
  //                 ╰─────────────────────────────╯ ╰────────────────────────────────╯
  ),

   [L_NUM] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_LBRC, KC_GRV, KC_LPRN, KC_RPRN,  KC_RBRC,      KC_NO,   KC_7, KC_8, KC_9,   KC_0,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_QUOT,   KC_EXLM, QMK_COLN, KC_EQL, KC_PLUS,  KC_NO,   KC_4, KC_5, KC_6,   QMK_COMM,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_UNDS,  KC_LCBR, QMK_SCLN, KC_RCBR, KC_MINS,      KC_NO,   KC_1, KC_2, KC_3, QMK_DOT,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                   KC_DOT, KC_SPC, KC_MINS, QK_BOOT,    QK_BOOT, KC_ENT, KC_BSPC, KC_DEL
  //              ╰────────────────────────────────╯ ╰────────────────────────────────╯
  ),

   [L_FUN] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_F12, KC_F7,   KC_F8,  KC_F9, KC_PSCR,      QK_BOOT,   KC_F7,   KC_F8,  KC_F9,  KC_F10,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F11, KC_F4,   KC_F5,  KC_F6, KC_SYRQ,      KC_NO,   KC_F4,   KC_F5,  KC_F6, KC_LSFT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F10,  KC_F1,  KC_F2,  KC_F3, KC_PAUS,      KC_NO,   KC_F1,  KC_F2,  KC_F3,   KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                   KC_ESC, KC_SPC, KC_TAB, QK_BOOT,    QK_BOOT, KC_NO,   KC_NO,   KC_NO
  //              ╰────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

     [L_SYM] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_LCBR, KC_TILD,  KC_LPRN, KC_RPRN, KC_RCBR,    KC_NO,   KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_DQT,  KC_PIPE, KC_SCLN, KC_NO, KC_PLUS,        KC_NO,   KC_DLR, KC_PERC, KC_CIRC, KC_COMM,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_NO,  KC_NO, KC_NO, KC_NO,  KC_UNDS,         KC_NO,   KC_EXLM, KC_AT, KC_HASH,   KC_BSLS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                   KC_ESC, KC_RPRN, KC_UNDS, QK_BOOT,    QK_BOOT, KC_NO,   KC_NO,   KC_NO
  //              ╰────────────────────────────────╯ ╰──────────────────────────────────╯
  ),

    [L_MEDIA] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         QUIT,   CLOSE,   FIND,   PUSH,   LINUX,    DF(L_COLEMAK),   KC_NO,    KC_NO,   KC_NO,   QK_BOOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         SALL, RELOAD, SAVE,  NEWTAB,      KC_NO,    DF(L_QWERTY),   KC_MPRV,  KC_VOLD, KC_VOLU, KC_MNXT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        UNDO,   CUT,   COPY,   KC_NO,       PASTE,    QMK_ENG,   KC_NO,   KC_NO,   KC_NO,   COMM,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                      KC_NO, KC_NO, KC_NO, KC_MUTE,    KC_MUTE, KC_MSTP, KC_MPLY,  KC_M
  //                 ╰─────────────────────────────╯ ╰─────────────────────────────────╯
  ),

    [L_MOUSE] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_NO,  KC_BTN1,   KC_MS_U,  KC_BTN2, KC_WH_U,    DF(L_COLEMAK),   KC_NO,    KC_NO,   KC_NO,   QK_BOOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_NO,  KC_MS_L, KC_MS_D, KC_MS_R,   KC_WH_D,    DF(L_QWERTY),   KC_MPRV,  KC_VOLD, KC_VOLU, KC_MNXT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,    QMK_ENG,   KC_ACL0,   KC_ACL1,   KC_ACL2,   COMM,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                      KC_NO, KC_NO, KC_NO, KC_MUTE,    KC_MUTE, KC_MSTP, KC_MPLY,  KC_M
  //                 ╰─────────────────────────────╯ ╰─────────────────────────────────╯
  ),

};

// DF(L_QWERTY)
// DF(L_COLEMAK)

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ E N C O D E R                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef ENCODER_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r  L                                          │
// └───────────────────────────────────────────────────────────┘

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }

// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r  R                                          │
// └───────────────────────────────────────────────────────────┘

    } else if (index == 1) {
      if(IS_LAYER_ON(L_NAV)){
          if (clockwise) {
              tap_code(KC_VOLU);
          } else {
              tap_code(KC_VOLD);
          }
      }else {
            if (clockwise) {
              tap_code(KC_PGDN);
          } else {
              tap_code(KC_PGUP);
          }
      }
    }
    return true;
}

#endif // ENCODER_ENABLE
