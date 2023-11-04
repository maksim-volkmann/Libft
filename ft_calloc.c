/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:14:38 by mvolkman          #+#    #+#             */
/*   Updated: 2023/10/26 01:55:22 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t n)
{
	void	*memory;

	memory = (void *)malloc(count * n);
	if (!memory)
		return (NULL);
	ft_bzero(memory, count * n);
	return (memory);
}
