/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardo-na <dardo-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:53:58 by dardo-na          #+#    #+#             */
/*   Updated: 2022/07/23 04:03:45 by dardo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_str(int fd, char *one_str)
{
	char	*buff;
	int		n_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	n_bytes = 1;
	while (!ft_strchr(one_str, '\n') && n_bytes != 0)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n_bytes] = '\0';
		one_str = ft_strjoin(one_str, buff);
	}
	free(buff);
	return (one_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*one_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	one_str[fd] = ft_read_str(fd, one_str[fd]);
	if (!one_str[fd])
		return (NULL);
	line = ft_get_line(one_str[fd]);
	one_str[fd] = ft_new_str(one_str[fd]);
	return (line);
}
