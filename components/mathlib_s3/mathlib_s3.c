#include <stdio.h>
#include "mathlib_s3.h"
#include "sdkconfig.h"

void copy_pie(q15* in, q15* out, uint32_t size);
inline void copy(q15* in, q15* out, uint32_t size)
{
#ifdef CONFIG_CHECK_PARAM
    assert(((uint32_t)out % 16) == 0);
    assert((size % 8) == 0);
    assert(size > 0);
#endif 
    copy_pie(in, out, size);
}

void copy_16_pie(q15* in, q15* out, uint32_t size);
inline void copy_16(q15* in, q15* out, uint32_t size)
{
#ifdef CONFIG_CHECK_PARAM
    assert(((uint32_t)in % 16) == 0);
    assert(((uint32_t)out % 16) == 0);
    assert((size % 8) == 0);
    assert(size > 0);
#endif 
    copy_16_pie(in, out, size);
}

void scaleVector_q15_pie(q15* in, q15* k, q15* out, uint32_t size);
inline void scaleVector(q15* in, q15* k, q15* out, uint32_t size)
{
#ifdef CONFIG_CHECK_PARAM
    assert(((uint32_t)k % 2) == 0);
    assert(((uint32_t)out % 16) == 0);
    assert((size % 8) == 0);
    assert(size > 0);
#endif 
    scaleVector_q15_pie(in, k, out, size);
}

void scaleVector_q15_16_pie(q15* in, q15* k, q15* out, uint32_t size);
inline void scaleVector_16(q15* in, q15* k, q15* out, uint32_t size)
{
#ifdef CONFIG_CHECK_PARAM
    assert(((uint32_t)in % 16) == 0);
    assert(((uint32_t)k % 2) == 0);
    assert(((uint32_t)out % 16) == 0);
    assert((size % 8) == 0);
    assert(size > 0);
#endif 
    scaleVector_q15_16_pie(in, k, out, size);
}

int32_t dot_product_q15_pie(q15* in1, q15* in2, uint32_t size);
inline q15 dot_product_q15(q15* in1, q15* in2, uint32_t size)
{
#ifdef CONFIG_CHECK_PARAM
     assert(((uint32_t)in1 % 16) == 0);
    assert(((uint32_t)in2 % 16) == 0);
    assert((size % 8) == 0);
    assert(size > 0);
#endif 
    int32_t x =dot_product_q15_pie(in1, in2, size);
    if( x > 1073741823) return INT16_MAX;
    else if( x < -1073741824) return INT16_MIN;
    return (q15)(x >> 15);
}
