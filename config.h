#ifndef CONFIG_HORUS_H
#define CONFIG_HORUS_H
#pragma once

// #define NO_DEBUG
// #define NO_PRINT

// #define RGB_MATRIX_ENABLE
#define ENABLE_RGB_MATRIX_BREATHING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_BREATHE_MAX 200 // 0-255
#define RGBLIGHT_EFFECT_BREATHE_MIN 20 // 0-255

#define USB_POLLING_INTERVAL_MS 1
#define FORCE_NKRO

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

#define LEADER_OVERRIDE
// Set leader timeout to 320 ms and enable per-key timing
#define LEADER_TIMEOUT 320
#define LEADER_PER_KEY_TIMING

#define DYNAMIC_MACRO_OVERRIDE
#define DYNAMIC_MACRO_SIZE 100
#define DYNAMIC_MACRO_DELAY 5

#define COMBO_TERM 72
#define COMBO_KEY_BUFFER_LENGTH 16
#define COMBO_BUFFER_LENGTH 16
#define COMBO_STRICT_TIMER
#define EXTRA_SHORT_COMBOS

#endif
