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
   std::printf("**** Data size %d *****\n",TEST_SIZE-8);
    
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
        inc[8*i+6].re=-200;
        inc[8*i+6].im=0;
        inc[8*i+7].re=0;
        inc[8*i+7].im=-100;
    }
    inc[0].re=0;
    inc[0].im=0;
    std::memset(out,0,sizeof(out));
    getTime();
    arg_16_q15(inc, out, TEST_SIZE-8);
    printTime("arg_q15",1);
    // for(int16_t k=0; k <6; k++)
    // {
    //     for(int i=k*8;i<(k*8)+8;i++)std::printf("%d\t",out[i]);
    //     std::printf("\n");  
    // } 
    // std::printf(".. %d %d...%d\n",out[TEST_SIZE-9],out[TEST_SIZE-8],out[TEST_SIZE-1]);   

    getTime();
    for(int i=0; i<ITER; i++)
    {
        arg_16_q15(inc, out, TEST_SIZE-8);
    }
    printTime("arg_q15",ITER);

    std::printf("**** Data size 1 *****\n");
    // std::printf("**** Data size 1 *****\n");
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

    getTime();
    for(int i=0; i<ITER; i++)
    {
        angle_q15=arg_fr16(cx);
        cx.re++;
    }
    printTime("arg_fr16",ITER);

    getTime();
    for(int i=0; i<ITER; i++)
    {
        angle_q15=arg(cx);
        cx.re++;
    }
    printTime("arg",ITER);

    std::printf("\n");
}

void test_sincos()
{
    q15 sn,cs;
    std::printf("**** Data size 1 *****\n");
    // std::printf("\n");
    // sincos_q15(16383/3, &sn, &cs);    
    // std::printf("pi/3 -> %d,%d\n",sn,cs);
    // std::printf("\n");
    // sincos_q15(4095, &sn, &cs);    
    // std::printf("pi/4 -> %d,%d\n",sn,cs);
    // sincos_q15(4095+8191, &sn, &cs);    
    // std::printf("3pi/4 -> %d,%d\n",sn,cs);
    // sincos_q15(-4095-8191, &sn, &cs);    
    // std::printf("-3pi/4 -> %d,%d\n",sn,cs);
    // sincos_q15(-4095, &sn, &cs);    
    // std::printf("-pi/4 -> %d,%d\n",sn,cs);

    q15 angle=0;
    getTime();
    for(int i=0; i<ITER; i++)
    {
        sincos_q15(angle, &sn, &cs);
        angle+=1;
    }
    printTime("sincos_q15",ITER);

     std::printf("\n");
}
