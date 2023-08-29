#include "inc/ft_printf.h"
#include <stdio.h>

int main(void)
{
	char a = 'x';
	char *str = NULL;
	char *c = &a;
	ft_printf("%w %c + %p", a, c);
}
