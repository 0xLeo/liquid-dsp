	.arch armv8-a+fp+simd
	.file	"LDSPsel2.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.align	2
	.global	VECTOR_mul
	.type	VECTOR_mul, %function
VECTOR_mul:
.LFB33:
	.file 1 "LDSPsel2.c"
	.loc 1 22 0
	.cfi_startproc
.LVL0:
	.loc 1 28 0
	ands	w8, w2, -4
.LVL1:
	mov	w4, 0
	beq	.L2
.LVL2:
.L3:
	.loc 1 29 0 discriminator 3
	ldr	s1, [x1, w4, uxtw 2]
	.loc 1 30 0 discriminator 3
	add	w7, w4, 1
	.loc 1 29 0 discriminator 3
	ldr	s0, [x0, w4, uxtw 2]
	.loc 1 31 0 discriminator 3
	add	w6, w4, 2
	.loc 1 32 0 discriminator 3
	add	w5, w4, 3
	.loc 1 29 0 discriminator 3
	fmul	s0, s0, s1
	str	s0, [x3, w4, uxtw 2]
	.loc 1 28 0 discriminator 3
	add	w4, w4, 4
.LVL3:
	.loc 1 30 0 discriminator 3
	ldr	s1, [x1, w7, uxtw 2]
	.loc 1 28 0 discriminator 3
	cmp	w8, w4
	.loc 1 30 0 discriminator 3
	ldr	s0, [x0, w7, uxtw 2]
	fmul	s0, s0, s1
	str	s0, [x3, w7, uxtw 2]
	.loc 1 31 0 discriminator 3
	ldr	s1, [x1, w6, uxtw 2]
	ldr	s0, [x0, w6, uxtw 2]
	fmul	s0, s0, s1
	str	s0, [x3, w6, uxtw 2]
	.loc 1 32 0 discriminator 3
	ldr	s0, [x0, w5, uxtw 2]
	ldr	s1, [x1, w5, uxtw 2]
	fmul	s0, s0, s1
	str	s0, [x3, w5, uxtw 2]
	.loc 1 28 0 discriminator 3
	bhi	.L3
.LVL4:
.L2:
	.loc 1 36 0 discriminator 1
	cmp	w2, w4
	bls	.L1
.L8:
	.loc 1 37 0 discriminator 2
	ldr	s0, [x0, w4, uxtw 2]
	ldr	s1, [x1, w4, uxtw 2]
	fmul	s0, s0, s1
	str	s0, [x3, w4, uxtw 2]
	.loc 1 36 0 discriminator 2
	add	w4, w4, 1
.LVL5:
	cmp	w4, w2
	bne	.L8
.L1:
	.loc 1 38 0
	ret
	.cfi_endproc
.LFE33:
	.size	VECTOR_mul, .-VECTOR_mul
