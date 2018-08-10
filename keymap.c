#include "gh60.h"
#include "action_layer.h"

#define _______ KC_TRNS
#define xxxxxxx KC_NO

// Layers
#define LBASE 0
#define LFN   1
#define LARR  2

// Arrow layer toggle
#define TGARR TG(LARR)

// Esc/FN
#define ESCFN LT(LFN, KC_ESC)

// LWIN/Lock
#define TDLOCK 0
#define KLOCK TD(TDLOCK)

// CTRL + PrintScreen
#define CPSCRN LCTL(KC_PSCREEN)

// CTRL + K (Origami)
#define ORIGAMI LCTL(KC_K)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* 0: qwerty */
	[LBASE] = {
		{ KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC },
		{ KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS },
		{ ESCFN  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, xxxxxxx, KC_ENT  },
		{ KC_LSFT, xxxxxxx, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, xxxxxxx, KC_UP   },
		{ KC_LCTL, KLOCK  , KC_LALT, xxxxxxx, xxxxxxx, KC_SPC , xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, MO(LFN), KC_LEFT, KC_DOWN, KC_RGHT }
	},
	/* 1: fn */
	[LFN] = {
		{ KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL  },
		{ KC_CAPS, _______, KC_UP  , _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_INS  },
		{ _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_HOME, KC_PGUP, _______, _______ },
		{ _______, xxxxxxx, _______, _______, _______, _______, _______, _______, _______, _______, KC_END , KC_PGDN, _______, KC_RSFT },
		{ _______, CPSCRN , _______, xxxxxxx, xxxxxxx, TGARR  , xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, KC_RALT, KC_RGUI, KC_RCTL }
	},
	/* 2: non-arrow overlay */
	[LARR] = {
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, xxxxxxx, _______ },
		{ _______, xxxxxxx, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, xxxxxxx, KC_RSFT },
		{ _______, _______, _______, xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, KC_RALT, KC_RGUI, KC_RCTL }
	}
};

const uint16_t PROGMEM fn_actions[] = {};

qk_tap_dance_action_t tap_dance_actions[] = {
 [TDLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_L))
};

/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
};

void matrix_scan_user(void) {
};
*/