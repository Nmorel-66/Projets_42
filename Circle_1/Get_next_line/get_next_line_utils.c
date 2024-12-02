/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:13:40 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/30 11:09:30 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	len = ft_strlen(s);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((unsigned char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_strdup("");
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (len1 + len2 + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
