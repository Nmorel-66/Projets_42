/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:52:15 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/13 10:03:02 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

