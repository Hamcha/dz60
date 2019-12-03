#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define xxxxxxx KC_NO

// Layers
#define LBASE 0
#define LFN 1
#define LARR 2

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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* 0: qwerty */
	[LBASE] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , xxxxxxx, KC_BSPC,
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
		ESCFN  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT,
		KC_LSFT, xxxxxxx, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_UP  , KC_RSFT,
		KC_LCTL, KLOCK  , KC_LALT,                            KC_SPC , KC_SPC , KC_SPC , MO(LFN), KC_LEFT, xxxxxxx, KC_DOWN, KC_RGHT
	),
	/* 1: fn */
	[LFN] = LAYOUT(
		KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_DEL,
		KC_CAPS, _______, KC_UP  , _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_INS ,
		_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_HOME, KC_PGUP,          RESET  ,
		_______, xxxxxxx, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_END , KC_PGDN, _______, KC_RSFT,
		_______, CPSCRN , _______,                            TGARR  , TGARR  , TGARR  , _______, KC_RALT, xxxxxxx, KC_RGUI, KC_RCTL
	),
	/* 2: non-arrow overlay */
	[LARR] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, xxxxxxx,          _______,
		_______, xxxxxxx, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, xxxxxxx, KC_RSFT,
		_______, _______, _______,                            _______, _______, _______, xxxxxxx, KC_RALT, xxxxxxx, KC_RGUI, KC_RCTL
	)
};
// clang-format on

const uint16_t PROGMEM fn_actions[] = {};

qk_tap_dance_action_t tap_dance_actions[] = {[TDLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_L))};

enum { SNIP_FOR, SNIP_IF, SNIP_LOG, SNIP_COM, SNIP_CON, SHCUT_CODE, SHCUT_TERM, SHCUT_FIREFOX, SHCUT_CHROME, SHCUT_TELEGRAM, SHCUT_RIPCORD, SHCUT_DFU, SHCUT_NEWTAB };

const uint16_t PROGMEM snip_for_combo[] = {KC_F, KC_O, KC_R, COMBO_END};
const uint16_t PROGMEM snip_if_combo[]  = {KC_I, KC_F, KC_E, COMBO_END};
const uint16_t PROGMEM snip_log_combo[] = {KC_L, KC_O, KC_G, COMBO_END};
const uint16_t PROGMEM snip_com_combo[] = {KC_C, KC_O, KC_M, COMBO_END};
const uint16_t PROGMEM snip_con_combo[] = {KC_C, KC_O, KC_N, COMBO_END};

const uint16_t PROGMEM shcut_code_combo[]     = {KC_O, KC_D, KC_E, COMBO_END};
const uint16_t PROGMEM shcut_term_combo[]     = {KC_T, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM shcut_firefox_combo[]  = {KC_F, KC_I, KC_R, COMBO_END};
const uint16_t PROGMEM shcut_chrome_combo[]   = {KC_B, KC_R, KC_O, COMBO_END};
const uint16_t PROGMEM shcut_telegram_combo[] = {KC_T, KC_E, KC_G, COMBO_END};
const uint16_t PROGMEM shcut_ripcord_combo[]  = {KC_R, KC_I, KC_P, COMBO_END};
const uint16_t PROGMEM shcut_dfu_combo[]      = {KC_D, KC_F, KC_U, COMBO_END};
const uint16_t PROGMEM shcut_newtab_combo[]   = {KC_T, KC_N, KC_B, COMBO_END};

// clang-format off
combo_t key_combos[COMBO_COUNT] = {
	[SNIP_FOR] = COMBO_ACTION(snip_for_combo),
	[SNIP_IF] = COMBO_ACTION(snip_if_combo),
	[SNIP_LOG] = COMBO_ACTION(snip_log_combo),
    [SNIP_COM] = COMBO_ACTION(snip_com_combo),
    [SNIP_CON] = COMBO_ACTION(snip_con_combo),
	[SHCUT_CODE] = COMBO_ACTION(shcut_code_combo),
	[SHCUT_TERM] = COMBO_ACTION(shcut_term_combo),
	[SHCUT_FIREFOX] = COMBO_ACTION(shcut_firefox_combo),
	[SHCUT_CHROME] = COMBO_ACTION(shcut_chrome_combo),
	[SHCUT_TELEGRAM] = COMBO_ACTION(shcut_telegram_combo),
	[SHCUT_RIPCORD] = COMBO_ACTION(shcut_ripcord_combo),
    [SHCUT_DFU] = COMBO_ACTION(shcut_dfu_combo),
    [SHCUT_NEWTAB] = COMBO_ACTION(shcut_newtab_combo)
};
// clang-format on

#define SNIP_SHORTCUT LCTL(LSFT(KC_I))
#define VSCODE_SNIPPET(x)      \
    tap_code16(SNIP_SHORTCUT); \
    SEND_STRING(x);            \
    tap_code16(KC_ENT);

void process_combo_event(uint8_t combo_index, bool pressed) {
    if (pressed) {
        switch (combo_index) {
            case SNIP_FOR:
                VSCODE_SNIPPET("for");
                break;
            case SNIP_IF:
                VSCODE_SNIPPET("if");
                break;
            case SNIP_LOG:
                VSCODE_SNIPPET("log");
                break;
            case SNIP_COM:
                VSCODE_SNIPPET("/*");
                break;
            case SNIP_CON:
                VSCODE_SNIPPET("//");
                break;
            case SHCUT_CODE:
                tap_code16(KC_F13);
                break;
            case SHCUT_TERM:
                tap_code16(KC_F14);
                break;
            case SHCUT_FIREFOX:
                tap_code16(KC_F15);
                break;
            case SHCUT_CHROME:
                tap_code16(KC_F16);
                break;
            case SHCUT_TELEGRAM:
                tap_code16(KC_F17);
                break;
            case SHCUT_RIPCORD:
                tap_code16(KC_F18);
                break;
            case SHCUT_DFU:
                tap_code16(KC_F19);
                wait_ms(100);
                bootloader_jump();
                break;
            case SHCUT_NEWTAB:
                tap_code16(LCTL(KC_T));
                break;
        }
    }
}

/*
void matrix_scan_user(void) {
};
*/