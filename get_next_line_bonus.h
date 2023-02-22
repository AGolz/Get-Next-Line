/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:03:18 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/22 22:06:37 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char *str_1, char *str_2);
char	*ft_strchr(const char *str, int ch);

char	*get_next_line(int fd);

#endif