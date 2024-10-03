section .text
	global ft_strcpy

ft_strcpy:
	xor rcx, rcx
	xor rax, rax
	.loop:
		mov bl, [rsi + rcx]
		mov [rdi + rcx], bl
		test bl, bl
		jz .end
		inc rcx
		jmp .loop
	
	.end:
		mov rax, rdi
		ret
