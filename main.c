#include <stdio.h>

// Déclaration de la fonction assembleur
extern int ft_strlen(char *str);

int main() {
    char *str = "matthi";
	printf("La valeur de matthis est de %d\n", ft_strlen(str));
    return 0;
}
