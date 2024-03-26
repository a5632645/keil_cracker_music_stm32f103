#ifndef __PLAYER_SAMPLE_H
#define __PLAYER_SAMPLE_H

#include <stdint.h>
#include "index_t.h"

typedef enum {
    kLoopMode_NoLoop,
    kLoopMode_Forward,
    kLoopMode_PingPong
} LoopMode_enum;

typedef struct {
    const uint8_t* data;
    SampleIndex_t length;
    uint8_t base_pitch;

    LoopMode_enum loop_mode;
    SampleIndex_t loop_start_pos;
} Sample_t;

inline static uint32_t Sample_GetSample(const Sample_t* pSample, uint32_t index) {
    uint32_t bit_index = index & 0b111;
    uint32_t byte_index = index >> 3;
    uint32_t byte = pSample->data[byte_index];
    return (byte >> bit_index) & 0x1;
}

#endif // !__PLAYER_SAMPLE_H

