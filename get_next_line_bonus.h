/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardo-na <dardo-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:54:42 by dardo-na          #+#    #+#             */
/*   Updated: 2022/07/16 23:55:01 by dardo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);

char	*ft_read_to_str(int fd, char *str);

char	*ft_strchr(char *s, int c);

size_t	ft_strlen(char *s);

char	*ft_strjoin(char *str, char *buff);

char	*ft_get_line(char *str);

char	*ft_new_str(char *str);

#endif
