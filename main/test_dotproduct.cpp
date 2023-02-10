#include "test.h"

inline q15 dot_product_c(q15* din1, q15* din2, uint32_t size)
{
    int32_t sum=0;
    for (uint32_t i = 0; i < size; i++)
    {
        sum += ((int32_t)din1[i])*din2[i];
    }
    return (q15)(sum >> 15);
}

void test_dotproduct()
{
    std::printf("**** Data size %d *****\n",TEST_SIZE-8);

    for(int16_t i=0; i < TEST_SIZE; i++)
    {
        in1[i]=toQ15(0.5)/16;
        in2[i]=toQ15(0.03);
        out[i]=0;
    }
    in1[1]=toQ15(-0.25);

    getTime();
    for(int i=0; i<ITER; i++)
    {
        out[0]=dot_product_16_16(in1, in2, TEST_SIZE-8);
    }
    printTime("dot_product_16_16",ITER);

    getTime();
    for(int i=0; i<ITER; i++)
    {
        out[1]=dot_product_1_16(&in2[1], in2, TEST_SIZE-8);
    }
    printTime("dot_product_1_16",ITER);

    getTime();
    for(int i=0; i<ITER; i++)
    {
        out[2]=dot_product_c(in1, in2, TEST_SIZE-8);
    }
    printTime("dot_product_c",ITER);

    for(int i=0;i<3;i++)std::printf("%f ",toFloat(out[i]));

    std::printf("\n");
}