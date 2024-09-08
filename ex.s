section .text
    global ft_strlen


ft_strlen:
    xor rax, rax

    .start_loop:
        cmp		BYTE [rdi + rax], 0
        je .end_ftstrlen
        inc rax
        jmp .start_loop

    .end_ftstrlen:
        ret