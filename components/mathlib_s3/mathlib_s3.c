#include <stdio.h>
#include "mathlib_s3.h"

void scaleVectors_q15_pie(q15* in, q15* k, q15* out, uint32_t size);

inline void scaleVectors(q15* in, q15* k, q15* out, uint32_t size)
{
    assert(((uint32_t)in % 16) == 0);
    assert(((uint32_t)k % 2) == 0);
    assert(((uint32_t)out % 16) == 0);
    assert((size % 8) == 0);
    assert(size > 0);

    scaleVectors_q15_pie(in, k, out, size);
}

int32_t dot_product_q15_pie(q15* in1, q15* in2, uint32_t size);

inline q15 dot_product_q15(q15* in1, q15* in2, uint32_t size)
{
    assert(((uint32_t)in1 % 16) == 0);
    assert(((uint32_t)in2 % 16) == 0);
    assert((size % 8) == 0);
    assert(size > 0);
    
    int32_t x =dot_product_q15_pie(in1, in2, size);
    if( x > 1073741823) return INT16_MAX;
    else if( x < -1073741824) return INT16_MIN;
    return (q15)(x >> 15);
}

int32_t dot_product2_q15_pie(q15* in1, q15* in2, uint32_t size);
int32_t dot_product3_q15_pie(q15* in1, q15* in2, uint32_t size);

inline void test(q15* in, q15* out, uint32_t size)
{
    dot_product2_q15_pie(in, out, size);
}
