	.cpu generic+fp+simd
	.file	"DSPlib1.c"
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
	.ident	"GCC: (Debian/Linaro 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
