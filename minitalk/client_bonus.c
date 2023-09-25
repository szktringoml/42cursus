/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:26:00 by string            #+#    #+#             */
/*   Updated: 2023/09/25 14:54:01 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

unsigned char	*g_str;

void	ft_handler_from_server(int sig, siginfo_t *info, void *context)
{
	size_t	len;
	pid_t	pid;

	pid = 0;
	(void)sig;
	(void)context;
	(void)info;
	len = ft_strlen(g_str);
	write(1, "\nCaught a signal from the server\n", 33);
	write(1, "---------input message---------\n", 32);
	write(1, g_str, len);
	exit(0);
}

void	ft_send_message(const unsigned char *str, pid_t pid)
{
	static int	shift = 7;
	static int	i = 8;

	while (*str)
	{
		if ((*str >> shift) % 2 == 1)
			siguser1_kill(pid);
		if ((*str >> shift) % 2 == 0)
			siguser2_kill(pid);
		shift--;
		if (shift == -1)
		{
			shift = 7;
			str++;
		}
		usleep(120);
	}
	sleep(1);
	while (i--)
		null_terminated_char_submit(pid);
}

//void create_blockset(struct sigaction *s_sigaction, sigset_t *blockset)
//{
//	if(sigemptyset(&s_sigaction->sa_mask) == -1)
//	{
//		write(1, "sigenptyset Error", 18);
//		exit(1);
//	}
//	if(sigemptyset(blockset) == -1)
//	{
//		write(1, "sigenptyset Error", 18);
//		exit(1);
//	}
//	if(sigaddset(blockset, SIGINT) == -1)
//	{
//		write(1, "sigaddset Error", 17);
//			exit(1);
//	}
//}

int	main(int argc, char *argv[])
{
	struct sigaction	s_sigaction;

	if (argc != 3)
	{
		write(STDERR, "input Error\n", 12);
		exit(1);
	}
	s_sigaction.sa_mask = sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = ft_handler_from_server;
	if (sigaction(SIGUSER1, &s_sigaction, NULL) == -1 || sigaction(SIGUSER2,
			&s_sigaction, NULL) == -1)
	{
		write(STDERR, "sigaction Error\n", 16);
		exit(1);
	}
	g_str = (unsigned char *)argv[2];
	ft_send_message((const unsigned char *)g_str, (pid_t)ft_atoi(argv[1]));
	while(1)
		pause();
	exit(0);
}
