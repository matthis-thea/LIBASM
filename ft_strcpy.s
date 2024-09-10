section .text
	global ft_strcpy

ft_strcpy:
	.loop:
		mov bl, [rsi]
		mov [rdi], bl
		test bl, bl
		jz .end
		inc rsi
		inc rdi
		jmp .loop
	
	.end:
		mov rax, rdi
		ret