.Letext0:
	.file 2 "/usr/lib/gcc/aarch64-linux-gnu/4.9/include/stddef.h"
	.file 3 "/usr/include/aarch64-linux-gnu/bits/types.h"
	.file 4 "/usr/include/libio.h"
	.file 5 "/usr/include/stdio.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x323
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.4byte	.LASF52
	.byte	0x1
	.4byte	.LASF53
	.4byte	.LASF54
	.8byte	.Ltext0
	.8byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.4byte	.LASF7
	.byte	0x2
	.byte	0xd4
	.4byte	0x38
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.4byte	.LASF0
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.4byte	.LASF1
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.4byte	.LASF2
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.4byte	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.4byte	.LASF4
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.4byte	.LASF5
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.4byte	.LASF6
	.uleb128 0x2
	.4byte	.LASF8
	.byte	0x3
	.byte	0x83
	.4byte	0x69
	.uleb128 0x2
	.4byte	.LASF9
	.byte	0x3
	.byte	0x84
	.4byte	0x69
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.4byte	.LASF10
	.uleb128 0x5
	.byte	0x8
	.uleb128 0x6
	.byte	0x8
	.4byte	0x95
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.4byte	.LASF11
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.4byte	.LASF12
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.4byte	.LASF13
	.uleb128 0x7
	.4byte	.LASF43
	.byte	0xd8
	.byte	0x4
	.byte	0xf5
	.4byte	0x22a
	.uleb128 0x8
	.4byte	.LASF14
	.byte	0x4
	.byte	0xf6
	.4byte	0x62
	.byte	0
	.uleb128 0x8
	.4byte	.LASF15
	.byte	0x4
	.byte	0xfb
	.4byte	0x8f
	.byte	0x8
	.uleb128 0x8
	.4byte	.LASF16
	.byte	0x4
	.byte	0xfc
	.4byte	0x8f
	.byte	0x10
	.uleb128 0x8
	.4byte	.LASF17
	.byte	0x4
	.byte	0xfd
	.4byte	0x8f
	.byte	0x18
	.uleb128 0x8
	.4byte	.LASF18
	.byte	0x4
	.byte	0xfe
	.4byte	0x8f
	.byte	0x20
	.uleb128 0x8
	.4byte	.LASF19
	.byte	0x4
	.byte	0xff
	.4byte	0x8f
	.byte	0x28
	.uleb128 0x9
	.4byte	.LASF20
	.byte	0x4
	.2byte	0x100
	.4byte	0x8f
	.byte	0x30
	.uleb128 0x9
	.4byte	.LASF21
	.byte	0x4
	.2byte	0x101
	.4byte	0x8f
	.byte	0x38
	.uleb128 0x9
	.4byte	.LASF22
	.byte	0x4
	.2byte	0x102
	.4byte	0x8f
	.byte	0x40
	.uleb128 0x9
	.4byte	.LASF23
	.byte	0x4
	.2byte	0x104
	.4byte	0x8f
	.byte	0x48
	.uleb128 0x9
	.4byte	.LASF24
	.byte	0x4
	.2byte	0x105
	.4byte	0x8f
	.byte	0x50
	.uleb128 0x9
	.4byte	.LASF25
	.byte	0x4
	.2byte	0x106
	.4byte	0x8f
	.byte	0x58
	.uleb128 0x9
	.4byte	.LASF26
	.byte	0x4
	.2byte	0x108
	.4byte	0x262
	.byte	0x60
	.uleb128 0x9
	.4byte	.LASF27
	.byte	0x4
	.2byte	0x10a
	.4byte	0x268
	.byte	0x68
	.uleb128 0x9
	.4byte	.LASF28
	.byte	0x4
	.2byte	0x10c
	.4byte	0x62
	.byte	0x70
	.uleb128 0x9
	.4byte	.LASF29
	.byte	0x4
	.2byte	0x110
	.4byte	0x62
	.byte	0x74
	.uleb128 0x9
	.4byte	.LASF30
	.byte	0x4
	.2byte	0x112
	.4byte	0x70
	.byte	0x78
	.uleb128 0x9
	.4byte	.LASF31
	.byte	0x4
	.2byte	0x116
	.4byte	0x4d
	.byte	0x80
	.uleb128 0x9
	.4byte	.LASF32
	.byte	0x4
	.2byte	0x117
	.4byte	0x54
	.byte	0x82
	.uleb128 0x9
	.4byte	.LASF33
	.byte	0x4
	.2byte	0x118
	.4byte	0x26e
	.byte	0x83
	.uleb128 0x9
	.4byte	.LASF34
	.byte	0x4
	.2byte	0x11c
	.4byte	0x27e
	.byte	0x88
	.uleb128 0x9
	.4byte	.LASF35
	.byte	0x4
	.2byte	0x125
	.4byte	0x7b
	.byte	0x90
	.uleb128 0x9
	.4byte	.LASF36
	.byte	0x4
	.2byte	0x12e
	.4byte	0x8d
	.byte	0x98
	.uleb128 0x9
	.4byte	.LASF37
	.byte	0x4
	.2byte	0x12f
	.4byte	0x8d
	.byte	0xa0
	.uleb128 0x9
	.4byte	.LASF38
	.byte	0x4
	.2byte	0x130
	.4byte	0x8d
	.byte	0xa8
	.uleb128 0x9
	.4byte	.LASF39
	.byte	0x4
	.2byte	0x131
	.4byte	0x8d
	.byte	0xb0
	.uleb128 0x9
	.4byte	.LASF40
	.byte	0x4
	.2byte	0x132
	.4byte	0x2d
	.byte	0xb8
	.uleb128 0x9
	.4byte	.LASF41
	.byte	0x4
	.2byte	0x134
	.4byte	0x62
	.byte	0xc0
	.uleb128 0x9
	.4byte	.LASF42
	.byte	0x4
	.2byte	0x136
	.4byte	0x284
	.byte	0xc4
	.byte	0
	.uleb128 0xa
	.4byte	.LASF55
	.byte	0x4
	.byte	0x9a
	.uleb128 0x7
	.4byte	.LASF44
	.byte	0x18
	.byte	0x4
	.byte	0xa0
	.4byte	0x262
	.uleb128 0x8
	.4byte	.LASF45
	.byte	0x4
	.byte	0xa1
	.4byte	0x262
	.byte	0
	.uleb128 0x8
	.4byte	.LASF46
	.byte	0x4
	.byte	0xa2
	.4byte	0x268
	.byte	0x8
	.uleb128 0x8
	.4byte	.LASF47
	.byte	0x4
	.byte	0xa6
	.4byte	0x62
	.byte	0x10
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.4byte	0x231
	.uleb128 0x6
	.byte	0x8
	.4byte	0xaa
	.uleb128 0xb
	.4byte	0x95
	.4byte	0x27e
	.uleb128 0xc
	.4byte	0x86
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.4byte	0x22a
	.uleb128 0xb
	.4byte	0x95
	.4byte	0x294
	.uleb128 0xc
	.4byte	0x86
	.byte	0x13
	.byte	0
	.uleb128 0x3
	.byte	0x4
	.byte	0x4
	.4byte	.LASF48
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.4byte	.LASF49
	.uleb128 0xd
	.4byte	.LASF56
	.byte	0x1
	.byte	0x12
	.8byte	.LFB33
	.8byte	.LFE33-.LFB33
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x30a
	.uleb128 0xe
	.string	"_x"
	.byte	0x1
	.byte	0x12
	.4byte	0x30a
	.uleb128 0x1
	.byte	0x50
	.uleb128 0xe
	.string	"_y"
	.byte	0x1
	.byte	0x13
	.4byte	0x30a
	.uleb128 0x1
	.byte	0x51
	.uleb128 0xe
	.string	"_n"
	.byte	0x1
	.byte	0x14
	.4byte	0x3f
	.uleb128 0x1
	.byte	0x52
	.uleb128 0xe
	.string	"_z"
	.byte	0x1
	.byte	0x15
	.4byte	0x30a
	.uleb128 0x1
	.byte	0x53
	.uleb128 0xf
	.string	"t"
	.byte	0x1
	.byte	0x18
	.4byte	0x3f
	.4byte	.LLST0
	.uleb128 0xf
	.string	"i"
	.byte	0x1
	.byte	0x1b
	.4byte	0x3f
	.4byte	.LLST1
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.4byte	0x294
	.uleb128 0x10
	.4byte	.LASF50
	.byte	0x5
	.byte	0xa8
	.4byte	0x268
	.uleb128 0x10
	.4byte	.LASF51
	.byte	0x5
	.byte	0xa9
	.4byte	0x268
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",%progbits
.Ldebug_loc0:
.LLST0:
	.8byte	.LVL0-.Ltext0
	.8byte	.LVL1-.Ltext0
	.2byte	0x6
	.byte	0x72
	.sleb128 0
	.byte	0x9
	.byte	0xfc
	.byte	0x1a
	.byte	0x9f
	.8byte	.LVL1-.Ltext0
	.8byte	.LFE33-.Ltext0
	.2byte	0x1
	.byte	0x58
	.8byte	0
	.8byte	0
