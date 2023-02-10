# esp32s3-dsp

This is esp32s3 chip with 2 CPU core(s), WiFi/BLE, silicon revision 1, Minimum free heap size: 380832 bytes

**** Data size 1016 *****
copy_16(1000): 2561nsec
copy(1000): 3358nsec
std::memcpy(1000): 8192nsec

**** Data size 1016 *****
scaleVector_16(1000): 2601nsec
scaleVector(1000): 3405nsec
scaleVector_c(1000): 69usec

**** Data size 1016 *****
dot_product_16_16(1000): 2650nsec
dot_product_1_16(1000): 3462nsec
dot_product_c(1000): 57usec
