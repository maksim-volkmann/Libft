/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:01:41 by mvolkman          #+#    #+#             */
/*   Updated: 2023/11/05 20:44:38 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;
	t_list	*last;

	current = *lst;
	last = NULL;
	while (current)
	{
		last = current;
		current = current->next;
	}
	if (last)
		last->next = new;
	else
		*lst = new;
}
