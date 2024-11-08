/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:33:13 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/08 18:47:47 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *str, char c)
{
	size_t	i;
	size_t	cw;

	i = 0;
	cw = 0;
	while (str[i]!='\0')
	{
		if (str[i] == c)
			cw++;
		i++;	
	}
	return (cw++);
}
char	*ft_addword(const char *str, int start, int end)
{
    int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (end - start + 2));
	if (word == NULL)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}


char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	k;
	char	**dest;

	dest = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	k = 0; 
	while (s[i] != '\0')
	{
		 while (s[i] == c)
            i++;
        len = 0;
        while (s[i + len] != '\0' && s[i + len] != c)
            len++;
        dest[k++] = ft_addword(s, i, i + len);
        i = i + len;
    }
    dest[k] = 0;
    return (dest);
}
int	main(void)
{
	char	str[] = "Bleu;blanc;rouge";
	char	c = ';';
	int i = 0;
	
	char **res = ft_split(str, c);
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}