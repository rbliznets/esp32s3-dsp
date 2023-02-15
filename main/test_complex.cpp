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
   std::printf("**** Data size %d *****\n",TEST_SIZE);
    
    for(int16_t i=0; i < TEST_SIZE/8; i++)
    {
        inc[8*i].re=200;
        inc[8*i].im=100;
        inc[8*i+1].re=-200;
        inc[8*i+1].im=100;
        inc[8*i+2].re=-200;
        inc[8*i+2].im=-100;
        inc[8*i+3].re=200;
        inc[8*i+3].im=-100;
        inc[8*i+4].re=0;
        inc[8*i+4].im=100;
        inc[8*i+5].re=200;
        inc[8*i+5].im=0;
        inc[8*i+6].re=-100;
        inc[8*i+6].im=0;
        inc[8*i+7].re=0;
        inc[8*i+7].im=-0;
    }
    std::memset(out,0,sizeof(out));
    arg_q15(inc, out, TEST_SIZE);
    for(int i=0;i<8;i++)std::printf("%d ",out[i]);
    std::printf("\n");   
    for(int i=8;i<16;i++)std::printf("%d ",out[i]);
    std::printf("\n");   
    for(int i=16;i<20;i++)std::printf("%d ",out[i]);
    std::printf("\n");   
    for(int i=24;i<28;i++)std::printf("%d ",out[i]);
    std::printf("\n");   
    for(int i=32;i<36;i++)std::printf("%d ",out[i]);
    std::printf("\n");   
    // std::printf("... %d %d\n",out[TEST_SIZE-2],out[TEST_SIZE-1]);   

    // std::printf("**** Data size 1 *****\n");
    complex_q15 cx = {-200, 100};
    std::complex<float> q={toFloat(cx.re),toFloat(cx.im)};
    float angle = std::arg(q);
    // float radius = std::abs(q);
    // std::printf("%fe^%fi\n",radius,angle);
    q15 angle_q15=atan2_q15(cx.im,cx.re);
    assert(angle_q15 == 13954);
    // std::printf("%d\n",angle_q15);


    // getTime();
    // for(int i=0; i<ITER; i++)
    // {
    //     angle = std::arg(q);
    //     q+=1;
    // }
    // printTime("float std::arg",ITER);

    // getTime();
    // for(int i=0; i<ITER; i++)
    // {
    //     angle_q15=arg_fr16(cx);
    //     cx.re++;
    // }
    // printTime("arg_fr16",ITER);

    // getTime();
    // for(int i=0; i<ITER; i++)
    // {
    //     angle_q15=arg(cx);
    //     cx.re++;
    // }
    // printTime("arg",ITER);
}
