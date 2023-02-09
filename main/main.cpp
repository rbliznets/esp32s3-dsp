#include <cstdio>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_timer.h"
#include <cstring>

#include "mathlib_s3.h"
#define countof(x) (sizeof(x)/sizeof(x[0]))

#define TEST_SIZE (1024)

__attribute__((aligned(16)))
static q15 in1[TEST_SIZE];
__attribute__((aligned(16)))
static q15 in2[TEST_SIZE];
__attribute__((aligned(16)))
static q15 out[TEST_SIZE];

int64_t mTime=0;
int64_t getTime()
{
    int64_t res=0;
    int64_t time = esp_timer_get_time();
    res=time-mTime;		
    mTime=time;
    return res;
};
void printTime(uint32_t n=1)
{
    uint64_t time = getTime();
    uint64_t res=time/n;
    if(res >= 10000000)
    {
        std::printf("%lisec\n",(long)(res/1000000));
    }
    else
    {
        if(res<10000)
        {
            if(res < 10)
            {
                double f = time/(double)n;
                std::printf("%linsec\n",(long)(f*1000));
            }
            else
            {
                std::printf("%liusec\n",(long)res);
            }
        }
        else
        {
            std::printf("%limsec\n",(long)(res/1000));
        }
    }
}


q15 dot_product(q15* din1, q15* din2, uint32_t size)
{
    int32_t sum=0;
    for (uint32_t i = 0; i < size; i++)
    {
        sum += ((int32_t)din1[i])*din2[i];
    }
    return (q15)(sum >> 15);
}

extern "C" void app_main(void)
{
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    std::printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
            CONFIG_IDF_TARGET,
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
    std::printf("silicon revision %d, ", chip_info.revision);
    std::printf("Minimum free heap size: %d bytes\n", (int)esp_get_minimum_free_heap_size());

    // for(int16_t i=0; i < countof(in1); i++)
    // {
    //     in1[i]=toQ15(0.5);
    // }
    // q15 k=toQ15(-0.5);
    // scaleVectors(in1, &k, out, countof(in1));
    // std::printf("scaleVectors result: %f\n",toFloat(out[0]));

    // for (size_t i = 0; i < 128; i++)
    // {
    //   in1[i]=toQ15(0.5)/2;
    //   in2[i]=toQ15(0.5)/2;
    // }
    // std::printf("dot_product_q15 result: %f\n",toFloat(dot_product_q15(in1,in2,8)));
    // std::printf("dot_product result: %f\n",toFloat(dot_product(in1,in2,8)));
    // std::printf("dot_product_q15 result: %f\n",toFloat(dot_product_q15(in1,in2,16)));
    // std::printf("dot_product result: %f\n",toFloat(dot_product(in1,in2,16)));
    // std::printf("dot_product_q15 result: %f\n",toFloat(dot_product_q15(in1,in2,32)));
    // std::printf("dot_product result: %f\n",toFloat(dot_product(in1,in2,32)));
    // std::printf("dot_product_q15 result: %f\n",toFloat(dot_product_q15(in1,in2,128)));
    // std::printf("dot_product result: %f\n",toFloat(dot_product(in1,in2,128)));

    for (size_t i = 0; i < TEST_SIZE; i++)
    {
      in1[i]=i;
      out[i]=0;
    }

    getTime();
    for(int i=0;i<1000;i++)test(&in1[1],out,TEST_SIZE);
    printTime(1000);
    for(int i=0;i<40;i++)std::printf("%d ",out[i]);
    std::printf("\n");

    getTime();
    for(int i=0;i<1000;i++)std::memcpy(out,(uint8_t*)(&in1[1]),(TEST_SIZE-8)*sizeof(q15));
    printTime(1000);

    getTime();
    for(int i=0;i<1000;i++)std::memcpy(out,in1,(TEST_SIZE)*sizeof(q15));
    printTime(1000);

}
