    .data
    .section .rodata.embedded
fir_SAT_MAX_30: 
	.word 16383
	.word -16384

    .text
    .align  4
///////////////////////////////////////////////////////////////////////////////////////////////////////
    .type   fir_q15_pie,@function
    .align  4
    .global fir_q15_pie
fir_q15_pie: 
// in   - a2
// k    - a3
// ksize- a4
// out  - a5
// size - a6
    entry	a1, 16

    //l32r	a7, fir_SAT_MAX_30

    EE.VLDBC.16.IP q6, a7, 2
    EE.VLDBC.16 q7, a7

    ee.vst.128.ip       q6, a5, 16
    ee.vst.128.ip       q7, a5, 16

    s32i.n  a7,a5,0

    retw.n
