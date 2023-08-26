#include "inc/ft_printf.h"
#include <stdio.h>

int main(void)
{
	char a = 'x';
	char *c = &a;
	ft_printf("%c + %s %p", 'a', "42tokyo", c);
}
