#include "sampler.h"
#include <math.h>
#include "sample.h"

void Sampler_Init(Sampler* pSampler) {
    //pSampler->current_index = 0.0f;
    pSampler->current_index = SampleIndex_FromIntergal(0);
    //pSampler->index_step = 0.0f;
    pSampler->index_step = SampleIndex_FromIntergal(0);
    pSampler->play_pitch = 0;
    pSampler->sample = NULL;
    pSampler->is_forward = true;
    pSampler->is_work = false;
}

void Sampler_Tick(Sampler* pSampler) {
    if (!pSampler->is_work) return;

    const LoopMode_enum loopmode = pSampler->sample->loop_mode;
    //float new_index = pSampler->current_index + pSampler->index_step;
    SampleIndex_t new_index = SampleIndex_Add(pSampler->current_index, pSampler->index_step);
    if (pSampler->is_forward) {
        if (new_index >= pSampler->sample->length) {
            if (loopmode == kLoopMode_NoLoop) {
                // disable it
                pSampler->is_work = false;
            }
            else if (loopmode == kLoopMode_Forward) {
                // back to loop start pos
                new_index = pSampler->sample->loop_start_pos;
            }
            else if (loopmode == kLoopMode_PingPong) {
                // keep
                new_index = pSampler->current_index;
                pSampler->is_forward = false;
            }
        }
    }
    else {
        //new_index = pSampler->current_index - pSampler->index_step;
        new_index = SampleIndex_Sub(pSampler->current_index, pSampler->index_step);
        if (new_index < pSampler->sample->loop_start_pos && loopmode == kLoopMode_PingPong) {
            // keep
            new_index = pSampler->current_index;
            pSampler->is_forward = true;
        }

        if (new_index < 0) {
            pSampler->is_work = false;
        }
    }
    pSampler->current_index = new_index;
}

void Sampler_NoteOn(Sampler* pSampler, uint8_t pitch, const Sample_t* pSample) {
    pSampler->play_pitch = pitch;
    pSampler->sample = pSample;
    //pSampler->index_step = exp2f((pitch - pSample->base_pitch) / 12.0f);
    pSampler->index_step = SampleIndex_exp2div12((int32_t)(pitch - pSample->base_pitch));
    //pSampler->current_index = 0.0f;
    pSampler->current_index = SampleIndex_FromIntergal(0);
    pSampler->is_work = true;
    pSampler->is_forward = true;
}

uint32_t Sampler_ReadOutput(const Sampler* pSampler) {
    if (!pSampler->is_work) {
        return 0.0f;
    }

    //uint32_t index = (uint32_t)(pSampler->current_index);
    uint32_t index = (uint32_t)(SampleIndex_IntergalPart(pSampler->current_index));
    //return pSampler->sample->data[index];
    return Sample_GetSample(pSampler->sample, index);
}
