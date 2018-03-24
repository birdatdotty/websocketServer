	.file	"createHTML.cc"
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.align 8
.LC0:
	.string	"<!DOCTYPE html><html lang='ru-RU'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><meta http-equiv='X-UA-Compatible' content='ie=edge'><title>%s</title></head><body>%s</body></html>"
	.text
	.globl	_Z10createPageNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES4_S4_
	.type	_Z10createPageNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES4_S4_, @function
_Z10createPageNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES4_S4_:
.LFB948:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA948
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rbx
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv@PLT
	addq	%rax, %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv@PLT
	addq	%rbx, %rax
	addq	$1, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -32(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv@PLT
	movq	%rax, %rbx
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv@PLT
	movq	%rax, %rdx
	movq	-24(%rbp), %rsi
	movq	-32(%rbp), %rax
	movq	%rbx, %rcx
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB0:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEPKc@PLT
.LEHE0:
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$1, %ebx
.L2:
	movl	%ebx, %eax
	jmp	.L5
.L4:
	movq	%rax, %rdi
	call	__cxa_begin_catch@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, %ebx
.LEHB1:
	call	__cxa_end_catch@PLT
.LEHE1:
	jmp	.L2
.L5:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE948:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
	.align 4
.LLSDA948:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT948-.LLSDATTD948
.LLSDATTD948:
	.byte	0x1
	.uleb128 .LLSDACSE948-.LLSDACSB948
.LLSDACSB948:
	.uleb128 .LEHB0-.LFB948
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L4-.LFB948
	.uleb128 0x1
	.uleb128 .LEHB1-.LFB948
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE948:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT948:
	.text
	.size	_Z10createPageNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES4_S4_, .-_Z10createPageNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES4_S4_
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.ident	"fuck you"
	.section	.note.GNU-stack,"",@progbits
