/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:11:47 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/23 10:18:27 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) Value * ((Value > 0) - (Value < 0))
#endif
/*
#include <stdio.h>
#include "ft_abs.h"

int	main(void)
{
	printf("%d\n", ABS(-18));
	return (0);
}*/
