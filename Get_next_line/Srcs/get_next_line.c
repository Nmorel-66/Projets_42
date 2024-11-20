/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:07:57 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/20 14:19:29 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void 		*buffer;
	static char	*line;
	size_t		cursor;
    
	cursor = 1;
	buffer = malloc(sizeof(char)* BUFFER_SIZE + 1 );
	if(!buffer)
		return (NULL);
	while (!ft_strchr(buffer,'\n') && cursor > 0)
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		if (cursor == -1)
		{
			return (NULL);
			free(buffer);
		}
		line = ft_strjoin(line, buffer);
		if (!line)
		{
			return (NULL);
			free(buffer);
		}
	}
	line = ft_strjoin(line, ft_strrtrim(buffer, '\n'));
	if (!line)
		{
			return (NULL);
			free(buffer);
		}
	free (buffer);
	return (line);
}
