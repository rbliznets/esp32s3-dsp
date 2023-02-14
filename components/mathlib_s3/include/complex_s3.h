/*!
	\file
	\brief Оптимизированные функции для комплексных чисел.
	\authors Близнец Р.А.
	\version 0.3.0.0
	\date 14.02.2023
	\copyright (c) Copyright 2023, ООО "Глобал Ориент", Москва, Россия, https://github.com/Global-Orient/Gonets
*/

#pragma once
#include "mathlib_s3.h"

#ifdef __cplusplus
extern "C"
{
#endif
/// Complex number.
typedef __attribute__((aligned(4))) struct complex_q15{
    q15 re; ///< real
    q15 im; ///< imagine
} complex_q15;

/// argument.
/*!
    \param[in] value .
    \return argument in radians. (Pi = 16383)
*/
inline q15 arg(complex_q15 value)
{
    return atan2_q15(value.im, value.re);
};

/// The square magnitude of a complex vector divided by 2.
/*!
    out=(in.re^2 + in.im^2)/2
    \param[in] in complex vector (16 bytes aligned).
    \param[out] out magnitude (16 bytes aligned).
    \param[in] size vector size (multiple of 8).
*/
void magnitude_q15(complex_q15* in, q15* out, uint32_t size);

#ifdef __cplusplus
}
#endif
