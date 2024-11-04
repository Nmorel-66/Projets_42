/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:04:56 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/04 16:32:39 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	strlcat( char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (dest[i] != '\0' && (i < size))
		i++;
	j = i;
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j]= '\0';
	return (j);
}
