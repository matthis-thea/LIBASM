#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Déclaration de la fonction assembleur
extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *restrict dst, const char *restrict src);

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char str_one[1000000];
		char str_two[1000000];

		printf("-------------------- Test for ft_strlen --------------------\n");
		printf("String : %s\nLIBASM function : %ld\nC native function : %ld\n", argv[1], ft_strlen(argv[1]), strlen(argv[1]));
		printf("------------------------------------------------------------\n");
		printf("-------------------- Test for ft_strcpy --------------------\n");
		printf("String : %s\n", argv[1]);
		ft_strcpy(str_one, argv[1]);
		printf("LIBASM function : %s\n", str_one);
		strcpy(str_two, argv[1]);
		printf("native function : %s\n", str_two);

		printf("------------------------------------------------------------\n");
	}
	else
		printf("Please, enter one argument\n");
	return (0);
}
