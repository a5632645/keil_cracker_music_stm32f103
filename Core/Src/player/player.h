#ifndef __PLAYER_PLAYER_H
#define __PLAYER_PLAYER_H

#include <stdint.h>
#include "pattern.h"
#include "sample.h"
#include "sampler.h"
#include "constant.h"

typedef struct {
    const Pattern_t* pPattern_array;
    const Sample_t* pSample_array;
    const uint8_t* pattern_idx_array;
    uint32_t pattern_idx_length;
    uint8_t pattern_pos;
    uint8_t line_pos;
    const Pattern_t* pCurrent_pattern;
    Sampler samplers[NUM_AUDIO_CHANNEL];
    uint32_t next_command_idxs[NUM_AUDIO_CHANNEL];
    uint8_t speed;
    uint8_t speed_counter;
} Player_t;

void Player_Init(Player_t* pPlayer);
void Player_SampleTick(Player_t* pPlayer);
void Player_NextLine(Player_t* pPlayer);
uint32_t Player_ReadOutput(const Player_t* pPlayer, uint32_t channel);

#endif // !__PLAYER_PLAYER_H
