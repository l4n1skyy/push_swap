/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <lanusri-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/08/30 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_add_mapped_node(t_list **new_list, void *content,
	void (*del)(void *))
{
	t_list	*new_node;

	new_node = ft_lstnew(content);
	if (!new_node)
	{
		del(content);
		ft_lstclear(new_list, del);
		return (0);
	}
	ft_lstadd_back(new_list, new_node);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*mapped_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		mapped_content = f(lst->content);
		if (!mapped_content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (!ft_add_mapped_node(&new_list, mapped_content, del))
			return (NULL);
		lst = lst->next;
	}
	return (new_list);
}
