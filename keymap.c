#include "gh60.h"
#include "action_layer.h"

#define _______ KC_TRNS
#define xxxxxxx KC_NO

// Layers
#define LBASE 0
#define LFN   1
#define LARR  2

// Functions
#define FFN  0
#define FARR 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* 0: qwerty */
	[LBASE] = {
		{ KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC },
		{ KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS },
		{ KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, xxxxxxx, KC_ENT  },
		{ KC_LSFT, xxxxxxx, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, xxxxxxx, KC_RSFT },
		{ KC_LCTL, KC_LGUI, KC_LALT, xxxxxxx, xxxxxxx, KC_SPC , xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, F(FFN) , KC_RALT, KC_RGUI, KC_RCTL }
	},
	/* 1: fn */
	[LFN] = {
		{ KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL  },
		{ _______, _______, KC_UP  , _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_INS  },
		{ _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, _______, _______ },
		{ _______, xxxxxxx, _______, _______, _______, _______, _______, _______, _______, _______, KC_END , KC_PGDN, _______, _______ },
		{ _______, _______, _______, xxxxxxx, xxxxxxx, F(FARR), xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______, _______, _______ }
	},
	/* 2: arrows overlay */
	[LARR] = {
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, xxxxxxx, _______ },
		{ _______, xxxxxxx, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, xxxxxxx, KC_UP   },
		{ _______, _______, _______, xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, KC_LEFT, KC_DOWN, KC_RGHT }
	}
};

const uint16_t PROGMEM fn_actions[] = {
	[FFN] = ACTION_LAYER_MOMENTARY(LFN), // Fn overlay
	[FARR] = ACTION_LAYER_TOGGLE(LARR),  // arrow overlay
};

/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
};

void matrix_scan_user(void) {
};
*/