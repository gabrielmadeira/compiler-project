## FIXED INIT
.scanIntStr: .string	"%d"
.printIntStr: .string	"%d"
.printStringStr: .string "%s"
## TAC_BEGINFUN
	.globl print_stack
print_stack:
	pushq %rbp
	movq %rsp, %rbp
## TAC_PRINTL (string)
	movq _ijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iSTACKggi(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_MOVE
	movl _0(%rip), %eax
	movl %eax, _i(%rip)
## TAC_LABEL
._label0:
## TAC_LES
	movl _i(%rip), %edx
	movl _stack_pointer(%rip), %eax
	cmpl	%eax, %edx
	setl %al
	movzbl %al, %eax
	movl %eax, __temp2(%rip)
## TAC_IFZ
	movl __temp2(%rip), %eax
	testl %eax, %eax
	je ._label1
## TAC_ACALL
	movl	_i(%rip), %eax
	cltq
	leaq 0(,%rax,4), %rdx
	leaq _stack(%rip), %rax
	movl (%rdx,%rax), %eax
	movl %eax, __temp0(%rip)
## TAC_PRINTL (int)
	movl __temp0(%rip), %esi
	leaq .printIntStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _igi(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_ADD
	movl _i(%rip), %edx
	movl _1(%rip), %eax
	addl %edx, %eax
	movl %eax, __temp1(%rip)
## TAC_MOVE
	movl __temp1(%rip), %eax
	movl %eax, _i(%rip)
## TAC_JUMP
jmp ._label0
## TAC_LABEL
._label1:
## TAC_PRINTL (string)
	movq _ioni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _ijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_MOVE
	movl _0(%rip), %eax
	movl %eax, _i(%rip)
## TAC_RET
	movl _0(%rip), %eax
## TAC_ENDFUN
	popq %rbp
	ret
## TAC_BEGINFUN
	.globl main
main:
	pushq %rbp
	movq %rsp, %rbp
## TAC_PRINTL (string)
	movq _iesyesyesyesyesyesyesyesyesyesyesyesyesyesyepyepyesyesyesyesyesyesyesyesyesyesyesyesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyesyesyesyesyesyesyesyeqyepsepwepnepnepnepnepwepueryesyesyesyesyesyesyesyesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyesyesyesyeqyepsepyepoepnepnepnepnepnepnepnepnepnepnepvepmepueryesyesyesyesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyeqyepoepwepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepwepoeryesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyesqeszesnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnesnesnesxesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyesyeqyepsepmerzesreqnepnepnepnepnepnepnepnepnepnepnernesteqneprepueryesyesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyesaesnepnepnepnepvepmepqeszesnepnepnepnepnesnesnepxepyepoepnepnepnesnesvesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyesyesyeqqeszesreqnepnepnepvepmepuerpeqpepsepyepoepnepnernestesnerxesyesyesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyeqsepwepnepnepwepuerpesxesnepnepnepnepnepnepnesnesxeqpepsepwepnepnepweruesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyesyesqeszesreqnepnepnepvepmepmerpesresteqpeprepyepoepnepnernestesnesxesyesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyeqyepsepwepwepoerqesxesnepnepnepnepvepoepnepnepnesnesxeqxepoepwepwepueryesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyesqesxesnepnepnepnepvepmepqeszesnepnepnesnesnepxepyepoepnepnepnesnesxesxesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyesyesyesyesqeszesreqnepnepnepvepmepuepsepyepoepnepnernestesnesxesyesyesyesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyesyesyesyesyesyesyesyesqeszesnepnepnepnepnesnesnesxesyesyesyesyesyesyesyesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iesyesyesyesyesyesyesyesyesyesyesyesyesyesyespespesyesyesyesyesyesyesyesyesyesyesyesyesyesyoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _ijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _igggggggggggWelcomegtogoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iggggggggggrtrtrtrtrtroni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _igggggggggguSuTuAuCuKuoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iggggggrtrtrtrtrtrtrtrtrtroni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _igggggguSuIuMuUuLuAuTuOuRuoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iggggggrtrtrrtrtrtrtrrtrtroni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _igggggggggggu2u0u2u3uoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _igggggggggggrtrtrtrtrononi(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _iggggggbygGabrielgMadeiraoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_PRINTL (string)
	movq _ijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_LABEL
._label2:
## TAC_DIF
	movl _operation(%rip), %edx
	movl _3(%rip), %eax
	cmpl	%eax, %edx
	setne %al
	movzbl %al, %eax
	movl %eax, __temp15(%rip)
## TAC_IFZ
	movl __temp15(%rip), %eax
	testl %eax, %eax
	je ._label10
## TAC_PRINTL (string)
	movq _iChoosegagstackgoperationgong1ggPushong2ggPopong3ggExitongOperationggi(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_READ
	leaq __temp3(%rip), %rax
	movq %rax, %rsi
	leaq .scanIntStr(%rip), %rax
	movq %rax, %rdi
	movl $0, %eax
	call __isoc99_scanf@PLT
## TAC_MOVE
	movl __temp3(%rip), %eax
	movl %eax, _operation(%rip)
## TAC_EQ
	movl _operation(%rip), %edx
	movl _1(%rip), %eax
	cmpl	%eax, %edx
	sete %al
	movzbl %al, %eax
	movl %eax, __temp12(%rip)
## TAC_EQ
	movl _operation(%rip), %edx
	movl _2(%rip), %eax
	cmpl	%eax, %edx
	sete %al
	movzbl %al, %eax
	movl %eax, __temp13(%rip)
## TAC_OR
	movl __temp12(%rip), %edx
	movl __temp13(%rip), %eax
	orl %edx, %eax
	movl %eax, __temp14(%rip)
## TAC_IFZ
	movl __temp14(%rip), %eax
	testl %eax, %eax
	je ._label9
## TAC_EQ
	movl _operation(%rip), %edx
	movl _1(%rip), %eax
	cmpl	%eax, %edx
	sete %al
	movzbl %al, %eax
	movl %eax, __temp8(%rip)
## TAC_IFZ
	movl __temp8(%rip), %eax
	testl %eax, %eax
	je ._label7
## TAC_SUB
	movl _stack_max_size(%rip), %eax
	movl _1(%rip), %edx
	subl %edx, %eax
	movl %eax, __temp6(%rip)
## TAC_LES
	movl _stack_pointer(%rip), %edx
	movl __temp6(%rip), %eax
	cmpl	%eax, %edx
	setl %al
	movzbl %al, %eax
	movl %eax, __temp7(%rip)
## TAC_IFZ
	movl __temp7(%rip), %eax
	testl %eax, %eax
	je ._label3
## TAC_PRINTL (string)
	movq _iEntergagvaluegtogpushggi(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_READ
	leaq __temp4(%rip), %rax
	movq %rax, %rsi
	leaq .scanIntStr(%rip), %rax
	movq %rax, %rdi
	movl $0, %eax
	call __isoc99_scanf@PLT
## TAC_MOVE
	movl __temp4(%rip), %eax
	movl %eax, _input(%rip)
## TAC_MOVEVEC
	movl _stack_pointer(%rip), %edx
	movl _input(%rip), %eax
	movslq %edx, %rdx
	leaq 0(,%rdx,4), %rcx
	leaq _stack(%rip), %rdx
	movl %eax, (%rcx,%rdx)
## TAC_ADD
	movl _stack_pointer(%rip), %edx
	movl _1(%rip), %eax
	addl %edx, %eax
	movl %eax, __temp5(%rip)
## TAC_MOVE
	movl __temp5(%rip), %eax
	movl %eax, _stack_pointer(%rip)
## TAC_JUMP
jmp ._label4
## TAC_LABEL
._label3:
## TAC_PRINTL (string)
	movq _iStackgisgfullhoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_LABEL
._label4:
## TAC_JUMP
jmp ._label8
## TAC_LABEL
._label7:
## TAC_GRE
	movl _stack_pointer(%rip), %edx
	movl _0(%rip), %eax
	cmpl	%eax, %edx
	setg %al
	movzbl %al, %eax
	movl %eax, __temp10(%rip)
## TAC_IFZ
	movl __temp10(%rip), %eax
	testl %eax, %eax
	je ._label5
## TAC_SUB
	movl _stack_pointer(%rip), %eax
	movl _1(%rip), %edx
	subl %edx, %eax
	movl %eax, __temp9(%rip)
## TAC_MOVE
	movl __temp9(%rip), %eax
	movl %eax, _stack_pointer(%rip)
## TAC_JUMP
jmp ._label6
## TAC_LABEL
._label5:
## TAC_PRINTL (string)
	movq _iStackghasgnogvaluehoni(%rip), %rax
	movq %rax, %rsi
	leaq .printStringStr(%rip), %rax
	movq %rax, %rdi
	call printf@PLT
## TAC_LABEL
._label6:
## TAC_LABEL
._label8:
## TAC_CALL
	call print_stack
	movl	%eax, __temp11(%rip)
## TAC_MOVE
	movl __temp11(%rip), %eax
	movl %eax, _i(%rip)
## TAC_LABEL
._label9:
## TAC_JUMP
jmp ._label2
## TAC_LABEL
._label10:
## TAC_ENDFUN
	popq %rbp
	ret
## DATA SECTION
	.data

	.globl _i
_i: .long 0
	.globl _0
_0: .long 0
	.globl _stack_pointer
_stack_pointer: .long 0
	.globl _stack
_stack:
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.globl _20
_20: .long 20
	.globl _stack_max_size
_stack_max_size: .long 20
	.globl _operation
_operation: .long 0
	.globl _input
_input: .long 0
_ijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjoni_l:
	.string "=============================================\n"
	.section .data.rel.local,"aw"
_ijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjoni: .quad _ijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjoni_l
_iSTACKggi_l:
	.string "STACK: "
	.section .data.rel.local,"aw"
_iSTACKggi: .quad _iSTACKggi_l
_igi_l:
	.string " "
	.section .data.rel.local,"aw"
_igi: .quad _igi_l
	.globl _1
_1: .long 1
_ioni_l:
	.string "\n"
	.section .data.rel.local,"aw"
_ioni: .quad _ioni_l
_iesyesyesyesyesyesyesyesyesyesyesyesyesyesyepyepyesyesyesyesyesyesyesyesyesyesyesyesyesyesyoni_l:
	.string "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesyesyesyesyesyesyesyesyesyesyesyepyepyesyesyesyesyesyesyesyesyesyesyesyesyesyesyoni: .quad _iesyesyesyesyesyesyesyesyesyesyesyesyesyesyepyepyesyesyesyesyesyesyesyesyesyesyesyesyesyesyoni_l
_iesyesyesyesyesyesyesyesyesyesyeqyepsepwepnepnepnepnepwepueryesyesyesyesyesyesyesyesyesyesyoni_l:
	.string "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿⣿⣿⣿⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesyesyesyesyesyesyesyeqyepsepwepnepnepnepnepwepueryesyesyesyesyesyesyesyesyesyesyoni: .quad _iesyesyesyesyesyesyesyesyesyesyeqyepsepwepnepnepnepnepwepueryesyesyesyesyesyesyesyesyesyesyoni_l
_iesyesyesyesyesyesyeqyepsepyepoepnepnepnepnepnepnepnepnepnepnepvepmepueryesyesyesyesyesyesyoni_l:
	.string "⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⡀⠀⠀⠀⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesyesyesyeqyepsepyepoepnepnepnepnepnepnepnepnepnepnepvepmepueryesyesyesyesyesyesyoni: .quad _iesyesyesyesyesyesyeqyepsepyepoepnepnepnepnepnepnepnepnepnepnepvepmepueryesyesyesyesyesyesyoni_l
_iesyesyesyeqyepoepwepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepwepoeryesyesyesyoni_l:
	.string "⠀⠀⠀⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⡀⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyeqyepoepwepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepwepoeryesyesyesyoni: .quad _iesyesyesyeqyepoepwepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepwepoeryesyesyesyoni_l
_iesyesyesyesqeszesnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnesnesnesxesyesyesyoni_l:
	.string "⠀⠀⠀⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠁⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesqeszesnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnesnesnesxesyesyesyoni: .quad _iesyesyesyesqeszesnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnepnesnesnesxesyesyesyoni_l
_iesyesyesyesyeqyepsepmerzesreqnepnepnepnepnepnepnepnepnepnepnernesteqneprepueryesyesyesyesyoni_l:
	.string "⠀⠀⠀⠀⢀⣠⣌⡙⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⢋⣡⣄⡀⠀⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesyeqyepsepmerzesreqnepnepnepnepnepnepnepnepnepnepnernesteqneprepueryesyesyesyesyoni: .quad _iesyesyesyesyeqyepsepmerzesreqnepnepnepnepnepnepnepnepnepnepnernesteqneprepueryesyesyesyesyoni_l
_iesyesyesyesaesnepnepnepnepvepmepqeszesnepnepnepnepnesnesnepxepyepoepnepnepnesnesvesyesyesyoni_l:
	.string "⠀⠀⠀⠘⠿⣿⣿⣿⣷⣦⣈⠙⠿⣿⣿⣿⣿⠿⠋⣁⣴⣾⣿⣿⣿⠿⠃⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesaesnepnepnepnepvepmepqeszesnepnepnepnepnesnesnepxepyepoepnepnepnesnesvesyesyesyoni: .quad _iesyesyesyesaesnepnepnepnepvepmepqeszesnepnepnepnepnesnesnepxepyepoepnepnepnesnesvesyesyesyoni_l
_iesyesyesyesyesyeqqeszesreqnepnepnepvepmepuerpeqpepsepyepoepnepnernestesnerxesyesyesyesyesyoni_l:
	.string "⠀⠀⠀⠀⠀⢈⠙⠻⢿⣿⣿⣷⣦⣄⡉⢉⣠⣴⣾⣿⣿⡿⠟⠋⡁⠀⠀⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesyesyeqqeszesreqnepnepnepvepmepuerpeqpepsepyepoepnepnernestesnerxesyesyesyesyesyoni: .quad _iesyesyesyesyesyeqqeszesreqnepnepnepvepmepuerpeqpepsepyepoepnepnernestesnerxesyesyesyesyesyoni_l
_iesyesyesyeqsepwepnepnepwepuerpesxesnepnepnepnepnepnepnesnesxeqpepsepwepnepnepweruesyesyesyoni_l:
	.string "⠀⠀⠀⢠⣶⣿⣿⣶⣄⡉⠛⠿⣿⣿⣿⣿⣿⣿⠿⠛⢉⣠⣶⣿⣿⣶⡄⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyeqsepwepnepnepwepuerpesxesnepnepnepnepnepnepnesnesxeqpepsepwepnepnepweruesyesyesyoni: .quad _iesyesyesyeqsepwepnepnepwepuerpesxesnepnepnepnepnepnepnesnesxeqpepsepwepnepnepweruesyesyesyoni_l
_iesyesyesyesyesqeszesreqnepnepnepvepmepmerpesresteqpeprepyepoepnepnernestesnesxesyesyesyesyoni_l:
	.string "⠀⠀⠀⠀⠈⠙⠻⢿⣿⣿⣷⣦⣌⡉⠻⠟⢉⣡⣴⣾⣿⣿⡿⠟⠋⠁⠀⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesyesqeszesreqnepnepnepvepmepmerpesresteqpeprepyepoepnepnernestesnesxesyesyesyesyoni: .quad _iesyesyesyesyesqeszesreqnepnepnepvepmepmerpesresteqpeprepyepoepnepnernestesnesxesyesyesyesyoni_l
_iesyesyesyeqyepsepwepwepoerqesxesnepnepnepnepvepoepnepnepnesnesxeqxepoepwepwepueryesyesyesyoni_l:
	.string "⠀⠀⠀⢀⣠⣶⣶⣤⡈⠛⠿⣿⣿⣿⣷⣾⣿⣿⣿⠿⠛⢁⣤⣶⣶⣄⡀⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyeqyepsepwepwepoerqesxesnepnepnepnepvepoepnepnepnesnesxeqxepoepwepwepueryesyesyesyoni: .quad _iesyesyesyeqyepsepwepwepoerqesxesnepnepnepnepvepoepnepnepnesnesxeqxepoepwepwepueryesyesyesyoni_l
_iesyesyesyesqesxesnepnepnepnepvepmepqeszesnepnepnesnesnepxepyepoepnepnepnesnesxesxesyesyesyoni_l:
	.string "⠀⠀⠀⠈⠛⠿⣿⣿⣿⣷⣦⣈⠙⠿⣿⣿⠿⠋⣁⣴⣾⣿⣿⣿⠿⠛⠁⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesqesxesnepnepnepnepvepmepqeszesnepnepnesnesnepxepyepoepnepnepnesnesxesxesyesyesyoni: .quad _iesyesyesyesqesxesnepnepnepnepvepmepqeszesnepnepnesnesnepxepyepoepnepnepnesnesxesxesyesyesyoni_l
_iesyesyesyesyesyesyesqeszesreqnepnepnepvepmepuepsepyepoepnepnernestesnesxesyesyesyesyesyesyoni_l:
	.string "⠀⠀⠀⠀⠀⠀⠈⠙⠻⢿⣿⣿⣷⣦⣄⣠⣴⣾⣿⣿⡿⠟⠋⠁⠀⠀⠀⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesyesyesyesqeszesreqnepnepnepvepmepuepsepyepoepnepnernestesnesxesyesyesyesyesyesyoni: .quad _iesyesyesyesyesyesyesqeszesreqnepnepnepvepmepuepsepyepoepnepnernestesnesxesyesyesyesyesyesyoni_l
_iesyesyesyesyesyesyesyesyesyesyesqeszesnepnepnepnepnesnesnesxesyesyesyesyesyesyesyesyesyesyoni_l:
	.string "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠿⣿⣿⣿⣿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesyesyesyesyesyesyesyesqeszesnepnepnepnepnesnesnesxesyesyesyesyesyesyesyesyesyesyoni: .quad _iesyesyesyesyesyesyesyesyesyesyesqeszesnepnepnepnepnesnesnesxesyesyesyesyesyesyesyesyesyesyoni_l
_iesyesyesyesyesyesyesyesyesyesyesyesyesyesyespespesyesyesyesyesyesyesyesyesyesyesyesyesyesyoni_l:
	.string "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	.section .data.rel.local,"aw"
_iesyesyesyesyesyesyesyesyesyesyesyesyesyesyespespesyesyesyesyesyesyesyesyesyesyesyesyesyesyoni: .quad _iesyesyesyesyesyesyesyesyesyesyesyesyesyesyespespesyesyesyesyesyesyesyesyesyesyesyesyesyesyoni_l
_ijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjoni_l:
	.string "===============================\n"
	.section .data.rel.local,"aw"
_ijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjoni: .quad _ijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjoni_l
_igggggggggggWelcomegtogoni_l:
	.string "           Welcome to \n"
	.section .data.rel.local,"aw"
_igggggggggggWelcomegtogoni: .quad _igggggggggggWelcomegtogoni_l
_iggggggggggrtrtrtrtrtroni_l:
	.string "          +-+-+-+-+-+\n"
	.section .data.rel.local,"aw"
_iggggggggggrtrtrtrtrtroni: .quad _iggggggggggrtrtrtrtrtroni_l
_igggggggggguSuTuAuCuKuoni_l:
	.string "          |S|T|A|C|K|\n"
	.section .data.rel.local,"aw"
_igggggggggguSuTuAuCuKuoni: .quad _igggggggggguSuTuAuCuKuoni_l
_iggggggrtrtrtrtrtrtrtrtrtroni_l:
	.string "      +-+-+-+-+-+-+-+-+-+\n"
	.section .data.rel.local,"aw"
_iggggggrtrtrtrtrtrtrtrtrtroni: .quad _iggggggrtrtrtrtrtrtrtrtrtroni_l
_igggggguSuIuMuUuLuAuTuOuRuoni_l:
	.string "      |S|I|M|U|L|A|T|O|R|\n"
	.section .data.rel.local,"aw"
_igggggguSuIuMuUuLuAuTuOuRuoni: .quad _igggggguSuIuMuUuLuAuTuOuRuoni_l
_iggggggrtrtrrtrtrtrtrrtrtroni_l:
	.string "      +-+-++-+-+-+-++-+-+\n"
	.section .data.rel.local,"aw"
_iggggggrtrtrrtrtrtrtrrtrtroni: .quad _iggggggrtrtrrtrtrtrtrrtrtroni_l
_igggggggggggu2u0u2u3uoni_l:
	.string "           |2|0|2|3|\n"
	.section .data.rel.local,"aw"
_igggggggggggu2u0u2u3uoni: .quad _igggggggggggu2u0u2u3uoni_l
_igggggggggggrtrtrtrtrononi_l:
	.string "           +-+-+-+-+\n\n"
	.section .data.rel.local,"aw"
_igggggggggggrtrtrtrtrononi: .quad _igggggggggggrtrtrtrtrononi_l
_iggggggbygGabrielgMadeiraoni_l:
	.string "      by Gabriel Madeira\n"
	.section .data.rel.local,"aw"
_iggggggbygGabrielgMadeiraoni: .quad _iggggggbygGabrielgMadeiraoni_l
_iChoosegagstackgoperationgong1ggPushong2ggPopong3ggExitongOperationggi_l:
	.string "Choose a stack operation:\n 1: Push\n 2: Pop\n 3: Exit\n Operation: "
	.section .data.rel.local,"aw"
_iChoosegagstackgoperationgong1ggPushong2ggPopong3ggExitongOperationggi: .quad _iChoosegagstackgoperationgong1ggPushong2ggPopong3ggExitongOperationggi_l
_iEntergagvaluegtogpushggi_l:
	.string "Enter a value to push: "
	.section .data.rel.local,"aw"
_iEntergagvaluegtogpushggi: .quad _iEntergagvaluegtogpushggi_l
_iStackgisgfullhoni_l:
	.string "Stack is full!\n"
	.section .data.rel.local,"aw"
_iStackgisgfullhoni: .quad _iStackgisgfullhoni_l
_iStackghasgnogvaluehoni_l:
	.string "Stack has no value!\n"
	.section .data.rel.local,"aw"
_iStackghasgnogvaluehoni: .quad _iStackghasgnogvaluehoni_l
	.globl _2
_2: .long 2
	.globl _3
_3: .long 3
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
