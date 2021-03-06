#ifndef SENG440_LOEFFLER_2D_FIXED_ASM_H
#define SENG440_LOEFFLER_2D_FIXED_ASM_H

#include <stdint.h>
#include "util/constants.h"

void dct_loeffler_2d_fixed_asm(DataType data_in[8][8], int16_t data_out[8][8]);

#endif // SENG440_LOEFFLER_2D_FIXED_ASM_H