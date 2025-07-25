#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for custom lang keycodes."
#endif

enum custom_lang_keycodes {
  CUSTOM_LANG_START = CUSTOM_SAFE_RANGE,

  EQ_JS, // ===
  NEQ_JS, // !==
  ARR_F_JS, // ()=>{}◀️
  EN_LTEQ, // <=
  EN_GTEQ, // >=
  EN_ARR1, // ->
  EN_ARR2, // =>
  EN_FISH, // ::<>()◀️◀️◀️
  EN_MACR, // #[]◀️
  EN_CLTG, // </
  AG2COLN, // ::
  AG2SLSH, // //⎵
  EN2QUOT, // ''◀️
  AG2DQUO, // ""◀️
  EN2AMPR, // &&
  EN2PIPE, // ||
  EN_HOME, // ~/
  AG_2B1,  // ()
  EN_2B2,  // []◀️
  EN_2B3,  // {}◀️
  EN_2B4,  // <>◀️
  AG_CMNT, // /* ⎵ ⎵ */◀️◀️◀️

  EN_O_UMLAUT,
  EN_S_O_UMLAUT,
  EN_A_UMLAUT,
  EN_S_A_UMLAUT,
  EN_U_UMLAUT,
  EN_S_U_UMLAUT,
  EN_ESZETT,
  EN_S_ESZETT,

  CUSTOM_LANG_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE CUSTOM_LANG_NEW_SAFE_RANGE
};

void tap_umlaut(uint16_t keycode) {
    // Clear any existing modifiers
    clear_mods();
    clear_weak_mods();
    
    register_code(KC_LALT);
    tap_code(KC_U);
    unregister_code(KC_LALT);
    
    wait_ms(100); // Longer delay for dead key processing
    tap_code(keycode);
}

void tap_s_umlaut(uint16_t keycode) {
    // Clear any existing modifiers
    clear_mods();
    clear_weak_mods();
    
    register_code(KC_LALT);
    tap_code(KC_U);
    unregister_code(KC_LALT);
    
    wait_ms(100); // Longer delay for dead key processing
    
    register_code(KC_LSFT);
    tap_code(keycode);
    unregister_code(KC_LSFT);
}

// Мои языко-символьные клавиши
bool process_my_lang_keys(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EN_O_UMLAUT:
        tap_umlaut(KC_O);
        return false;
      case EN_S_O_UMLAUT:
        tap_s_umlaut(KC_O);
        return false;
      case EN_A_UMLAUT:
        tap_umlaut(KC_A);
        return false;
      case EN_S_A_UMLAUT:
        tap_s_umlaut(KC_A);
        return false;
      case EN_U_UMLAUT:
        tap_umlaut(KC_U);
        return false;
      case EN_S_U_UMLAUT:
        tap_s_umlaut(KC_U);
        return false;
      case EN_ESZETT:
        // Clear modifiers and use Option+S directly
        clear_mods();
        clear_weak_mods();
        register_code(KC_LALT);
        tap_code(KC_S);
        unregister_code(KC_LALT);
        return false;
      case EN_S_ESZETT:
        // Uppercase ß is typically SS
        clear_mods();
        clear_weak_mods();
        tap_code(KC_S);
        tap_code(KC_S);
        return false;
    }
  }
  // English-specific codes
  switch (keycode) {
    case EN_LTEQ:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_LT);
        lang_shift_tap_key(AG_EQL);
      }
      return false;
      break;
    case EN_GTEQ:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_GT);
        lang_shift_tap_key(AG_EQL);
      }
      return false;
      break;
    case EN_ARR1:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_MINS);
        lang_shift_tap_key(EN_GT);
      }
      return false;
      break;
    case EN_ARR2:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_EQL);
        lang_shift_tap_key(EN_GT);
      }
      return false;
      break;
    case EN_FISH:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_COLN);
        lang_shift_tap_key(AG_COLN);
        lang_shift_tap_key(EN_LT);
        lang_shift_tap_key(EN_GT);
        lang_shift_tap_key(EN_LPRN);
        lang_shift_tap_key(EN_RPRN);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case EN_MACR:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_HASH);
        lang_shift_tap_key(EN_LBRC);
        lang_shift_tap_key(EN_RBRC);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case EN_CLTG:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_LT);
        lang_shift_tap_key(AG_SLSH);
      }
      return false;
      break;
    case AG2COLN:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_COLN);
        lang_shift_tap_key(AG_COLN);
      }
      return false;
      break;
    case AG2SLSH:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_SLSH);
        lang_shift_tap_key(AG_SLSH);
        register_code(KC_SPC); unregister_code(KC_SPC);
      }
      return false;
      break;
    case EN2QUOT:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_QUOT);
        lang_shift_tap_key(EN_QUOT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case AG2DQUO:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_DQUO);
        lang_shift_tap_key(AG_DQUO);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case EN2AMPR:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_AMPR);
        lang_shift_tap_key(EN_AMPR);
      }
      return false;
      break;
    case EN2PIPE:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_PIPE);
        lang_shift_tap_key(EN_PIPE);
      }
      return false;
      break;
    case EN_HOME:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_TILD);
        lang_shift_tap_key(AG_SLSH);
      }
      return false;
      break;
    case AG_2B1:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_LPRN);
        lang_shift_tap_key(AG_RPRN);
      }
      return false;
      break;

    case EQ_JS:
      if(record->event.pressed){
        lang_shift_tap_key(AG_EQL);
        lang_shift_tap_key(AG_EQL);
        lang_shift_tap_key(AG_EQL);
      }
      return false;
      break;
    case NEQ_JS:
      if(record->event.pressed){
        lang_shift_tap_key(AG_EXCL);
        lang_shift_tap_key(AG_EQL);
        lang_shift_tap_key(AG_EQL);
      }
      return false;
      break;
    case ARR_F_JS:
      if(record->event.pressed){
        lang_shift_tap_key(AG_LPRN);
        lang_shift_tap_key(AG_RPRN);
        lang_shift_tap_key(AG_EQL);
        lang_shift_tap_key(EN_GT);
        lang_shift_tap_key(EN_LCBR);
        lang_shift_tap_key(EN_RCBR);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case EN_2B2:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_LBRC);
        lang_shift_tap_key(EN_RBRC);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case EN_2B3:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_LCBR);
        lang_shift_tap_key(EN_RCBR);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case EN_2B4:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_LT);
        lang_shift_tap_key(EN_GT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case AG_CMNT:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_SLSH);
        lang_shift_tap_key(AG_ASTR);
        register_code(KC_SPC); unregister_code(KC_SPC);
        register_code(KC_SPC); unregister_code(KC_SPC);
        lang_shift_tap_key(AG_ASTR);
        lang_shift_tap_key(AG_SLSH);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
  }
  return true;
}
