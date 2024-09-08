NAME = libft.a

SRC  = ex.s

OBJ = $(SRC:.s=.o) 

RM = rm -rf

all : $(NAME)

# $(NAME) : $(OBJ)
# 	 ar -crs $(NAME) $(OBJ)


	
clean :
	$(RM) $(OBJ)

fclean :	clean
	$(RM) $(NAME)


re :	fclean all

.PHONY :	all clean fclean re