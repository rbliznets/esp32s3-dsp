#include "test.h"
#include <cstring>

void test_copy()
{
    for(int16_t i=0; i < TEST_SIZE; i++)
    {
        in1[i]=i;
        out[i]=0;
    }
    std::printf("Data size %d\n",TEST_SIZE-8);

    getTime();
    for(int i=0; i<ITER; i++)copy_16(in1,  out, TEST_SIZE-8);
    printTime("copy_16",ITER);
    std::printf("result %d\n",out[TEST_SIZE-9]);

    getTime();
    for(int i=0; i<ITER; i++)copy(&in1[3], out, TEST_SIZE-8);
    printTime("copy",ITER);
    std::printf("result %d\n",out[TEST_SIZE-9]);

    getTime();
    for(int i=0; i<ITER; i++)std::memcpy(out,in1,(TEST_SIZE-8)*sizeof(q15));
    printTime("std::memcpy",ITER);

}