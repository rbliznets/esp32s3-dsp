#include "test.h"

void scaleVector_c(q15* in, q15* k, q15* out, uint32_t size)
{
   for(uint32_t i=0; i<size; i++)
   {
       out[i]=(in1[i]*(*k)) >> 15;
   }
}

void test_scalevector()
{
    for(int16_t i=0; i < TEST_SIZE; i++)
    {
        in1[i]=toQ15(0.5);
        out[i]=0;
    }
    q15 k=toQ15(-0.5);
    std::printf("**** Data size %d\n",TEST_SIZE);

    getTime();
    for(int i=0; i<ITER; i++)scaleVector_16(in1, &k, out, TEST_SIZE-8);
    printTime("scaleVector_16",ITER);
    std::printf("result %f\n",toFloat(out[TEST_SIZE-9]));

    getTime();
    for(int i=0; i<ITER; i++)scaleVector(&in1[3], &k, out, TEST_SIZE-8);
    printTime("scaleVector",ITER);

    getTime();
    for(int i=0; i<ITER; i++)scaleVector_c(in1, &k, out, TEST_SIZE-8);
    printTime("scaleVector_c",ITER);
}