/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:23:58 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/13 15:34:07 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
    
	if (!lst || !del)
		return;
	tmp = *lst;
	while (*lst != NULL)
	{
	tmp = (*lst)->next;
	ft_lstdelone(*lst, del);
	*lst = tmp;   
	} 
}