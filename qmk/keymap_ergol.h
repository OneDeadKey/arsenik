#pragma once
#include "keycodes.h"
// clang-format off

// Aliases
#define EL_GRV  KC_GRV  // `
#define EL_1    KC_1    // 1
#define EL_2    KC_2    // 2
#define EL_3    KC_3    // 3
#define EL_4    KC_4    // 4
#define EL_5    KC_5    // 5
#define EL_6    KC_6    // 6
#define EL_7    KC_7    // 7
#define EL_8    KC_8    // 8
#define EL_9    KC_9    // 9
#define EL_0    KC_0    // 0
#define EL_SLSH KC_MINS // /
#define EL_EQL  KC_EQL  // =
#define EL_Q    KC_Q    // Q
#define EL_C    KC_W    // C
#define EL_O    KC_E    // O
#define EL_P    KC_R    // P
#define EL_W    KC_T    // W
#define EL_J    KC_Y    // J
#define EL_M    KC_U    // M
#define EL_D    KC_I    // D
#define EL_ODK  KC_O    // odk (dead lafayette)
#define EL_Y    KC_P    // Y
#define EL_LBRC KC_LBRC // [
#define EL_RBRC KC_RBRC // ]
#define EL_A    KC_A    // A
#define EL_S    KC_S    // S
#define EL_E    KC_D    // E
#define EL_N    KC_F    // N
#define EL_F    KC_G    // F
#define EL_L    KC_H    // L
#define EL_R    KC_J    // R
#define EL_T    KC_K    // R
#define EL_I    KC_L    // I
#define EL_U    KC_SCLN // U
#define EL_QUOT KC_QUOT // '
#define EL_BSLS KC_NUHS // (backslash)
#define EL_LABK KC_NUBS // <
#define EL_Z    KC_Z    // Z
#define EL_X    KC_X    // X
#define EL_MINS KC_C    // -
#define EL_V    KC_V    // V
#define EL_B    KC_B    // B
#define EL_DOT  KC_N    // .
#define EL_H    KC_M    // H
#define EL_G    KC_COMM // G
#define EL_COMM KC_DOT  // ,
#define EL_K    KC_SLSH // K

//SHIFTED
#define EL_TILD S(EL_GRV)  // ~
#define EL_EURO S(EL_1)    // €
#define EL_LDQF S(EL_2)    // «
#define EL_RDQF S(EL_3)    // »
#define EL_DLR  S(EL_4)    // $
#define EL_PERC S(EL_5)    // %
#define EL_CIRC S(EL_6)    // ^
#define EL_AMPR S(EL_7)    // &
#define EL_ASTR S(EL_8)    // *
#define EL_HASH S(EL_9)    // #
#define EL_AT   S(EL_0)    // @
#define EL_UNDS S(EL_SLSH) // _
#define EL_PLUS S(EL_EQL)  // =
#define EL_EXLM S(EL_ODK)  // !
#define EL_LCBR S(EL_LBRC) // {
#define EL_RCBR S(EL_RBRC) // }
#define EL_DQUO S(EL_QUOT) // "
#define EL_PIPE S(EL_BSLS) // |
#define EL_RABK S(EL_LABK) // >
#define EL_QUES S(EL_MINS) // ?
#define EL_COLN S(EL_DOT)  // :
#define EL_SCLN S(EL_COMM) // ;

//ALTGR  //Symbol layer
#define EL_SUB1 ALGR(EL_1)    // ₁
#define EL_SUB2 ALGR(EL_2)    // ₂
#define EL_SUB3 ALGR(EL_3)    // ₃
#define EL_SUB4 ALGR(EL_4)    // ₄
#define EL_SUB5 ALGR(EL_5)    // ₅
#define EL_SUB6 ALGR(EL_6)    // ₆
#define EL_SUB7 ALGR(EL_7)    // ₇
#define EL_SUB8 ALGR(EL_8)    // ₈
#define EL_SUB9 ALGR(EL_9)    // ₉
#define EL_SUB0 ALGR(EL_0)    // ₀
#define EL_LPRN ALGR(EL_S)    // (
#define EL_RPRN ALGR(EL_E)    // )
#define EL_LT   ALGR(EL_C)    // <
#define EL_GT   ALGR(EL_O)    // >

//ALTGR  //Symbol layer //SHIFTED
#define EL_SUP1 ALGR(S(EL_1))    // ¹
#define EL_SUP2 ALGR(S(EL_2))    // ²
#define EL_SUP3 ALGR(S(EL_3))    // ³
#define EL_SUP4 ALGR(S(EL_4))    // ⁴
#define EL_SUP5 ALGR(S(EL_5))    // ⁵
#define EL_SUP6 ALGR(S(EL_6))    // ⁶
#define EL_SUP7 ALGR(S(EL_7))    // ⁷
#define EL_SUP8 ALGR(S(EL_8))    // ⁸
#define EL_SUP9 ALGR(S(EL_9))    // ⁹
#define EL_SUP0 ALGR(S(EL_0))    // ⁰

#define EL_DCIR ALGR(S(EL_Q))    // ^ (dead)
#define EL_LEEQ ALGR(S(EL_C))    // <=
#define EL_GREQ ALGR(S(EL_O))    // >=
#define EL_CURR ALGR(S(EL_P))    // ¤ (dead)
#define EL_PERM ALGR(S(EL_W))    // ‰
#define EL_RNGA ALGR(S(EL_J))    // ° (dead)
#define EL_MUL  ALGR(S(EL_D))    // ×
#define EL_ACUT ALGR(S(EL_ODK))  // ´ (dead)
#define EL_DGRV ALGR(S(EL_Y))    // ` (dead)
#define EL_CARN ALGR(S(EL_A))    // ˇ (dead)
// #define EL_RNGA ALGR(S(EL_N))    // ° (dead)
#define EL_NEQL ALGR(S(EL_F))    // !=
#define EL_DSLS ALGR(S(EL_L))    // TODO!! / dead
#define EL_PLMN ALGR(S(EL_R))    // ±
#define EL_MACR ALGR(S(EL_T))    // ¯ (dead)
#define EL_DIV  ALGR(S(EL_I))    // ÷
#define EL_DACU ALGR(S(EL_U))    // ˝ (dead)
#define EL_DTIL ALGR(S(EL_Z))    // ~ (dead)
#define EL_CEDL ALGR(S(EL_X))    // ¸ (dead)
#define EL_OGON ALGR(S(EL_MINS)) // ˛ (dead)
#define EL_DCLN ALGR(S(EL_G))    // cédille ronde (dead)
#define EL_BREV ALGR(S(EL_K))    // ˘ (dead)
