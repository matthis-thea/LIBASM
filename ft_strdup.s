section .text
	global  ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc

ft_strdup:
        push    rdi
        call    ft_strlen
        inc     rax
        mov     rdi, rax
        call    malloc WRT ..plt
        test    rax, rax
        jz      .end
        mov     rdi, rax
        pop     rsi
        call    ft_strcpy

.end:
        ret