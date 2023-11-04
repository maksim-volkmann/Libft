/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:45:46 by mvolkman          #+#    #+#             */
/*   Updated: 2023/11/03 00:35:27 by mvolkman         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	if ((!set) || (!s1))
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	str = (char *)malloc(end - start + 1 + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
