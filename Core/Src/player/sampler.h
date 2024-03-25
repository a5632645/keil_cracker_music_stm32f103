#ifndef __PLAYER_SAMPLER_H
#define __PLAYER_SAMPLER_H

#include "sample.h"
#include <stdbool.h>
#include "index_t.h"

typedef struct _Sampler {
    const Sample_t* sample;
    //float current_index;
    SampleIndex_t current_index;
    //float index_step;
    SampleIndex_t index_step;
    uint8_t play_pitch;
    bool is_forward;
    bool is_work;
} Sampler;

void Sampler_Init(Sampler* pSampler);
void Sampler_Tick(Sampler* pSampler);
void Sampler_NoteOn(Sampler* pSampler, uint8_t pitch, const Sample_t* pSample);
uint32_t Sampler_ReadOutput(const Sampler* pSampler);

#endif // !__PLAYER_SAMPLER_H
