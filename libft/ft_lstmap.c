/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:53:26 by oorlov            #+#    #+#             */
/*   Updated: 2018/11/05 20:53:28 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *alst;
	t_list *tmp;
	t_list *first;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	alst = ft_lstnew(tmp->content, tmp->content_size);
	if (!alst)
		return (NULL);
	first = alst;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		alst->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!alst->next)
			return (NULL);
		alst = alst->next;
		lst = lst->next;
	}
	return (first);
}
