#include "cdata.h"
#include "sample.h"
#include "octave.h"
#include <stddef.h>

#define CMD_T(LINE, NOTE, SAMPLE_NO) ((LINE) | (NOTE) << 8 | (SAMPLE_NO) << 16)
#define CMD_FX_JMP_T(LINE, JMP_LINE) ((LINE) | (CMD_FX_JMP << 4 | JMP_LINE) << 24)

static const uint32_t cmd_0_3[] = {
    CMD_T(6,NOTE_C(3),0x7),
    CMD_T(10,NOTE_C(3),0x7),
    CMD_T(14,NOTE_C(3),0x7),
    CMD_T(18,NOTE_C(3),0x7),
    CMD_T(21,NOTE_C(3),0x7),
    CMD_T(24,NOTE_C(3),0x7),
    CMD_T(26,NOTE_C(3),0x7),
    CMD_T(28,NOTE_C(3),0x7),
    CMD_T(29,NOTE_C(3),0x7),
    CMD_T(30,NOTE_C(3),0x7),
    CMD_T(31,NOTE_C(3),0x7),
    CMD_T(32,NOTE_AS(2),0x7),
    CMD_T(34,NOTE_C(3),0x7),
    CMD_T(36,NOTE_C(3),0x7),
    CMD_T(38,NOTE_AS(2),0x7),
    CMD_T(40,NOTE_C(3),0x7),
    CMD_T(42,NOTE_C(3),0x7),
    CMD_T(44,NOTE_C(3),0x7),
    CMD_T(46,NOTE_AS(2),0x7),
    CMD_T(48,NOTE_C(3),0x7),
    CMD_T(50,NOTE_DS(3),0x7),
    CMD_T(52,NOTE_C(3),0x7),
    CMD_T(54,NOTE_C(3),0x7),
    CMD_T(56,NOTE_C(3),0x7),
    CMD_T(58,NOTE_C(3),0x7),
    CMD_T(59,NOTE_C(3),0x7),
    CMD_T(60,NOTE_C(3),0x7),
    CMD_T(62,NOTE_C(3),0x7),
};
static const uint32_t cmd_1_0[] = {
    CMD_T(0,NOTE_E(2),0xf)
};
static const uint32_t cmd_1_1[] = {
    CMD_FX_JMP_T(55,0)
};
static const uint32_t cmd_1_2[] = {
    CMD_T(0,NOTE_E(2),0xf)
};
static const uint32_t cmd_1_3[] = {
    CMD_T(0,NOTE_C(3),0x7),
    CMD_T(3,NOTE_C(3),0x7),
    CMD_T(6,NOTE_C(3),0x7),
    CMD_T(10,NOTE_C(3),0x7),
    CMD_T(14,NOTE_C(3),0x7),
    CMD_T(18,NOTE_C(3),0x7)
};
static const uint32_t cmd_2_0[] = {
    CMD_T(0,NOTE_E(2),0xf)
};
static const uint32_t cmd_2_1[] = {
    CMD_T(1,NOTE_E(2),0xf)
};
static const uint32_t cmd_2_2[] = {
    CMD_T(32,NOTE_A(2),0xf)
};
static const uint32_t cmd_2_3[] = {
    CMD_T(0,NOTE_G(2),0x2),
    CMD_T(32,NOTE_C(3),0x2)
};

static const uint32_t cmd_3_0[] = {
    CMD_T(0,NOTE_D(2),0xf),
    CMD_T(28,NOTE_A(1),0xf),
    CMD_T(32,NOTE_E(2),0xf)
};
static const uint32_t cmd_3_1[] = {
    CMD_T(0,NOTE_D(2),0xf),
    CMD_T(28,NOTE_E(2),0xf),
    CMD_T(32,NOTE_B(2),0xf)
};
static const uint32_t cmd_3_2[] = {
    CMD_T(0,NOTE_G(2),0xf),
    CMD_T(28,NOTE_A(2),0xf),
    CMD_T(32,NOTE_E(2),0xf)
};
static const uint32_t cmd_3_3[] = {
    CMD_T(0,NOTE_AS(2),0x2),
    CMD_T(28,NOTE_F(2),0x2),
    CMD_T(32,NOTE_G(2),0x2)
};

static const uint32_t cmd_4_0[] = {
    CMD_T(0,NOTE_F(2),0xf),
    CMD_T(28,NOTE_E(2),0xf),
    CMD_T(32,NOTE_D(2),0xf),
    CMD_T(60,NOTE_C(2),0xf)
};
static const uint32_t cmd_4_1[] = {
    CMD_T(0,NOTE_C(3),0xf),
    CMD_T(28,NOTE_B(2),0xf),
    CMD_T(32,NOTE_A(2),0xf),
    CMD_T(60,NOTE_E(2),0xf)
};
static const uint32_t cmd_4_2[] = {
    CMD_T(0,NOTE_F(2),0xf),
    CMD_T(28,NOTE_E(2),0xf),
    CMD_T(32,NOTE_D(2),0xf),
    CMD_T(60,NOTE_C(2),0xf)
};
static const uint32_t cmd_4_3[] = {
    CMD_T(0,NOTE_GS(2),0x2),
    CMD_T(28,NOTE_G(2),0x2),
    CMD_T(32,NOTE_F(2),0x2),
    CMD_T(60,NOTE_C(2),0x2)
};

static const uint32_t cmd_5_0[] = {
    CMD_T(0,NOTE_E(2),0xf),
    CMD_T(2,NOTE_C(3),0x7),
    CMD_T(4,NOTE_C(3),0x7),
    CMD_T(6,NOTE_C(3),0x4),
    CMD_T(8,NOTE_C(3),0x7),
    CMD_T(10,NOTE_C(3),0x7),
    CMD_T(12,NOTE_C(3),0xd),
    CMD_T(14,NOTE_B(2),0x1),
    CMD_T(16,NOTE_B(2),0x1),
    CMD_T(18,NOTE_C(2),0x4),
    CMD_T(20,NOTE_C(3),0x7),
    CMD_T(22,NOTE_C(3),0x7),
    CMD_T(24,NOTE_C(3),0xd),
    CMD_T(26,NOTE_B(2),0x1),
    CMD_T(28,NOTE_C(3),0x7),
    CMD_T(30,NOTE_C(3),0x7),
    CMD_T(32,NOTE_C(3),0x7),
    CMD_T(34,NOTE_C(3),0x7),
    CMD_T(36,NOTE_C(3),0x7),
    CMD_T(38,NOTE_AS(2),0x7),
    CMD_T(40,NOTE_C(3),0x7),
    CMD_T(42,NOTE_C(3),0x7),
    CMD_T(44,NOTE_C(3),0x7),
    CMD_T(46,NOTE_AS(2),0x7),
    CMD_T(48,NOTE_C(3),0x7),
    CMD_T(50,NOTE_DS(3),0x7),
    CMD_T(52,NOTE_C(3),0x7),
    CMD_T(54,NOTE_C(3),0x7),
    CMD_T(56,NOTE_C(3),0x7),
    CMD_T(58,NOTE_C(3),0x7),
    CMD_T(59,NOTE_C(3),0x7),
    CMD_T(60,NOTE_C(3),0x7),
    CMD_T(62,NOTE_C(3),0x7)
};
static const uint32_t cmd_5_1[] = {
    CMD_T(0,NOTE_E(2),0xf)
};
static const uint32_t cmd_5_2[] = {
    CMD_T(0,NOTE_E(1),0xf),
    CMD_T(48,NOTE_A(2),0x6),
    CMD_T(50,NOTE_A(2),0x6),
    CMD_T(52,NOTE_A(2),0x6),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(58,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_5_3[] = {
    CMD_T(0,NOTE_G(2),0x2)
};

static const uint32_t cmd_6_0[] = {
    CMD_T(0,NOTE_E(2),0xf),
    CMD_T(2,NOTE_C(3),0x7),
    CMD_T(4,NOTE_C(3),0x7),
    CMD_T(6,NOTE_C(3),0x4),
    CMD_T(8,NOTE_C(3),0x7),
    CMD_T(10,NOTE_C(3),0x7),
    CMD_T(12,NOTE_C(3),0xd),
    CMD_T(14,NOTE_B(2),0x1),
    CMD_T(16,NOTE_B(2),0x1),
    CMD_T(18,NOTE_C(2),0x4),
    CMD_T(20,NOTE_C(3),0x7),
    CMD_T(22,NOTE_C(3),0x7),
    CMD_T(24,NOTE_C(3),0xd),
    CMD_T(26,NOTE_B(2),0x1),
    CMD_T(28,NOTE_C(3),0x7),
    CMD_T(30,NOTE_C(3),0x7),
    CMD_T(32,NOTE_C(2),0xf),
    CMD_T(34,NOTE_C(3),0x7),
    CMD_T(36,NOTE_C(3),0x7),
    CMD_T(38,NOTE_C(3),0x4),
    CMD_T(40,NOTE_C(3),0x7),
    CMD_T(42,NOTE_C(3),0x7),
    CMD_T(44,NOTE_C(3),0xd),
    CMD_T(46,NOTE_B(2),0x1),
    CMD_T(48,NOTE_B(2),0x1),
    CMD_T(50,NOTE_C(2),0x4),
    CMD_T(52,NOTE_C(3),0x7),
    CMD_T(54,NOTE_C(3),0x7),
    CMD_T(56,NOTE_C(3),0xd),
    CMD_T(58,NOTE_B(2),0x1),
    CMD_T(60,NOTE_C(3),0x7),
    CMD_T(62,NOTE_C(3),0x7)
};
static const uint32_t cmd_6_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(50,NOTE_A(2),0x5),
    CMD_T(52,NOTE_A(2),0x5),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6),
};
static const uint32_t cmd_6_2[] = {
    CMD_T(0,NOTE_E(2),0xe),
    CMD_T(2,NOTE_E(2),0xe),
    CMD_T(4,NOTE_E(2),0x1e),
    CMD_T(6,NOTE_E(2),0xe),
    CMD_T(8,NOTE_E(2),0xe),
    CMD_T(10,NOTE_E(2),0xe),
    CMD_T(12,NOTE_E(2),0x1e),
    CMD_T(14,NOTE_E(2),0xe),
    CMD_T(16,NOTE_E(2),0xe),
    CMD_T(18,NOTE_E(2),0x1e),
    CMD_T(20,NOTE_E(2),0xe),
    CMD_T(22,NOTE_E(2),0xe),
    CMD_T(24,NOTE_E(2),0x1e),
    CMD_T(26,NOTE_E(2),0xe),
    CMD_T(28,NOTE_E(2),0x1e),
    CMD_T(30,NOTE_E(2),0xe),
    CMD_T(32,NOTE_C(2),0xe),
    CMD_T(34,NOTE_C(2),0xe),
    CMD_T(36,NOTE_C(2),0x1e),
    CMD_T(38,NOTE_C(2),0xe),
    CMD_T(40,NOTE_C(2),0xe),
    CMD_T(42,NOTE_C(2),0xe),
    CMD_T(44,NOTE_C(2),0x1e),
    CMD_T(46,NOTE_C(2),0xe),
    CMD_T(48,NOTE_C(2),0xe),
    CMD_T(50,NOTE_C(2),0x1e),
    CMD_T(52,NOTE_C(2),0xe),
    CMD_T(54,NOTE_C(2),0xe),
    CMD_T(56,NOTE_C(2),0x1e),
    CMD_T(58,NOTE_C(2),0xe),
    CMD_T(60,NOTE_C(2),0x1e),
    CMD_T(62,NOTE_C(2),0xe)
};
static const uint32_t cmd_6_3[] = {
    CMD_T(0,NOTE_E(2),0xf),
    CMD_T(32,NOTE_C(2),0xf)
};

