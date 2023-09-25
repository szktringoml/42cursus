/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:25:41 by string            #+#    #+#             */
/*   Updated: 2023/09/25 14:03:06 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler_from_client(int sig, siginfo_t *info, void *context)
{
	static int		shift = 0;
	static int		c = 0;
	static pid_t	pid = 0;

	(void)info;
	(void)pid;
	(void)context;
	c *= 2;
	if (sig == SIGUSER1)
		c += 1;
	if (sig == SIGUSER2)
		c += 0;
	shift++;
	if (shift == 8)
	{
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
