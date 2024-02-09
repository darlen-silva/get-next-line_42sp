/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardo-na <dardo-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:02:45 by dardo-na          #+#    #+#             */
/*   Updated: 2024/02/08 22:48:20 by dardo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_strings(char *left_str, char *buff, size_t len)
{
	char	*new_str;
	char	*ptr;
	size_t	i;

	if (len < 1)
		return (left_str);
	new_str = (char *)malloc(sizeof(*new_str) * len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	ptr = left_str;
	while (ptr && *ptr)
		new_str[i++] = *ptr++;
	while (*buff)
		new_str[i++] = *buff++;
	new_str[i] = '\0';
	if (left_str != NULL)
		free(left_str);
	return (new_str);
}
