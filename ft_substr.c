/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:53:15 by mvolkman          #+#    #+#             */
/*   Updated: 2023/11/01 11:26:56 by mvolkman         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	size_t	strlen;
	size_t	sublen;
	char	*substr;
	size_t	i;

	strlen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= strlen)
		return (ft_strdup(""));
	sublen = n;
	if (sublen > (strlen - start))
		sublen = strlen - start;
	substr = (char *)malloc(sublen + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < sublen)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
