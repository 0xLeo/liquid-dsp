	.cpu generic+fp+simd
	.file	"DSPlib2.c"
	.text
	.align	2
	.global	sumAllElements
	.type	sumAllElements, %function
sumAllElements:
	fcvtzs	w1, s0
	add	x1, x0, x1, sxtw 2
	cmp	x1, x0, sxtw
	bls	.L4
	movi	v1.4s, 0
.L3:
	ldr	q0, [x0], 16
	cmp	x1, x0, sxtw
	fadd	v1.4s, v1.4s, v0.4s
	bhi	.L3
	orr	v0.16b, v1.16b, v1.16b
.L2:
#APP
// 5747 "/usr/lib/gcc/aarch64-linux-gnu/4.9/include/arm_neon.h" 1
	ins v1.d[0], v1.d[1]
// 0 "" 2
#NO_APP
	fadd	v1.2s, v1.2s, v0.2s
	dup	s0, v1.s[0]
	dup	s1, v1.s[1]
	fadd	s0, s1, s0
	ret
.L4:
	movi	v0.4s, 0
	movi	v1.4s, 0
	b	.L2
	.size	sumAllElements, .-sumAllElements
	.align	2
	.global	mul_el
	.type	mul_el, %function
mul_el:
	stp	x29, x30, [sp, -48]!
	add	x29, sp, 0
	str	x19, [sp, 16]
	mov	x19, x0
	sbfiz	x0, x2, 2, 32
	str	w2, [x29, 44]
	str	x1, [x29, 32]
	bl	malloc
	ldr	w2, [x29, 44]
	cmp	w2, wzr
	ble	.L12
	sub	w2, w2, #1
	ldr	x1, [x29, 32]
	ubfx	x2, x2, 2, 30
	mov	x3, 0
	add	x2, x2, 1
	lsl	x2, x2, 4
.L9:
	ldr	q1, [x19, x3]
	ldr	q0, [x1, x3]
	fmul	v0.4s, v0.4s, v1.4s
	str	q0, [x0, x3]
	add	x3, x3, 16
	cmp	x3, x2
	bne	.L9
.L12:
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 48
	ret
	.size	mul_el, .-mul_el
	.align	2
	.global	dot_prod
	.type	dot_prod, %function
dot_prod:
	stp	x29, x30, [sp, -32]!
	add	x29, sp, 0
	str	x19, [sp, 16]
	mov	w19, w2
	bl	mul_el
	ucvtf	s0, w19
	fcvtzs	w1, s0
	add	x1, x0, x1, sxtw 2
	cmp	x1, x0, sxtw
	bls	.L16
	movi	v1.4s, 0
.L15:
	ldr	q0, [x0], 16
	cmp	x1, x0, sxtw
	fadd	v1.4s, v1.4s, v0.4s
	bhi	.L15
	orr	v0.16b, v1.16b, v1.16b
.L14:
#APP
// 5747 "/usr/lib/gcc/aarch64-linux-gnu/4.9/include/arm_neon.h" 1
	ins v1.d[0], v1.d[1]
// 0 "" 2
#NO_APP
	fadd	v1.2s, v1.2s, v0.2s
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 32
	dup	s0, v1.s[0]
	dup	s1, v1.s[1]
	fadd	s0, s0, s1
	ret
.L16:
	movi	v0.4s, 0
	movi	v1.4s, 0
	b	.L14
	.size	dot_prod, .-dot_prod
	.align	2
	.global	autocorr
	.type	autocorr, %function
autocorr:
	stp	x29, x30, [sp, -96]!
	add	x29, sp, 0
	stp	x19, x20, [sp, 16]
	uxtw	x19, w1
	lsl	x2, x19, 2
	str	x2, [x29, 88]
	stp	x23, x24, [sp, 48]
	mov	x23, x0
	mov	x0, x2
	stp	x21, x22, [sp, 32]
	str	d8, [sp, 64]
	bl	malloc
	mov	x21, x0
	lsl	x0, x19, 3
	sub	w22, w19, #1
	mov	x20, x19
	bl	malloc
	mov	x24, x0
	ldr	x2, [x29, 88]
	mov	x1, x23
	bl	memcpy
	tbnz	w22, #31, .L27
	ucvtf	s8, w19
	mov	x19, 0
.L22:
	mov	w2, w20
	mov	x1, x24
	mov	x0, x23
	bl	mul_el
	fcvtzs	w3, s8
	add	x3, x0, x3, sxtw 2
	cmp	x3, x0, sxtw
	bls	.L24
	movi	v0.4s, 0
.L21:
	ldr	q1, [x0], 16
	cmp	x3, x0, sxtw
	fadd	v0.4s, v0.4s, v1.4s
	bhi	.L21
	orr	v1.16b, v0.16b, v0.16b
.L20:
#APP
// 5747 "/usr/lib/gcc/aarch64-linux-gnu/4.9/include/arm_neon.h" 1
	ins v0.d[0], v0.d[1]
// 0 "" 2
#NO_APP
	fadd	v0.2s, v0.2s, v1.2s
	add	x24, x24, 4
	dup	s1, v0.s[0]
	dup	s0, v0.s[1]
	fadd	s0, s1, s0
	str	s0, [x21, x19, lsl 2]
	add	x19, x19, 1
	cmp	w22, w19
	bge	.L22
.L27:
	mov	x0, x21
	ldp	x19, x20, [sp, 16]
	ldp	x21, x22, [sp, 32]
	ldp	x23, x24, [sp, 48]
	ldr	d8, [sp, 64]
	ldp	x29, x30, [sp], 96
	ret
.L24:
	movi	v1.4s, 0
	movi	v0.4s, 0
	b	.L20
	.size	autocorr, .-autocorr
	.ident	"GCC: (Debian/Linaro 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
