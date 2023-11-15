/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:02:59 by mvolkman          #+#    #+#             */
/*   Updated: 2023/11/06 12:51:31 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*add_node(t_list *new_list, t_list *new_node)
{
	t_list	*last_node;

	if (!new_list)
		new_list = new_node;
	else
	{
		last_node = new_list;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	return (new_list);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	if (!(lst) || !(f) || !(del))
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_list = add_node(new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
