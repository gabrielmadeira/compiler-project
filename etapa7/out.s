## FIXED INIT
.scanIntStr: .string	"%d"
.printIntStr: .string	"%d"
.printStringStr: .string "%s"
## TAC_BEGINFUN
	.globl main
main:
	pushq %rbp
	movq %rsp, %rbp
## TAC_LABEL
._label0:
## TAC_LES
	movl _count(%rip), %edx
	movl _iterations(%rip), %eax
	cmpl	%eax, %edx
	setl %al
	movzbl %al, %eax
	movl %eax, __temp91(%rip)
## TAC_IFZ
	movl __temp91(%rip), %eax
	testl %eax, %eax
	je ._label1
## TAC_MUL
	movl	$1, %eax
	sall	$4, %eax
	movl	%eax, __temp0(%rip)
## TAC_MUL
	movl	__temp0(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp1(%rip)

## TAC_MUL
	movl	__temp1(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp2(%rip)

## TAC_MUL
	movl	__temp2(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp3(%rip)

## TAC_MUL
	movl	__temp3(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp4(%rip)

## TAC_MUL
	movl	__temp4(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp5(%rip)

## TAC_MUL
	movl	__temp5(%rip), %eax
	sall	$7, %eax
	movl	%eax, __temp6(%rip)

## TAC_MUL
	movl	__temp6(%rip), %eax
	sall	$2, %eax
	movl	%eax, __temp7(%rip)

## TAC_MUL
	movl	__temp7(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp8(%rip)

## TAC_MOVE
	movl __temp8(%rip), %eax
	movl %eax, _a(%rip)
## TAC_MUL
	movl	$1, %eax
	sall	$4, %eax
	movl	%eax, __temp9(%rip)
## TAC_MUL
	movl	__temp9(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp10(%rip)

## TAC_MUL
	movl	__temp10(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp11(%rip)

## TAC_MUL
	movl	__temp11(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp12(%rip)

## TAC_MUL
	movl	__temp12(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp13(%rip)

## TAC_MUL
	movl	__temp13(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp14(%rip)

## TAC_MUL
	movl	__temp14(%rip), %eax
	sall	$7, %eax
	movl	%eax, __temp15(%rip)

## TAC_MUL
	movl	__temp15(%rip), %eax
	sall	$2, %eax
	movl	%eax, __temp16(%rip)

## TAC_MUL
	movl	__temp16(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp17(%rip)

## TAC_MOVE
	movl __temp17(%rip), %eax
	movl %eax, _b(%rip)
## TAC_MUL
	movl	$1, %eax
	sall	$4, %eax
	movl	%eax, __temp18(%rip)
## TAC_MUL
	movl	__temp18(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp19(%rip)

## TAC_MUL
	movl	__temp19(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp20(%rip)

## TAC_MUL
	movl	__temp20(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp21(%rip)

## TAC_MUL
	movl	__temp21(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp22(%rip)

## TAC_MUL
	movl	__temp22(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp23(%rip)

## TAC_MUL
	movl	__temp23(%rip), %eax
	sall	$7, %eax
	movl	%eax, __temp24(%rip)

## TAC_MUL
	movl	__temp24(%rip), %eax
	sall	$2, %eax
	movl	%eax, __temp25(%rip)

## TAC_MUL
	movl	__temp25(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp26(%rip)

## TAC_MOVE
	movl __temp26(%rip), %eax
	movl %eax, _c(%rip)
## TAC_MUL
	movl	$1, %eax
	sall	$4, %eax
	movl	%eax, __temp27(%rip)
## TAC_MUL
	movl	__temp27(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp28(%rip)

## TAC_MUL
	movl	__temp28(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp29(%rip)

## TAC_MUL
	movl	__temp29(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp30(%rip)

## TAC_MUL
	movl	__temp30(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp31(%rip)

## TAC_MUL
	movl	__temp31(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp32(%rip)

## TAC_MUL
	movl	__temp32(%rip), %eax
	sall	$7, %eax
	movl	%eax, __temp33(%rip)

## TAC_MUL
	movl	__temp33(%rip), %eax
	sall	$2, %eax
	movl	%eax, __temp34(%rip)

## TAC_MUL
	movl	__temp34(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp35(%rip)

## TAC_MOVE
	movl __temp35(%rip), %eax
	movl %eax, _d(%rip)
## TAC_MUL
	movl	$1, %eax
	sall	$4, %eax
	movl	%eax, __temp36(%rip)
## TAC_MUL
	movl	__temp36(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp37(%rip)

## TAC_MUL
	movl	__temp37(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp38(%rip)

## TAC_MUL
	movl	__temp38(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp39(%rip)

## TAC_MUL
	movl	__temp39(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp40(%rip)

## TAC_MUL
	movl	__temp40(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp41(%rip)

## TAC_MUL
	movl	__temp41(%rip), %eax
	sall	$7, %eax
	movl	%eax, __temp42(%rip)

## TAC_MUL
	movl	__temp42(%rip), %eax
	sall	$2, %eax
	movl	%eax, __temp43(%rip)

## TAC_MUL
	movl	__temp43(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp44(%rip)

## TAC_MOVE
	movl __temp44(%rip), %eax
	movl %eax, _e(%rip)
## TAC_MUL
	movl	$1, %eax
	sall	$4, %eax
	movl	%eax, __temp45(%rip)
## TAC_MUL
	movl	__temp45(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp46(%rip)

## TAC_MUL
	movl	__temp46(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp47(%rip)

## TAC_MUL
	movl	__temp47(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp48(%rip)

## TAC_MUL
	movl	__temp48(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp49(%rip)

## TAC_MUL
	movl	__temp49(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp50(%rip)

## TAC_MUL
	movl	__temp50(%rip), %eax
	sall	$7, %eax
	movl	%eax, __temp51(%rip)

## TAC_MUL
	movl	__temp51(%rip), %eax
	sall	$2, %eax
	movl	%eax, __temp52(%rip)

## TAC_MUL
	movl	__temp52(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp53(%rip)

## TAC_MOVE
	movl __temp53(%rip), %eax
	movl %eax, _f(%rip)
## TAC_MUL
	movl	$1, %eax
	sall	$4, %eax
	movl	%eax, __temp54(%rip)
## TAC_MUL
	movl	__temp54(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp55(%rip)

## TAC_MUL
	movl	__temp55(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp56(%rip)

## TAC_MUL
	movl	__temp56(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp57(%rip)

## TAC_MUL
	movl	__temp57(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp58(%rip)

## TAC_MUL
	movl	__temp58(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp59(%rip)

## TAC_MUL
	movl	__temp59(%rip), %eax
	sall	$7, %eax
	movl	%eax, __temp60(%rip)

## TAC_MUL
	movl	__temp60(%rip), %eax
	sall	$2, %eax
	movl	%eax, __temp61(%rip)

## TAC_MUL
	movl	__temp61(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp62(%rip)

## TAC_MOVE
	movl __temp62(%rip), %eax
	movl %eax, _g(%rip)
## TAC_MUL
	movl	$1, %eax
	sall	$4, %eax
	movl	%eax, __temp63(%rip)
## TAC_MUL
	movl	__temp63(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp64(%rip)

## TAC_MUL
	movl	__temp64(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp65(%rip)

## TAC_MUL
	movl	__temp65(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp66(%rip)

## TAC_MUL
	movl	__temp66(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp67(%rip)

## TAC_MUL
	movl	__temp67(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp68(%rip)

## TAC_MUL
	movl	__temp68(%rip), %eax
	sall	$7, %eax
	movl	%eax, __temp69(%rip)

## TAC_MUL
	movl	__temp69(%rip), %eax
	sall	$2, %eax
	movl	%eax, __temp70(%rip)

## TAC_MUL
	movl	__temp70(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp71(%rip)

## TAC_MOVE
	movl __temp71(%rip), %eax
	movl %eax, _h(%rip)
## TAC_MUL
	movl	$1, %eax
	sall	$4, %eax
	movl	%eax, __temp72(%rip)
## TAC_MUL
	movl	__temp72(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp73(%rip)

## TAC_MUL
	movl	__temp73(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp74(%rip)

## TAC_MUL
	movl	__temp74(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp75(%rip)

## TAC_MUL
	movl	__temp75(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp76(%rip)

## TAC_MUL
	movl	__temp76(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp77(%rip)

## TAC_MUL
	movl	__temp77(%rip), %eax
	sall	$7, %eax
	movl	%eax, __temp78(%rip)

## TAC_MUL
	movl	__temp78(%rip), %eax
	sall	$2, %eax
	movl	%eax, __temp79(%rip)

## TAC_MUL
	movl	__temp79(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp80(%rip)

## TAC_MOVE
	movl __temp80(%rip), %eax
	movl %eax, _i(%rip)
## TAC_MUL
	movl	$1, %eax
	sall	$4, %eax
	movl	%eax, __temp81(%rip)
## TAC_MUL
	movl	__temp81(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp82(%rip)

## TAC_MUL
	movl	__temp82(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp83(%rip)

## TAC_MUL
	movl	__temp83(%rip), %eax
	sall	$1, %eax
	movl	%eax, __temp84(%rip)

## TAC_MUL
	movl	__temp84(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp85(%rip)

## TAC_MUL
	movl	__temp85(%rip), %eax
	sall	$4, %eax
	movl	%eax, __temp86(%rip)

## TAC_MUL
	movl	__temp86(%rip), %eax
	sall	$7, %eax
	movl	%eax, __temp87(%rip)

## TAC_MUL
	movl	__temp87(%rip), %eax
	sall	$2, %eax
	movl	%eax, __temp88(%rip)

## TAC_MUL
	movl	__temp88(%rip), %eax
	sall	$3, %eax
	movl	%eax, __temp89(%rip)

## TAC_MOVE
	movl __temp89(%rip), %eax
	movl %eax, _j(%rip)
## TAC_ADD
	movl _count(%rip), %eax
	movl _1(%rip), %edx
	addl %edx, %eax
	movl %eax, __temp90(%rip)
## TAC_MOVE
	movl __temp90(%rip), %eax
	movl %eax, _count(%rip)
## TAC_JUMP
jmp ._label0
## TAC_LABEL
._label1:
## TAC_PRINTL (int)
	movl _a(%rip), %esi
	leaq .printIntStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _igEndoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_ENDFUN
	popq %rbp
	ret
## DATA SECTION
	.data

	.globl _iterations
_iterations: .long 1000000000
	.globl _1000000000
_1000000000: .long 1000000000
	.globl _count
_count: .long 0
	.globl _0
_0: .long 0
	.globl _a
_a: .long 1
	.globl _1
_1: .long 1
	.globl _b
_b: .long 1
	.globl _c
_c: .long 1
	.globl _d
_d: .long 1
	.globl _e
_e: .long 1
	.globl _f
_f: .long 1
	.globl _g
_g: .long 1
	.globl _h
_h: .long 1
	.globl _i
_i: .long 1
	.globl _j
_j: .long 1
	.globl _2
_2: .long 2
	.globl _8
_8: .long 8
	.globl _16
_16: .long 16
	.globl _128
_128: .long 128
	.globl _4
_4: .long 4
_igEndoni_l:
	.string " End\n"
	.section .data.rel.local,"aw"
_igEndoni: .quad _igEndoni_l
	.globl __temp0
__temp0: .long 0
	.globl __temp1
__temp1: .long 0
	.globl __temp2
__temp2: .long 0
	.globl __temp3
__temp3: .long 0
	.globl __temp4
__temp4: .long 0
	.globl __temp5
__temp5: .long 0
	.globl __temp6
__temp6: .long 0
	.globl __temp7
__temp7: .long 0
	.globl __temp8
__temp8: .long 0
	.globl __temp9
__temp9: .long 0
	.globl __temp10
__temp10: .long 0
	.globl __temp11
__temp11: .long 0
	.globl __temp12
__temp12: .long 0
	.globl __temp13
__temp13: .long 0
	.globl __temp14
__temp14: .long 0
	.globl __temp15
__temp15: .long 0
	.globl __temp16
__temp16: .long 0
	.globl __temp17
__temp17: .long 0
	.globl __temp18
__temp18: .long 0
	.globl __temp19
__temp19: .long 0
	.globl __temp20
__temp20: .long 0
	.globl __temp21
__temp21: .long 0
	.globl __temp22
__temp22: .long 0
	.globl __temp23
__temp23: .long 0
	.globl __temp24
__temp24: .long 0
	.globl __temp25
__temp25: .long 0
	.globl __temp26
__temp26: .long 0
	.globl __temp27
__temp27: .long 0
	.globl __temp28
__temp28: .long 0
	.globl __temp29
__temp29: .long 0
	.globl __temp30
__temp30: .long 0
	.globl __temp31
__temp31: .long 0
	.globl __temp32
__temp32: .long 0
	.globl __temp33
__temp33: .long 0
	.globl __temp34
__temp34: .long 0
	.globl __temp35
__temp35: .long 0
	.globl __temp36
__temp36: .long 0
	.globl __temp37
__temp37: .long 0
	.globl __temp38
__temp38: .long 0
	.globl __temp39
__temp39: .long 0
	.globl __temp40
__temp40: .long 0
	.globl __temp41
__temp41: .long 0
	.globl __temp42
__temp42: .long 0
	.globl __temp43
__temp43: .long 0
	.globl __temp44
__temp44: .long 0
	.globl __temp45
__temp45: .long 0
	.globl __temp46
__temp46: .long 0
	.globl __temp47
__temp47: .long 0
	.globl __temp48
__temp48: .long 0
	.globl __temp49
__temp49: .long 0
	.globl __temp50
__temp50: .long 0
	.globl __temp51
__temp51: .long 0
	.globl __temp52
__temp52: .long 0
	.globl __temp53
__temp53: .long 0
	.globl __temp54
__temp54: .long 0
	.globl __temp55
__temp55: .long 0
	.globl __temp56
__temp56: .long 0
	.globl __temp57
__temp57: .long 0
	.globl __temp58
__temp58: .long 0
	.globl __temp59
__temp59: .long 0
	.globl __temp60
__temp60: .long 0
	.globl __temp61
__temp61: .long 0
	.globl __temp62
__temp62: .long 0
	.globl __temp63
__temp63: .long 0
	.globl __temp64
__temp64: .long 0
	.globl __temp65
__temp65: .long 0
	.globl __temp66
__temp66: .long 0
	.globl __temp67
__temp67: .long 0
	.globl __temp68
__temp68: .long 0
	.globl __temp69
__temp69: .long 0
	.globl __temp70
__temp70: .long 0
	.globl __temp71
__temp71: .long 0
	.globl __temp72
__temp72: .long 0
	.globl __temp73
__temp73: .long 0
	.globl __temp74
__temp74: .long 0
	.globl __temp75
__temp75: .long 0
	.globl __temp76
__temp76: .long 0
	.globl __temp77
__temp77: .long 0
	.globl __temp78
__temp78: .long 0
	.globl __temp79
__temp79: .long 0
	.globl __temp80
__temp80: .long 0
	.globl __temp81
__temp81: .long 0
	.globl __temp82
__temp82: .long 0
	.globl __temp83
__temp83: .long 0
	.globl __temp84
__temp84: .long 0
	.globl __temp85
__temp85: .long 0
	.globl __temp86
__temp86: .long 0
	.globl __temp87
__temp87: .long 0
	.globl __temp88
__temp88: .long 0
	.globl __temp89
__temp89: .long 0
	.globl __temp90
__temp90: .long 0
	.globl __temp91
__temp91: .long 0