static const uint32_t cmd_7_0[] = {
    CMD_T(0,NOTE_D(2),0xf),
    CMD_T(2,NOTE_C(3),0x7),
    CMD_T(4,NOTE_C(3),0x7),
    CMD_T(6,NOTE_C(3),0x4),
    CMD_T(8,NOTE_C(3),0x7),
    CMD_T(10,NOTE_C(3),0x7),
    CMD_T(12,NOTE_C(3),0xd),
    CMD_T(14,NOTE_B(2),0x1),
    CMD_T(16,NOTE_B(2),0x1),
    CMD_T(18,NOTE_C(2),0x4),
    CMD_T(20,NOTE_C(3),0x7),
    CMD_T(22,NOTE_C(3),0x7),
    CMD_T(24,NOTE_C(3),0xd),
    CMD_T(26,NOTE_B(2),0x1),
    CMD_T(28,NOTE_C(3),0x7),
    CMD_T(30,NOTE_C(3),0x7),
};
static const uint32_t cmd_7_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(50,NOTE_A(2),0x5),
    CMD_T(52,NOTE_A(2),0x5),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_7_2[] = {
    CMD_T(0,NOTE_D(2),0xe),
    CMD_T(2,NOTE_D(2),0xe),
    CMD_T(4,NOTE_D(2),0x1e),
    CMD_T(6,NOTE_D(2),0xe),
    CMD_T(8,NOTE_D(2),0xe),
    CMD_T(10,NOTE_D(2),0xe),
    CMD_T(12,NOTE_D(2),0x1e),
    CMD_T(14,NOTE_D(2),0xe),
    CMD_T(16,NOTE_D(2),0xe),
    CMD_T(18,NOTE_D(2),0x1e),
    CMD_T(20,NOTE_D(2),0xe),
    CMD_T(22,NOTE_D(2),0xe),
    CMD_T(24,NOTE_D(2),0x1e),
    CMD_T(26,NOTE_D(2),0xe),
    CMD_T(28,NOTE_D(2),0x1e),
    CMD_T(30,NOTE_D(2),0xe),
    CMD_T(32,NOTE_E(2),0xe),
    CMD_T(34,NOTE_E(2),0xe),
    CMD_T(36,NOTE_E(2),0x1e),
    CMD_T(38,NOTE_E(2),0xe),
    CMD_T(40,NOTE_E(2),0xe),
    CMD_T(42,NOTE_E(2),0xe),
    CMD_T(44,NOTE_E(2),0x1e),
    CMD_T(46,NOTE_E(2),0xe),
    CMD_T(48,NOTE_E(2),0xe),
    CMD_T(50,NOTE_E(2),0x1e),
    CMD_T(52,NOTE_E(2),0xe),
    CMD_T(54,NOTE_E(2),0xe),
    CMD_T(56,NOTE_E(2),0x1e),
    CMD_T(58,NOTE_E(2),0xe),
    CMD_T(60,NOTE_E(2),0x1e),
    CMD_T(62,NOTE_E(2),0xe)
};
static const uint32_t cmd_7_3[] = {
    CMD_T(0, NOTE_D(2), 0xf),
    CMD_T(32, NOTE_E(2),0xf)
};

static const uint32_t cmd_8_0[] = {
    CMD_T(0,NOTE_E(2),0xf),
    CMD_T(32,NOTE_C(2),0xf)
};
static const uint32_t cmd_8_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(50,NOTE_A(2),0x5),
    CMD_T(52,NOTE_A(2),0x5),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_8_2[] = {
    CMD_T(0,NOTE_E(2),0xf),
    CMD_T(2,NOTE_C(3),0x7),
    CMD_T(4,NOTE_C(3),0x7),
    CMD_T(6,NOTE_C(3),0x4),
    CMD_T(8,NOTE_C(3),0x7),
    CMD_T(10,NOTE_C(3),0x7),
    CMD_T(12,NOTE_C(3),0xd),
    CMD_T(14,NOTE_B(2),0x1),
    CMD_T(16,NOTE_B(2),0x1),
    CMD_T(18,NOTE_C(2),0x4),
    CMD_T(20,NOTE_C(3),0x7),
    CMD_T(22,NOTE_C(3),0x7),
    CMD_T(24,NOTE_C(3),0xd),
    CMD_T(26,NOTE_B(2),0x1),
    CMD_T(28,NOTE_C(3),0x7),
    CMD_T(30,NOTE_C(3),0x7),
    CMD_T(32,NOTE_C(2),0xf),
    CMD_T(34,NOTE_C(3),0x7),
    CMD_T(36,NOTE_C(3),0x7),
    CMD_T(38,NOTE_C(3),0x4),
    CMD_T(40,NOTE_C(3),0x7),
    CMD_T(42,NOTE_C(3),0x7),
    CMD_T(44,NOTE_C(3),0xd),
    CMD_T(46,NOTE_B(2),0x1),
    CMD_T(48,NOTE_B(2),0x1),
    CMD_T(50,NOTE_C(2),0x4),
    CMD_T(52,NOTE_C(3),0x7),
    CMD_T(54,NOTE_C(3),0x7),
    CMD_T(56,NOTE_C(3),0xd),
    CMD_T(58,NOTE_B(2),0x1),
    CMD_T(60,NOTE_C(3),0x7),
    CMD_T(62,NOTE_C(3),0x7),
};
static const uint32_t cmd_8_3[] = {
    CMD_T(0,NOTE_B(2),0x1)
};

static const uint32_t cmd_9_0[] = {
    CMD_T(0,NOTE_D(2),0xf),
    CMD_T(32,NOTE_E(2),0xf)
};
static const uint32_t cmd_9_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(50,NOTE_A(2),0x5),
    CMD_T(52,NOTE_A(2),0x5),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_9_2[] = {
    CMD_T(0,NOTE_D(2),0xe),
    CMD_T(2,NOTE_D(2),0xe),
    CMD_T(4,NOTE_D(2),0x1e),
    CMD_T(6,NOTE_D(2),0xe),
    CMD_T(8,NOTE_D(2),0xe),
    CMD_T(10,NOTE_D(2),0xe),
    CMD_T(12,NOTE_D(2),0x1e),
    CMD_T(14,NOTE_D(2),0xe),
    CMD_T(16,NOTE_D(2),0xe),
    CMD_T(18,NOTE_D(2),0x1e),
    CMD_T(20,NOTE_D(2),0xe),
    CMD_T(22,NOTE_D(2),0xe),
    CMD_T(24,NOTE_D(2),0x1e),
    CMD_T(26,NOTE_D(2),0xe),
    CMD_T(28,NOTE_D(2),0x1e),
    CMD_T(30,NOTE_D(2),0xe),
    CMD_T(32,NOTE_D(2),0xe),
    CMD_T(34,NOTE_E(2),0xe),
    CMD_T(36,NOTE_E(2),0x1e),
    CMD_T(38,NOTE_E(2),0xe),
    CMD_T(40,NOTE_E(2),0xe),
    CMD_T(42,NOTE_E(2),0xe),
    CMD_T(44,NOTE_E(2),0x1e),
    CMD_T(46,NOTE_E(2),0xe),
    CMD_T(48,NOTE_E(2),0xe),
    CMD_T(50,NOTE_E(2),0x1e),
    CMD_T(52,NOTE_E(2),0xe),
    CMD_T(54,NOTE_E(2),0xe),
    CMD_T(56,NOTE_E(2),0x1e),
    CMD_T(58,NOTE_E(2),0xe),
    CMD_T(60,NOTE_E(2),0x1e),
    CMD_T(62,NOTE_E(2),0xe),
};
static const uint32_t cmd_9_3[] = {
    CMD_T(0,NOTE_F(2),0xc),
    CMD_T(8,NOTE_DS(2),0xc),
    CMD_T(12,NOTE_D(2),0xc),
    CMD_T(20,NOTE_AS(1),0xc),
    CMD_T(32,NOTE_DS(2),0xc),
    CMD_T(40,NOTE_G(2),0xc),
    CMD_T(44,NOTE_C(2),0xc)
};

