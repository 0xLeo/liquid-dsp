   0x0000000000400994 <+0>:	stp	x29, x30, [sp,#-144]!
   0x0000000000400998 <+4>:	mov	x29, sp
   0x000000000040099c <+8>:	str	x0, [x29,#40]
   0x00000000004009a0 <+12>:	str	x1, [x29,#32]
   0x00000000004009a4 <+16>:	str	w2, [x29,#28]
   0x00000000004009a8 <+20>:	ldrsw	x0, [x29,#28]
   0x00000000004009ac <+24>:	lsl	x0, x0, #2
   0x00000000004009b0 <+28>:	bl	0x400540 <malloc@plt>
   0x00000000004009b4 <+32>:	str	x0, [x29,#128]
   0x00000000004009b8 <+36>:	str	wzr, [x29,#140]
   0x00000000004009bc <+40>:	b	0x400a9c <mul_el+264>
   0x00000000004009c0 <+44>:	ldrsw	x0, [x29,#140]
   0x00000000004009c4 <+48>:	lsl	x0, x0, #2
   0x00000000004009c8 <+52>:	ldr	x1, [x29,#128]
   0x00000000004009cc <+56>:	add	x2, x1, x0
   0x00000000004009d0 <+60>:	ldrsw	x0, [x29,#140]
   0x00000000004009d4 <+64>:	lsl	x0, x0, #2
   0x00000000004009d8 <+68>:	ldr	x1, [x29,#40]
   0x00000000004009dc <+72>:	add	x0, x1, x0
   0x00000000004009e0 <+76>:	str	x0, [x29,#120]
   0x00000000004009e4 <+80>:	ldr	x0, [x29,#120]
   0x00000000004009e8 <+84>:	ldr	q0, [x0]
   0x00000000004009ec <+88>:	mov	x3, v0.d[0]
   0x00000000004009f0 <+92>:	mov	x4, v0.d[1]
   0x00000000004009f4 <+96>:	ldrsw	x0, [x29,#140]
   0x00000000004009f8 <+100>:	lsl	x0, x0, #2
   0x00000000004009fc <+104>:	ldr	x1, [x29,#32]
   0x0000000000400a00 <+108>:	add	x0, x1, x0
   0x0000000000400a04 <+112>:	str	x0, [x29,#112]
   0x0000000000400a08 <+116>:	ldr	x0, [x29,#112]
   0x0000000000400a0c <+120>:	ldr	q0, [x0]
   0x0000000000400a10 <+124>:	mov	x0, v0.d[0]
   0x0000000000400a14 <+128>:	mov	x1, v0.d[1]
   0x0000000000400a18 <+132>:	fmov	d0, x3
   0x0000000000400a1c <+136>:	mov	v0.d[1], x4
   0x0000000000400a20 <+140>:	str	q0, [x29,#96]
   0x0000000000400a24 <+144>:	fmov	d0, x0
   0x0000000000400a28 <+148>:	mov	v0.d[1], x1
   0x0000000000400a2c <+152>:	str	q0, [x29,#80]
   0x0000000000400a30 <+156>:	ldr	q0, [x29,#96]
   0x0000000000400a34 <+160>:	mov	x3, v0.d[0]
   0x0000000000400a38 <+164>:	mov	x4, v0.d[1]
   0x0000000000400a3c <+168>:	ldr	q0, [x29,#80]
   0x0000000000400a40 <+172>:	mov	x0, v0.d[0]
   0x0000000000400a44 <+176>:	mov	x1, v0.d[1]
   0x0000000000400a48 <+180>:	fmov	d0, x3
   0x0000000000400a4c <+184>:	mov	v0.d[1], x4
   0x0000000000400a50 <+188>:	fmov	d1, x0
   0x0000000000400a54 <+192>:	mov	v1.d[1], x1
   0x0000000000400a58 <+196>:	fmul	v0.4s, v0.4s, v1.4s
   0x0000000000400a5c <+200>:	mov	x0, v0.d[0]
   0x0000000000400a60 <+204>:	mov	x1, v0.d[1]
   0x0000000000400a64 <+208>:	str	x2, [x29,#72]
   0x0000000000400a68 <+212>:	fmov	d0, x0
   0x0000000000400a6c <+216>:	mov	v0.d[1], x1
   0x0000000000400a70 <+220>:	str	q0, [x29,#48]
   0x0000000000400a74 <+224>:	ldr	x0, [x29,#72]
   0x0000000000400a78 <+228>:	ldr	q0, [x29,#48]
   0x0000000000400a7c <+232>:	mov	x1, v0.d[0]
   0x0000000000400a80 <+236>:	mov	x2, v0.d[1]
   0x0000000000400a84 <+240>:	fmov	d0, x1
   0x0000000000400a88 <+244>:	mov	v0.d[1], x2
   0x0000000000400a8c <+248>:	str	q0, [x0]
   0x0000000000400a90 <+252>:	ldr	w0, [x29,#140]
   0x0000000000400a94 <+256>:	add	w0, w0, #0x4
   0x0000000000400a98 <+260>:	str	w0, [x29,#140]
   0x0000000000400a9c <+264>:	ldr	w1, [x29,#140]
   0x0000000000400aa0 <+268>:	ldr	w0, [x29,#28]
   0x0000000000400aa4 <+272>:	cmp	w1, w0
   0x0000000000400aa8 <+276>:	b.lt	0x4009c0 <mul_el+44>
   0x0000000000400aac <+280>:	ldr	x0, [x29,#128]
   0x0000000000400ab0 <+284>:	ldp	x29, x30, [sp],#144
   0x0000000000400ab4 <+288>:	ret
