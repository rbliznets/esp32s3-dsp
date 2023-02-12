
    .text
    .align  4
	.literal_position
	.literal	.SAT_MAX_30, 1073692671
	.literal	.SAT_MIN_30, -1073692672
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

    l32r	a7, .SAT_MAX_30
    EE.MOVI.32.Q q6, a7, 0
    EE.MOVI.32.Q q6, a7, 1
    EE.MOVI.32.Q q6, a7, 2
    EE.MOVI.32.Q q6, a7, 3
    l32r	a7, .SAT_MIN_30
    EE.MOVI.32.Q q7, a7, 0
    EE.MOVI.32.Q q7, a7, 1
    EE.MOVI.32.Q q7, a7, 2
    EE.MOVI.32.Q q7, a7, 3

    movi.n a7,1
    wur.sar_byte a7
    EE.ZERO.QACC
    ee.vst.128.ip  q0, a2, 16
    ee.vst.128.ip  q1, a3, 16

    EE.VSMULAS.S16.QACC q0, q1, 0
    EE.VLDBC.16.IP q2, a2, 2
    EE.SRC.Q q0, q0, q2

    EE.VSMULAS.S16.QACC q0, q1, 1
    EE.VLDBC.16.IP q2, a2, 2
    EE.SRC.Q q0, q0, q2

    EE.VSMULAS.S16.QACC q0, q1, 2
    EE.VLDBC.16.IP q2, a2, 2
    EE.SRC.Q q0, q0, q2

    EE.VSMULAS.S16.QACC q0, q1, 3
    EE.VLDBC.16.IP q2, a2, 2
    EE.SRC.Q q0, q0, q2

    EE.VSMULAS.S16.QACC q0, q1, 4
    EE.VLDBC.16.IP q2, a2, 2
    EE.SRC.Q q0, q0, q2

    EE.VSMULAS.S16.QACC q0, q1, 5
    EE.VLDBC.16.IP q2, a2, 2
    EE.SRC.Q q0, q0, q2

    EE.VSMULAS.S16.QACC q0, q1, 6
    EE.VLDBC.16.IP q2, a2, 2
    EE.SRC.Q q0, q0, q2

    EE.VSMULAS.S16.QACC q0, q1, 7
    EE.VLDBC.16.IP q2, a2, 2
    EE.SRC.Q q0, q0, q2

    retw.n
