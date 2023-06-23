
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:45:06 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/19 08:18:10 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../inc/ft_printf.h"

t_format ft_createFormInfo()
{
	t_format formInfo;
	formInfo.minus = 0;
	formInfo.space = 0;
	formInfo.sharp = 0;
	formInfo.spec = 0;
	formInfo.plus = 0;
	return(formInfo);
}

size_t hub_print_nbr(t_format formInfo, va_list ap)
{
	size_t print_nbr;
	
	if(formInfo.spec == 'c' )
		print_nbr = gen_c(formInfo, ap);	
	if(formInfo.spec == 's')	
		print_nbr = gen_s(ap);
	if(formInfo.spec == 'd' ||  formInfo.spec == 'i' || formInfo.spec == 'u')
		print_nbr = gen_diu(formInfo, ap);
	if(formInfo.spec == 'p')
		print_nbr = gen_p(ap);
	if(formInfo.spec == 'x' || formInfo.spec == 'X')
		print_nbr = gen_xX(formInfo, ap);
	if(formInfo.spec == '%')
	{
		print_nbr = 1;
		ft_putchar_fd('%',1);
	}
	return print_nbr;
}

size_t ft_perser(char *format,va_list ap)
{
	t_format formInfo;
	formInfo = ft_createFormInfo();
	while(*format && !ft_strchr(SPECS, *format)) 
	{
		if(*format == '#')
			formInfo.sharp = 1;
		if(*format == '+')
			formInfo.plus= 1;
		if(*format == ' ')
			formInfo.space = 1;
		format++;
	}
	formInfo.spec = *format;
	return (hub_print_nbr( formInfo, ap));
}	

int ft_printf(const char *format, ...)
{
	size_t print_nbr;
	print_nbr = 0;
	va_list ap;
	va_start(ap, format);
	while(*format)
	{
		if(*format == '%')
		{
			if(*(++format))
			  	print_nbr += ft_perser((char *)format, ap);	
			while(*format && !ft_strchr(SPECS, *format))
				format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			print_nbr++;
		}
		if(*format)
			format++;
	}
	va_end(ap);
	return print_nbr;
}	

