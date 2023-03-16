## FIXED INIT
.printIntStr: .string	"%d\n"
.printStringStr: .string "%s\n"
## TAC_BEGINFUN
	.globl main
main:
	pushq %rbp
	movq %rsp, %rbp
TAC_LESTAC_IFZ## TAC_PRINTINT
	movl _x(%rip), %esi
	leaq .printIntStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
TAC_LABEL## TAC_ENDFUN
	popq %rbp
	ret
## DATA SECTION
	.data

	.globl _a
_a: .long 3
	.globl _3
_3: .long 3
	.globl _b
_b: .long 4
	.globl _4
_4: .long 4
	.globl _x
_x: .long 5
	.globl _5
_5: .long 5
	.globl __temp0
__temp0: .long 0
