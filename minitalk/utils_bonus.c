/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:25:46 by string            #+#    #+#             */
/*   Updated: 2023/09/25 14:11:23 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	ft_strlen(const unsigned char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int	nb;
	size_t		i;
	int			minus_flag;

	i = 0;
	nb = 0;
	minus_flag = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		(nb = (nb * 10) + str[i] - 48);
		i++;
	}
	return (nb * minus_flag);
}

void	siguser1_kill(pid_t pid)
{
	if (kill(pid, SIGUSER1) == -1)
	{
		write(STDERR, "kill Error\n", 13);
		exit(1);
	}
}

void	siguser2_kill(pid_t pid)
{
	if (kill(pid, SIGUSER2) == -1)
	{
		write(STDERR, "kill Error\n", 13);
		exit(1);
	}
}

void	null_terminated_char_submit(pid_t pid)
{
	if (kill(pid, SIGUSER2) == -1)
	{
		write(STDERR, "kill Error\n", 13);
		exit(1);
	}
	usleep(10);
}
