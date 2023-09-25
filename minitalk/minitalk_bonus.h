/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:25:54 by string            #+#    #+#             */
/*   Updated: 2023/09/25 14:08:58 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const unsigned char *s);

int		ft_atoi(const char *str);

void	siguser1_kill(pid_t pid);

void	siguser2_kill(pid_t pid);

void	null_terminated_char_submit(pid_t pid);

void	null_terminated_char_notice(pid_t pid);

void	ft_send_message(const unsigned char *str, pid_t pid);

void	ft_handler_from_server(int sig, siginfo_t *info, void *context);

void	ft_handler_from_client(int sig, siginfo_t *info, void *context);

# define SIGUSER1 10
# define SIGUSER2 12
# define STDERR 2
#endif