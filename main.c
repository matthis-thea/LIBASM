#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

// Déclaration de la fonction assembleur
size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *restrict dst, const char *restrict src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, const void *buf, size_t count);

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		char str_one[1000000];
		char str_two[1000000];

		printf("-------------------- Test for ft_strlen --------------------\n");
		printf("LIBASM function : %ld\nC Native function : %ld\n", ft_strlen(argv[1]), strlen(argv[1]));
		printf("------------------------------------------------------------\n\n\n\n\n\n\n");



		printf("-------------------- Test for ft_strcpy --------------------\n");
		printf("Native function : %s\n", str_two);
		char *test = strcpy(str_two, argv[1]);
		printf("Retour de la native function: %s\n", test);
		printf("LIBASM function : %s\n", str_one);
		char *test_one = ft_strcpy(str_one, argv[1]);
		printf("Retour de la LIBASM function: %s\n", test_one);
		printf("------------------------------------------------------------\n\n\n\n\n\n\n");



		printf("-------------------- Test for ft_strcmp --------------------\n");
		printf("LIBASM function : %d\nC Native function : %d\n", ft_strcmp(argv[1], argv[2]), strcmp(argv[1], argv[2]));
		printf("------------------------------------------------------------\n\n\n\n\n\n\n");



		printf("-------------------- Test for ft_write --------------------\n");
		printf("Native function :\n");
		ssize_t result = write(atoi(argv[3]), argv[1], strlen(argv[1]));
		printf("\n");
		if (result == -1)
			perror("write error with invalid file descriptor");
		else
			printf("Le retour de la Native function est %ld\n", result);
		int fd = open("write.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
		if (fd == -1)
			return (1);
		write(fd, argv[1], strlen(argv[1]));
		close(fd);

		printf("LIBASM function :\n");
		ssize_t result_two = ft_write(atoi(argv[3]), argv[1], strlen(argv[1]));
		printf("\n");
		if (result_two == -1)
			perror("ft_write error with invalid file descriptor");
		else
			printf("Le retour de la LIBASM function est %ld\n", result_two);
		int fd_one = open("ft_write.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
		if (fd_one == -1)
			return (1);
		write(fd_one, argv[1], strlen(argv[1]));
		close(fd_one);
		printf("------------------------------------------------------------\n\n\n\n\n\n\n");



		printf("-------------------- Test for ft_read --------------------\n");
		printf("Native function :\n");
		char	buf[100];
		int fd_two = open("write.txt", O_RDONLY);
		if (fd_two == -1)
			return (1);
		int nb_read = -1;
		int count = 0;
		while (nb_read != 0)
		{
			nb_read = read(fd_two, buf, 100);
			if (nb_read == -1)
			{
				printf("Erreur de lecture !\n");
				return (1);
			}
			buf[nb_read] = '\0';
			printf("\e[36m%d : [\e[0m%s\e[36m]\e[0m\n", count, buf);
			count++;
		}
		printf("\n");

		printf("LIBASM function :\n");
		char	buf_two[100];
		int fd_three = open("write.txt", O_RDONLY);
		if (fd_three == -1)
			return (1);
		int nb_read_one = -1;
		int count_one = 0;
		while (nb_read_one != 0)
		{
			nb_read_one = ft_read(fd_three, buf_two, 100);
			if (nb_read_one == -1)
			{
				printf("Erreur de lecture !\n");
				return (1);
			}
			buf_two[nb_read_one] = '\0';
			printf("\e[36m%d : [\e[0m%s\e[36m]\e[0m\n", count_one, buf_two);
			count_one++;
		}
		printf("\n");
		printf("------------------------------------------------------------\n\n\n\n\n\n\n");
	}
	else
		printf("Please, enter three argument\n");
	return (0);
}
