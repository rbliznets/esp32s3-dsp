    .text
    .type   cmul_q15_pie,@function
    .align  4
    .global cmul_q15_pie
cmul_q15_pie: 
// x   - a2
// y   - a3
// return z=x*y - a2
    entry	a1, 16
    
    ssai    15 

    EE.MOVI.32.Q q0, a2, 0
    EE.MOVI.32.Q q1, a3, 0
    EE.CMUL.S16 q2, q0, q1, 0
    EE.MOVI.32.A q2, a2, 0

    retw.n
/////////////////////////////////////////////////////////////////////////////////
    .text
    .type   cmul10_q15_pie,@function
    .align  4
    .global cmul10_q15_pie
cmul10_q15_pie: 
// in1[10]   - a2
// k[1]   - a3
// out[10]   - a4
    entry	a1, 16
    
    ssai    15 
    EE.VLDBC.32 q1, a3          // k -> q1

    EE.VLD.128.IP q0, a2, 16    // in1[0..3] -> q0
    EE.CMUL.S16 q2, q0, q1, 0 
    //EE.CMUL.S16.LD.INCP q1, a2, q2, q0, q1, 1 // q2=q0*q1, in1[4..7] -> q0
    EE.CMUL.S16 q2, q0, q1, 1 // q2=q0*q1, 
    EE.VST.128.IP q2, a4, 16    // q2 -> out[0..3]

    EE.VLD.128.IP q0, a2, 16    // in1[4..7] -> q0
    EE.CMUL.S16 q2, q0, q1, 0 
     //EE.CMUL.S16.ST.INCP q2, a4, q2, q0, q1, 0 
    //EE.CMUL.S16.LD.INCP q1, a2, q2, q0, q1, 1 // q2=q0*q1, in1[8..11] -> q0
    EE.CMUL.S16 q2, q0, q1, 1 // q2=q0*q1, in1[8..11] -> q0
    EE.VST.128.IP q2, a4, 16    // q2 -> out[4..7]

    EE.VLD.128.IP q0, a2, 0    // in1[8..11] -> q0
    EE.CMUL.S16 q2, q0, q1, 0 // q2=q0*q1
    //EE.CMUL.S16.ST.INCP q2, a4, q2, q0, q1, 0 // q2=q0*q1
    EE.VST.L.64.IP q2, a4, 0   // q2 -> out[8 9]

    retw.n
