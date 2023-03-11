/*!
	\file
	\brief Оптимизированные функции для комплексных чисел.
	\authors Близнец Р.А.
	\version 0.3.0.0
	\date 14.02.2023
	\copyright (c) Copyright 2023, ООО "Глобал Ориент", Москва, Россия, https://github.com/Global-Orient/Gonets
*/

#include <assert.h>
#include "complex_s3.h"
#include "sdkconfig.h"
#include <math.h>


void magnitude_q15_pie(complex_q15* in, q15* out, uint32_t size);
inline void magnitude_q15(complex_q15* in, q15* out, uint32_t size)
{
#ifdef CONFIG_CHECK_PARAM
    assert(((uint32_t)in % 16) == 0);
    assert(((uint32_t)out % 16) == 0);
    assert((size % 8) == 0);
    assert(size > 0);
#endif 
    magnitude_q15_pie(in, out, size);
}

complex_q15 cmul_q15_pie(complex_q15 x, complex_q15 y);
inline complex_q15 cmul_q15(complex_q15 x, complex_q15 y)
{
	return cmul_q15_pie(x, y);
};

void cmul10_q15_pie(complex_q15* in, complex_q15* k, complex_q15* out);
void cmul10_q15(complex_q15* in, complex_q15* k, complex_q15* out)
{
#ifdef CONFIG_CHECK_PARAM
    assert(((uint32_t)in % 16) == 0);
    assert(((uint32_t)k % 4) == 0);
    assert(((uint32_t)out % 16) == 0);
#endif 
    cmul10_q15_pie(in, k, out);
}

void init_fft(complex_q15* w, uint32_t fftSize)
{
#ifdef CONFIG_CHECK_PARAM
    assert(((uint32_t)w % 16) == 0);
#endif 
    float e = M_PI * 2.0 / fftSize;
    for (int i = 0; i < (fftSize >> 1); i++) 
    {
        w[i].re = (int16_t)roundf(INT16_MAX * cosf(i * e));
        w[i].im = (int16_t)roundf(INT16_MAX * sinf(i * e));
    }
}

void fft_radix2(complex_q15* data, complex_q15* w, uint32_t fftSize)
{
#ifdef CONFIG_CHECK_PARAM
    assert(((uint32_t)data % 16) == 0);
#endif 
    
}
