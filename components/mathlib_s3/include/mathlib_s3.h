/*!
	\file
	\brief Оптимизированные функции DSP.
	\authors Близнец Р.А.
	\version 0.3.0.0
	\date 11.11.2022
*/

#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef int16_t q15; ///< fixed point S.15
#define toQ15(f) ((q15)(f*INT16_MAX))
#define toFloat(q) ((((int16_t)q))/((float)INT16_MAX))

#define to8SIZE(size) ((((size)+7)/8)*8)

/// Copy vector.
/*!
    out=in
    \param[in] in vector.
    \param[out] out output vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8, >= 8).
*/
void copy(q15* in, q15* out, uint32_t size);
/// Copy vector.
/*!
    out=in
    \param[in] in vector (16 bytes aligned).
    \param[out] out output vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8, >= 8).
*/
void copy_16(q15* in, q15* out, uint32_t size);

/// Multiply vector by scalar.
/*!
    out=in * k
    \param[in] in vector (16 bytes aligned).
    \param[in] k pointer for scalar (2 bytes aligned).
    \param[out] out output vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8, >= 8).
*/
void scaleVector_16(q15* in, q15* k, q15* out, uint32_t size);

/// Multiply vector by scalar.
/*!
    out=in1 * k
    \param[in] in vector.
    \param[in] k pointer for scalar (2 bytes aligned).
    \param[out] out output vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8, >= 16).
*/
void scaleVector(q15* in, q15* k, q15* out, uint32_t size);

/// Dot product of vectors q15.
/*!
    \param[in] in1 vector (16 bytes aligned).
    \param[in] in2 vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8, >= 8).
    \return result
*/
q15 dot_product_16_16(q15* in1, q15* in2, uint32_t size);
/// Dot product of vectors q15.
/*!
    \param[in] in1 vector.
    \param[in] in2 vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8, >= 8).
    \return result
*/
q15 dot_product_1_16(q15* in1, q15* in2, uint32_t size);
/// FIR q15.
/*!
    \param[in] in data.
    \param[in] k coefficients (16 bytes aligned).
    \param[in] ksize size of coefficients (multiple of 8, >= 8).
    \param[out] out output vector.
    \param[in] size vector size.
*/
void fir_1_16(q15* in, q15* k, uint32_t ksize, q15* out, uint32_t size);

/// Addition of two vectors with saturation.
/*!
    out=in1 + in2
    \param[in] in1 q15 vector (16 bytes aligned).
    \param[in] in2 q15 vector (16 bytes aligned).
    \param[out] out sum vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8).
*/
void addVectors_q15(q15* in1, q15* in2, q15* out, uint32_t size);

/// Normalize vector q15.
/*!
    \param[in] in q15 vector (16 bytes aligned).
    \param[out] out q15 vector (16 bytes aligned).
    \param[in] size vector size (multiple of 8).
*/
int16_t normalize_q15(q15* in, q15* out, uint32_t size);

/// FIR q15.
/*!
    \param[in] in data vector(16 bytes aligned).
    \param[in] k coefficients(16 bytes aligned).
    \param[in] ksize size of coefficients(multiple of 8, >= 8)..
    \param[out] out output vector (16 bytes aligned).
    \param[in] size vector size(multiple of 8, >= 8).
*/
void fir_16_16_q15(q15* in, q15* k, uint32_t ksize, q15* out, uint32_t size);

/// atan2 q15.
/*!
    \param[in] y.
    \param[in] x.
    \return atan(y/x) in radians. (Pi = 16383)
*/
q15 atan2_q15(q15 y, q15 x);

/// atan q15.
/*!
    \param[in] y tangents.
    \return atan(y) in radians. (Pi = 16383)
*/
inline q15 atan_q15(q15 y)
{
    return atan2_q15(y, 0x7fff);
};

#ifdef __cplusplus
}
#endif