.LLST1:
	.8byte	.LVL0-.Ltext0
	.8byte	.LVL2-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.8byte	.LVL2-.Ltext0
	.8byte	.LFE33-.Ltext0
	.2byte	0x1
	.byte	0x54
	.8byte	0
	.8byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x2c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x8
	.byte	0
	.2byte	0
	.2byte	0
	.8byte	.Ltext0
	.8byte	.Letext0-.Ltext0
	.8byte	0
	.8byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF8:
	.string	"__off_t"
.LASF15:
	.string	"_IO_read_ptr"
.LASF27:
	.string	"_chain"
.LASF7:
	.string	"size_t"
.LASF33:
	.string	"_shortbuf"
.LASF56:
	.string	"VECTOR_mul"
.LASF21:
	.string	"_IO_buf_base"
.LASF13:
	.string	"long long unsigned int"
.LASF12:
	.string	"long long int"
.LASF4:
	.string	"signed char"
.LASF28:
	.string	"_fileno"
.LASF16:
	.string	"_IO_read_end"
.LASF6:
	.string	"long int"
.LASF14:
	.string	"_flags"
.LASF22:
	.string	"_IO_buf_end"
.LASF31:
	.string	"_cur_column"
.LASF49:
	.string	"double"
.LASF30:
	.string	"_old_offset"
.LASF35:
	.string	"_offset"
.LASF44:
	.string	"_IO_marker"
.LASF50:
	.string	"stdin"
.LASF1:
	.string	"unsigned int"
.LASF0:
	.string	"long unsigned int"
.LASF19:
	.string	"_IO_write_ptr"
.LASF54:
	.string	"/home/linaro/liquid-dsp-01/mysrc"
.LASF46:
	.string	"_sbuf"
.LASF3:
	.string	"short unsigned int"
.LASF53:
	.string	"LDSPsel2.c"
.LASF34:
	.string	"_lock"
.LASF52:
	.string	"GNU C 4.9.2 -march=armv8-a -mlittle-endian -mabi=lp64 -g -O2"
.LASF29:
	.string	"_flags2"
.LASF41:
	.string	"_mode"
.LASF51:
	.string	"stdout"
.LASF10:
	.string	"sizetype"
.LASF23:
	.string	"_IO_save_base"
.LASF20:
	.string	"_IO_write_end"
.LASF55:
	.string	"_IO_lock_t"
.LASF43:
	.string	"_IO_FILE"
.LASF48:
	.string	"float"
.LASF47:
	.string	"_pos"
.LASF26:
	.string	"_markers"
.LASF2:
	.string	"unsigned char"
.LASF5:
	.string	"short int"
.LASF32:
	.string	"_vtable_offset"
.LASF11:
	.string	"char"
.LASF45:
	.string	"_next"
.LASF9:
	.string	"__off64_t"
.LASF17:
	.string	"_IO_read_base"
.LASF25:
	.string	"_IO_save_end"
.LASF36:
	.string	"__pad1"
.LASF37:
	.string	"__pad2"
.LASF38:
	.string	"__pad3"
.LASF39:
	.string	"__pad4"
.LASF40:
	.string	"__pad5"
.LASF42:
	.string	"_unused2"
.LASF24:
	.string	"_IO_backup_base"
.LASF18:
	.string	"_IO_write_base"
	.ident	"GCC: (Debian/Linaro 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
