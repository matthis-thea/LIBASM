# Variables

NASM = nasm
NASMFLAGS = -f elf64
LD = ld 
LDFLAGS = 
GCC = gcc
GCCFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Sources files and object linked
EXEC = libasm
ASM_SOURCES = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s
C_SOURCES = main.c
OBJ_FILES = $(ASM_SOURCES:.s=.o) $(C_SOURCES:.c=.o)

# Rules by default
all: $(EXEC) clean

# Rules for all exec files
$(EXEC): % : $(OBJ_FILES)
	$(GCC) -o $@ $^
	$(clean)

# Rules for assembly .s on .o and .c on .o
%.o: %.s
	$(NASM) $(NASMFLAGS) -o $@ $<

%.o: %.c
	$(GCC) $(GCCFLAGS) -c $< -o $@


# Rules for clen	
clean :
	$(RM) $(OBJ_FILES)

fclean :	clean
	$(RM) $(EXEC)


re :	fclean all

.PHONY :	all clean fclean re