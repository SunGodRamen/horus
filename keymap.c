#include QMK_KEYBOARD_H

#include "g/keymap_combo.h"

enum planck_layers {
    _DVORAK,
    _NAVIGATE,
    _NUMBERS,
    _MOUSE,
    _CONFIGURE,
    _PLOVER,
    _MIDI,
    _MUSIC
};

enum planck_keycodes {
    ENC_BTN = SAFE_RANGE
};

#define NAV_SPC LT(1,KC_SPC)    // NAVIGATE/SPACE BAR
#define MACRO MO(1)             // MACRO RECORD
#define NUM MO(2)               // NUMBERS
#define MOUSE MO(3)             // MOUSE
#define PLVR TO(5)              // PLOVER
#define MIDI TO(6)              // MIDI
#define MUSIC TO(7)             // INSTRUMENT

#define ALT_O LALT_T(KC_O)
#define GUI_E LGUI_T(KC_E)
#define CTL_U LCTL_T(KC_U)
#define LTAB LSFT(LCTL(KC_TAB))
#define NTAB LCTL(KC_TAB)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |      |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | TUNE |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  M1  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |  M2  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MUSIC | MIDI |PLOVER| MOUSE| RSHFT|NAVSPC|NUMBER|      |      |      | MREC |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    _______,  KC_QUOT,  KC_COMM, KC_DOT,  KC_P,  KC_Y,    KC_F,    KC_G,  KC_C,    KC_R,    KC_L,    ENC_BTN,
    _______,  KC_A,     ALT_O,   GUI_E,   CTL_U, KC_I,    KC_D,    KC_H,  KC_T,    KC_N,    KC_S,    DM_PLY1,
    _______,  KC_SCLN,  KC_Q,    KC_J,    KC_K,  KC_X,    KC_B,    KC_M,  KC_W,    KC_V,    KC_Z,    DM_PLY2,
    _______,  MUSIC,    MIDI,    PLVR,    MOUSE, KC_RSFT, NAV_SPC, NUM,   _______, _______, _______, MACRO
),


/* NAVIGATE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | BACK | LTAB | NTAB | FWRD |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   ←  |   ↓  |   ↑  |   →  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | HOME | PGDN | PGUP | END  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIGATE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_WBAK, LTAB,    NTAB,    KC_WFWD, ENC_BTN,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, DM_REC1,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  DM_REC2,
    _______, _______, _______, _______, _______, _______, _______, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, _______
),

/* NUMBER
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |   7  |   8  |   9  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   4  |   5  |   6  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   1  |   2  |   3  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    ENC_BTN,
    _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_4,    KC_5,    KC_6,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | BTN2 | BTN3 | BTN1 |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ENC_BTN,
    _______, KC_BTN2, KC_BTN3, KC_BTN1, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* CONFIGURE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_CONFIGURE] = LAYOUT_planck_grid(
    EE_CLR,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ENC_BTN,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    ENC_BTN,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    TO(0),   XXXXXXX, XXXXXXX, XXXXXXX, KC_C,    KC_V,    KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* MIDI
 * ,-----------------------------------------------------------------------------------.
 * |  C#  |  D#  |      |  F#  |  G#  |  A#  |      |  C#2 |  D#2 |      |      |EncBtn|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   C  |   D  |   E  |   F  |   G  |   A  |   B  |   C2 |   D2 |   E2 |   F2 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TO(0)|      |      |      |OctDwn|Sustain| Mod |OctUp |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MIDI] = LAYOUT_planck_grid(
    MI_Cs,   MI_Ds,    XXXXXXX, MI_Fs,   MI_Gs,   MI_As,   XXXXXXX, MI_Cs2,  MI_Ds2,  XXXXXXX, XXXXXXX, ENC_BTN,
    MI_C,    MI_D,     MI_E,    MI_F,    MI_G,    MI_A,    MI_B,    MI_C2,   MI_D2,   MI_E2,   MI_F2,   XXXXXXX,
    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    TO(0),   XXXXXXX,  XXXXXXX, XXXXXXX, MI_OCTD, MI_SUST, MI_MOD,  MI_OCTU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* MUSIC
 * ,-----------------------------------------------------------------------------------.
 * |  C#4 |  D#4 |      |  F#4 |  G#4 |  A#4 |      |  C#5 |  D#5 |      |  F#5 |  G#5 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  C4  |  D4  |  E4  |  F4  |  G4  |  A4  |  B4  |  C5  |  D5  |  E5  |  F5  |  G5  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  C#3 |  D#3 |      |  F#3 |  G#3 |  A#3 |      |  C#4 |  D#4 |      |  F#4 |  G#4 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  C3  |  D3  |  E3  |  F3  |  G3  |  A3  |  B3  |  C4  |  D4  |  E4  |  F4  |  G4  |
 * `-----------------------------------------------------------------------------------'
 */
[_MUSIC] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ENC_BTN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    TO(0),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};
/* clang-format on */

#ifdef AUDIO_ENABLE

float streets_of_cairo[][2] = {
    {NOTE_A3, 32},
    {NOTE_B3, 32},
    {NOTE_C4, 64},
    {NOTE_B3, 64},
    {NOTE_A3, 64},
    {NOTE_A3, 32},
    {NOTE_B3, 32},
    {NOTE_C4, 32},
    {NOTE_E4, 32},
    {NOTE_B3, 32},
    {NOTE_C4, 32},
    {NOTE_A3, 64},
};

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _MUSIC:
            music_on();
            break;
        default:
            music_off();
            break;
    }
    return update_tri_layer_state(state, _NUMBERS, _MOUSE, _CONFIGURE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENC_BTN:
            if (record->event.pressed) {
                // Handle the custom behavior of ENC_BTN depending on the active layer
                layer_state_t layer = layer_state | default_layer_state;
                uint8_t layer_number = biton32(layer);
                switch (layer_number) {
                    case _DVORAK:
                        // Code to execute if the _DVORAK layer is active
                        break;
                    case _NAVIGATE:
                        // Code to execute if the _NAVIGATE layer is active
                        break;
                    case _NUMBERS:
                        // Code to execute if the _NUMBERS layer is active
                        break;
                    // Add more cases for each of your layers
                }
            }
            return false; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_SPACE)) {
        PLAY_SONG(streets_of_cairo);
    } else if (leader_sequence_two_keys(KC_E, KC_G)) {
        SEND_STRING("AVONS394@gmail.com");
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            // Perform action when the DVORAK layer is active
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case _NAVIGATE:
            // Perform action when the NAVIGATE layer is active
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
            break;
        case _NUMBERS:
            // Perform action when the NUMBERS layer is active
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
            break;
        case _MOUSE:
            // Perform action when the MOUSE layer is active
            if (clockwise) {
                tap_code(KC_MS_WH_DOWN);
            } else {
                tap_code(KC_MS_WH_UP);
            }
            break;
        case _CONFIGURE:
            if (clockwise) {
                rgblight_increase_hue();
            } else {
                rgblight_decrease_hue();
            }
            break;
        // ... add more cases for your other layers
        default:
            // Default case if no other layer matches
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
    }
    return false;
}

