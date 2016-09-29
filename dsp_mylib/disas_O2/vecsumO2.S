	.cpu generic+fp+simd
	.file	"DSPlib3.c"
	.text
	.align	2
	.global	sum_vec
	.type	sum_vec, %function
sum_vec:
	stp	x29, x30, [sp, -48]!
	add	x29, sp, 0
	stp	x19, x20, [sp, 16]
	ubfiz	x20, x2, 2, 32
	mov	x19, x0
	mov	x0, x20
	str	w2, [x29, 44]
	str	x1, [x29, 32]
	bl	malloc
	ldr	w2, [x29, 44]
	lsr	w2, w2, 2
	cbz	w2, .L2
	sub	w2, w2, #1
	ldr	x1, [x29, 32]
	add	x2, x2, 1
	mov	x3, x0
	lsl	x2, x2, 4
	add	x4, x19, x2
.L3:
	ldr	q1, [x19], 16
	ldr	q0, [x1], 16
	cmp	x19, x4
	fadd	v0.4s, v0.4s, v1.4s
	str	q0, [x3], 16
	bne	.L3
	add	x0, x0, x2
.L2:
	sub	x0, x0, x20
	ldp	x19, x20, [sp, 16]
	ldp	x29, x30, [sp], 48
	ret
	.size	sum_vec, .-sum_vec
	.ident	"GCC: (Debian/Linaro 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
