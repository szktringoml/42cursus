// #include "inc/ft_printf_bonus.h"
// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	a;
// 	char	*c;

// 	a = 'x';
// 	// char *str = NULL;
// 	c = &a;
// 	printf("========================\n");
// 	printf("\n return (%i\n", ft_printf(" %% ")));
// 	printf("\n return (%i\n", printf(" %% ")));
// 	printf("========================\n");
// 	printf("\n return (%i\n", ft_printf(" %d %d %d %d %d %d %d", INT_MAX,
// 			INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)));
// 	printf("\n return (%i\n", printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN,
// 			LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)));
// 	printf("========================\n");
// 	printf("\n return (%i\n", ft_printf(" %c %c %c ", '0', 0, '1')));
// 	printf("\n return (%i\n", printf(" %c %c %c ", '0', 0, '1')));
// 	printf("========================\n");
// 	printf("\n return (%i\n", ft_printf(" %c %c %c ", '1', '2', '3')));
// 	printf("\n return (%i\n", printf(" %c %c %c ", '1', '2', '3')));
// 	printf("========================\n");
// 	printf("\n return (%i\n", ft_printf(" %c %c %c ", '2', '1', 0)));
// 	printf("\n return (%i\n", printf(" %c %c %c ", '2', '1', 0)));
// 	printf("========================\n");
// 	printf("\n return (%i\n", ft_printf(" %+d ", 100)));
// 	printf("\n return (%i\n", printf(" %+d ", 100)));
// 	printf("========================\n");
// 	printf("\n return (%i\n", ft_printf(" %w %s ", 100)));
// 	// printf("\n return (%i\n", printf(" %+d ", 100)));
// 	printf("\n このケースは本家だとError(CFLAGなしだとwarning)\n");
// 	printf("========================\n");
// 	printf("\n return (%i\n", ft_printf(" %i  %w %s ", 42, "42tokyo")));
// 	// printf("\n return (%i\n", printf(" %i %w %s ", 42, "42Tokyo")));
// 	printf("\n このケースは本家だとError(CFLAGなしだとwarning)\n");
// 	printf("========================\n");
// 	printf("\n return (%i\n", ft_printf(" %##x ", c)));
// 	printf("\n return (%i\n", printf(" %##x ", c)));
// 	printf("========================\n");
// 	printf("\n return (%i\n", ft_printf(" % 1s ", "")));
// 	printf("\n return (%i\n", printf("% 1s ", "")));
// }
