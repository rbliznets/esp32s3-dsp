    .text
    .align  4
    .global dot_product_q15_pie
    .type   dot_product_q15_pie,@function
dot_product_q15_pie: 
// in1   - a2
// in2   - a3
// size  - a4
    entry	a1, 16

    srli 	a4, a4, 3           //  size/8 	
    ee.zero.accx                //  accx = 0 	
    ee.vld.128.ip   q0, a2, 16  //  in1[0..7] -> q0	
    ee.vld.128.ip   q1, a3, 16  //  in2[0..7] -> q1	

    loopnez a4, .loop_end_dot_product_q15_pie
        ee.vmulas.s16.accx.ld.ip    q0, a2, 16, q0, q1  // accx += dotproduct(q0,q1);  in1[n..n+7] -> q0
        ee.vld.128.ip               q1, a3, 16          // in2[n..n+7] -> q1
    .loop_end_dot_product_q15_pie:

    movi.n	a5, 0
    EE.SRS.ACCX a2, a5, 0  // a2 = sat(accx)
    //SRAI a2, a2, 15        // a2 = a2 >> 15

    retw.n
