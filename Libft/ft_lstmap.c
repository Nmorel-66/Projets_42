/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:08:19 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/14 09:13:28 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst || !f || !del)
		return ;
	new_lst	= ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst->next != NULL)
	{
		ft_lstadd_back(&new_lst, f(lst->content));
	}
	return (new_lst);
}
