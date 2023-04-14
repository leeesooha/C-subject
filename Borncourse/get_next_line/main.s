	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_get_next_line          ## -- Begin function get_next_line
	.p2align	4, 0x90
_get_next_line:                         ## @get_next_line
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	%edi, -12(%rbp)
	cmpl	$0, -12(%rbp)
	jge	LBB0_2
## %bb.1:
	movq	$0, -8(%rbp)
	jmp	LBB0_11
LBB0_2:
	movl	-12(%rbp), %esi
	leaq	_get_next_line.lst(%rip), %rdi
	leaq	-24(%rbp), %rdx
	callq	_find_file
	cmpl	$0, %eax
	jne	LBB0_4
## %bb.3:
	movq	$0, -8(%rbp)
	jmp	LBB0_11
LBB0_4:
	movq	-24(%rbp), %rax
	cmpq	$0, 8(%rax)
	jne	LBB0_6
## %bb.5:
	leaq	_get_next_line.lst(%rip), %rdi
	leaq	-24(%rbp), %rsi
	callq	_free_fd
	movq	$0, -8(%rbp)
	jmp	LBB0_11
LBB0_6:
	leaq	-24(%rbp), %rdi
	callq	_get_buff
	cmpl	$0, %eax
	jne	LBB0_8
## %bb.7:
	leaq	_get_next_line.lst(%rip), %rdi
	leaq	-24(%rbp), %rsi
	callq	_free_fd
	movq	%rax, -8(%rbp)
	jmp	LBB0_11
LBB0_8:
	leaq	-32(%rbp), %rdi
	leaq	-24(%rbp), %rsi
	callq	_get_print
	cmpl	$0, %eax
	jne	LBB0_10
## %bb.9:
	leaq	_get_next_line.lst(%rip), %rdi
	leaq	-24(%rbp), %rsi
	callq	_free_fd
	movq	%rax, -8(%rbp)
	jmp	LBB0_11
LBB0_10:
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB0_11:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_find_file              ## -- Begin function find_file
	.p2align	4, 0x90
