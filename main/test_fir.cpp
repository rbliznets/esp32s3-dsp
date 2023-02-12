#include "test.h"
#include <cstring>

void test_fir()
{
    uint16_t size = TEST_SIZE-24;
    std::printf("**** Data size %d *****\n",size);

    std::memset(out,0,sizeof(out));
    std::memset(in1,0,sizeof(in1));
    for(int i=0;i<(size/20);i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            in1[i*20+j] = 10000;
        }
        for (size_t j = 10; j < 20; j++)
        {
            in1[i*20+j] = -10000;
        }
    }

    getTime();
    for(int i=0; i<ITER; i++)
    {
        fir_1_16(in1, kgauss, countof(kgauss), out, size);
    }
    printTime("fir_1_16",ITER);
    // for(int i=0;i<50;i++)std::printf("%d ",out[i]);
    // std::printf(" ... %d %d %d %d\n",out[size-2],out[size-1],out[size],out[size+1]);
    // std::memset(out,0,sizeof(out));

    getTime();
    for(int i=0; i<ITER; i++)
    {
        fir_16_16_q15(in1, kgauss, countof(kgauss), out, size);
    }
    printTime("fir_16_16_q15",ITER);
    // for(int i=0;i<50;i++)std::printf("%d ",out[i]);
    // std::printf(" ... %d %d %d %d\n",out[size-2],out[size-1],out[size],out[size+1]);
    // std::memset(out,0,sizeof(out));

    std::printf("\n");
}