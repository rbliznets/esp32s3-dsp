# esp32s3-dsp

```
This is esp32s3 (240MHz) chip with 2 CPU core(s), WiFi/BLE, silicon revision 1, Minimum free heap size: 379416 bytes

**** Data size 1016 *****
copy_16(1000): 1715nsec
copy(1000): 2244nsec
std::memcpy(1000): 5459nsec

**** Data size 1016 *****
scaleVector_16(1000): 1732nsec
scaleVector(1000): 2279nsec
scaleVector_c(1000): 46usec

**** Data size 1016 *****
dot_product_16_16(1000): 1771nsec
dot_product_1_16(1000): 2306nsec
dot_product_c(1000): 38usec

**** Data size 1000 *****
fir_1_16(1000): 196usec
fir_16_16_q15(1000): 36usec
```
