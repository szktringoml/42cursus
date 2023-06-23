/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:14:39 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/23 11:23:37 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

size_t gen_c(t_format formInfo, va_list ap)
{
	char c;
	if(formInfo.spec == '%')
	{
		write(1, "%", 1);
		return 1;
	}
	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	return 1;
}

size_t gen_s(va_list ap)
{
	char *str;
	str = va_arg(ap, char*);
	ft_putstr_fd(str, 1);
	return ft_strlen(str);
}

size_t gen_diu(t_format formInfo, va_list ap)
{
	size_t print_nbr;
	int nb;
	char *str;
	print_nbr = 0;
	nb = va_arg(ap, int);
	
	if(nb > 0 && formInfo.plus)
		print_nbr =	write(1, "+", 1);
	else if(nb > 0 && formInfo.space)
		print_nbr =	write(1, " ", 1);
	if(formInfo.spec == 'u')
		str = ft_utoa((unsigned int)nb);
	else
		str = ft_itoa(nb);
    print_nbr += ft_strlen(str);
	ft_putstr_fd(str,1);
	free(str);
	return(print_nbr);
}
//size_t gen_u(t_format formInfo, va_list ap)
//{
//	size_t print_nbr;
//	int nb;
//	char *str;
//	print_nbr = 0;
//	nb = va_arg(ap, int);
//	printf("\n----------in get_u----------\n");
//	printf("va_arg(uint) %x\n",nb);
//	printf("int to uint %x\n",(unsigned int)nb);
//	if(formInfo.plus)
//		print_nbr =	write(1, "+", 1);
//	else if(formInfo.space)
//		print_nbr =	write(1, " ", 1);
//	str = ft_utoa((unsigned int)nb);
//	//printf("str = %s\n",str);
//    print_nbr += ft_strlen(str);
//	ft_putstr_fd(str,1);
//	free(str);
//	return(print_nbr);
//}

void recursive_hex_p(size_t p, size_t *print_nbr)
{
	size_t remain;
	char c;	
	if(p > 0)
	{
		remain = p % 16;
		c = HEXLOWER[remain];
		p /= 16;
		recursive_hex_p(p, print_nbr);
		write(1, &c, 1);
		*print_nbr = *print_nbr + 1;
	}
	
}

size_t gen_p(va_list ap)
{
	size_t print_nbr;
	size_t p;		
	
	p = va_arg(ap, size_t);
	print_nbr = write(1, "0x", 2);
	recursive_hex_p(p, &print_nbr);
	return print_nbr;
}

void recursive_hex_xX(long long nb, t_format formInfo, size_t *print_nbr)
{
	size_t remain;
	char c;
	if(nb > 0)
	{
		remain = nb % 16;
		if(formInfo.spec == 'X')
		   c = HEXUPPER[remain];
		else
			c = HEXLOWER[remain];		
		nb /= 16;
		recursive_hex_xX(nb, formInfo, print_nbr);
		write(1, &c, 1);
		*print_nbr = *print_nbr + 1;
	}
}

size_t gen_xX(t_format formInfo, va_list ap)
{
	size_t print_nbr;
	long long nb;
	nb = va_arg(ap, long long);
	print_nbr = 0;
	if(nb == 0)
  		return write(1, "0", 1);		
	if(formInfo.spec == 'X')
	{
		if(formInfo.sharp)
			print_nbr = write(1, "0X", 2);
		recursive_hex_xX(nb, formInfo, &print_nbr);
	}
	else
	{
		if(formInfo.sharp)
			print_nbr = write(1, "0x", 2);
		recursive_hex_xX(nb, formInfo, &print_nbr);
	}
	return print_nbr;
}
