/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:57:15 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/18 17:08:18 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/include/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

//color
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

//client
void	chartobit(int c, int pid);
void	message_sent(char **argv, int server_pid);
void	is_arrive(int a);
void	push_client_pid(int server_pid);
int		pid_control(char *pid);

//server
void	zerone(int signal);
void	bitochar(int d);
int		get_client_pid(char *j, int d);

//utils
void	ft_put_digit(int digit);
void	ft_putnbr(int pid);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);

#endif