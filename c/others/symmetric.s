	.file	"symmetric.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"Enter the no. of rows(or cols) of the square matrix: "
.LC1:
	.string	"%d"
.LC2:
	.string	"The input matrix is:"
.LC3:
	.string	"The matrix is symmetric!"
	.align 4
.LC4:
	.string	"The matrix is  not  symmetric!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$40032, %esp
	movl	$.LC0, (%esp)
	call	printf
	leal	26(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	__isoc99_scanf
	leal	32(%esp), %eax
	movl	%eax, 28(%esp)
	movzwl	26(%esp), %eax
	cwtl
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	input_martix
	movl	$.LC2, (%esp)
	call	puts
	movzwl	26(%esp), %eax
	cwtl
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	print_matrix
	movzwl	26(%esp), %eax
	cwtl
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	issymmetric
	testw	%ax, %ax
	je	.L2
	movl	$.LC3, (%esp)
	call	puts
	jmp	.L3
.L2:
	movl	$.LC4, (%esp)
	call	puts
.L3:
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	issymmetric
	.type	issymmetric, @function
issymmetric:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	12(%ebp), %eax
	movw	%ax, -20(%ebp)
	movw	$1, -2(%ebp)
	movw	$0, -6(%ebp)
	jmp	.L6
.L13:
	movzwl	-6(%ebp), %eax
	movw	%ax, -4(%ebp)
	jmp	.L7
.L10:
	movswl	-6(%ebp), %edx
	movswl	-20(%ebp), %eax
	imull	%edx, %eax
	movl	%eax, %edx
	movswl	-4(%ebp), %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movswl	-4(%ebp), %ecx
	movswl	-20(%ebp), %eax
	imull	%ecx, %eax
	movl	%eax, %ecx
	movswl	-6(%ebp), %eax
	addl	%ecx, %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	je	.L8
	movw	$0, -2(%ebp)
	jmp	.L9
.L8:
	addw	$1, -4(%ebp)
.L7:
	movzwl	-4(%ebp), %eax
	cmpw	-20(%ebp), %ax
	jl	.L10
.L9:
	cmpw	$0, -2(%ebp)
	je	.L15
.L11:
	addw	$1, -6(%ebp)
.L6:
	movzwl	-6(%ebp), %eax
	cmpw	-20(%ebp), %ax
	jl	.L13
	jmp	.L12
.L15:
	nop
.L12:
	movzwl	-2(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	issymmetric, .-issymmetric
	.section	.rodata
	.align 4
.LC5:
	.string	"Enter element in row %d column %d: "
	.text
	.globl	input_martix
	.type	input_martix, @function
input_martix:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %eax
	movw	%ax, -28(%ebp)
	movw	$0, -12(%ebp)
	jmp	.L17
.L20:
	movw	$0, -10(%ebp)
	jmp	.L18
.L19:
	movswl	-10(%ebp), %edx
	movswl	-12(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC5, (%esp)
	call	printf
	movswl	-12(%ebp), %edx
	movswl	-28(%ebp), %eax
	imull	%edx, %eax
	movl	%eax, %edx
	movswl	-10(%ebp), %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	__isoc99_scanf
	addw	$1, -10(%ebp)
.L18:
	movzwl	-10(%ebp), %eax
	cmpw	-28(%ebp), %ax
	jl	.L19
	addw	$1, -12(%ebp)
.L17:
	movzwl	-12(%ebp), %eax
	cmpw	-28(%ebp), %ax
	jl	.L20
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	input_martix, .-input_martix
	.section	.rodata
.LC6:
	.string	"%d\t"
	.text
	.globl	print_matrix
	.type	print_matrix, @function
print_matrix:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %eax
	movw	%ax, -28(%ebp)
	movw	$0, -12(%ebp)
	jmp	.L22
.L25:
	movw	$0, -10(%ebp)
	jmp	.L23
.L24:
	movswl	-12(%ebp), %edx
	movswl	-28(%ebp), %eax
	imull	%edx, %eax
	movl	%eax, %edx
	movswl	-10(%ebp), %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	addw	$1, -10(%ebp)
.L23:
	movzwl	-10(%ebp), %eax
	cmpw	-28(%ebp), %ax
	jl	.L24
	movl	$10, (%esp)
	call	putchar
	addw	$1, -12(%ebp)
.L22:
	movzwl	-12(%ebp), %eax
	cmpw	-28(%ebp), %ax
	jl	.L25
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	print_matrix, .-print_matrix
	.ident	"GCC: (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
