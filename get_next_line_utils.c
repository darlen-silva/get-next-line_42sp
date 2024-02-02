/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardo-na <dardo-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:02:45 by dardo-na          #+#    #+#             */
/*   Updated: 2024/02/01 22:50:03 by dardo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*join_strings(char *left_str, char *buff, int n_bytes)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	len = ft_strlen(left_str) + n_bytes + 1;
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (left_str[++i])
		str[i] = left_str[i];
	while (*buff)
		str[i++] = *buff++;
	str[i] = '\0';
	free(left_str);
	return (str);
}

char	*parse_line(char *left_str, int len)
{
	int		i;
	char	*str;

	if (!left_str || !*left_str)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (*left_str && *left_str != '\n')
		str[i++] = *left_str++;
	if (*left_str == '\n')
		str[i++] = *left_str;
	str[i] = '\0';
	return (str);
}

char	*new_string(char *left_str, int len)
{
	int		j;
	char	*str;

	if (!*left_str)
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - len + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (left_str[len])
		str[j++] = left_str[++len];
	str[j] = '\0';
	free(left_str);
	return (str);
}
