#include "inc/ft_printf.h"
#include <stdio.h>

int main(void)
{
	char a = 'x';
	//char *str = NULL;
	char *c = &a;
	ft_printf("%s %w %c %c %p %e\n", "strstr", 'c', a, c);
	//printf("%s %w %c %c %p %ei\n", "strstr", 'c', a, c);
}
