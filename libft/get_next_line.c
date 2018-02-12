/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:22:16 by gbryon            #+#    #+#             */
/*   Updated: 2018/01/16 14:03:00 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <fcntl.h>

int		look_at_the_line(char *buf, char **line)
{
	int				i;
	char			*new_line;
	char			*next_line;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		new_line = ft_strsub(buf, 0, i);
		next_line = ft_strjoin(*line, new_line);
		free(*line);
		if (new_line == NULL || next_line == NULL)
			return (-1);
		free(new_line);
		*line = next_line;
		ft_memcpy(buf, &(buf[i + 1]), BUFF_SIZE - i - 1);
		buf[BUFF_SIZE - i - 1] = '\0';
		return (1);
	}
	new_line = ft_strjoin(*line, buf);
	free(*line);
	*line = new_line;
	return (0);
}

int		look_at_tmp(char *buf, char **line)
{
	int				i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		free(*line);
		*line = ft_strsub(buf, 0, i);
		ft_memcpy(buf, &(buf[i + 1]), BUFF_SIZE - i - 1);
		buf[BUFF_SIZE - i - 1] = '\0';
		return (1);
	}
	ft_strcpy(*line, buf);
	buf[0] = '\0';
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				result;
	int				ret;
	static char		buf[F_MAX_FD][BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE < 1 || (read(fd, &result, 0) < 0))
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	ft_memset(*line, 0, BUFF_SIZE + 1);
	if (buf[fd][0] && (result = look_at_tmp(buf[fd], line)) == 1)
		return (result);
	while ((ret = read(fd, buf[fd], BUFF_SIZE)) > 0)
	{
		buf[fd][ret] = '\0';
		if ((ret = look_at_the_line(buf[fd], line)) == 1)
			return (ret);
	}
	if (*line[0] != '\0')
	{
		ft_memset(buf[fd], 0, 1);
		return (1);
	}
	return (0);
}
