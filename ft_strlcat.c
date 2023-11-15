/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:00:24 by mvolkman          #+#    #+#             */
/*   Updated: 2023/11/06 14:24:16 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	d;
	size_t	s;
	size_t	i;
	size_t	available_space;

	d = 0;
	while (dest[d] != '\0' && d < n)
		d++;
	s = 0;
	while (src[s] != '\0')
		s++;
	if (d < n)
	{
		available_space = n - d - 1;
		i = 0;
		while (i < available_space && src[i] != '\0')
		{
			dest[d + i] = src[i];
			i++;
		}
		dest[d + i] = '\0';
	}
	return (d + s);
}
