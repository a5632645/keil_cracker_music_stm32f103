#include "sample.h"
#include "cdata.h"
//#include "wrapper/audiofile_wrapper.h"
#include <malloc.h>
#include "octave.h"

//#define DEFAULT_BASE_PITCH NOTE_C(4)

//Sample_t LoadFromFile(const char* filename) {
//    Sample_t sample = { 0 };
//    AudioFile_t file = AudioFile_Load(filename);
//
//    sample.length = SampleIndex_FromIntergal((int32_t)file.length);
//    sample.data = file.data;
//    sample.base_pitch = DEFAULT_BASE_PITCH;
//    sample.loop_mode = kLoopMode_NoLoop;
//    sample.loop_start_pos = SampleIndex_FromIntergal(0);
//    return sample;
//}
//
//void Sample_DeInit(Sample_t* pSample) {
//    free(pSample->data);
//    pSample->length = SampleIndex_FromIntergal(0);
//    pSample->data = NULL;
//}
