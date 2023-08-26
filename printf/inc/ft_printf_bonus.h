/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:46:09 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/07/07 06:41:47 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

# define HEXUPPER "0123456789ABCDEF"
# define HEXLOWER "0123456789abcdef"
# define SPECS "cspdiuxX%"

typedef struct s_format
{
	int		minus;
	int		space;
	int		sharp;
	char	spec;
	int		plus;
}			t_format;

int			ft_printf(const char *format, ...);

size_t		gen_c(t_format forminfo, va_list ap);

size_t		gen_s(va_list ap);

size_t		gen_diu(t_format forminfo, va_list ap);

size_t		gen_p(va_list ap);

size_t		gen_xlx(t_format forminfo, va_list ap);

void		recursive_hex_p(size_t p, size_t *print_nbr);

void		recursive_hex_xlx(unsigned int nb, t_format forminfo,
				size_t *print_nbr);

size_t		hub_print_nbr(t_format forminfo, va_list ap);

size_t		ft_perser(char *format, va_list ap);

void		ft_putchar_fd(char c, int fd);

char		*ft_strchr(const char *s, int c);

size_t		ft_strlen(const char *s);

char		*ft_itoa(int n);

char		*ft_utoa(unsigned int n);

char		*ft_strdup(const char *str);

t_format	ft_createFormInfo(void);

#endif
