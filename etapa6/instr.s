
## FIXED INIT
.printIntStr: .string	"%d\n"
.printStringStr: .string	"%s\n"


## TAC_BEGINFUN
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_PRINTINT
	movl	var1(%rip), %esi
	leaq	.printIntStr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT


## TAC_ENDFUN 
	popq	%rbp
	ret

## DATA SECTION
	.globl	var1
	.data
var1: .long	6
