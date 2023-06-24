/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardo-na <dardo-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:01:59 by dardo-na          #+#    #+#             */
/*   Updated: 2023/06/23 23:02:31 by dardo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*parse_string_from_read(int fd, char *str)
{
	char	*buff;
	int		n_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	n_bytes = 1;
	while (!ft_strchr(str, '\n') && n_bytes != 0)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n_bytes] = '\0';
		str = join_strings(str, buff, n_bytes);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			len;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = parse_string_from_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	len = 0;
	while (str[fd][len] && str[fd][len] != '\n')
		len++;
	line = parse_line(str[fd], len);
	str[fd] = new_string(str[fd], len);
	return (line);
}
