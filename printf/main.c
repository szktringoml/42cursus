#include "inc/ft_printf.h"
#include <stdio.h>

int main(void)
{
	char a = 'x';
	//char *str = NULL;
	char *c = &a;
	printf("========================\n");
	printf("%i\n", ft_printf(" %% "));
	printf("========================\n");
	printf("%i\n", printf(" %% "));
	printf("========================\n");
}
