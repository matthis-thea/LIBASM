section .text
	global ft_strcpy

ft_strcpy:
	xor rcx, rcx
	.loop:
		mov bl, [rsi]
		mov [rdi], bl
		test bl, bl
		jz .end
		inc rsi
		inc rdi
		inc rcx
		jmp .loop
	
	.end:
		mov BYTE [rdi + rcx], 0
		mov rax, rdi
		ret
