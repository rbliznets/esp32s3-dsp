    .text
    .align  4
	.literal_position
	.literal	.PLUS_PI, 16383
	.literal	.MINUS_PI, -16383
///////////////////////////////////////////////////////////////////////////////////////////////////////
    .type   atan2_q15_s3,@function
    .align  4
    .global atan2_q15_s3
atan2_q15_s3: 
// y   - a2
// x   - a3
// tan - a4
    entry	a1, 16

    abs 	a5, a3       // x1 = abs(x)	
    movi.n  a6, 0        // sum = 0

    // 0 step
    l16si   a8, a4, 0   // a8 = tan[0]
    bgez a2, .step0
        // y < 0
        sub a7,a5,a2    // xn = x1 - y
        add.n a2,a2,a5  // y = y + x1
        sub a6,a6,a8  // sum -= tan[0]
        j .step0_end
    .step0:
        // y >= 0
        add.n a7,a5,a2  // xn = x1 + y
        sub a2,a2,a5    // y = y - x1
        add.n a6,a6,a8  // sum += tan[0]
    .step0_end:
        beqz a2,.step12_end
        mov.n a5,a7     //  x1 = xn

    // 1 step
    l16si a8, a4, 2     // a8 = tan[1]
    srai a9, a5, 1      // a9 = (x1 >> 1)    
    srai a10, a2, 1     // a10 = (y >> 1)    
    bgez a2, .step1
        // y < 0
        sub a7,a5,a10    // xn = x1 - (y >> 1)
        add.n a2,a2,a9  // y = y + (x1 >> 1) 
        sub a6,a6,a8  // sum -= tan[1]
        j .step1_end
    .step1:
        // y >= 0
        add.n a7,a5,a10  // xn = x1 + (y >> 1)
        sub a2,a2,a9    // y = y - (x1 >> 1) 
        add.n a6,a6,a8  // sum += tan[1]
    .step1_end:
        beqz a2,.step12_end
        mov.n a5,a7    //  x1 = xn

    // 2 step
    l16si a8, a4, 4     // a8 = tan[2]
    srai a9, a5, 2      // a9 = (x1 >> 2)    
    srai a10, a2, 2     // a10 = (y >> 2)    
    bgez a2, .step2
        // y < 0
        sub a7,a5,a10    // xn = x1 - (y >> 2)
        add.n a2,a2,a9  // y = y + (x1 >> 2) 
        sub a6,a6,a8  // sum -= tan[2]
        j .step2_end
    .step2:
        // y >= 0
        add.n a7,a5,a10  // xn = x1 + (y >> 2)
        sub a2,a2,a9    // y = y - (x1 >> 2) 
        add.n a6,a6,a8  // sum += tan[2]
    .step2_end:
        beqz a2,.step12_end
        mov.n a5,a7    //  x1 = xn

    // 3 step
    l16si a8, a4, 6     // a8 = tan[3]
    srai a9, a5, 3      // a9 = (x1 >> 3)    
    srai a10, a2, 3     // a10 = (y >> 3)    
    bgez a2, .step3
        // y < 0
        sub a7,a5,a10    // xn = x1 - (y >> 3)
        add.n a2,a2,a9  // y = y + (x1 >> 3) 
        sub a6,a6,a8  // sum -= tan[3]
        j .step3_end
    .step3:
        // y >= 0
        add.n a7,a5,a10  // xn = x1 + (y >> 3)
        sub a2,a2,a9    // y = y - (x1 >> 3) 
        add.n a6,a6,a8  // sum += tan[3]
    .step3_end:
        beqz a2,.step12_end
        mov.n a5,a7    //  x1 = xn

    // 4 step
    l16si a8, a4, 8     // a8 = tan[4]
    srai a9, a5, 4      // a9 = (x1 >> 4)    
    srai a10, a2, 4     // a10 = (y >> 4)    
    bgez a2, .step4
        // y < 0
        sub a7,a5,a10    // xn = x1 - (y >> 4)
        add.n a2,a2,a9  // y = y + (x1 >> 4) 
        sub a6,a6,a8  // sum -= tan[4]
        j .step4_end
    .step4:
        // y >= 0
        add.n a7,a5,a10  // xn = x1 + (y >> 4)
        sub a2,a2,a9    // y = y - (x1 >> 4) 
        add.n a6,a6,a8  // sum += tan[4]
    .step4_end:
        beqz a2,.step12_end
        mov.n a5,a7    //  x1 = xn

    // 5 step
    l16si a8, a4, 10     // a8 = tan[5]
    srai a9, a5, 5      // a9 = (x1 >> 5)    
    srai a10, a2, 5     // a10 = (y >> 5)    
    bgez a2, .step5
        // y < 0
        sub a7,a5,a10    // xn = x1 - (y >> 5)
        add.n a2,a2,a9  // y = y + (x1 >> 5) 
        sub a6,a6,a8  // sum -= tan[5]
        j .step5_end
    .step5:
        // y >= 0
        add.n a7,a5,a10  // xn = x1 + (y >> 5)
        sub a2,a2,a9    // y = y - (x1 >> 5) 
        add.n a6,a6,a8  // sum += tan[5]
    .step5_end:
        beqz a2,.step12_end
        mov.n a5,a7    //  x1 = xn

    // 6 step
    l16si a8, a4, 12     // a8 = tan[6]
    srai a9, a5, 6      // a9 = (x1 >> 6)    
    srai a10, a2, 6     // a10 = (y >> 6)    
    bgez a2, .step6
        // y < 0
        sub a7,a5,a10    // xn = x1 - (y >> 6)
        add.n a2,a2,a9  // y = y + (x1 >>6) 
        sub a6,a6,a8  // sum -= tan[6]
        j .step6_end
    .step6:
        // y >= 0
        add.n a7,a5,a10  // xn = x1 + (y >> 6)
        sub a2,a2,a9    // y = y - (x1 >> 6) 
        add.n a6,a6,a8  // sum += tan[6]
    .step6_end:
        beqz a2,.step12_end
        mov.n a5,a7    //  x1 = xn

    // 7 step
    l16si a8, a4, 14     // a8 = tan[7]
    srai a9, a5, 7      // a9 = (x1 >> 7)    
    srai a10, a2, 7     // a10 = (y >> 7)    
    bgez a2, .step7
        // y < 0
        sub a7,a5,a10    // xn = x1 - (y >> 7)
        add.n a2,a2,a9  // y = y + (x1 >>7) 
        sub a6,a6,a8  // sum -= tan[7]
        j .step7_end
    .step7:
        // y >= 0
        add.n a7,a5,a10  // xn = x1 + (y >> 7)
        sub a2,a2,a9    // y = y - (x1 >> 7) 
        add.n a6,a6,a8  // sum += tan[7]
    .step7_end:
        beqz a2,.step12_end
        mov.n a5,a7    //  x1 = xn

    // 8 step
    l16si a8, a4, 16     // a8 = tan[8]
    srai a9, a5, 8      // a9 = (x1 >> 8)    
    srai a10, a2, 8     // a10 = (y >> 8)    
    bgez a2, .step8
        // y < 0
        sub a7,a5,a10    // xn = x1 - (y >> 8)
        add.n a2,a2,a9  // y = y + (x1 >>8) 
        sub a6,a6,a8  // sum -= tan[8]
        j .step8_end
    .step8:
        // y >= 0
        add.n a7,a5,a10  // xn = x1 + (y >> 8)
        sub a2,a2,a9    // y = y - (x1 >> 8) 
        add.n a6,a6,a8  // sum += tan[8]
    .step8_end:
        beqz a2,.step12_end
        mov.n a5,a7    //  x1 = xn

    // 9 step
    l16si a8, a4, 18     // a8 = tan[9]
    srai a9, a5, 9      // a9 = (x1 >> 9)    
    srai a10, a2, 9     // a10 = (y >> 9)    
    bgez a2, .step9
        // y < 0
        sub a7,a5,a10    // xn = x1 - (y >> 9)
        add.n a2,a2,a9  // y = y + (x1 >>9) 
        sub a6,a6,a8  // sum -= tan[9]
        j .step9_end
    .step9:
        // y >= 0
        add.n a7,a5,a10  // xn = x1 + (y >> 9)
        sub a2,a2,a9    // y = y - (x1 >> 9) 
        add.n a6,a6,a8  // sum += tan[9]
    .step9_end:
        beqz a2,.step12_end
        mov.n a5,a7    //  x1 = xn

    // 10 step
    l16si a8, a4, 20     // a8 = tan[10]
    srai a9, a5, 10      // a9 = (x1 >> 10)    
    srai a10, a2, 10     // a10 = (y >> 10)    
    bgez a2, .step10
        // y < 0
        sub a7,a5,a10    // xn = x1 - (y >> 10)
        add.n a2,a2,a9  // y = y + (x1 >>10) 
        sub a6,a6,a8  // sum -= tan[10]
        j .step10_end
    .step10:
        // y >= 0
        add.n a7,a5,a10  // xn = x1 + (y >> 10)
        sub a2,a2,a9    // y = y - (x1 >> 10) 
        add.n a6,a6,a8  // sum += tan[10]
    .step10_end:
        beqz a2,.step12_end
        mov.n a5,a7    //  x1 = xn

    // 11 step
    l16si a8, a4, 22     // a8 = tan[11]
    srai a9, a5, 11      // a9 = (x1 >> 11)    
    srai a10, a2, 11     // a10 = (y >> 11)    
    bgez a2, .step11
        // y < 0
        sub a7,a5,a10    // xn = x1 - (y >> 11)
        add.n a2,a2,a9  // y = y + (x1 >>11) 
        sub a6,a6,a8  // sum -= tan[11]
        j .step11_end
    .step11:
        // y >= 0
        add.n a7,a5,a10  // xn = x1 + (y >> 11)
        sub a2,a2,a9    // y = y - (x1 >> 11) 
        add.n a6,a6,a8  // sum += tan[11]
    .step11_end:
        beqz a2,.step12_end

    // 12 step
    l16si a8, a4, 24     // a8 = tan[12]
    bgez a2, .step12
        // y < 0
        sub a6,a6,a8  // sum -= tan[12]
        j .step12_end
    .step12:
        // y >= 0
        add.n a6,a6,a8  // sum += tan[12]
    .step12_end:

    bgez a3,.end_atan2_q15_s3
        // x < 0
        bgez a6,.last_check
            // sum < 0
            l32r a7,.MINUS_PI
            j .end1_atan2_q15_s3
        .last_check:
            // sum >= 0
            l32r a7,.PLUS_PI
        .end1_atan2_q15_s3:
        sub a2,a7,a6
        retw.n
    .end_atan2_q15_s3:
    mov.n a2,a6
    retw.n
