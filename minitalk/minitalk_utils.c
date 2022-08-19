/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:57:04 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/18 16:57:27 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	ft_put_digit(int digit)
{
	digit = digit + 48;
	write(1, &digit, 1);
}

void	ft_putnbr(int pid)
{
	if (pid >= 10)
		ft_putnbr(pid / 10);
	ft_put_digit(pid % 10);
}

int	ft_atoi(const char *str)
{
	long	num;

	num = 0;
	while ((*str <= '9' && *str >= '0'))
	{
		num = (num * 10) + (*str - 48);
		str++;
	}
	return (num);
}

int	pid_control(char *pid)
{
	int	i;

	i = 0;
	if (!pid)
		return (1);
	while (pid[i])
	{
		if (!ft_strchr("0123456789", pid[i++]))
			return (1);
	}
	return (0);
}

/* 
int	main(void)
{
	const char a[]= "Mehmet";
	printf("%p", ft_strchr(a, 'h'));
}
*/
