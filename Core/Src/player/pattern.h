#ifndef __PLAYER_PATTERN_H
#define __PLAYER_PATTERN_H

#include <stdint.h>
#include "constant.h"

typedef union {
    uint32_t command;
    struct {
    	// [7:0]
        uint8_t line_no;
        // [15:8]
        uint8_t pitch;
        // [23:16]
        uint8_t sample_no;
        /**
        * [27:24] type
        * [31:28] arg
         */
        uint8_t fx;
    };
} Command_t;

typedef struct {
    const uint32_t* commands;
    uint32_t length;
} Channel_Pattern_t;

typedef struct {
    Channel_Pattern_t patterns[NUM_AUDIO_CHANNEL];
} Pattern_t;

#endif // !__PLAYER_PATTERN_H
