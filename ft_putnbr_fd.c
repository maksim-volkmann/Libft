/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:42:34 by mvolkman          #+#    #+#             */
/*   Updated: 2023/10/26 01:34:19 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(long num)
{
	int	power;

	power = 1;
	while (num / power >= 10)
		power *= 10;
	return (power);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		power;
	long	temp;

	num = n;
	if (num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	power = ft_power(num);
	while (power > 0)
	{
		temp = (num / power) + '0';
		write(fd, &temp, 1);
		num = num % power;
		power = power / 10;
	}
}