///////////////////////////////////////////////////////////////////////////////////////////////////////
    .type   arg_q15_pie,@function
    .align  4
    .global arg_q15_pie
arg_q15_pie: 
// in   - a2
// out  - a3
// size  - a4
// tan - a5
    entry	a1, 16

    EE.VLD.128.IP q0, a2, 16
    EE.VLD.128.IP q1, a2, 16
    EE.VUNZIP.16 q0, q1         // x -> q0, y -> q1

    EE.ZERO.Q q7
    EE.ZERO.Q q6            // sum -> q6
    EE.MOV.S16.QACC q0      // x-> QACC

    MOVI.N a6, -1
    MOVI.N a7, 0
    EE.VRELU.S16 q0, a6, a7     // abs(x) -> q0

    WSR.SAR a7
    // step 0
    EE.VCMP.LT.S16 q5, q1, q7  // neg y
    EE.VCMP.GT.S16 q4, q1, q7  // pos y

    // xn = x1 + y or xn = x1 - y
    EE.VMUL.S16 q3, q1, q4 // pos -y
    EE.VSUBS.S16 q2, q0, q3 // |x|-(-y) -> q2
    EE.VMUL.S16 q3, q1, q5 // neg -y
    EE.VADDS.S16 q2, q2, q3 // |x|+(-y) -> q2

    // y = y - x1 or y = y + x1
    EE.VMUL.S16 q3, q0, q4 // pos -|x|
    EE.VADDS.S16 q1, q1, q3 // y = y + (-|x|); -> q1
    EE.VMUL.S16 q3, q0, q5 // neg -|x|
    EE.VSUBS.S16 q1, q1, q3 // y - (-|x|) -> q1
    
    EE.VADDS.S16 q0, q2, q7     // x1 = xn

    //  sum += tan[0] or sum -= tan[0]
    EE.VLDBC.16.IP q2, a5, 2   // q2 = 8{tan[0]}
    EE.VMUL.S16 q4, q2, q4 // pos -tan[0]
    EE.VSUBS.S16 q6, q6, q4 // sum = sum -(-tan[0])
    EE.VMUL.S16 q5, q2, q5 // neg -tan[0]
    EE.VADDS.S16 q6, q6, q6 // sum = sum +(-tan[0])

    EE.VST.128.IP q6, a3, 16 //@@@@ debug step 0

    retw.n
