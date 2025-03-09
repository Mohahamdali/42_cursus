/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:48:21 by mhamdali          #+#    #+#             */
/*   Updated: 2025/03/09 13:27:45 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <libc.h>
void	accept_signal(int sig, siginfo_t *info, void *context)
{
	static char		c = 0;
	static int		i = 0;
	static pid_t	pid = 0;

	(void)context;
	if (pid != info->si_pid)
	{
		c = 0;
		i = 0;
		pid = info->si_pid;
	}
	if (sig == SIGUSR2)
		c |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		c = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction		sa;
	pid_t					pid;

	(void)av;
	if (ac != 1)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sa.sa_sigaction = accept_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
