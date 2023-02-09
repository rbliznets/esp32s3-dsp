#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef int16_t q15; ///< fixed point S.15
#define toQ15(f) ((q15)(f*INT16_MAX))
#define toFloat(q) ((((int16_t)q))/((float)INT16_MAX))


/// Complex number.
typedef __attribute__((aligned(4))) struct complex_q15{
    q15 re; ///< real
    q15 im; ///< imagine
} complex_q15;

/// Copy vector.
/*!
    out=in
    \param[in] in vector (16 bytes aligned).
    \param[out] out output vector.
    \param[in] size vector size (multiple of 8).
*/
void copy(q15* in, q15* out, uint32_t size);
/// Copy vector.
/*!
    out=in
    \param[in] in vector (16 bytes aligned).
    \param[out] out output vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8).
*/
void copy_16(q15* in, q15* out, uint32_t size);

/// Multiply vector by scalar.
/*!
    out=in * k
    \param[in] in vector (16 bytes aligned).
    \param[in] k pointer for scalar (2 bytes aligned).
    \param[out] out output vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8).
*/
void scaleVector_16(q15* in, q15* k, q15* out, uint32_t size);

/// Multiply vector by scalar.
/*!
    out=in1 * k
    \param[in] in vector (2 bytes aligned).
    \param[in] k pointer for scalar (2 bytes aligned).
    \param[out] out output vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8).
*/
void scaleVector(q15* in, q15* k, q15* out, uint32_t size);

/// Dot product of vectors q15.
/*!
    \param[in] in1 vector (16 bytes aligned).
    \param[in] in2 vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8).
    \return result
*/
q15 dot_product_q15(q15* in1, q15* in2, uint32_t size);

#ifdef __cplusplus
}
#endif

