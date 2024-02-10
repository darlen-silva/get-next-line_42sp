/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardo-na <dardo-na@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:39:00 by dardo-na          #+#    #+#             */
/*   Updated: 2024/02/10 18:02:47 by dardo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*string_from_read(int fd, char *buff, char *str);

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	str[fd] = string_from_read(fd, buff, str[fd]);
	if (str[fd] == NULL)
		return (NULL);
	line = str[fd];
	str[fd] = NULL;
	return (line);
}

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

static char	*string_from_read(int fd, char *buff, char *str)
{
	size_t	n;
	int		c;
	ssize_t	bytes;

	n = 0;
	c = 0;
	bytes = 1;
	while (bytes > 0 && c != '\n')
	{
		n += read_line(fd, buff, &bytes, &c);
		if (n == 0)
			break ;
		str = join_strings(str, buff, n);
		if (str == NULL)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	buff = NULL;
	return (str);
}
