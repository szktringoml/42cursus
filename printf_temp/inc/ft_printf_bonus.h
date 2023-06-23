/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 07:18:52 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/23 11:25:12 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdarg.h>

#define HEXUPPER "0123456789ABCDEF"
#define HEXLOWER "0123456789abcdef"
#define SPECS "cspdiuxX"

typedef struct s_format{
	int minus;
	int space;
	int sharp;
	char spec;
	int plus;
}	t_format;

int ft_printf(const char *format, ...);

size_t gen_c(t_format formInfo, va_list ap);

size_t gen_s( va_list ap);

size_t gen_diu(t_format formInfo, va_list ap);

//size_t gen_u(t_format formInfo, va_list ap);

size_t gen_p(va_list ap);

size_t gen_xX(t_format formInfo, va_list ap);

void recursive_hex_p(size_t p, size_t *print_nbr);

void recursive_hex_xX(long long nb, t_format formInfo, size_t *print_nbr);

size_t hub_print_nbr(t_format formInfo, va_list ap);

size_t ft_perser(char *format, va_list ap);

void ft_putchar_fd(char c, int fd);

char *ft_strchr(const char *s, int c);

size_t ft_strlen(const char *s);

char *ft_itoa(int n);

char *ft_utoa(unsigned int n);

char *ft_strdup(const char *str);

t_format ft_createFormInfo(void);

#endif
