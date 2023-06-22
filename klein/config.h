// Copyright 2022 ssh (@snsten)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define MATRIX_ROWS 8 // Rows are doubled-up.
#define MATRIX_COLS 5

#define MASTER_RIGHT
#define SOFT_SERIAL_PIN D2

#define AUDIO_PIN B5

#ifdef POINTING_DEVICE_ENABLE
    #define POINTING_DEVICE_ROTATION_90
    #define CIRQUE_PINNACLE_DIAMETER_MM 35

    #define CIRQUE_PINNACLE_TAP_ENABLE
    // #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
    // #define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
    // #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#endif

#ifdef OLED_ENABLE
    #define OLED_DISPLAY_128X64
    #define SPLIT_OLED_ENABLE
#endif

#ifdef AUDIO_ENABLE
    #define NO_MUSIC_MODE
#endif

#define TAPPING_TERM 170

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// ┌─────────────────────────────────────────────────┐
// │ e n c o d e r s                                 │
// └─────────────────────────────────────────────────┘

// #define ENCODERS_PAD_A { F4 } //PIN A3
// #define ENCODERS_PAD_B { F5 } //PIN A2
#define ENCODERS_PAD_A       { D1 }
#define ENCODERS_PAD_B       { D0 }
#define ENCODERS_PAD_A_RIGHT { D0 }
#define ENCODERS_PAD_B_RIGHT { D1 }
#define ENCODER_RESOLUTION 2
