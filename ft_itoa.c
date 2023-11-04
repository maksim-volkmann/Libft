/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:31:49 by mvolkman          #+#    #+#             */
/*   Updated: 2023/11/04 11:25:38 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(long n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		c++;
	}
	while (n >= 1)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static int	ft_power(long num)
{
	int	power;

	power = 1;
	while (num / power >= 10)
		power *= 10;
	return (power);
}

static void	ft_append_digit(char *str, int *i, long *num, int power)
{
	str[(*i)++] = *num / power + '0';
	*num %= power;
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	int		i;
	int		power;
	char	*str;

	num = n;
	len = ft_int_len(num);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[i++] = '-';
		num = -num;
	}
	power = ft_power(num);
	while (power > 0)
	{
		ft_append_digit (str, &i, &num, power);
		power /= 10;
	}
	str[i] = '\0';
	return (str);
}
