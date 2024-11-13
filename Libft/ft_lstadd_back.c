/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:52:15 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/13 17:34:19 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{	
	if (!lst || !new)
		return (0);
	if (*lst == NULL)
	{
		*lst = new;
		return (0);
	}
	while ((*lst)->next != NULL)
		(*lst) = (*lst)->next;
	(*lst)->next = new;
}
