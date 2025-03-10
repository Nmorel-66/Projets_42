/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:07:57 by nimorel           #+#    #+#             */
/*   Updated: 2025/03/10 20:28:30 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (i <= len)
	{
		line[i] = readed_data[i];
		i++;
	}
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

static int	ft_read(int fd, char **readed_data, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*readed_data, buffer);
		if (!temp)
		{
			free(*readed_data);
			return (-1);
		}
		free(*readed_data);
		*readed_data = temp;
		if (ft_strchr(*readed_data, '\n'))
			break ;
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*readed_data = NULL;
	ssize_t		bytes_read;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!readed_data)
		readed_data = malloc(1);
	bytes_read = ft_read(fd, &readed_data, buffer);
	if (bytes_read == -1)
		return (free(readed_data), readed_data = NULL, NULL);
	if (ft_strchr(readed_data, '\n') || (bytes_read == 0 && *readed_data))
	{
		line = ft_createline(readed_data);
		readed_data = ft_buffer_save(readed_data);
		return (line);
	}
	return (free(readed_data), readed_data = NULL, NULL);
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
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (EXIT_SUCCESS);
}*/

/*static char *ft_createline(char *readed_data) {
    char *line;
    char *pos;
    int len;
    int i;

    pos = ft_strchr(readed_data, '\n');
    if (pos)
        len = pos - readed_data;
    else
        len = ft_strlen(readed_data);
    line = malloc(sizeof(char) * (len + 2));
    if (!line)
        return (NULL);
    i = 0;
    while (i <= len) {
        line[i] = readed_data[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

static char *ft_buffer_save(char *readed_data) {
    char *temp;
    char *pos;

    pos = ft_strchr(readed_data, '\n');
    if (!pos) {
        free(readed_data);
        return (NULL);
    }
    temp = malloc(strlen(pos + 1) + 1);
    if (!temp)
        return (NULL);
    memcpy(temp, pos + 1, strlen(pos + 1) + 1);
    free(readed_data);
    return (temp);
}

static int ft_read(int fd, char **readed_data, char *buffer) {
    ssize_t bytes_read;
    char *temp;

    bytes_read = 1;
    while (bytes_read > 0) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        temp = malloc(strlen(*readed_data) + bytes_read + 1);
        if (!temp) {
            free(*readed_data);
            return (-1);
        }
        memcpy(temp, *readed_data, strlen(*readed_data));
        memcpy(temp + strlen(*readed_data), buffer, bytes_read + 1);
        free(*readed_data);
        *readed_data = temp;
        if (ft_strchr(*readed_data, '\n'))
            break;
    }
    return (bytes_read);
}

char *get_next_line(int fd) {
    static char *readed_data = NULL;
    ssize_t bytes_read;
    char *line;
    char buffer[BUFFER_SIZE + 1];

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!readed_data) {
        readed_data = malloc(1);
        if (!readed_data)
            return (NULL);
        readed_data[0] = '\0';
    }
    bytes_read = ft_read(fd, &readed_data, buffer);
    if (bytes_read == -1)
        return (free(readed_data), readed_data = NULL, NULL);
    if (ft_strchr(readed_data, '\n') || (bytes_read == 0 && *readed_data)) {
        line = ft_createline(readed_data);
        readed_data = ft_buffer_save(readed_data);
        return (line);
    }
    return (free(readed_data), readed_data = NULL, NULL);
}*/