static const uint32_t cmd_10_0[] = {
    CMD_T(0,NOTE_E(2),0xf),
    CMD_T(32,NOTE_C(2),0xf)
};
static const uint32_t cmd_10_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(36,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(50,NOTE_A(2),0x5),
    CMD_T(52,NOTE_A(2),0x5),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_10_2[] = {
    CMD_T(0,NOTE_E(2),0xe),
    CMD_T(2,NOTE_E(2),0xe),
    CMD_T(4,NOTE_E(2),0x1e),
    CMD_T(6,NOTE_E(2),0xe),
    CMD_T(8,NOTE_E(2),0xe),
    CMD_T(10,NOTE_E(2),0xe),
    CMD_T(12,NOTE_E(2),0x1e),
    CMD_T(14,NOTE_E(2),0xe),
    CMD_T(16,NOTE_E(2),0xe),
    CMD_T(18,NOTE_E(2),0x1e),
    CMD_T(20,NOTE_E(2),0xe),
    CMD_T(22,NOTE_E(2),0xe),
    CMD_T(24,NOTE_E(2),0x1e),
    CMD_T(26,NOTE_E(2),0xe),
    CMD_T(28,NOTE_E(2),0x1e),
    CMD_T(30,NOTE_E(2),0xe),
    CMD_T(32,NOTE_C(2),0xe),
    CMD_T(34,NOTE_C(2),0xe),
    CMD_T(36,NOTE_C(2),0x1e),
    CMD_T(38,NOTE_C(2),0xe),
    CMD_T(40,NOTE_C(2),0xe),
    CMD_T(42,NOTE_C(2),0xe),
    CMD_T(44,NOTE_C(2),0x1e),
    CMD_T(46,NOTE_C(2),0xe),
    CMD_T(48,NOTE_C(2),0xe),
    CMD_T(50,NOTE_C(2),0x1e),
    CMD_T(52,NOTE_C(2),0xe),
    CMD_T(54,NOTE_C(2),0xe),
    CMD_T(56,NOTE_C(2),0x1e),
    CMD_T(58,NOTE_C(2),0xe),
    CMD_T(60,NOTE_C(2),0x1e),
    CMD_T(62,NOTE_C(2),0xe),
};
static const uint32_t cmd_10_3[] = {
    CMD_T(0,NOTE_DS(2),0xc),
    CMD_T(8,NOTE_C(2),0xc),
    CMD_T(12,NOTE_G(2),0xc),
    CMD_T(20,NOTE_C(2),0xc),
    CMD_T(24,NOTE_DS(2),0xc),
    CMD_T(28,NOTE_C(2),0xc),
    CMD_T(32,NOTE_C(3),0xc)
};

static const uint32_t cmd_11_0[] = {
    CMD_T(0,NOTE_D(2),0xf),
    CMD_T(32,NOTE_E(2),0xf)
};
static const uint32_t cmd_11_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(36,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(50,NOTE_A(2),0x5),
    CMD_T(52,NOTE_A(2),0x5),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_11_2[] = {
    CMD_T(0,NOTE_D(2),0xe),
    CMD_T(2,NOTE_D(2),0xe),
    CMD_T(4,NOTE_D(2),0x1e),
    CMD_T(6,NOTE_D(2),0xe),
    CMD_T(8,NOTE_D(2),0xe),
    CMD_T(10,NOTE_D(2),0xe),
    CMD_T(12,NOTE_D(2),0x1e),
    CMD_T(14,NOTE_D(2),0xe),
    CMD_T(16,NOTE_D(2),0xe),
    CMD_T(18,NOTE_D(2),0x1e),
    CMD_T(20,NOTE_D(2),0xe),
    CMD_T(22,NOTE_D(2),0xe),
    CMD_T(24,NOTE_D(2),0x1e),
    CMD_T(26,NOTE_D(2),0xe),
    CMD_T(28,NOTE_D(2),0x1e),
    CMD_T(30,NOTE_D(2),0xe),
    CMD_T(32,NOTE_E(2),0xe),
    CMD_T(34,NOTE_E(2),0xe),
    CMD_T(36,NOTE_E(2),0x1e),
    CMD_T(38,NOTE_E(2),0xe),
    CMD_T(40,NOTE_E(2),0xe),
    CMD_T(42,NOTE_E(2),0xe),
    CMD_T(44,NOTE_E(2),0x1e),
    CMD_T(46,NOTE_E(2),0xe),
    CMD_T(48,NOTE_E(2),0xe),
    CMD_T(50,NOTE_E(2),0x1e),
    CMD_T(52,NOTE_E(2),0xe),
    CMD_T(54,NOTE_E(2),0xe),
    CMD_T(56,NOTE_E(2),0x1e),
    CMD_T(58,NOTE_E(2),0xe),
    CMD_T(60,NOTE_E(2),0x1e),
    CMD_T(62,NOTE_E(2),0xe),
};
static const uint32_t cmd_11_3[] = {
    CMD_T(0,NOTE_C(3),0xc),
    CMD_T(4,NOTE_AS(2),0xc),
    CMD_T(8,NOTE_C(3),0xc),
    CMD_T(12,NOTE_D(3),0xc),
    CMD_T(14,NOTE_C(3),0xc),
    CMD_T(32,NOTE_DS(2),0xc),
    CMD_T(40,NOTE_G(2),0xc),
    CMD_T(44,NOTE_C(2),0xc)
};

static const uint32_t cmd_12_0[] = {
    CMD_T(0,NOTE_E(2),0xf),
    CMD_T(32,NOTE_C(2),0xf)
};
static const uint32_t cmd_12_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(36,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(50,NOTE_A(2),0x5),
    CMD_T(52,NOTE_A(2),0x5),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_12_2[] = {
    CMD_T(0,NOTE_AS(2),0x7),
    CMD_T(2,NOTE_C(3),0x7),
    CMD_T(4,NOTE_C(3),0x7),
    CMD_T(6,NOTE_AS(2),0x7),
    CMD_T(8,NOTE_C(3),0x7),
    CMD_T(10,NOTE_C(3),0x7),
    CMD_T(12,NOTE_C(3),0x7),
    CMD_T(14,NOTE_AS(2),0x7),
    CMD_T(16,NOTE_C(3),0x7),
    CMD_T(18,NOTE_DS(3),0x7),
    CMD_T(20,NOTE_C(3),0x7),
    CMD_T(22,NOTE_C(3),0x7),
    CMD_T(24,NOTE_C(3),0x7),
    CMD_T(26,NOTE_C(3),0x7),
    CMD_T(27,NOTE_C(3),0x7),
    CMD_T(28,NOTE_C(3),0x7),
    CMD_T(30,NOTE_C(3),0x7),
    CMD_T(32,NOTE_AS(2),0x7),
    CMD_T(34,NOTE_C(3),0x7),
    CMD_T(36,NOTE_C(3),0x7),
    CMD_T(38,NOTE_AS(2),0x7),
    CMD_T(40,NOTE_C(3),0x7),
    CMD_T(42,NOTE_C(3),0x7),
    CMD_T(44,NOTE_C(3),0x7),
    CMD_T(46,NOTE_AS(2),0x7),
    CMD_T(48,NOTE_C(3),0x7),
    CMD_T(50,NOTE_DS(3),0x7),
    CMD_T(52,NOTE_C(3),0x7),
    CMD_T(54,NOTE_C(3),0x7),
    CMD_T(56,NOTE_C(3),0x7),
    CMD_T(58,NOTE_C(3),0x7),
    CMD_T(59,NOTE_C(3),0x7),
    CMD_T(60,NOTE_C(3),0x7),
    CMD_T(62,NOTE_C(3),0x7)
};

static const uint32_t cmd_13_0[] = {
    CMD_T(0,NOTE_D(2),0xf),
    CMD_T(32,NOTE_E(2),0xf)
};
static const uint32_t cmd_13_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(36,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(48,NOTE_A(2),0x6),
    CMD_T(50,NOTE_A(2),0x6),
    CMD_T(52,NOTE_A(2),0x6),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(58,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_13_2[] = {
    CMD_T(0,NOTE_AS(2),0x7),
    CMD_T(2,NOTE_C(3),0x7),
    CMD_T(4,NOTE_C(3),0x7),
    CMD_T(6,NOTE_AS(2),0x7),
    CMD_T(8,NOTE_C(3),0x7),
    CMD_T(10,NOTE_C(3),0x7),
    CMD_T(12,NOTE_C(3),0x7),
    CMD_T(14,NOTE_AS(2),0x7),
    CMD_T(16,NOTE_C(3),0x7),
    CMD_T(18,NOTE_DS(3),0x7),
    CMD_T(20,NOTE_C(3),0x7),
    CMD_T(22,NOTE_C(3),0x7),
    CMD_T(24,NOTE_C(3),0x7),
    CMD_T(26,NOTE_C(3),0x7),
    CMD_T(27,NOTE_C(3),0x7),
    CMD_T(28,NOTE_C(3),0x7),
    CMD_T(30,NOTE_C(3),0x7),
    CMD_T(32,NOTE_AS(2),0x7),
    CMD_T(34,NOTE_C(3),0x7),
    CMD_T(36,NOTE_C(3),0x7),
    CMD_T(38,NOTE_AS(2),0x7),
    CMD_T(40,NOTE_C(3),0x7),
    CMD_T(42,NOTE_C(3),0x7),
    CMD_T(44,NOTE_C(3),0x7),
    CMD_T(46,NOTE_AS(2),0x7),
    CMD_T(48,NOTE_C(3),0x7),
    CMD_T(50,NOTE_DS(3),0x7),
    CMD_T(52,NOTE_C(3),0x7),
    CMD_T(54,NOTE_C(3),0x7),
    CMD_T(56,NOTE_C(3),0x7),
    CMD_T(58,NOTE_C(3),0x7),
    CMD_T(59,NOTE_C(3),0x7),
    CMD_T(60,NOTE_C(3),0x7),
    CMD_T(62,NOTE_C(3),0x7)
};

static const uint32_t cmd_14_0[] = {
    CMD_T(0,NOTE_D(2),0xf),
    CMD_T(32,NOTE_E(2),0xf)
};
static const uint32_t cmd_14_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(50,NOTE_A(2),0x5),
    CMD_T(52,NOTE_A(2),0x5),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_14_2[] = {
    CMD_T(0,NOTE_D(2),0xf),
    CMD_T(2,NOTE_C(3),0x7),
    CMD_T(4,NOTE_C(3),0x7),
    CMD_T(6,NOTE_C(3),0x4),
    CMD_T(8,NOTE_C(3),0x7),
    CMD_T(10,NOTE_C(3),0x7),
    CMD_T(12,NOTE_C(3),0xd),
    CMD_T(14,NOTE_B(2),0x1),
    CMD_T(16,NOTE_B(2),0x1),
    CMD_T(18,NOTE_C(2),0x4),
    CMD_T(20,NOTE_C(3),0x7),
    CMD_T(22,NOTE_C(3),0x7),
    CMD_T(24,NOTE_C(3),0xd),
    CMD_T(26,NOTE_B(2),0x1),
    CMD_T(28,NOTE_C(3),0x7),
    CMD_T(30,NOTE_C(3),0x7),
    CMD_T(32,NOTE_E(2),0xf),
    CMD_T(34,NOTE_C(3),0x7),
    CMD_T(36,NOTE_C(3),0x7),
    CMD_T(38,NOTE_C(3),0x4),
    CMD_T(40,NOTE_C(3),0x7),
    CMD_T(42,NOTE_C(3),0x7),
    CMD_T(44,NOTE_C(3),0xd),
    CMD_T(46,NOTE_B(2),0x1),
    CMD_T(48,NOTE_B(2),0x1),
    CMD_T(50,NOTE_C(2),0x4),
    CMD_T(52,NOTE_C(3),0x7),
    CMD_T(54,NOTE_C(3),0x7),
    CMD_T(56,NOTE_C(3),0xd),
    CMD_T(58,NOTE_B(2),0x1),
    CMD_T(60,NOTE_C(3),0x7),
    CMD_T(62,NOTE_C(3),0x7),
};

static const uint32_t cmd_15_0[] = {
    CMD_T(0,NOTE_E(2),0xf),
    CMD_T(32,NOTE_C(2),0xf)
};
static const uint32_t cmd_15_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(50,NOTE_A(2),0x5),
    CMD_T(52,NOTE_A(2),0x5),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_15_2[] = {
    CMD_T(0,NOTE_E(2),0xf),
    CMD_T(2,NOTE_C(3),0x7),
    CMD_T(4,NOTE_C(3),0x7),
    CMD_T(6,NOTE_C(3),0x4),
    CMD_T(8,NOTE_C(3),0x7),
    CMD_T(10,NOTE_C(3),0x7),
    CMD_T(12,NOTE_C(3),0xd),
    CMD_T(14,NOTE_B(2),0x1),
    CMD_T(16,NOTE_B(2),0x1),
    CMD_T(18,NOTE_C(2),0x4),
    CMD_T(20,NOTE_C(3),0x7),
    CMD_T(22,NOTE_C(3),0x7),
    CMD_T(24,NOTE_C(3),0xd),
    CMD_T(26,NOTE_B(2),0x1),
    CMD_T(28,NOTE_C(3),0x7),
    CMD_T(30,NOTE_C(3),0x7),
    CMD_T(32,NOTE_C(2),0xf),
    CMD_T(34,NOTE_C(3),0x7),
    CMD_T(36,NOTE_C(3),0x7),
    CMD_T(38,NOTE_C(3),0x4),
    CMD_T(40,NOTE_C(3),0x7),
    CMD_T(42,NOTE_C(3),0x7),
    CMD_T(44,NOTE_C(3),0xd),
    CMD_T(46,NOTE_B(2),0x1),
    CMD_T(48,NOTE_B(2),0x1),
    CMD_T(50,NOTE_C(2),0x4),
    CMD_T(52,NOTE_C(3),0x7),
    CMD_T(54,NOTE_C(3),0x7),
    CMD_T(56,NOTE_C(3),0xd),
    CMD_T(58,NOTE_B(2),0x1),
    CMD_T(60,NOTE_C(3),0x7),
    CMD_T(62,NOTE_C(3),0x7),
};
static const uint32_t cmd_15_3[] = {
    CMD_T(0,NOTE_DS(2),0xc),
    CMD_T(8,NOTE_C(2),0xc),
    CMD_T(12,NOTE_G(2),0xc),
    CMD_T(20,NOTE_C(2),0xc),
    CMD_T(24,NOTE_DS(2),0xc),
    CMD_T(28,NOTE_C(2),0xc)
};

static const uint32_t cmd_16_0[] = {
    CMD_T(0,NOTE_D(2),0xf),
    CMD_T(32,NOTE_E(2),0xf)
};
static const uint32_t cmd_16_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(48,NOTE_A(2),0x6),
    CMD_T(50,NOTE_A(2),0x6),
    CMD_T(52,NOTE_A(2),0x6),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(58,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_16_2[] = {
    CMD_T(0,NOTE_D(2),0xf),
    CMD_T(2,NOTE_C(3),0x7),
    CMD_T(4,NOTE_C(3),0x7),
    CMD_T(6,NOTE_C(3),0x4),
    CMD_T(8,NOTE_C(3),0x7),
    CMD_T(10,NOTE_C(3),0x7),
    CMD_T(12,NOTE_C(3),0xd),
    CMD_T(14,NOTE_B(2),0x1),
    CMD_T(16,NOTE_B(2),0x1),
    CMD_T(18,NOTE_C(2),0x4),
    CMD_T(20,NOTE_C(3),0x7),
    CMD_T(22,NOTE_C(3),0x7),
    CMD_T(24,NOTE_C(3),0xd),
    CMD_T(26,NOTE_B(2),0x1),
    CMD_T(28,NOTE_C(3),0x7),
    CMD_T(30,NOTE_C(3),0x7),
    CMD_T(32,NOTE_C(3),0x7),
    CMD_T(33,NOTE_C(3),0x7),
    CMD_T(34,NOTE_C(3),0x7),
    CMD_T(35,NOTE_C(3),0x7),
    CMD_T(36,NOTE_AS(2),0x7),
    CMD_T(38,NOTE_C(3),0x7),
    CMD_T(41,NOTE_C(3),0x7),
    CMD_T(44,NOTE_AS(2),0x7),
    CMD_T(48,NOTE_C(3),0x7),
    CMD_T(50,NOTE_AS(2),0x7),
    CMD_T(52,NOTE_C(3),0x7),
    CMD_T(54,NOTE_DS(3),0x7),
    CMD_T(56,NOTE_C(3),0x7),
    CMD_T(58,NOTE_C(3),0x7),
    CMD_T(60,NOTE_AS(2),0x7),
    CMD_T(62,NOTE_AS(3),0x7),
};
static const uint32_t cmd_16_3[] = {
    CMD_T(0,NOTE_DS(2),0xc),
    CMD_T(8,NOTE_C(2),0xc),
    CMD_T(12,NOTE_G(2),0xc),
    CMD_T(20,NOTE_C(2),0xc),
    CMD_T(24,NOTE_DS(2),0xc),
    CMD_T(28,NOTE_C(2),0xc)
};

static const uint32_t cmd_17_0[] = {
    CMD_T(0,NOTE_E(2),0xf),
    CMD_T(32,NOTE_C(2),0xf)
};
static const uint32_t cmd_17_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(50,NOTE_A(2),0x5),
    CMD_T(52,NOTE_A(2),0x5),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_17_2[] = {
    CMD_T(0,NOTE_E(2),0xe),
    CMD_T(2,NOTE_E(2),0xe),
    CMD_T(4,NOTE_E(2),0x1e),
    CMD_T(6,NOTE_E(2),0xe),
    CMD_T(8,NOTE_E(2),0xe),
    CMD_T(10,NOTE_E(2),0xe),
    CMD_T(12,NOTE_E(2),0x1e),
    CMD_T(14,NOTE_E(2),0xe),
    CMD_T(16,NOTE_E(2),0xe),
    CMD_T(18,NOTE_E(2),0x1e),
    CMD_T(20,NOTE_E(2),0xe),
    CMD_T(22,NOTE_E(2),0xe),
    CMD_T(24,NOTE_E(2),0x1e),
    CMD_T(26,NOTE_E(2),0xe),
    CMD_T(28,NOTE_E(2),0x1e),
    CMD_T(30,NOTE_E(2),0xe),
    CMD_T(32,NOTE_C(2),0xe),
    CMD_T(34,NOTE_C(2),0xe),
    CMD_T(36,NOTE_C(2),0x1e),
    CMD_T(38,NOTE_C(2),0xe),
    CMD_T(40,NOTE_C(2),0xe),
    CMD_T(42,NOTE_C(2),0xe),
    CMD_T(44,NOTE_C(2),0x1e),
    CMD_T(46,NOTE_C(2),0xe),
    CMD_T(48,NOTE_C(2),0xe),
    CMD_T(50,NOTE_C(2),0x1e),
    CMD_T(52,NOTE_C(2),0xe),
    CMD_T(54,NOTE_C(2),0xe),
    CMD_T(56,NOTE_C(2),0x1e),
    CMD_T(58,NOTE_C(2),0xe),
    CMD_T(60,NOTE_C(2),0x1e),
    CMD_T(62,NOTE_C(2),0xe),
};

static const uint32_t cmd_18_0[] = {
    CMD_T(0,NOTE_D(2),0xf),
    CMD_T(32,NOTE_E(2),0xf)
};
static const uint32_t cmd_18_1[] = {
    CMD_T(0,NOTE_A(2),0x5),
    CMD_T(2,NOTE_A(2),0x5),
    CMD_T(6,NOTE_A(2),0x5),
    CMD_T(8,NOTE_A(2),0x6),
    CMD_T(12,NOTE_A(2),0x5),
    CMD_T(14,NOTE_A(2),0x5),
    CMD_T(18,NOTE_A(2),0x5),
    CMD_T(20,NOTE_A(2),0x5),
    CMD_T(24,NOTE_A(2),0x6),
    CMD_T(28,NOTE_A(2),0x5),
    CMD_T(30,NOTE_A(2),0x6),
    CMD_T(32,NOTE_A(2),0x5),
    CMD_T(34,NOTE_A(2),0x5),
    CMD_T(38,NOTE_A(2),0x5),
    CMD_T(40,NOTE_A(2),0x6),
    CMD_T(44,NOTE_A(2),0x5),
    CMD_T(46,NOTE_A(2),0x5),
    CMD_T(50,NOTE_A(2),0x5),
    CMD_T(52,NOTE_A(2),0x5),
    CMD_T(56,NOTE_A(2),0x6),
    CMD_T(60,NOTE_A(2),0x5),
    CMD_T(62,NOTE_A(2),0x6)
};
static const uint32_t cmd_18_2[] = {
    CMD_T(0,NOTE_D(2),0xe),
    CMD_T(2,NOTE_D(2),0xe),
    CMD_T(4,NOTE_D(2),0x1e),
    CMD_T(6,NOTE_D(2),0xe),
    CMD_T(8,NOTE_D(2),0xe),
    CMD_T(10,NOTE_D(2),0xe),
    CMD_T(12,NOTE_D(2),0x1e),
    CMD_T(14,NOTE_D(2),0xe),
    CMD_T(16,NOTE_D(2),0xe),
    CMD_T(18,NOTE_D(2),0x1e),
    CMD_T(20,NOTE_D(2),0xe),
    CMD_T(22,NOTE_D(2),0xe),
    CMD_T(24,NOTE_D(2),0x1e),
    CMD_T(26,NOTE_D(2),0xe),
    CMD_T(28,NOTE_D(2),0x1e),
    CMD_T(30,NOTE_D(2),0xe),
    CMD_T(32,NOTE_E(2),0xe),
    CMD_T(34,NOTE_E(2),0xe),
    CMD_T(36,NOTE_E(2),0x1e),
    CMD_T(38,NOTE_E(2),0xe),
    CMD_T(40,NOTE_E(2),0xe),
    CMD_T(42,NOTE_E(2),0xe),
    CMD_T(44,NOTE_E(2),0x1e),
    CMD_T(46,NOTE_E(2),0xe),
    CMD_T(48,NOTE_E(2),0xe),
    CMD_T(50,NOTE_E(2),0x1e),
    CMD_T(52,NOTE_E(2),0xe),
    CMD_T(54,NOTE_E(2),0xe),
    CMD_T(56,NOTE_E(2),0x1e),
    CMD_T(58,NOTE_E(2),0xe),
    CMD_T(60,NOTE_E(2),0x1e),
    CMD_T(62,NOTE_E(2),0xe),
};
static const uint32_t cmd_18_3[] = {
    CMD_T(0,NOTE_F(2),0xc),
    CMD_T(8,NOTE_DS(2),0xc),
    CMD_T(12,NOTE_D(2),0xc),
    CMD_T(20,NOTE_AS(1),0xc),
    CMD_T(32,NOTE_DS(2),0xc),
    CMD_T(40,NOTE_G(2),0xc),
    CMD_T(44,NOTE_C(2),0xc)
};

#define CMD_LEN(X) sizeof(X)/sizeof(X[0])
#define EMPTY_CMD {NULL,0}
#define NE_CMD(X) {X,CMD_LEN(X)}
const Pattern_t cdata_keil_patterns[19] = {
    {
        {
            EMPTY_CMD,EMPTY_CMD,EMPTY_CMD,NE_CMD(cmd_0_3)
        }
    },
    {
        {
            NE_CMD(cmd_1_0),NE_CMD(cmd_1_1),NE_CMD(cmd_1_2),NE_CMD(cmd_1_3)
        }
    },
    {
        {
            NE_CMD(cmd_2_0),NE_CMD(cmd_2_1),NE_CMD(cmd_2_2),NE_CMD(cmd_2_3)
        }
    },
    {
        {
            NE_CMD(cmd_3_0),NE_CMD(cmd_3_1),NE_CMD(cmd_3_2),NE_CMD(cmd_3_3)
        }
    },
    {
        {
            NE_CMD(cmd_4_0),NE_CMD(cmd_4_1),NE_CMD(cmd_4_2),NE_CMD(cmd_4_3)
        }
    },
    {
        {
            NE_CMD(cmd_5_0),NE_CMD(cmd_5_1),NE_CMD(cmd_5_2),NE_CMD(cmd_5_3)
        }
    },
    {
        {
            NE_CMD(cmd_6_0),NE_CMD(cmd_6_1),NE_CMD(cmd_6_2),NE_CMD(cmd_6_3)
        }
    },
    {
        {
            NE_CMD(cmd_7_0),NE_CMD(cmd_7_1),NE_CMD(cmd_7_2),NE_CMD(cmd_7_3)
        }
    },
    {
        {
            NE_CMD(cmd_8_0),NE_CMD(cmd_8_1),NE_CMD(cmd_8_2),NE_CMD(cmd_8_3)
        }
    },
    {
        {
            NE_CMD(cmd_9_0),NE_CMD(cmd_9_1),NE_CMD(cmd_9_2),NE_CMD(cmd_9_3)
        }
    },
    {
        {
            NE_CMD(cmd_10_0),NE_CMD(cmd_10_1),NE_CMD(cmd_10_2),NE_CMD(cmd_10_3)
        }
    },
    {
        {
            NE_CMD(cmd_11_0),NE_CMD(cmd_11_1),NE_CMD(cmd_11_2),NE_CMD(cmd_11_3)
        }
    },
    {
        {
            NE_CMD(cmd_12_0),NE_CMD(cmd_12_1),NE_CMD(cmd_12_2),EMPTY_CMD
        }
    },
    {
        {
            NE_CMD(cmd_13_0),NE_CMD(cmd_13_1),NE_CMD(cmd_13_2),EMPTY_CMD
        }
    },
    {
        {
            NE_CMD(cmd_14_0),NE_CMD(cmd_14_1),NE_CMD(cmd_14_2),EMPTY_CMD
        }
    },
    {
        {
            NE_CMD(cmd_15_0),NE_CMD(cmd_15_1),NE_CMD(cmd_15_2),NE_CMD(cmd_15_3)
        }
    },
    {
        {
            NE_CMD(cmd_16_0),NE_CMD(cmd_16_1),NE_CMD(cmd_16_2),NE_CMD(cmd_16_3)
        }
    },
    {
        {
            NE_CMD(cmd_17_0),NE_CMD(cmd_17_1),NE_CMD(cmd_17_2),EMPTY_CMD
        }
    },
    {
        {
            NE_CMD(cmd_18_0),NE_CMD(cmd_18_1),NE_CMD(cmd_18_2),NE_CMD(cmd_18_3)
        }
    }
};

//static const char* sample_names[] = {
//    "1_b.wav","2_b.wav","4_b.wav","5_b.wav","6_b.wav","7_b.wav","c_b.wav","d_b.wav","e_b.wav","f_b.wav","1e_b.wav"
//};

static const uint8_t cdata_keil_sample_1[] = {
    0b11111100,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11001111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b10011111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111111,0b11111111,0b11111111,0b11001111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11100111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11001111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110011,0b11111111,0b11111111,0b11111111,0b11111100,0b11111111,0b11111111,0b00111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111001,0b11111111,0b11111111,0b01111111,0b11111110,0b11111111,0b11111111,0b10011111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111100,0b11111111,0b11111111,0b00111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b11111111,0b01111111,0b11111110,0b11111111,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11100111,0b11111111,0b11111111,0b11111111,0b11111001,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b11001111,0b11111111,0b11111111,0b11111111,0b11110011,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b10011111,0b11111111,0b11111111,0b11111111,0b11100111,0b11111111,0b11111111,0b11111111,0b11111001,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11100111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11001111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b10011111,0b11111111,0b11111111,0b11111111,0b11001111,0b11111111,0b11111111,0b11111111,0b11110011,0b11111111,0b11111111,0b11111111,0b11111100,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11100111,0b11111111,0b11111111,0b11111111,0b11111001,0b11111111,0b11111111,0b01111111,0b11111110,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11110011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111100,0b11111111,0b11111111,0b00111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111001,0b11111111,0b11111111,0b01111111,0b11111110,0b11111111,0b11111111,0b10011111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111100,0b11111111,0b11111111,0b00111111,0b11111111,0b11111111,0b11111111,0b11001111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b01111111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111001,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,
};
static const uint8_t cdata_keil_sample_2[] = {
    0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11011011,0b00110110,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01101111,0b01011011,0b10010010,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b01001011,0b10010010,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11011011,0b10010010,0b00000100,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b01011011,0b10010010,0b00000100,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11011011,0b10010010,0b00000100,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11011011,0b10010110,0b00000100,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11011011,0b10010010,0b00000100,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11011011,0b10010010,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11011011,0b10010010,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11011011,0b10110010,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11011011,0b00010010,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01101111,0b00011011,0b00000010,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01101111,0b11000011,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b01001101,0b01010010,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b01001001,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10111111,0b00000101,0b10010000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010111,0b01001000,0b10010010,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010111,0b01001001,0b10010010,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10010111,0b01001000,0b10010010,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010110,0b01001001,0b00010010,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010111,0b01001000,0b10010010,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010111,0b01001001,0b00000010,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10010111,0b01001000,0b10010010,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10111111,0b00000100,0b10010010,0b00000100,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10111111,0b01000100,0b10010010,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00100101,0b10010000,0b00100000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00101111,0b10010000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b10000001,0b00100100,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01000101,0b00000010,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10111111,0b01001000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10111111,0b00001000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00100010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11011111,0b00000100,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000100,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00100010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000100,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000100,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01001111,0b00000100,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01011111,0b00000100,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00100010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000100,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000100,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00010001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00101111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00100111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000
};
static const uint8_t cdata_keil_sample_4[] = {
    0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b00000011,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b11110000,0b00000001,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00100111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00100111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00010010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01000101,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10111111,0b00001001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01011011,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b11101000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b11101000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b11110100,0b11111111,0b11111111,0b00000001
};
static const uint8_t cdata_keil_sample_5[] = {
    0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b01111000,0b01111000,0b00001110,0b00011100,0b00111000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b01110000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,
};
static const uint8_t cdata_keil_sample_6[] = {
    0b11111100,0b11111111,0b11111111,0b01111011,0b00111100,0b00111100,0b00001100,0b10000111,0b11100111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11110111,0b00100000,0b00000000,0b00000000,0b01000000,0b11111100,0b11111111,0b11111111,0b11111111,0b10001111,0b00000011,0b00000001,0b00000000,0b00000000,0b01111000,0b11111100,0b11111111,0b11111111,0b11111111,0b00011111,0b00000110,0b10000001,0b00000001,0b00000000,0b00000000,0b11000011,0b11110111,0b11111111,0b11111111,0b11111111,0b00111001,0b00001000,0b10000110,0b11000001,0b00100000,0b00011100,0b00000110,0b01110000,0b01111100,0b11111110,0b11111111,0b01111111,0b00011100,0b00001110,0b11000011,0b01100001,0b00110000,0b10000100,0b01111000,0b01111000,0b11111100,0b10011110,0b11001111,0b11111111,0b11111111,0b11110111,0b11010111,0b11011111,0b00111000,0b00110000,0b00111000,0b00001000,0b10000100,0b10000011,0b00001111,0b00001111,0b00001111,0b10011110,0b11000111,0b11100011,0b11100011,0b11100011,0b11100001,0b11110001,0b01111000,0b11111100,0b11100000,0b11100001,0b11100001,0b11100011,0b11100000,0b01110000,0b00111000,0b00011100,0b11000110,0b10000111,0b10000111,0b10000111,0b10000111,0b11000011,0b11111011,0b11110001,0b11100011,0b11000111,0b10001111,0b00001111,0b00001110,0b00001110,0b00001111,0b00011100,0b00011100,0b00111100,0b00111100,0b00111100,0b00011110,0b00011111,0b00001111,0b11000111,0b11111111,0b01110001,0b11000111,0b00011101,0b01111111,0b01111000,0b01111000,0b11110000,0b11110000,0b01111010,0b01111100,0b01111000,0b01111000,0b11111000,0b10111000,0b01100011,0b11000110,0b11111000,0b01110001,0b11100000,0b00010001,0b11100111,0b11000111,0b00011111,0b00001110,0b01111110,0b10011100,0b11110011,0b10011110,0b01111111,0b00011110,0b00000111,0b11000111,0b10001111,0b00011111,0b00001110,0b10011000,0b11110000,0b11110000,0b00100001,0b11000111,0b11100001,0b11100001,0b00010000,0b11001111,0b11000101,0b11100001,0b11100011,0b11100000,0b11110001,0b11100011,0b10001111,0b01001111,0b11111100,0b01111000,0b11111000,0b11111000,0b10110001,0b00000011,0b10001111,0b10000111,0b00011110,0b01111000,0b11110000,0b11100000,0b10000111,0b00001111,0b00001111,0b00011110,0b00111110,0b00011100,0b00111011,0b11111100,0b11110000,0b11110000,0b01111000,0b11111000,0b11010001,0b10001111,0b10001111,0b00011111,0b00011110,0b00011110,0b00011110,0b11100111,0b10000001,0b00000111,0b00001111,0b00011110,0b00111110,0b00111100,0b01111000,0b11111000,0b00111000,0b01111110,0b01111100,0b11110000,0b10000111,0b01111111,0b01111100,0b11111000,0b11110000,0b11110000,0b11100001,0b11110001,0b11110000,0b01111000,0b01111000,0b11110000,0b11100001,0b11000011,0b10000111,0b00000111,0b11011111,0b11100001,0b10000011,0b00011111,0b00111110,0b01111100,0b11100000,0b10000111,0b10000111,0b00000111,0b00011111,0b01111100,0b01111000,0b01111000,0b11110000,0b11100001,0b11100001,0b11000001,0b10000011,0b00000111,0b00001111,0b00001111,0b00011110,0b00111110,0b11111000,0b11111000,0b11111001,0b11110000,0b11100000,0b11110001,0b11100001,0b11000011,0b10000111,0b10000111,0b10000111,0b00001111,0b00011111,0b01111100,0b11111000,0b11100000,0b11000001,0b10000111,0b00011111,0b01111100,0b11111000,0b11100000,0b11000001,0b10000111,0b11111111,0b00000011,0b00011111,0b11111000,0b00000001,0b11111100,0b10000011,0b00011111,0b00111110,0b11111000,0b11100001,0b00000111,0b00111111,0b11111100,0b11111000,0b11100111,0b01111001,0b11111000,0b11110000,0b11100011,0b11111111,0b11110001,0b11000001,0b11000111,0b10000111,0b10111111,0b11111111,0b10001111,0b00111111,0b11111111,0b00011111,0b01111100,0b11111000,0b11110000,0b11111111,0b11111111,0b11111000,0b11110011,0b11111111,0b11001111,0b11111111,0b11111000,0b00001111,0b01000111,0b00010000,0b01111000,0b11000000,0b00000111,0b01111110,0b11100000,0b00000111,0b11100111,0b01111101,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011
};
static const uint8_t cdata_keil_sample_7[] = {
    0b11111100,0b11111111,0b01111111,0b11001110,0b10001000,0b11111000,0b01111111,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b00000000,0b00000000,0b11110000,0b11111111,0b00111111,0b00000000,0b00000000,0b11111100,0b11111111,0b00110011,0b00000000,0b00000000,0b11111110,0b11111111,0b00110111,0b00000010,0b00000000,0b11111010,0b11111111,0b11111111,0b00010011,0b00000010,0b00010010,0b11101100,0b11111111,0b11111111,0b00010011,0b00000001,0b00000000,0b10001000,0b11111111,0b11111111,0b01101111,0b00100010,0b00100001,0b00010010,0b10000000,0b11011101,0b11111111,0b01100110,0b01100110,0b01100010,0b00000010,0b00001001,0b11011011,0b11111101,0b11111111,0b11111111,0b01111111,0b01100010,0b00000000,0b00110010,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00010010,0b10000001,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11011011,0b11011111,0b11000100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110000,0b11111111,0b11111111,0b11111111,0b00000001,0b01000000,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11100001,0b11111111,0b11111111,0b10000001,0b11111111,0b11111111,0b11111111,0b11111111,0b11100001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11100001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b11101000,0b11100001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00001111,0b11111101,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b00011111,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111
};
static const uint8_t cdata_keil_sample_c[] = {
    0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111100,0b11111111,0b01111111,0b00000000,0b11111000,0b00001111,0b00000000,0b00000000,0b11111000,0b00111111,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b01111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b01111000,0b10100000,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111100,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11111000,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111100,0b11111111,0b11111111,0b00111111,0b11111100,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b00111111,0b11111110,0b11111111,0b11111111,0b00011111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b10001111,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b11000111,0b11111111,0b11111111,0b11111111,0b11100011,0b11111111,0b11111111,0b11111111,0b11100001,0b11111111,0b11111111,0b11111111,0b11110001,0b11111111,0b11111111,0b01111111,0b11111000,0b11111111,0b11111111,0b01111111,0b11111000,0b11111111,0b11111111,0b00111111,0b11111100,0b11111111,0b11111111,0b00011111,0b11111100,0b11111111,0b11111111,0b00011111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b10000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11100001,0b11111111,0b11111111,0b11111111,0b11100001,0b11111111,0b11111111,0b11111111,0b11110000,0b11111111,0b11111111,0b01111111,0b11110000,0b11111111,0b11111111,0b01111111,0b11111000,0b11111111,0b11111111,0b00111111,0b11111100,0b11111111,0b11111111,0b00111111,0b11111100,0b11111111,0b11111111,0b00011111,0b11111110,0b11111111,0b11111111,0b00011111,0b11111110,0b11111111,0b11111111,0b00011111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b10000011,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111110,0b11111111,0b11111111,0b00011111,0b11111100,0b11111111,0b11111111,0b00111111,0b11111100,0b11111111,0b11111111,0b01111111,0b11111000,0b11111111,0b11111111,0b01111111,0b11111000,0b11111111,0b11111111,0b11111111,0b11110000,0b11111111,0b11111111,0b11111111,0b11110000,0b11111111,0b11111111,0b11111111,0b11100000,0b11111111,0b11111111,0b11111111,0b11100001,0b11111111,0b11111111,0b11111111,0b11100001,0b11111111,0b11111111,0b11111111,0b11100001,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b10000011,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b00000111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b00001111,0b11111111,0b11111111,0b11111111,0b00011111,0b11111110,0b11111111,0b11111111,0b00011111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111111,0b11111111,0b11111111,0b00000111,0b11111111,0b11111111,0b11111111,0b00000111,0b11111111,0b11111111,0b11111111,0b10000111,0b11111111,0b11111111,0b11111111,0b10000011,0b11111111,0b11111111,0b11111111,0b10000011,0b11111111,0b11111111,0b11111111,0b10000011,0b11111111,0b11111111,0b11111111,0b11000001,0b11111111,0b11111111,0b11111111,0b11000001,0b11111111,0b11111111,0b11111111,0b11000001,0b11111111,0b11111111,0b11111111,0b11100000,0b11111111,0b11111111,0b11111111,0b11110000,0b11111111,0b11111111,0b01111111,0b11110000,0b11111111,0b11111111,0b00111111,0b11111000,0b11111111,0b11111111,0b00111111,0b11111000,0b11111111,0b11111111,0b00011111,0b11111100,0b11111111,0b11111111,0b00011111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111111,0b11111111,0b11111111,0b00000111,0b11111111,0b11111111,0b11111111,0b10000011,0b11111111,0b11111111,0b11111111,0b11000011,0b11111111,0b11111111,0b11111111,0b11000001,0b11111111,0b11111111,0b11111111,0b11000001,0b11111111,0b11111111,0b11111111,0b11100000,0b11111111,0b11111111,0b11111111,0b11100000,0b11111111,0b11111111,0b11111111,0b11100000,0b11111111,0b11111111,0b11111111,0b11100000,0b11111111,0b11111111,0b01111111,0b11110000,0b11111111,0b11111111,0b01111111,0b11110000,0b11111111,0b11111111,0b01111111,0b11110000,0b11111111,0b11111111,0b00111111,0b11111000,0b11111111,0b11111111,0b00111111,0b11111000,0b11111111,0b11111111,0b00111111,0b11111000,0b11111111,0b11111111,0b00011111,0b11111100,0b11111111,0b11111111,0b00011111,0b11111100,0b11111111,0b11111111,0b00011111,0b11111100,0b11111111,0b11111111,0b00011111,0b11111100,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111110,0b11111111,0b11111111,0b00001111,0b11111100,0b11111111,0b11111111,0b00001111,0b11111100,0b11111111,0b11111111,0b00001111,0b11111100,0b11111111,0b11111111,0b00001111,0b11111100,0b11111111,0b11111111,0b00011111,0b11111000,0b11111111,0b11111111,0b00011111,0b11111000,0b11111111,0b11111111,0b00011111,0b11111000,0b11111111,0b11111111,0b00111111,0b11110000,0b11111111,0b11111111,0b00111111,0b11110000,0b11111111,0b11111111,0b00111111,0b11110000,0b11111111,0b11111111,0b01111111,0b11100000,0b11111111,0b11111111,0b01111111,0b11100000,0b11111111,0b11111111,0b11111111,0b11000000,0b11111111,0b11111111,0b11111111,0b11000001,0b11111111,0b11111111,0b11111111,0b10000001,0b11111111,0b11111111,0b11111111,0b10000001,0b11111111,0b11111111,0b11111111,0b10000011,0b11111111,0b11111111,0b11111111,0b00000011,0b11111111,0b11111111,0b11111111,0b00000011,0b11111111,0b11111111,0b11111111,0b00000011,0b11111111,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000011,0b11111111,0b11111111,0b11111111,0b00000011,0b11111111,0b11111111,0b11111111,0b00000011,0b11111111,0b11111111,0b11111111,0b10000011,0b11111111,0b11111111,0b11111111,0b10000001,0b11111111,0b11111111,0b11111111,0b10000001,0b11111111,0b11111111,0b11111111,0b11000001,0b11111111,0b11111111,0b11111111,0b11000000,0b11111111,0b11111111,0b11111111,0b11000000,0b11111111,0b11111111,0b11111111,0b11000000,0b11111111,0b11111111,0b11111111,0b11100000,0b11111111,0b11111111,0b01111111,0b11100000,0b11111111,0b11111111,0b00111111,0b11110000,0b11111111,0b11111111,0b00111111,0b11110000,0b11111111,0b11111111,0b00011111,0b11111000,0b11111111,0b11111111,0b00011111,0b11111100,0b11111111,0b11111111,0b00001111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000011,0b11111111,0b11111111,0b11111111,0b10000011,0b11111111,0b11111111,0b11111111,0b10000001,0b11111111,0b11111111,0b01111111,0b11000000,0b11111111,0b11111111,0b01111111,0b11100000,0b11111111,0b11111111,0b00111111,0b11100000,0b11111111,0b11111111,0b00111111,0b11110000,0b11111111,0b11111111,0b00011111,0b11110000,0b11111111,0b11111111,0b00011111,0b11110000,0b11111111,0b11111111,0b00011111,0b11111000,0b11111111,0b11111111,0b00001111,0b11111000,0b11111111,0b11111111,0b00001111,0b11111000,0b11111111,0b11111111,0b00001111,0b11111000,0b11111111,0b11111111,0b00001111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00001111,0b11111100,0b11111111,0b11111111,0b00001111,0b11111000,0b11111111,0b11111111,0b00001111,0b11111000,0b11111111,0b11111111,0b00001111,0b11111000,0b11111111,0b11111111,0b00011111,0b11110000,0b11111111,0b11111111,0b00011111,0b11110000,0b11111111,0b11111111,0b00011111,0b11110000,0b11111111,0b11111111,0b00111111,0b11110000,0b11111111,0b11111111,0b00111111,0b11100000,0b11111111,0b11111111,0b00111111,0b11100000,0b11111111,0b11111111,0b01111111,0b11100000,0b11111111,0b11111111,0b01111111,0b11000000,0b11111111,0b11111111,0b11111111,0b11000000,0b11111111,0b11111111,0b11111111,0b10000000,0b11111111,0b11111111,0b11111111,0b00000001,0b11111111,0b11111111,0b11111111,0b00000001,0b11111111,0b11111111,0b11111111,0b00000011,0b11111110,0b11111111,0b11111111,0b00000111,0b11111110,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00001111,0b11111000,0b11111111,0b11111111,0b00001111,0b11111000,0b11111111,0b11111111,0b00011111,0b11110000,0b11111111,0b11111111,0b00011111,0b11110000,0b11111111,0b11111111,0b00111111,0b11110000,0b11111111,0b11111111,0b00111111,0b11100000,0b11111111,0b11111111,0b00111111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11110000,0b11111111,0b11111111,0b00011111,0b11110000,0b11111111,0b11111111,0b00001111,0b11110000,0b11111111,0b11111111,0b00001111,0b11111000,0b11111111,0b11111111,0b00001111,0b11111000,0b11111111,0b11111111,0b00000111,0b11111000,0b11111111,0b11111111,0b00000111,0b11111000,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000011,0b11111100,0b11111111,0b11111111,0b00000011,0b11111100,0b11111111,0b11111111,0b00000011,0b11111110,0b11111111,0b11111111,0b00000011,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111111,0b11111111,0b11111111,0b00000001,0b11111111,0b11111111,0b11111111,0b00000000,0b11111111,0b11111111,0b11111111,0b00000000,0b11111111,0b11111111,0b01111111,0b10000000,0b11111111,0b11111111,0b01111111,0b11000000,0b11111111,0b11111111,0b00111111,0b11000000,0b11111111,0b11111111,0b00111111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00001111,0b11110000,0b11111111,0b11111111,0b00001111,0b11111000,0b11111111,0b11111111,0b00000111,0b11111000,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000011,0b11111100,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111111,0b11111111,0b11111111,0b00000000,0b11111111,0b11111111,0b11111111,0b10000000,0b11111111,0b11111111,0b01111111,0b10000000,0b11111111,0b11111111,0b00111111,0b11000000,0b11111111,0b11111111,0b00111111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11110000,0b11111111,0b11111111,0b00001111,0b11110000,0b11111111,0b11111111,0b00000111,0b11111000,0b11111111,0b11111111,0b00000111,0b11111100,0b11111111,0b11111111,0b00000011,0b11111100,0b11111111,0b11111111,0b00000011,0b11111110,0b11111111,0b11111111,0b00000011,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b00000001,0b11111110,0b11111111,0b11111111,0b00000001,0b11111100,0b11111111,0b11111111,0b00000001,0b11111100,0b11111111,0b11111111,0b00000011,0b11111100,0b11111111,0b11111111,0b00000011,0b11111100,0b11111111,0b11111111,0b00000011,0b11111000,0b11111111,0b11111111,0b00000011,0b11111000,0b11111111,0b11111111,0b00000111,0b11111000,0b11111111,0b11111111,0b00000111,0b11110000,0b11111111,0b11111111,0b00000111,0b11110000,0b11111111,0b11111111,0b00001111,0b11110000,0b11111111,0b11111111,0b00001111,0b11100000,0b11111111,0b11111111,0b00001111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11000000,0b11111111,0b11111111,0b00111111,0b10000000,0b11111111,0b11111111,0b01111111,0b10000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b11111111,0b00000000,0b11111111,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b00000001,0b11111100,0b11111111,0b11111111,0b00000011,0b11111100,0b11111111,0b11111111,0b00000011,0b11111000,0b11111111,0b11111111,0b00000111,0b11111000,0b11111111,0b11111111,0b00000111,0b11110000,0b11111111,0b11111111,0b00001111,0b11100000,0b11111111,0b11111111,0b00001111,0b11100000,0b11111111,0b11111111,0b00011111,0b11100000,0b11111111,0b11111111,0b00011111,0b11000000,0b11111111,0b11111111,0b00011111,0b11000000,0b11111111,0b11111111,0b00111111,0b11000000,0b11111111,0b11111111,0b00111111,0b10000000,0b11111111,0b11111111,0b00111111,0b10000000,0b11111111,0b11111111,0b00111111,0b10000000,0b11111111,0b11111111,0b01111111,0b10000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b00111111,0b10000000,0b11111111,0b11111111,0b00111111,0b10000000,0b11111111,0b11111111,0b00011111,0b10000000,0b11111111,0b11111111,0b00011111,0b11000000,0b11111111,0b11111111,0b00011111,0b11000000,0b11111111,0b11111111,0b00001111,0b11000000,0b11111111,0b11111111,0b00001111,0b11000000,0b11111111,0b11111111,0b00001111,0b11100000,0b11111111,0b11111111,0b00000111,0b11100000,0b11111111,0b11111111,0b00000111,0b11110000,0b11111111,0b11111111,0b00000011,0b11111000,0b11111111,0b11111111,0b00000011,0b11111000,0b11111111,0b11111111,0b00000001,0b11111100,0b11111111,0b11111111,0b00000000,0b11111100,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b00111111,0b10000000,0b11111111,0b11111111,0b00011111,0b10000000,0b11111111,0b11111111,0b00011111,0b11000000,0b11111111,0b11111111,0b00001111,0b11100000,0b11111111,0b11111111,0b00001111,0b11100000,0b11111111,0b11111111,0b00000111,0b11110000,0b11111111,0b11111111,0b00000011,0b11110000,0b11111111,0b11111111,0b00000011,0b11111000,0b11111111,0b11111111,0b00000001,0b11111100,0b11111111,0b11111111,0b00000001,0b11111100,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b01111111,0b00000000,0b11111110,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b00111111,0b10000000,0b11111111,0b11111111,0b00111111,0b10000000,0b11111111,0b11111111,0b00011111,0b11000000,0b11111111,0b11111111,0b00001111,0b11000000,0b11111111,0b11111111,0b00001111,0b11100000,0b11111111,0b11111111,0b00000111,0b11110000,0b11111111,0b11111111,0b00000111,0b11110000,0b11111111,0b11111111,0b00000011,0b11111000,0b11111111,0b11111111,0b00000011,0b11111000,0b11111111,0b11111111,0b00000001,0b11111000,0b11111111,0b11111111,0b00000001,0b11111000,0b11111111,0b11111111,0b00000001,0b11111100,0b11111111,0b11111111,0b00000000,0b11111100,0b11111111,0b11111111,0b00000000,0b11111100,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b01111111,0b00000000,0b11111110,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111111,0b11111111,0b01111111,0b00000000,0b11111110,0b11111111,0b01111111,0b00000000,0b11111110,0b11111111,0b11111111,0b00000000,0b11111110,0b11111111,0b11111111,0b00000000,0b11111100,0b11111111,0b11111111,0b00000000,0b11111100,0b11111111,0b11111111,0b00000001,0b11111100,0b11111111,0b11111111,0b00000001,0b11111000,0b11111111,0b11111111,0b00000001,0b11111000,0b11111111,0b11111111,0b00000011,0b11111000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000011,0b11110000,0b11111111,0b11111111,0b00000011,0b11100000,0b11111111,0b11111111,0b00000111,0b11000000,0b11111111,0b11111111,0b00001111,0b11000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00011111,0b10000000,0b11111111,0b11111111,0b00011111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111110,0b11111111,0b01111111,0b00000000,0b11111110,0b11111111,0b01111111,0b00000000,0b11111100,0b11111111,0b11111111,0b00000000,0b11111100,0b11111111,0b11111111,0b00000000,0b11111000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000011,0b11110000,0b11111111,0b11111111,0b00000011,0b11100000,0b11111111,0b11111111,0b00000011,0b11100000,0b11111111,0b11111111,0b00000111,0b11100000,0b11111111,0b11111111,0b00000111,0b11000000,0b11111111,0b11111111,0b00000111,0b11000000,0b11111111,0b11111111,0b00001111,0b11000000,0b11111111,0b11111111,0b00001111,0b11000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00011111,0b10000000,0b11111111,0b11111111,0b00011111,0b10000000,0b11111111,0b11111111,0b00011111,0b00000000,0b11111111,0b11111111,0b00011111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00011111,0b00000000,0b11111111,0b11111111,0b00011111,0b10000000,0b11111111,0b11111111,0b00011111,0b10000000,0b11111111,0b11111111,0b00001111,0b11000000,0b11111111,0b11111111,0b00000111,0b11000000,0b11111111,0b11111111,0b00000111,0b11100000,0b11111111,0b11111111,0b00000011,0b11110000,0b11111111,0b11111111,0b00000011,0b11110000,0b11111111,0b11111111,0b00000001,0b11111000,0b11111111,0b11111111,0b00000000,0b11111000,0b11111111,0b11111111,0b00000000,0b11111100,0b11111111,0b01111111,0b00000000,0b11111110,0b11111111,0b01111111,0b00000000,0b11111110,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00011111,0b00000000,0b11111111,0b11111111,0b00011111,0b10000000,0b11111111,0b11111111,0b00001111,0b11000000,0b11111111,0b11111111,0b00001111,0b11000000,0b11111111,0b11111111,0b00000111,0b11100000,0b11111111,0b11111111,0b00000011,0b11100000,0b11111111,0b11111111,0b00000011,0b11110000,0b11111111,0b11111111,0b00000001,0b11111000,0b11111111,0b11111111,0b00000001,0b11111000,0b11111111,0b11111111,0b00000000,0b11111100,0b11111111,0b01111111,0b00000000,0b11111100,0b11111111,0b01111111,0b00000000,0b11111110,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00111111,0b00000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b11000000,0b11111111,0b11111111,0b00000111,0b11000000,0b11111111,0b11111111,0b00000011,0b11000000,0b11111111,0b11111111,0b00000011,0b11100000,0b11111111,0b11111111,0b00000011,0b11100000,0b11111111,0b11111111,0b00000011,0b11100000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11100000,0b11111111,0b11111111,0b00000001,0b11100000,0b11111111,0b11111111,0b00000011,0b11100000,0b11111111,0b11111111,0b00000011,0b11000000,0b11111111,0b11111111,0b00000111,0b11000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00001111,0b00000000,0b11111111,0b11111111,0b00011111,0b00000000,0b11111111,0b11111111,0b00011111,0b00000000,0b11111110,0b11111111,0b00111111,0b00000000,0b11111110,0b11111111,0b00111111,0b00000000,0b11111100,0b11111111,0b01111111,0b00000000,0b11111100,0b11111111,0b01111111,0b00000000,0b11111000,0b11111111,0b11111111,0b00000000,0b11111000,0b11111111,0b11111111,0b00000000,0b11111000,0b11111111,0b11111111,0b00000000,0b11110000,0b11111111,0b11111111,0b00000000,0b11110000,0b11111111,0b11111111,0b00000001,0b11110000,0b11111111,0b11111111,0b00000001,0b11100000,0b11111111,0b11111111,0b00000001,0b11100000,0b11111111,0b11111111,0b00000011,0b11100000,0b11111111,0b11111111,0b00000011,0b11100000,0b11111111,0b11111111,0b00000011,0b11000000,0b11111111,0b11111111,0b00000111,0b11000000,0b11111111,0b11111111,0b00000111,0b11000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00001111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b11000000,0b11111111,0b11111111,0b00000011,0b11000000,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b00000001,0b11100000,0b11111111,0b11111111,0b00000001,0b11100000,0b11111111,0b11111111,0b00000001,0b11100000,0b11111111,0b11111111,0b00000000,0b11110000,0b11111111,0b11111111,0b00000000,0b11110000,0b11111111,0b11111111,0b00000000,0b11110000,0b11111111,0b01111111,0b00000000,0b11111000,0b11111111,0b00111111,0b00000000,0b11111100,0b11111111,0b00111111,0b00000000,0b11111100,0b11111111,0b00011111,0b00000000,0b11111110,0b11111111,0b00011111,0b00000000,0b11111110,0b11111111,0b00001111,0b00000000,0b11111111,0b11111111,0b00000111,0b00000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000011,0b11000000,0b11111111,0b11111111,0b00000011,0b11000000,0b11111111,0b11111111,0b00000001,0b11100000,0b11111111,0b11111111,0b00000001,0b11100000,0b11111111,0b11111111,0b00000000,0b11110000,0b11111111,0b11111111,0b00000000,0b11110000,0b11111111,0b01111111,0b00000000,0b11110000,0b11111111,0b01111111,0b00000000,0b11111000,0b11111111,0b01111111,0b00000000,0b11111000,0b11111111,0b00111111,0b00000000,0b11111000,0b11111111,0b00111111,0b00000000,0b11111100,0b11111111,0b00111111,0b00000000,0b11111100,0b11111111,0b00111111,0b00000000,0b11111100,0b11111111,0b00011111,0b00000000,0b11111110,0b11111111,0b00011111,0b00000000,0b11111110,0b11111111,0b00011111,0b00000000,0b11111110,0b11111111,0b00001111,0b00000000,0b11111110,0b11111111,0b00001111,0b00000000,0b11111111,0b11111111,0b00001111,0b00000000,0b11111111,0b11111111,0b00001111,0b00000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b10000000,0b11111111,0b11111111,0b00000111,0b00000000,0b11111111,0b11111111,0b00000111,0b00000000,0b11111111,0b11111111,0b00001111,0b00000000,0b11111111,0b11111111,0b00001111,0b00000000,0b11111111,0b11111111,0b00001111,0b00000000,0b11111110,0b11111111,0b00011111,0b00000000,0b11111110,0b11111111,0b00011111,0b00000000,0b11111110,0b11111111,0b00011111,0b00000000,0b11111100,0b11111111,0b00111111,0b00000000,0b11111100,0b11111111,0b00111111,0b00000000,0b11111100,0b11111111,0b00111111,0b00000000,0b11111000,0b11111111,0b00111111,0b00000000,0b11111000,0b11111111,0b00111111,0b00000000,0b11110000,0b11111111,0b01111111,0b00000000,0b11110000,0b11111111,0b01111111,0b00000000,0b11100000,0b11111111,0b11111111,0b00000000,0b11100000,0b11111111,0b11111111,0b00000000,0b11100000,0b11111111,0b11111111,0b00000000,0b11000000,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b00000001,0b10000000,0b11111111,0b11111111,0b00000001,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000001,0b10000000,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b00000000,0b11100000,0b11111111,0b11111111,0b00000000,0b11100000,0b11111111,0b11111111,0b00000000,0b11100000,0b11111111,0b01111111,0b00000000,0b11110000,0b11111111,0b01111111,0b00000000,0b11110000,0b11111111,0b01111111,0b00000000,0b11110000,0b11111111,0b00111111,0b00000000,0b11110000,0b11111111,0b00111111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111100,0b11111111,0b00011111,0b00000000,0b11111100,0b11111111,0b00001111,0b00000000,0b11111110,0b11111111,0b00001111,0b00000000,0b11111110,0b11111111,0b00000111,0b00000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000011,0b10000000,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b00000001,0b11000000,0b11111111,0b11111111,0b00000000,0b11100000,0b11111111,0b01111111,0b00000000,0b11110000,0b11111111,0b01111111,0b00000000,0b11110000,0b11111111,0b00111111,0b00000000,0b11111000,0b11111111,0b00111111,0b00000000,0b11111000,0b11111111,0b00001111,0b00000000,0b11111100,0b11111111,0b00001111,0b00000000,0b11111100,0b11111111,0b00001111,0b00000000,0b11111100,0b11111111,0b00000111,0b00000000,0b11111110,0b11111111,0b00000111,0b00000000,0b11111110,0b11111111,0b00000111,0b00000000,0b11111110,0b11111111,0b00000111,0b00000000,0b11111110,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111110,0b11111111,0b00000111,0b00000000,0b11111110,0b11111111,0b00000111,0b00000000,0b11111110,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00001111,0b00000000,0b11111100,0b11111111,0b00001111,0b00000000,0b11111100,0b11111111,0b00001111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11110000,0b11111111,0b00111111,0b00000000,0b11110000,0b11111111,0b00111111,0b00000000,0b11100000,0b11111111,0b01111111,0b00000000,0b11100000,0b11111111,0b11111111,0b00000000,0b11000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000001,0b10000000,0b11111111,0b11111111,0b00000001,0b00000000,0b11111111,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000111,0b00000000,0b11111110,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00001111,0b00000000,0b11111100,0b11111111,0b00001111,0b00000000,0b11111100,0b11111111,0b00001111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00001111,0b00000000,0b11111000,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00000111,0b00000000,0b11111110,0b11111111,0b00000011,0b00000000,0b11111110,0b11111111,0b00000011,0b00000000,0b11111110,0b11111111,0b00000011,0b00000000,0b11111110,0b11111111,0b00000001,0b00000000,0b11111111,0b11111111,0b00000001,0b00000000,0b11111111,0b11111111,0b00000001,0b00000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b01111111,0b00000000,0b11000000,0b11111111,0b01111111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11100000,0b11111111,0b00111111,0b00000000,0b11100000,0b11111111,0b00011111,0b00000000,0b11110000,0b11111111,0b00011111,0b00000000,0b11111000,0b11111111,0b00001111,0b00000000,0b11111000,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00000011,0b00000000,0b11111110,0b11111111,0b00000011,0b00000000,0b11111111,0b11111111,0b00000001,0b00000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b01111111,0b00000000,0b11000000,0b11111111,0b01111111,0b00000000,0b11100000,0b11111111,0b00111111,0b00000000,0b11100000,0b11111111,0b00011111,0b00000000,0b11110000,0b11111111,0b00011111,0b00000000,0b11110000,0b11111111,0b00001111,0b00000000,0b11111000,0b11111111,0b00001111,0b00000000,0b11111100,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00000011,0b00000000,0b11111110,0b11111111,0b00000011,0b00000000,0b11111110,0b11111111,0b00000001,0b00000000,0b11111111,0b11111111,0b00000001,0b00000000,0b11111111,0b11111111,0b00000001,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b00000000,0b11111111,0b11111111,0b00000001,0b00000000,0b11111111,0b11111111,0b00000001,0b00000000,0b11111111,0b11111111,0b00000001,0b00000000,0b11111110,0b11111111,0b00000011,0b00000000,0b11111110,0b11111111,0b00000011,0b00000000,0b11111110,0b11111111,0b00000011,0b00000000,0b11111100,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00000111,0b00000000,0b11111000,0b11111111,0b00001111,0b00000000,0b11111000,0b11111111,0b00001111,0b00000000,0b11111000,0b11111111,0b00001111,0b00000000,0b11110000,0b11111111,0b00011111,0b00000000,0b11110000,0b11111111,0b00001111,0b00000000,0b11110000,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b00011111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b01111111,0b00000000,0b10000000,0b11111111,0b01111111,0b00000000,0b10000000,0b11111111,0b11111111,0b00000000,0b00000000,0b11111111,0b11111111,0b00000000,0b00000000,0b11111110,0b11111111,0b00000001,0b00000000,0b11111110,0b11111111,0b00000011,0b00000000,0b11111100,0b11111111,0b00000011,0b00000000,0b11111100,0b11111111,0b00000111,0b00000000,0b11111000,0b11111111,0b00000111,0b00000000,0b11111000,0b11111111,0b00000111,0b00000000,0b11110000,0b11111111,0b00001111,0b00000000,0b11110000,0b11111111,0b00001111,0b00000000,0b11110000,0b11111111,0b00001111,0b00000000,0b11100000,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11100000,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b00001111,0b00000000,0b11110000,0b11111111,0b00001111,0b00000000,0b11110000,0b11111111,0b00001111,0b00000000,0b11110000,0b11111111,0b00000111,0b00000000,0b11111000,0b11111111,0b00000111,0b00000000,0b11111100,0b11111111,0b00000011,0b00000000,0b11111100,0b11111111,0b00000001,0b00000000,0b11111110,0b11111111,0b00000001,0b00000000,0b11111110,0b11111111,0b00000000,0b00000000,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b01111111,0b00000000,0b10000000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b00011111,0b00000000,0b11110000,0b11111111,0b00001111,0b00000000,0b11110000,0b11111111,0b00001111,0b00000000,0b11111000,0b11111111,0b00000111,0b00000000,0b11111000,0b11111111,0b00000011,0b00000000,0b11111100,0b11111111,0b00000011,0b00000000,0b11111110,0b11111111,0b00000001,0b00000000,0b11111110,0b11111111,0b00000000,0b00000000,0b11111111,0b11111111,0b00000000,0b00000000,0b11111111,0b01111111,0b00000000,0b10000000,0b11111111,0b01111111,0b00000000,0b11000000,0b11111111,0b00111111,0b00000000,0b11000000,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b00011111,0b00000000,0b11100000,0b11111111,0b00001111,0b00000000,0b00000000
};
static const uint8_t cdata_keil_sample_d[] = {
    0b11111100,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b11000000,0b00000001,0b10000000,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b11000000,0b00000001,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b10000000,0b11111111,0b11111111,0b01000000,0b11111110,0b00000101,0b00000000,0b11111000,0b11111111,0b00001111,0b11100100,0b00001111
};
static const uint8_t cdata_keil_sample_e[] = {
    0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000
};
static const uint8_t cdata_keil_sample_f[] = {
    0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000
};
static const uint8_t cdata_keil_sample_1e[] = {
    0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111000,0b11111111,0b11111111,0b11111111,0b11111111,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11100000,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111100,0b11111111,0b11111111,0b11111111,0b11111111,0b00000111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111111,0b11111111,0b11111111,0b11111111,0b01111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11110000,0b11111111,0b11111111,0b11111111,0b11111111,0b00001111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b11111110,0b11111111,0b11111111,0b11111111,0b11111111,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b11000000,0b11111111,0b11111111,0b11111111,0b11111111,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000
};

const uint8_t cdata_pattern_idxs[22] = {
    0,1,2,3,4,5,6,7,10,9,10,11,12,13,8,14,15,16,17,9,17,18
};

#define EMPTY_SAMPLE(INDEX) {0}
const Sample_t cdata_keil_samples[0x20] = {
    EMPTY_SAMPLE(0),
    {cdata_keil_sample_1,SAMPLE_INDEX_FROM_INTERGAL(7624),NOTE_C(4),kLoopMode_Forward,SAMPLE_INDEX_FROM_INTERGAL(0)},
    {cdata_keil_sample_2,SAMPLE_INDEX_FROM_INTERGAL(29470),NOTE_C(4),kLoopMode_Forward,SAMPLE_INDEX_FROM_INTERGAL(24120)},
    EMPTY_SAMPLE(3),
    {cdata_keil_sample_4,SAMPLE_INDEX_FROM_INTERGAL(2506),NOTE_C(4),kLoopMode_NoLoop,SAMPLE_INDEX_FROM_INTERGAL(0)},
    {cdata_keil_sample_5,SAMPLE_INDEX_FROM_INTERGAL(1032),NOTE_C(4),kLoopMode_NoLoop,SAMPLE_INDEX_FROM_INTERGAL(0)},
    {cdata_keil_sample_6,SAMPLE_INDEX_FROM_INTERGAL(3074),NOTE_C(4),kLoopMode_NoLoop,SAMPLE_INDEX_FROM_INTERGAL(0)},
    {cdata_keil_sample_7,SAMPLE_INDEX_FROM_INTERGAL(2990),NOTE_C(4),kLoopMode_NoLoop,SAMPLE_INDEX_FROM_INTERGAL(0)},
    EMPTY_SAMPLE(8),
    EMPTY_SAMPLE(9),
    EMPTY_SAMPLE(0xa),
    EMPTY_SAMPLE(0xb),
    {cdata_keil_sample_c,SAMPLE_INDEX_FROM_INTERGAL(31098),NOTE_C(4),kLoopMode_Forward,SAMPLE_INDEX_FROM_INTERGAL(25254)},
    {cdata_keil_sample_d,SAMPLE_INDEX_FROM_INTERGAL(1300),NOTE_C(4),kLoopMode_NoLoop,SAMPLE_INDEX_FROM_INTERGAL(0)},
    {cdata_keil_sample_e,SAMPLE_INDEX_FROM_INTERGAL(1362),NOTE_C(4),kLoopMode_Forward,SAMPLE_INDEX_FROM_INTERGAL(176)},
    {cdata_keil_sample_f,SAMPLE_INDEX_FROM_INTERGAL(9772),NOTE_C(4),kLoopMode_Forward,SAMPLE_INDEX_FROM_INTERGAL(5266)},
    EMPTY_SAMPLE(0x10),
    EMPTY_SAMPLE(0x11),
    EMPTY_SAMPLE(0x12),
    EMPTY_SAMPLE(0x13),
    EMPTY_SAMPLE(0x14),
    EMPTY_SAMPLE(0x15),
    EMPTY_SAMPLE(0x16),
    EMPTY_SAMPLE(0x17),
    EMPTY_SAMPLE(0x18),
    EMPTY_SAMPLE(0x19),
    EMPTY_SAMPLE(0x1a),
    EMPTY_SAMPLE(0x1b),
    EMPTY_SAMPLE(0x1c),
    EMPTY_SAMPLE(0x1d),
    {cdata_keil_sample_1e,SAMPLE_INDEX_FROM_INTERGAL(1338),NOTE_C(4),kLoopMode_Forward,SAMPLE_INDEX_FROM_INTERGAL(234)}
};

//void LoadCData(void) {
//    uint32_t idxs[] = { 1,2,4,5,6,7,0xc,0xd,0xe,0xf,0x1e };
//    for (int i = 0; i < 11; ++i) {
//        cdata_keil_samples[idxs[i]] = LoadFromFile(sample_names[i]);
//    }
//
//    cdata_keil_samples[1].loop_mode = kLoopMode_Forward;
//    cdata_keil_samples[1].loop_start_pos = 0;
//
//    cdata_keil_samples[2].loop_mode = kLoopMode_Forward;
//    cdata_keil_samples[2].loop_start_pos = 24120;
//
//    cdata_keil_samples[0xc].loop_mode = kLoopMode_Forward;
//    cdata_keil_samples[0xc].loop_start_pos = 25254;
//
//    cdata_keil_samples[0xe].loop_mode = kLoopMode_Forward;
//    cdata_keil_samples[0xe].loop_start_pos = 176;
//
//    cdata_keil_samples[0xf].loop_mode = kLoopMode_Forward;
//    cdata_keil_samples[0xf].loop_start_pos = 5266;
//
//    cdata_keil_samples[0x1e].loop_mode = kLoopMode_Forward;
//    cdata_keil_samples[0x1e].loop_start_pos = 234;
//}
//
//void UnLoadCData(void) {
//    for (int i = 0; i < 11; ++i) {
//        Sample_DeInit(cdata_keil_samples + i);
//    }
//}