section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax
	xor rcx, rcx

	.loop:

		cmp BYTE[rdi + rcx], 0
		jz .end

		cmp BYTE[rsi + rcx], 0
		jz .end

		mov al, BYTE[rsi + rcx]
		cmp BYTE[rdi + rcx], al
		jnz .end

		inc rcx
		jmp .loop
	

	.end:
		movzx rax, BYTE[rdi + rcx]
		movzx rdx, BYTE[rsi + rcx]
		sub rax, rdx
		ret