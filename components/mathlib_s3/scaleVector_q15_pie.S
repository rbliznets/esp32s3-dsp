
// The function implements the following C code:
//void scaleVector(q15* in, q15* k, q15* out, uint32_t size)
//{
//    for(uint32_t i=0; i<size; i++)
//    {
//        out[i]=(in1[i]*(*k)) >> 15;
//    }
//}

    .text
    .align  4
    .global scaleVector_q15_16_pie
    .type   scaleVector_q15_16_pie,@function
scaleVector_q15_16_pie: 
// in   - a2
// k   - a3
// out   - a4
// size  - a5
    entry	a1, 16

    srli 	a5, a5, 3 //  size/8 	

    EE.LD.128.USAR.IP   q3, a2, 16 
    ee.vldbc.16     q1, a3     // q1 = 8[k]
    ssai            15         // sar = 15 

    loopnez a5, .loop_end_scaleVector_q15_16_pie
        EE.LD.128.USAR.IP   q4, a2, 16 
        EE.SRC.Q.QUP        q0, q3,q4
        ee.vmul.s16         q2, q0, q1
        ee.vst.128.ip       q2, a4, 16
    .loop_end_scaleVector_q15_16_pie:
    retw.n

    .text
    .align  4
    .global scaleVector_q15_pie
    .type   scaleVector_q15_pie,@function
scaleVector_q15_pie: 
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

