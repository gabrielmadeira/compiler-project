## FIXED INIT
.scanIntStr: .string	"%d"
.printIntStr: .string	"%d\n"
.printStringStr: .string "%s\n"
## TAC_BEGINFUN
	.globl main
main:
	pushq %rbp
	movq %rsp, %rbp
## TAC_MOVEVEC
	movl _33(%rip), %eax
	movl %eax, 12+_x(%rip)
## TAC_ACALL
	movl 12+_x(%rip), %eax
	movl %eax, __temp0(%rip)
## TAC_ADD
	movl __temp0(%rip), %edx
	movl _4(%rip), %eax
	addl %edx, %eax
	movl %eax, __temp1(%rip)
## TAC_MOVE
	movl __temp1(%rip), %eax
	movl %eax, _b(%rip)
## TAC_PRINTINT
	movl _b(%rip), %esi
	leaq .printIntStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_ENDFUN
	popq %rbp
	ret
## DATA SECTION
	.data

	.globl _b
_b: .long 1
	.globl _1
_1: .long 1
	.globl _x
_x:
	.long 5
	.long 6
	.long 7
	.long 8
	.globl _4
_4: .long 4
	.globl _5
_5: .long 5
	.globl _6
_6: .long 6
	.globl _7
_7: .long 7
	.globl _8
_8: .long 8
	.globl _3
_3: .long 3
	.globl _33
_33: .long 33
	.globl __temp0
__temp0: .long 0
	.globl __temp1
__temp1: .long 0
