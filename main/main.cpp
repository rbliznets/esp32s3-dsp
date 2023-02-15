#include <cstdio>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include <cstring>

#include "test.h"

__attribute__((aligned(16)))
q15 in1[TEST_SIZE];
__attribute__((aligned(16)))
q15 in2[TEST_SIZE];
__attribute__((aligned(16)))
q15 out[TEST_SIZE];
__attribute__((aligned(16)))
complex_q15 inc[TEST_SIZE];
__attribute__((aligned(16)))
q15 kgauss[24]={1,4,15,52,151,380,832,1579,2599,3710,4594,4933,4594,3710,2599,1579,832,380,151,52,15,4,1,0};

int64_t mTime=0;

int64_t getTime()
{
    int64_t res=0;
    int64_t time = esp_timer_get_time();
    res=time-mTime;		
    mTime=time;
    return res;
};

void printTime(const char* str, uint32_t n=1)
{
    uint64_t time = getTime();
    std::printf("%s(%ld): ",str,n);
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

void test_copy();
void test_scalevector();
void test_dotproduct();
void test_fir();
void test_complex();

extern "C" void app_main(void)
{
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    std::printf("This is %s (%dMHz) chip with %d CPU core(s), WiFi%s%s, ",
            CONFIG_IDF_TARGET,CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ,
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
    std::printf("silicon revision %d, ", chip_info.revision);
    std::printf("Minimum free heap size: %d bytes\n", (int)esp_get_minimum_free_heap_size());
#ifdef CONFIG_CHECK_PARAM
    std::printf("CONFIG_CHECK_PARAM enable\n");
#endif 
    std::printf("\n");

    // test_copy();
    // test_scalevector();
    // test_dotproduct();
    // test_fir();
    test_complex();
}
