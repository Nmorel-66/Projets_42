/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:01:02 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/18 10:01:55 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printstr(char *str)
{
	int	len = 0;

	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
