/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardo-na <dardo-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:01:59 by dardo-na          #+#    #+#             */
/*   Updated: 2024/02/08 22:51:14 by dardo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*string_from_read(int fd, char *str)
{
	char	*buff;
	ssize_t	bytes;
	size_t	i;
	size_t	n;
	int		c;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (!buff)
		return (NULL);
	n = 0;
	bytes = 1;
	c = 0;
	while (bytes > 0 && c != '\n')
	{
		i = 0;
		while (i < BUFFER_SIZE && bytes > 0 && c != '\n')
		{
			bytes = read(fd, &c, 1);
			if (bytes <= 0)
				break ;
			buff[i++] = c;
			n++;
		}
		buff[i] = '\0';
		str = join_strings(str, buff, n + i);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = string_from_read(fd, str);
	if (str == NULL)
		return (NULL);
	line = str;
	str = NULL;
	return (line);
}
/*
int	main(void)
{
	char *buff;
	int fd = open("./big.text", O_RDONLY);

	while (1)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			break;
		printf("%s", buff);
		free(buff);
	}
	close(fd);
	return (0);
} */
