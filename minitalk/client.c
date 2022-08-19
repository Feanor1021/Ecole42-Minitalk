/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:56:57 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/18 17:12:00 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	chartobit(int c, int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		c = c >> 1;
		i++;
	}
}

void	message_sent(char **argv, int server_pid)
{
	char	*str;

	str = argv[2];
	while (*str)
	{
		chartobit(*str, server_pid);
		str++;
	}
	if (*argv[2])
		chartobit('\n', server_pid);
	chartobit('\0', server_pid);
}

void	is_arrive(int a)
{
	(void)a;
	write(1, "\e[32mMessage Sent\n\e[0m",
		ft_strlen("\e[32mmessage sent\e[0m\n"));
}

void	push_client_pid(int server_pid)
{
	int	pid;
	int	i;

	i = 0;
	pid = getpid();
	while (i < 32)
	{
		if (pid & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		pid = pid >> 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	signal(SIGUSR2, is_arrive);
	if (argc == 3)
	{
		if (pid_control(argv[1]))
		{
			ft_printf("\e[31mWrong pid format!!\n\e[0m");
			return (1);
		}
		server_pid = ft_atoi(argv[1]);
		push_client_pid(server_pid);
		message_sent(argv, server_pid);
	}
	else
		ft_printf("\e[31mUsage is : <./client> <pid> <message>\e[0m");
	return (0);
}
