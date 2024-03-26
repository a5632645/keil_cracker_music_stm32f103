#include "player.h"
#include "cdata.h"
#include <memory.h>

void Player_Init(Player_t* pPlayer) {
    pPlayer->pSample_array = cdata_keil_samples;
    pPlayer->pattern_idx_array = cdata_pattern_idxs;
    pPlayer->pattern_idx_length = sizeof(cdata_pattern_idxs) / sizeof(cdata_pattern_idxs[0]);
    pPlayer->pPattern_array = cdata_keil_patterns;
    pPlayer->pattern_pos = 0;
    pPlayer->line_pos = 0;
    pPlayer->pCurrent_pattern = pPlayer->pPattern_array;
    pPlayer->speed = 4;
    pPlayer->speed_counter = pPlayer->speed;
    
    for (int i = 0; i < NUM_AUDIO_CHANNEL; ++i) {
        Sampler_Init(pPlayer->samplers + i);
    }
    memset(pPlayer->next_command_idxs, 0, sizeof(pPlayer->next_command_idxs));
}

void Player_SampleTick(Player_t* pPlayer) {
    for (int i = 0; i < NUM_AUDIO_CHANNEL; ++i) {
        Sampler_Tick(pPlayer->samplers + i);
    }
}

void Player_NextPattern(Player_t* pPlayer) {
    pPlayer->line_pos = 0;
    pPlayer->pattern_pos++;

    if (pPlayer->pattern_pos >= pPlayer->pattern_idx_length) {
        pPlayer->pattern_pos = 0;
        for (int i = 0; i < NUM_AUDIO_CHANNEL; ++i) {
            pPlayer->samplers[i].is_work = false;
        }
    }

    const uint32_t next_pattern_idx = pPlayer->pattern_idx_array[pPlayer->pattern_pos];
    pPlayer->pCurrent_pattern = pPlayer->pPattern_array + next_pattern_idx;
    memset(pPlayer->next_command_idxs, 0, sizeof(pPlayer->next_command_idxs));
}

void Player_NextLine(Player_t* pPlayer) {
    if (pPlayer->speed_counter >= pPlayer->speed - 1) {
        pPlayer->speed_counter = 0;
    }
    else {
        pPlayer->speed_counter++;
        return;
    }

    bool have_jmp_next_pattern = false;
    uint32_t next_pattern_line = 0;
    for (int i = 0; i < NUM_AUDIO_CHANNEL; ++i) {
        const uint32_t next_command_idx = pPlayer->next_command_idxs[i];
        // this channel has no commands now
        if (next_command_idx >= pPlayer->pCurrent_pattern->patterns[i].length) {
            continue;
        }

        Command_t cmd = { .command = pPlayer->pCurrent_pattern->patterns[i].commands[next_command_idx] };
        if (cmd.line_no <= pPlayer->line_pos) {
            pPlayer->next_command_idxs[i]++;

            const uint8_t fx_type = (cmd.fx & 0xf0) >> 4;
            const uint8_t fx_arg = cmd.fx & 0xf;
            if (fx_type == CMD_FX_JMP) {
                have_jmp_next_pattern = true;
                next_pattern_line = fx_arg;
            }
            else {
                Sampler_NoteOn(pPlayer->samplers + i, cmd.pitch, pPlayer->pSample_array + cmd.sample_no);
            }
        }
    }

    if (have_jmp_next_pattern) {
        Player_NextPattern(pPlayer);
        pPlayer->line_pos = next_pattern_line;
        for (int ch = 0; ch < NUM_AUDIO_CHANNEL; ++ch) {
            for (uint32_t i = 0; i < pPlayer->pCurrent_pattern->patterns[ch].length; ++i) {
                Command_t cmd = { .command = pPlayer->pCurrent_pattern->patterns[ch].commands[i] };
                if (cmd.line_no >= next_pattern_line) {
                    pPlayer->next_command_idxs[ch] = i;
                    break;
                }
            }
        }
    }
    else {
        pPlayer->line_pos++;
        if (pPlayer->line_pos >= NUM_LINES_PER_PATTERN) {
            Player_NextPattern(pPlayer);
        }
    }
}

uint32_t Player_ReadOutput(const Player_t* pPlayer, uint32_t channel) {
    return Sampler_ReadOutput(pPlayer->samplers + channel);
}