_find_file:                             ## @find_file
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	movq	%rdx, -32(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -40(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -40(%rbp)
	je	LBB1_5
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movq	-40(%rbp), %rax
	movl	(%rax), %ecx
	cmpl	-20(%rbp), %ecx
	jne	LBB1_4
## %bb.3:
	movq	-40(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	%rax, (%rcx)
	movl	$1, -4(%rbp)
	jmp	LBB1_11
LBB1_4:                                 ##   in Loop: Header=BB1_1 Depth=1
	movq	-40(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -40(%rbp)
	jmp	LBB1_1
LBB1_5:
	movl	$24, %edi
	callq	_malloc
	movq	-32(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-32(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB1_7
## %bb.6:
	movl	$0, -4(%rbp)
	jmp	LBB1_11
LBB1_7:
	movl	-20(%rbp), %eax
	movq	-32(%rbp), %rcx
	movq	(%rcx), %rcx
	movl	%eax, (%rcx)
	leaq	L_.str(%rip), %rdi
	callq	_ft_strdup
	movq	-32(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rax, 8(%rcx)
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	$0, 16(%rax)
	movq	-16(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB1_9
## %bb.8:
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	-16(%rbp), %rcx
	movq	%rax, (%rcx)
	jmp	LBB1_10
LBB1_9:
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	-48(%rbp), %rcx
	movq	%rax, 16(%rcx)
LBB1_10:
	movl	$1, -4(%rbp)
LBB1_11:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_free_fd                ## -- Begin function free_fd
	.p2align	4, 0x90
_free_fd:                               ## @free_fd
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rcx
	cmpq	(%rcx), %rax
	jne	LBB2_2
## %bb.1:
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, (%rcx)
	jmp	LBB2_6
LBB2_2:
	jmp	LBB2_3
LBB2_3:                                 ## =>This Inner Loop Header: Depth=1
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rcx
	cmpq	(%rcx), %rax
	je	LBB2_5
## %bb.4:                               ##   in Loop: Header=BB2_3 Depth=1
	movq	-24(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -24(%rbp)
	jmp	LBB2_3
LBB2_5:
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	-32(%rbp), %rcx
	movq	%rax, 16(%rcx)
LBB2_6:
	movq	-24(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB2_8
## %bb.7:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdi
	callq	_free
LBB2_8:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	callq	_free
	xorl	%ecx, %ecx
	movl	%ecx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_get_buff               ## -- Begin function get_buff
	.p2align	4, 0x90
_get_buff:                              ## @get_buff
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$112, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	%rdi, -80(%rbp)
LBB3_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdi
	movl	$10, %esi
	callq	_ft_strchr
	cmpq	$0, %rax
	setne	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	jne	LBB3_2
	jmp	LBB3_11
LBB3_2:                                 ##   in Loop: Header=BB3_1 Depth=1
	leaq	-64(%rbp), %rsi
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movl	(%rax), %edi
	movl	$42, %edx
	callq	_read
                                        ## kill: def $eax killed $eax killed $rax
	movl	%eax, -84(%rbp)
	cmpl	$-1, -84(%rbp)
	je	LBB3_5
## %bb.3:                               ##   in Loop: Header=BB3_1 Depth=1
	cmpl	$0, -84(%rbp)
	jne	LBB3_6
## %bb.4:                               ##   in Loop: Header=BB3_1 Depth=1
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movsbl	(%rax), %ecx
	cmpl	$0, %ecx
	jne	LBB3_6
LBB3_5:
	movl	$0, -68(%rbp)
	jmp	LBB3_12
LBB3_6:                                 ##   in Loop: Header=BB3_1 Depth=1
	cmpl	$0, -84(%rbp)
	jne	LBB3_8
## %bb.7:
	movl	$1, -68(%rbp)
	jmp	LBB3_12
LBB3_8:                                 ##   in Loop: Header=BB3_1 Depth=1
	leaq	-64(%rbp), %rsi
	movslq	-84(%rbp), %rax
	movb	$0, -64(%rbp,%rax)
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movq	%rax, -96(%rbp)
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdi
	callq	_ft_strjoin
	movq	-80(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rax, 8(%rcx)
	movq	-96(%rbp), %rdi
	callq	_free
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	cmpq	$0, 8(%rax)
	jne	LBB3_10
## %bb.9:
	movl	$0, -68(%rbp)
	jmp	LBB3_12
LBB3_10:                                ##   in Loop: Header=BB3_1 Depth=1
	jmp	LBB3_1
LBB3_11:
	movl	$1, -68(%rbp)
LBB3_12:
	movl	-68(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -100(%rbp)        ## 4-byte Spill
	jne	LBB3_14
## %bb.13:
	movl	-100(%rbp), %eax        ## 4-byte Reload
	addq	$112, %rsp
	popq	%rbp
	retq
LBB3_14:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_get_print              ## -- Begin function get_print
	.p2align	4, 0x90
_get_print:                             ## @get_print
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	$0, -40(%rbp)
LBB4_1:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	movq	-24(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	8(%rcx), %rcx
	movq	-40(%rbp), %rdx
	movsbl	(%rcx,%rdx), %esi
	cmpl	$0, %esi
	movb	%al, -41(%rbp)          ## 1-byte Spill
	je	LBB4_3
## %bb.2:                               ##   in Loop: Header=BB4_1 Depth=1
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movq	-40(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$10, %edx
	setne	%sil
	movb	%sil, -41(%rbp)         ## 1-byte Spill
LBB4_3:                                 ##   in Loop: Header=BB4_1 Depth=1
	movb	-41(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB4_4
	jmp	LBB4_5
LBB4_4:                                 ##   in Loop: Header=BB4_1 Depth=1
	movq	-40(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -40(%rbp)
	jmp	LBB4_1
LBB4_5:
	xorl	%esi, %esi
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdi
	movq	-40(%rbp), %rax
	addq	$1, %rax
	movq	%rax, %rdx
	callq	_ft_substr
	movq	-16(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-16(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB4_7
## %bb.6:
	movl	$0, -4(%rbp)
	jmp	LBB4_10
LBB4_7:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdi
	movq	-40(%rbp), %rax
	addq	$1, %rax
                                        ## kill: def $eax killed $eax killed $rax
	movl	%eax, %esi
	movq	$-1, %rdx
	callq	_ft_substr
	movq	-24(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rax, 8(%rcx)
	movq	-32(%rbp), %rdi
	callq	_free
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	cmpq	$0, 8(%rax)
	jne	LBB4_9
## %bb.8:
	movq	-16(%rbp), %rax
	movq	(%rax), %rdi
	callq	_free
	movl	$0, -4(%rbp)
	jmp	LBB4_10
LBB4_9:
	movl	$1, -4(%rbp)
LBB4_10:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_strdup              ## -- Begin function ft_strdup
	.p2align	4, 0x90
_ft_strdup:                             ## @ft_strdup
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	callq	_ft_strlen
	addq	$1, %rax
	movq	%rax, %rdi
	callq	_malloc
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jne	LBB5_2
## %bb.1:
	movq	$0, -8(%rbp)
	jmp	LBB5_6
LBB5_2:
	movq	$0, -24(%rbp)
LBB5_3:                                 ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	cmpb	$0, (%rax,%rcx)
	je	LBB5_5
## %bb.4:                               ##   in Loop: Header=BB5_3 Depth=1
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	movb	(%rax,%rcx), %dl
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rcx
	movb	%dl, (%rax,%rcx)
	movq	-24(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -24(%rbp)
	jmp	LBB5_3
LBB5_5:
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rcx
	movb	$0, (%rax,%rcx)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB5_6:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_strchr              ## -- Begin function ft_strchr
	.p2align	4, 0x90
_ft_strchr:                             ## @ft_strchr
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -40(%rbp)
	movl	-20(%rbp), %ecx
                                        ## kill: def $cl killed $cl killed $ecx
	movb	%cl, -41(%rbp)
	movq	$0, -32(%rbp)
LBB6_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-40(%rbp), %rax
	movq	-32(%rbp), %rcx
	cmpb	$0, (%rax,%rcx)
	je	LBB6_5
## %bb.2:                               ##   in Loop: Header=BB6_1 Depth=1
	movq	-40(%rbp), %rax
	movq	-32(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	movsbl	-41(%rbp), %esi
	cmpl	%esi, %edx
	jne	LBB6_4
## %bb.3:
	movq	-32(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -8(%rbp)
	jmp	LBB6_6
LBB6_4:                                 ##   in Loop: Header=BB6_1 Depth=1
	movq	-32(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -32(%rbp)
	jmp	LBB6_1
LBB6_5:
	movq	$0, -8(%rbp)
LBB6_6:
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_strjoin             ## -- Begin function ft_strjoin
	.p2align	4, 0x90
_ft_strjoin:                            ## @ft_strjoin
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rdi
	callq	_ft_strlen
	movq	-24(%rbp), %rdi
	movq	%rax, -56(%rbp)         ## 8-byte Spill
	callq	_ft_strlen
	movq	-56(%rbp), %rcx         ## 8-byte Reload
	addq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, %rdi
	callq	_malloc
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jne	LBB7_2
## %bb.1:
	movq	$0, -8(%rbp)
	jmp	LBB7_9
LBB7_2:
	movq	$0, -40(%rbp)
	movq	$0, -48(%rbp)
LBB7_3:                                 ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax
	movq	-48(%rbp), %rcx
	cmpb	$0, (%rax,%rcx)
	je	LBB7_5
## %bb.4:                               ##   in Loop: Header=BB7_3 Depth=1
	movq	-16(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	%rcx, %rdx
	addq	$1, %rdx
	movq	%rdx, -48(%rbp)
	movb	(%rax,%rcx), %sil
	movq	-32(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	%rcx, %rdx
	addq	$1, %rdx
	movq	%rdx, -40(%rbp)
	movb	%sil, (%rax,%rcx)
	jmp	LBB7_3
LBB7_5:
	movq	$0, -48(%rbp)
LBB7_6:                                 ## =>This Inner Loop Header: Depth=1
	movq	-24(%rbp), %rax
	movq	-48(%rbp), %rcx
	cmpb	$0, (%rax,%rcx)
	je	LBB7_8
## %bb.7:                               ##   in Loop: Header=BB7_6 Depth=1
	movq	-24(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	%rcx, %rdx
	addq	$1, %rdx
	movq	%rdx, -48(%rbp)
	movb	(%rax,%rcx), %sil
	movq	-32(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	%rcx, %rdx
	addq	$1, %rdx
	movq	%rdx, -40(%rbp)
	movb	%sil, (%rax,%rcx)
	jmp	LBB7_6
LBB7_8:
	movq	-32(%rbp), %rax
	movq	-40(%rbp), %rcx
	movb	$0, (%rax,%rcx)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB7_9:
	movq	-8(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_substr              ## -- Begin function ft_substr
	.p2align	4, 0x90
_ft_substr:                             ## @ft_substr
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	movq	%rdx, -32(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, %ecx
	movq	-16(%rbp), %rdi
	movq	%rcx, -56(%rbp)         ## 8-byte Spill
	callq	_ft_strlen
	movq	-56(%rbp), %rcx         ## 8-byte Reload
	cmpq	%rax, %rcx
	jae	LBB8_2
## %bb.1:
	cmpq	$0, -32(%rbp)
	jne	LBB8_3
LBB8_2:
	leaq	L_.str(%rip), %rdi
	callq	_ft_strdup
	movq	%rax, -8(%rbp)
	jmp	LBB8_13
LBB8_3:
	movq	-32(%rbp), %rax
	movq	-16(%rbp), %rdi
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	callq	_ft_strlen
	movl	-20(%rbp), %ecx
	movl	%ecx, %edx
	subq	%rdx, %rax
	movq	-64(%rbp), %rdx         ## 8-byte Reload
	cmpq	%rax, %rdx
	jbe	LBB8_5
## %bb.4:
	movq	-16(%rbp), %rdi
	callq	_ft_strlen
	movl	-20(%rbp), %ecx
	movl	%ecx, %edx
	subq	%rdx, %rax
	movq	%rax, -32(%rbp)
LBB8_5:
	movl	-20(%rbp), %eax
	movq	-16(%rbp), %rcx
	movl	%eax, %eax
	movl	%eax, %edx
	addq	%rdx, %rcx
	movq	%rcx, -16(%rbp)
	movq	-32(%rbp), %rcx
	shlq	$0, %rcx
	addq	$1, %rcx
	movq	%rcx, %rdi
	callq	_malloc
	movq	%rax, -40(%rbp)
	cmpq	$0, -40(%rbp)
	jne	LBB8_7
## %bb.6:
	movq	$0, -8(%rbp)
	jmp	LBB8_13
LBB8_7:
	movq	$0, -48(%rbp)
LBB8_8:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	movq	-16(%rbp), %rcx
	movq	-48(%rbp), %rdx
	movsbl	(%rcx,%rdx), %esi
	cmpl	$0, %esi
	movb	%al, -65(%rbp)          ## 1-byte Spill
	je	LBB8_10
## %bb.9:                               ##   in Loop: Header=BB8_8 Depth=1
	movq	-48(%rbp), %rax
	cmpq	-32(%rbp), %rax
	setb	%cl
	movb	%cl, -65(%rbp)          ## 1-byte Spill
LBB8_10:                                ##   in Loop: Header=BB8_8 Depth=1
	movb	-65(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB8_11
	jmp	LBB8_12
LBB8_11:                                ##   in Loop: Header=BB8_8 Depth=1
	movq	-16(%rbp), %rax
	movq	-48(%rbp), %rcx
	movb	(%rax,%rcx), %dl
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rcx
	movb	%dl, (%rax,%rcx)
	movq	-48(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -48(%rbp)
	jmp	LBB8_8
LBB8_12:
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rcx
	movb	$0, (%rax,%rcx)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB8_13:
	movq	-8(%rbp), %rax
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_strlen              ## -- Begin function ft_strlen
	.p2align	4, 0x90
_ft_strlen:                             ## @ft_strlen
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	$0, -16(%rbp)
LBB9_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	cmpb	$0, (%rax)
	je	LBB9_3
## %bb.2:                               ##   in Loop: Header=BB9_1 Depth=1
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -8(%rbp)
	jmp	LBB9_1
LBB9_3:
	movq	-16(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	xorl	%esi, %esi
	movl	$0, -4(%rbp)
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_open
	xorl	%esi, %esi
	movl	%eax, -20(%rbp)
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_open
	xorl	%esi, %esi
	movl	%eax, -24(%rbp)
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_open
	xorl	%esi, %esi
	movl	%eax, -28(%rbp)
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_open
	xorl	%esi, %esi
	movl	%eax, -32(%rbp)
	leaq	L_.str.5(%rip), %rdi
	movb	$0, %al
	callq	_open
	movl	%eax, -36(%rbp)
	movl	-20(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-24(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-28(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-20(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-32(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-24(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-28(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-28(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-28(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-28(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-28(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -80(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-36(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-36(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -88(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-36(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -92(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-36(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -96(%rbp)         ## 4-byte Spill
	callq	_free
	movl	-20(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -100(%rbp)        ## 4-byte Spill
	callq	_free
	movl	-20(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -104(%rbp)        ## 4-byte Spill
	callq	_free
	movl	-20(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -108(%rbp)        ## 4-byte Spill
	callq	_free
	movl	-20(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -112(%rbp)        ## 4-byte Spill
	callq	_free
	movl	-36(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
LBB10_1:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -16(%rbp)
	je	LBB10_3
## %bb.2:                               ##   in Loop: Header=BB10_1 Depth=1
	movq	-16(%rbp), %rsi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -116(%rbp)        ## 4-byte Spill
	callq	_free
	movl	-36(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	jmp	LBB10_1
LBB10_3:
	movl	-36(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rsi
	leaq	L_.str.7(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-20(%rbp), %edi
	movl	%eax, -120(%rbp)        ## 4-byte Spill
	callq	_get_next_line
	leaq	L_.str.6(%rip), %rdi
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	movl	-20(%rbp), %edi
	movl	%eax, -124(%rbp)        ## 4-byte Spill
	callq	_get_next_line
	leaq	L_.str.6(%rip), %rdi
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	movl	-20(%rbp), %edi
	movl	%eax, -128(%rbp)        ## 4-byte Spill
	callq	_get_next_line
	leaq	L_.str.6(%rip), %rdi
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	movl	-20(%rbp), %edi
	movl	%eax, -132(%rbp)        ## 4-byte Spill
	callq	_get_next_line
	leaq	L_.str.6(%rip), %rdi
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	movl	-20(%rbp), %edi
	movl	%eax, -136(%rbp)        ## 4-byte Spill
	callq	_get_next_line
	leaq	L_.str.6(%rip), %rdi
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	movl	-20(%rbp), %edi
	movl	%eax, -140(%rbp)        ## 4-byte Spill
	callq	_get_next_line
	leaq	L_.str.6(%rip), %rdi
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -144(%rbp)        ## 4-byte Spill
	movl	%ecx, %eax
	addq	$144, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.zerofill __DATA,__bss,_get_next_line.lst,8,3 ## @get_next_line.lst
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.space	1

L_.str.1:                               ## @.str.1
	.asciz	"Harry Potter.txt"

L_.str.2:                               ## @.str.2
	.asciz	"The Avengers.txt"

L_.str.3:                               ## @.str.3
	.asciz	"movie.txt"

L_.str.4:                               ## @.str.4
	.asciz	"gogo.txt"

L_.str.5:                               ## @.str.5
	.asciz	"test.txt"

L_.str.6:                               ## @.str.6
	.asciz	"%s"

L_.str.7:                               ## @.str.7
	.asciz	"\n%s"

.subsections_via_symbols
