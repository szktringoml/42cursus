/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:45:06 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/14 12:59:53 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <libft.h>
//size_t	ft_strlen(const char *s)
//{
//	size_t	i;
//
//	i = 0;
//	while (s[i] != '\0')
//		i++;
//	return (i);
//}

//void decToHexdecAndWrite(long long num, char case)
//{
//	unsigned int quo;
//   	unsigned int rem;
//	quo = num / 16;	
//	while(quo)
//	{
//		rem = quo % 16;
//		if(10 <= rem && rem >= 16)
//			write(1, (rem - 10)+'a', 1);
//		else
//			write(1, rem + '0', 1);
//		quo /= 16;		
//	}
//
//}
//size_t ft_isxdigit(num)
//{
//	char *str;
//	str = imp_itoa(num);
//	if(str[0] == '0')
//	{
//		if(str[1] == 'x' || str[1] == 'X')
//			return 16;
//		else
//			return 8;
//	}
//	else
//		return 10;
//}

//void octOrHexdecToDecAndWrite(long long num)
//{
//	long long ans;
//	size_t weight;
//	size_t x;
//	size_t dx;
//	unsigned int calcweight;
//	x = 0;
//	weight = ft_isdigit(num);
//	calcweight = 1;
//	ans = 0;
//	while(num != 0)
//	{
//		dx = x;
//		while(dx--)
//			calcweight = calcweight * weight;
//		ans +=  (num % 10) * calcweight;
//		num /= 10;
//		calcweight = 0;
//		x++;
//	}
//	ft_putstr_fd(imp_itoa(ans));
//}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void ft_putcharAndWidth(size_t **char_cnt, char c, const char *format, int **i)
{
	size_t width;
	width = 0;
	printf("3--------出力フォーマットを適用する---------------3\n");
		**i = **i + 1;
	printf("*i = %dのときformatは%c\n", **i, format[**i]);
	while(format[**i] && format[**i] != '%')
	{
		if(format[**i] == 'c')
		{
			printf("putchar→%c\n",c);
			ft_putchar_fd(c, 1);
			**char_cnt = **char_cnt + 1;
		}
		**i = **i + 1;
	}
	printf("%dの時formatが%cなのでここで終了\n", **i, format[**i]);
}

void ft_branchBySpec(size_t *char_cnt, const char *format, int *i, va_list args)
{
	int curr;
	curr = 1;
	while(format[(int)(*i + curr)] != '\0' && format[(int)(*i + curr)] != '%')
	{	
		printf("2--------sectionから指定子を見つけて分岐する---------------2\n");
		if(format[(int)(*i + curr)] == 'c')
		{
			printf("branch の関数内でのi+curr = %dにてcを見つけた！！！！！！\n", *i + curr);
			ft_putcharAndWidth(&char_cnt, va_arg(args, int), &format[*i], &i);
		}
		//	if(c  == 's')
	//		func();
	//	if(c  == 'p')
	//		func();
	//	if(c  == 'd')
	//		func();
	//	if(c  == 'i')
	//		func();
	//	if(c  == 'u')
	//		func();
	//	if(c  == 'x'):
	//		func();
	//	if(c  == 'X')
	//		func();
	//	if(c  == '%')
	//		func();
		curr++;
	}
	*i = *i - 1;
}

int ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int i=0;
	size_t char_cnt;
	char_cnt = 0;
	while(format[i])
	{
		printf("1--------pa-senntoを見つける---------------1\n");
		if(format[i] == '%')
		{	
			printf("%dにpa-senntoがあるので指定子を特定しに行きます\n", i);
			ft_branchBySpec(&char_cnt, format, &i, args);
		}
		
		//	if(*format == 'p')
	//	{
	//		long long num = hexadecToDec()	
	//		decToHexadecAndWrite(num);
	//	}
		//if(*format == 'd' || *format == 'i' || *format == 'u')
		//	octOrHexdecToDecAndWrite(va_arg(args, int));
		//if(*format == 'x' || *format == 'X')
		//	decToHexdecAndWrite(va_arg(args, long long), *format)
		//if(*format == '%')
		//{
		//}
		
		i++;
	}
	va_end(args);

	return char_cnt;
}	
#include <stdio.h>

int main()
{
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');

	return 0;
}
