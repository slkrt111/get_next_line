/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:31:04 by slebik            #+#    #+#             */
/*   Updated: 2024/11/29 11:55:11 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_to_buffer(int fd, char *buffer)
{
	int	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes >= 0)
		buffer[bytes] = '\0';
	return (bytes);
}

char	*update_line(char *line, char *buffer)
{
	char	*new_line;

	new_line = ft_strjoin(line, buffer);
	if (new_line == NULL)
		free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	line = NULL;
	bytes = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (buffer[0] || bytes >= 0)
	{
		if (buffer[0] == '\0')
		{
			bytes = read_to_buffer(fd, buffer);
			if (bytes <= 0)
				break ;
		}
		line = update_line(line, buffer);
		if (!line)
			return (NULL);
		if (is_nl(buffer))
			break ;
	}
	return (line);
}

/*char	*get_next_line(int fd)
	{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes;
	char		*line;

	line = NULL;
	bytes = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (buffer[0] || bytes >= 0)
	{
		if (buffer[0] == '\0')
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes < 0)
			{
				free(line);
				return (NULL);
			}
			if (bytes == 0)
				break ;
			buffer[bytes] = '\0'; 
		}
		line = ft_strjoin(line, buffer);
		if (line == NULL)
		{
			free(line);
			return (NULL);
		}
		if (is_nl(buffer))
			break ;
	}
	return (line);
}*/
/*
int main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("ca bug zer");
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}*/
