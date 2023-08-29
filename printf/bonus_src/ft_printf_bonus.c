/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:29:31 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/25 07:14:35 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_bonus.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

t_format	ft_createforminfo(void)
{
	t_format	forminfo;

	forminfo.minus = 0;
	forminfo.space = 0;
	forminfo.sharp = 0;
	forminfo.spec = 0;
	forminfo.plus = 0;
	return (forminfo);
}

size_t	hub_print_nbr(t_format forminfo, va_list ap)
{
	size_t	print_nbr;

	if (forminfo.spec == 'c')
		print_nbr = gen_c(forminfo, ap);
	if (forminfo.spec == 's')
		print_nbr = gen_s(ap);
	if (forminfo.spec == 'd' || forminfo.spec == 'i' || forminfo.spec == 'u')
		print_nbr = gen_diu(forminfo, ap);
	if (forminfo.spec == 'p')
		print_nbr = gen_p(ap);
	if (forminfo.spec == 'x' || forminfo.spec == 'X')
		print_nbr = gen_xlx(forminfo, ap);
	if (forminfo.spec == '%')
	{
		print_nbr = 1;
		ft_putchar_fd('%', 1);
	}
	return (print_nbr);
}

size_t	ft_parser(char *format, va_list ap)
{
	t_format	forminfo;

	forminfo = ft_createforminfo();
	while (*format && !ft_strchr(SPECS, *format))
	{
		if (*format == '#')
			forminfo.sharp = 1;
		if (*format == '+')
			forminfo.plus = 1;
		if (*format == ' ')
			forminfo.space = 1;
		format++;
	}
	printf("%c",*format);
	if(!ft_strchr(SPECS, *format))
	{
		write(1,"-----Error-----\n",11);
		return 0;
	}
	forminfo.spec = *format;
	return (hub_print_nbr(forminfo, ap));
}

int	ft_printf(const char *format, ...)
{
	size_t	print_nbr;
	va_list	ap;

	print_nbr = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(++format))
				print_nbr += ft_parser((char *)format, ap);	
			while (*format && !ft_strchr(SPECS, *format))
				format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			print_nbr++;
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (print_nbr);
}
