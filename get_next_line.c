/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmaksim <elmaksim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:23:27 by elmaksim          #+#    #+#             */
/*   Updated: 2024/01/24 13:40:37 by elmaksim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_reserve(char *reserve)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(reserve) - i + 1));
	if (!str)
		return (NULL);
	i++;
	c = 0;
	while (reserve[i])
		str[c++] = reserve[i++];
	str[c] = '\0';
	free(reserve);
	return (str);
}

static char	*ft_get_line(char *reserve)
{
	int		i;
	char	*str;

	i = 0;
	if (!reserve[i])
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
		str[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
	{
		str[i] = reserve[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_rd_reserv(int fd, char *reserve)
{
	ssize_t		rd_byte;
	char		*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rd_byte = 1;
	while (!ft_strchr(reserve, '\n') && rd_byte != 0)
	{
		rd_byte = read(fd, buf, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_byte] = '\0';
		reserve = ft_strjoin(reserve, buf);
	}
	free(buf);
	return (reserve);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reserve;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reserve = ft_rd_reserv(fd, reserve);
	if (!reserve)
		return (NULL);
	line = ft_get_line(reserve);
	reserve = ft_reserve(reserve);
	return (line);
}
