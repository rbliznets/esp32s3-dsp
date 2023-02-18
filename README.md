# esp32s3-dsp

```
This is esp32s3 (240MHz) chip with 2 CPU core(s), WiFi/BLE, silicon revision 1, Minimum free heap size: 375320 bytes

**** Data size 1016 *****
copy_16(1000): 1718nsec
copy(1000): 2245nsec
std::memcpy(1000): 5460nsec

**** Data size 1016 *****
scaleVector_16(1000): 1732nsec
scaleVector(1000): 2273nsec
scaleVector_c(1000): 46usec

**** Data size 1016 *****
dot_product_16_16(1000): 1770nsec
dot_product_1_16(1000): 2311nsec
dot_product_c(1000): 38usec

**** Data size 1000 *****
fir_1_16(1000): 196usec
fir_16_16_q15(1000): 36usec

**** Data size 1016 *****
arg_q15(1): 212usec
arg_q15(1000): 198usec
**** Data size 1 *****
float std::arg(1000): 1102nsec
arg_fr16(1000): 13usec
arg(1000): 692nsec

**** Data size 1 *****
sincos_q15(1000): 811nsec
```
