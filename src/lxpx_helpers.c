
#include "lxpx_helpers.h"

// "data-packing algorithm" as specified in the LXP-1 manual

void unpacked_to_packed (t_packed_value *packed, int unpacked)
{
	// -unipolar (nonnegative) parameter values live in [0x8000, 0xBFFF] = [0, max]
	// -bipolar parameter values live in [0x4000, 0x8000, 0xBFFF] = [-max, 0, max]

	// limit input to bipolar value range 
	if (unpacked > 0xBFFF)
		unpacked = 0xBFFF;
	else if (unpacked < 0x4000)
		unpacked = 0x4000;

	// unpacked to packed transformation
    packed->byte_0 =  (unpacked & 0x8000) >> 14;	// b7
    packed->byte_0 |= (unpacked & 0x80) >> 7;   	// a7
    
    packed->byte_1 = (unpacked & 0x7F);       		// a6-a0
    packed->byte_2 = (unpacked & 0x7F00) >> 8;     	// b6-b0
}
