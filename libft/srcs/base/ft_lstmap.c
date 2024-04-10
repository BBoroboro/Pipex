/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:41:23 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/15 16:36:07 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_nlst(t_list *temp, t_list *lst, void *(*f)(void *), \
		void (*del)(void *))
{
	t_list	*add;

	add = ft_lstnew(f(lst->content));
	if (!add)
	{
		ft_lstclear(&temp, del);
		return (NULL);
	}
	ft_lstadd_back(&temp, add);
	return (temp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		ft_nlst(temp, lst, f, del);
		lst = lst->next;
	}
	return (temp);
}
