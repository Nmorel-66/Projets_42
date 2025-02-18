/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:36:56 by nimorel           #+#    #+#             */
/*   Updated: 2024/09/25 10:03:18 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strstr(char *str, char *to_find, int i)
{
	int	j;

	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] != charset[j])
			i++;
		if (str[i] == charset[j] && (str[i] != '\0' || charset[j] != '\0'))
		{
			j++;
			if (j == ft_strlen(charset) - 1)
				word++;
		}
		i++;
	}
	return (word + 1);
}

char	*ft_words_dup(char *str, int start, int end)
{
	int		i;
	int		len;
	char	*w_str;

	i = 0;
	len = end - start;
	w_str = (char *)malloc(sizeof(char) * len + 1);
	if (w_str == NULL)
		return (NULL);
	while (i < len)
	{
		w_str[i++] = str[start++];
	}
	w_str[i] = '\0';
	return (w_str);
}

char	**ft_split(char *str, char *charset)
{
	int		start;
	char	**dest;
	int		i;
	int		end;
	int		cw;

	if (!(*str || *charset))
		return (NULL);
	cw = ft_count_words(str, charset);
	dest = (char **)malloc(sizeof(char *) * (cw + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (str[start] != '\0' && i <= cw)
	{
		end = ft_strstr(str, charset, start);
		dest[i] = ft_words_dup(str, start, end);
		start = end + ft_strlen(charset);
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/*
int	main(void)
{
	char	str[] = "Bleu; Blanc; Rouge";
	//char	*str = "";
	char	*charset = "; ";
	int i = 0;

	char **res = ft_split(str, charset);
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	i = 0;
	while (res[i++])
		free(res[i]);
	free(res);
	return (0);
}*/
