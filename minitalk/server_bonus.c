/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:55:37 by string            #+#    #+#             */
/*   Updated: 2023/09/25 14:54:09 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	null_terminated_char_notice(pid_t pid)
{
	if (kill(pid, SIGUSER1) == -1)
	{
		write(STDERR, "kill Error\n", 13);
		exit(1);
	}
}

void	ft_handler_from_client(int sig, siginfo_t *info, void *context)
{
	static int		shift = 0;
	static int		c = 0;
	static pid_t	pid = 0;

	if(info->si_pid != 0)
		pid = info->si_pid;
	(void)context;
	c *= 2;
	if (sig == SIGUSER1)
		c += 1;
	if (sig == SIGUSER2)
		c += 0;
	shift++;
	if (shift == 8)
	{
		if (c == 0)
			null_terminated_char_notice(pid);
		write(1, &c, 1);
		shift = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sigaction;

	s_sigaction.sa_mask = sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = ft_handler_from_client;
	pid = getpid();
	printf("server pid = %i\n", pid);
	if (sigaction(SIGUSER1, &s_sigaction, NULL) == -1 || sigaction(SIGUSER2,
			&s_sigaction, NULL))
	{
		write(STDERR, "sigaction Error\n", 16);
		exit(1);
	}
	while (1)
		pause();
	exit(0);
}
