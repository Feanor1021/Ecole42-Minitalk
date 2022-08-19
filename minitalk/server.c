/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:11:37 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/18 17:14:19 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	start_screen(void)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
		%s\n",
		RED, END);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
		%s \n", RED,
		END);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
		%s \n", RED,
		END);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
		%s\n", RED,
		END);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
		%s\n", RED,
		END);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: fyardimc%s\n", RED, getpid(), END,
		YELLOW,
		END);
	ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
		\n\n");
}

int	get_client_pid(char *j, int d)
{
	static unsigned int	pid_client;
	static unsigned int	client_pid;

	if (*j <= 31)
	{
		pid_client += d << *j;
		if (*j == 31)
		{
			client_pid = pid_client;
			pid_client = 0;
			(*j)++;
			return (client_pid);
		}
		(*j)++;
	}
	return (0);
}

void	bitochar(int d)
{
	static char			j;
	static unsigned int	writ;
	static int			i;
	static int			client_pid;

	if (j <= 31)
	{
		client_pid = get_client_pid(&j, d);
		return ;
	}
	writ += d << i;
	if (i == 7)
	{
		i = 0;
		if ((char)writ != '\0')
			ft_printf("%c", writ);
		else
		{
			j = 0;
			kill(client_pid, SIGUSR2);
		}
		writ = 0;
	}
	else
		i++;
}

void	zerone(int signal)
{
	if (signal == SIGUSR1)
		bitochar(1);
	else if (signal == SIGUSR2)
		bitochar(0);
}

int	main(void)
{
	start_screen();
	signal(SIGUSR1, zerone);
	signal(SIGUSR2, zerone);
	while (1)
		pause();
	return (0);
}
