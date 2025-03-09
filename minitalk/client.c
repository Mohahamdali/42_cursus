/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:46:20 by mhamdali          #+#    #+#             */
/*   Updated: 2025/03/09 12:54:27 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Error invalid PID\n", 2);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Error invalid PID\n", 2);
				exit(1);
			}
		}
		i--;
		usleep(500);
	}
}

void	send_message(int pid, char *msg)
{
	while (*msg)
	{
		send_bits(pid, *msg);
		msg++;
	}
	send_bits(pid, '\0');
}

void	check_av(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
		{
			ft_putstr_fd("Error\nnumber not valid\n", 2);
			exit(1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;

	if (ac != 3)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	check_av(av[1]);
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid > 99998)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	msg = av[2];
	send_message(pid, msg);
	return (0);
}
