/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:59:36 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/07 17:26:00 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	i = 0;
	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return ((char *)s1);
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while (s1[i + j] != '\0' && s2[j] != '\0'
			&& s1[i + j] == s2[j] && i + j < len)
			j++;
		if (j == s2_len)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
/*int main(void)
{
   char *string1 = "Hello World";
   char *string2 = "World";
   char *result;
   int len;
 
   len = 25;
   result = ft_strnstr(string1,string2, len);
   if (result != NULL) {
        printf("La sous-chaîne a été trouvée : %s\n", result);
    } else {
        printf("La sous-chaîne n'a pas été trouvée dans les %d\n n premiers caractères.\n", len);
    }

    return (0);
}*/
