#include "test.h"
#include <cstring>
#include <complex>

#define toQ15Angle(f) ((q15)(f*(M_1_PI/2)*INT16_MAX))
inline int16_t arg_fr16(complex_q15& data)
{
    return toQ15Angle(std::atan2(data.im,data.re));
};

void test_complex()
{
    std::printf("**** Data size1 *****\n");
    complex_q15 cx = {-200, 100};
    std::complex<float> q={toFloat(cx.re),toFloat(cx.im)};
    float angle = std::arg(q);
    // float radius = std::abs(q);
    // std::printf("%fe^%fi\n",radius,angle);
    q15 angle_q15=atan2_q15(cx.im,cx.re);
    assert(angle_q15 == 13954);
    // std::printf("%d\n",angle_q15);

    getTime();
    for(int i=0; i<ITER; i++)
    {
        angle = std::arg(q);
        q+=1;
    }
    printTime("float std::arg",ITER);

    // getTime();
    // for(int i=0; i<ITER; i++)
    // {
    //     angle_q15=arg_fr16(cx);
    //     cx.re++;
    // }
    // printTime("arg_fr16",ITER);

    getTime();
    for(int i=0; i<ITER; i++)
    {
        angle_q15=atan2_q15(cx.im,cx.re);
        cx.re++;
    }
    printTime("atan2_q15",ITER);
}
