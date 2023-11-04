/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:43:10 by mvolkman          #+#    #+#             */
/*   Updated: 2023/10/26 01:57:09 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	l;

	l = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack && n >= l)
	{
		if (ft_strncmp(haystack, needle, l) == 0)
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}
