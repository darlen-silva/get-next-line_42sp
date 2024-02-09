/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardo-na <dardo-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:01:59 by dardo-na          #+#    #+#             */
/*   Updated: 2024/02/09 17:30:28 by dardo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	size_t	read_line(int fd, char *buff, ssize_t *bytes, int *c)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && *c != '\n')
	{
		*bytes = read(fd, c, 1);
		if (*bytes <= 0)
			break ;
		buff[i++] = *c;
	}
	buff[i] = '\0';
	return (i);
}

static char	*string_from_read(int fd, char *str)
{
	char	*buff;
	size_t	n;
	int		c;
	ssize_t	bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (!buff)
		return (NULL);
	n = 0;
	bytes = 1;
	c = 0;
	while (bytes > 0 && c != '\n')
	{
		n += read_line(fd, buff, &bytes, &c);
		str = join_strings(str, buff, n);
		if (str == NULL)
		{
			free(buff);
			return (NULL);
		}
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
