#include <assert.h>
#include "mathlib_s3.h"
#include "sdkconfig.h"

static const q15 tan_array[13]={4095, 2417, 1277, 648, 325, 162, 81, 40, 20, 10, 4, 2, 1};
q15 atan2_q15_s3(q15 y, q15 x, const q15* tan);
inline q15 atan2_q15(q15 y, q15 x)
{
    return atan2_q15_s3(y,x,tan_array);
    // q15 xn, x1 = abs(x);
    // q15 sum = 0;
    // for(int16_t i=0; i < 13; i++)
    // {
    //     if(y > 0)
    //     {
    //         xn = x1 + (y >> i);
    //         y = y - (x1 >> i);
    //         sum += tan_array[i];
    //     }
    //     else if(y < 0)
    //     {
    //         xn = x1 - (y >> i);
    //         y = y + (x1 >> i);
    //         sum -= tan_array[i];
    //     }
    //     else break;
    //     x1 = xn;
    // }
    // if(x < 0)
    // {
    //     if(sum < 0)
    //     {
    //         sum = -16383-sum;
    //     }
    //     else
    //     {
    //         sum = 16383-sum;
    //     }
    // }
    // return sum;
}
