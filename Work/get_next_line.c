/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:07:57 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/28 17:03:26 by nimorel          ###   ########.fr       */
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

static char	*ft_read_line(int fd, char *buf, char *readed_data)
{
	ssize_t	bytes_read;
	char	*newline;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, sizeof(buf) - 1);
		if (bytes_read == -1)
			return (free(readed_data), readed_data = NULL, NULL);
		buf[bytes_read] = '\0';
		temp = ft_strjoin(readed_data, buf);
		//printf("join %s\n", temp);
		free(readed_data);
		readed_data = temp;
		if (ft_strchr(readed_data, '\n'))
		{
			newline = ft_createline(readed_data);
			readed_data = ft_buffer_save(readed_data);
			return (newline);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*readed_data = NULL;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, buf, readed_data);
	free(buf);
	free(readed_data);
	return (line);
}

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
}
