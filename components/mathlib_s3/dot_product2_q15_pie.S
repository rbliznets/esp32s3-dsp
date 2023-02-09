    .text
    .align  4
    .global dot_product2_q15_pie
    .type   dot_product2_q15_pie,@function
dot_product2_q15_pie: 
// in   - a2
// out   - a3
// size  - a4
    entry	a1, 16

    srli 	a4, a4, 3           //  size/8 	

    EE.LD.128.USAR.IP   q0, a2, 16 
    
    loopnez a4, .loop_end_dot_product2_q15_pie
        EE.LD.128.USAR.IP   q1, a2, 16 
        EE.SRC.Q.QUP        q2, q0,q1
        ee.vst.128.ip       q2, a3, 16
    .loop_end_dot_product2_q15_pie:

    retw.n

    .text
    .align  4
    .global dot_product3_q15_pie
    .type   dot_product3_q15_pie,@function
dot_product3_q15_pie: 
// in   - a2
// out   - a3
// size  - a4
    entry	a1, 16

    srli 	a4, a4, 3           //  size/8 	

    loopnez a4, .loop_end_dot_product3_q15_pie
        ee.vld.128.ip   q1, a2, 16 
        ee.vst.128.ip   q1, a3, 16
    .loop_end_dot_product3_q15_pie:

    retw.n

