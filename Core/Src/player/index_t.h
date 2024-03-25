#ifndef __PLAYER_INDEX_T_H
#define __PLAYER_INDEX_T_H

#include <stdint.h>

/**
* [30:8] integal part
* [7:0]  fraction part
 */
typedef int32_t SampleIndex_t;

inline static SampleIndex_t SampleIndex_Add(SampleIndex_t lh, SampleIndex_t rh) {
    return lh + rh;
}

inline static SampleIndex_t SampleIndex_Sub(SampleIndex_t lh, SampleIndex_t rh) {
    return lh - rh;
}

#define SAMPLE_INDEX_FROM_INTERGAL(INTERGAL) (INTERGAL * 256)
inline static SampleIndex_t SampleIndex_FromIntergal(int32_t intergal) {
    return intergal * 256;
}

inline static int32_t SampleIndex_IntergalPart(SampleIndex_t val) {
    return (uint32_t)(val) >> 8;
}

// Table for exp2(0..11/12)
static const int32_t exp2_table0[] = {
    256,271,287,304,323,341,362,383,406,430,456,483
};
// Table for exp2(-11..0/12)
static const int32_t exp2_table1[] = {
    256,242,228,215,203,192,181,171,161,152,144,136
};

inline static SampleIndex_t SampleIndex_exp2div12(int32_t val) {
    if (val < 0) {
        int32_t div = val / 12;
        int32_t mod = val - div * 12;
        return exp2_table1[-mod] >> (-div);
    }
    else if (val == 0) {
        return SampleIndex_FromIntergal(1);
    }
    else {
        int32_t div = val / 12;
        int32_t mod = val - div * 12;
        return exp2_table0[mod] << div;
    }
}

#endif // !__PLAYER_INDEX_T_H
