/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:59:44 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/22 19:02:29 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ch == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) ch)
			return ((char *)&str[i]);
		i++;
	}	
	return (NULL);
}

char	*ft_strjoin(char *str_1, char *str_2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!str_1)
	{
		str_1 = (char *)malloc(1 * sizeof(char));
		str_1[0] = '\0';
	}
	if (!str_1 || !str_2)
		return (NULL);
	str = malloc((ft_strlen(str_1) + ft_strlen(str_2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (str_1)
		while (str_1[++i] != '\0')
			str[i] = str_1[i];
	while (str_2[c] != '\0')
		str[i++] = str_2[c++];
	str[ft_strlen(str_1) + ft_strlen(str_2)] = '\0';
	free(str_1);
	return (str);
}
