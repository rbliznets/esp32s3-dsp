
    .text
    .align  4
    .global scaleVectors_q15_pie
    .type   scaleVectors_q15_pie,@function
// The function implements the following C code:
//void scaleVectors(int16_t* in, int16_t* k, int16_t* out, uint32_t size)
//{
//    for(uint32_t i=0; i<size; i++)
//    {
//        out[i]=(in1[i]*(*k)) >> 15;
//    }
//}
scaleVectors_q15_pie: 
// in   - a2
// k   - a3
// out   - a4
// size  - a5
    entry	a1, 16

    srli 	a5, a5, 3 //  size/8 	

    ee.vld.128.ip   q0, a2, 16
    ee.vldbc.16     q1, a3     // q1 = 8[k]
    ssai            15         // sar = 15 

    loopnez a5, .loop_end_scaleVector_q15_pie
        ee.vmul.s16.ld.incp     q0, a2, q2, q0, q1
        ee.vst.128.ip           q2, a4, 16
    .loop_end_scaleVector_q15_pie:
    retw.n

