/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:07:57 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/28 13:51:51 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_createline(char *readed_data)
{
	char	*line;
	char	*pos;
	int		len;
	int		i;

	pos = ft_strchr(readed_data, '\n');
	if (pos)
		len = pos - readed_data;
	else
		len = ft_strlen(readed_data);
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = readed_data[i];
		i++;
	}
	if (readed_data[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_buffer_save(char *readed_data)
{
	char	*temp;
	char	*pos;

	pos = ft_strchr(readed_data, '\n');
	if (!pos)
	{
		free(readed_data);
		return (NULL);
	}
	temp = ft_strdup(pos + 1);
	if (!temp)
		return (NULL);
	free(readed_data);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*readed_data = NULL;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	if (!readed_data)
		readed_data = ft_strdup("");
	if (!readed_data)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
		if (bytes_read == -1)
		{
			free(readed_data);
			readed_data = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(readed_data, buffer);
		if (!temp)
		{
			free(readed_data);
			return (NULL);
		}
		free(readed_data);
		readed_data = temp;
		if (ft_strchr(readed_data, '\n'))
		{
			line = ft_createline(readed_data);
			readed_data = ft_buffer_save(readed_data);
			return (line);
		}
	}
	if (readed_data != NULL && readed_data[0] != '\0')
	{
		line = ft_createline(readed_data);
		free(readed_data);
		readed_data = NULL;
		return (line);
	}
	free(readed_data);
	readed_data = NULL;
	return (NULL);
}
/*
int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        printf("Erreur lors de l'ouverture du fichier");
        return (EXIT_FAILURE);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (EXIT_SUCCESS);
}*/

