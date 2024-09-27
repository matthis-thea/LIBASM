section .text
	global ft_write
	extern __errno_location


ft_write:

	mov rax, 1        ; numéro du syscall pour `write`
    syscall           ; appel du syscall

    ; Vérification des erreurs
    cmp rax, -1       ; Vérifier si rax == -1 (erreur)
    jne .end          ; Si pas d'erreur, sauter à la fin

    ; Gestion de l'erreur
    mov rdi, [rel __errno_location]  ; Charger l'adresse de errno
    mov rdi, [rdi]                   ; Charger errno lui-même
    mov eax, -1                      ; Assigner -1 (erreur) à errno
    mov [rdi], eax

.end:
    ret