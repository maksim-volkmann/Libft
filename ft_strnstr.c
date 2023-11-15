/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:43:10 by mvolkman          #+#    #+#             */
/*   Updated: 2023/11/06 15:56:32 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && n >= l)
	{
		if (ft_strncmp(&haystack[i], needle, l) == 0)
			return ((char *)&haystack[i]);
		i++;
		n--;
	}
	return (NULL);
}
