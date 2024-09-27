#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>

// Déclaration de la fonction assembleur
size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *restrict dst, const char *restrict src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);

int main(int argc, char **argv)
{
	if (argc == 4 && atoi(argv[3]) >= 0 && atoi(argv[3]) <= 3)
	{
		char str_one[1000000];
		char str_two[1000000];

		printf("-------------------- Test for ft_strlen --------------------\n");
		printf("String : %s\nLIBASM function : %ld\nC Native function : %ld\n", argv[1], ft_strlen(argv[1]), strlen(argv[1]));
		printf("------------------------------------------------------------\n");



		printf("-------------------- Test for ft_strcpy --------------------\n");
		printf("String : %s\n", argv[1]);
		ft_strcpy(str_one, argv[1]);
		printf("LIBASM function : %s\n", str_one);
		strcpy(str_two, argv[1]);
		printf("Native function : %s\n", str_two);
		printf("------------------------------------------------------------\n");



		printf("-------------------- Test for ft_strcmp --------------------\n");
		printf("String one : %s | String two : %s\nLIBASM function : %d\nC Native function : %d\n", argv[1], argv[2], ft_strcmp(argv[1], argv[2]), strcmp(argv[1], argv[2]));
		printf("------------------------------------------------------------\n");



		printf("-------------------- Test for ft_write --------------------\n");
		printf("Native function :\n");
		ssize_t result = write(4, argv[1], strlen(argv[1]));  // Cela provoque une erreur car le descripteur -1 est invalide
		if (result == -1) {
			perror("ft_write error with invalid file descriptor");
		}
		printf("\n");
		printf("LIBASM function :\n");
		ft_write(4, argv[1], strlen(argv[1]));
		printf("\n");
		printf("------------------------------------------------------------\n");
	}
	else
		printf("Please, enter three argument and the third arguments need to be an integer between 0 and 2 !\n");
	return (0);
}
