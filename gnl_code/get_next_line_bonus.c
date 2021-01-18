/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkida <kkida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 08:41:03 by kkida             #+#    #+#             */
/*   Updated: 2021/01/18 22:49:16 by kkida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	int		free_remtxt(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (ERROR);
}

static int		get_last_line(char **rem_txt, char **line)
{
	*line = ft_strdup(*rem_txt);
	if (!*line)
		return (ERROR);
	free(*rem_txt);
	*rem_txt = NULL;
	return (0);
}

static int		make_line(char **rem_txt, char **line)
{
	char	*tmp;
	char	*new_rem;

	if ((tmp = ft_strchr(*rem_txt, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*rem_txt);
		if (!*line)
			return (ERROR);
		new_rem = ft_strdup(tmp + 1);
		if (!new_rem)
			return (ERROR);
		free(*rem_txt);
		*rem_txt = NULL;
		*rem_txt = new_rem;
		return (1);
	}
	else
		return (get_last_line(&*rem_txt, &*line));
}

static ssize_t	read_fd(int fd, char *buffer, char **rem_txt)
{
	ssize_t		nbytes;
	char		*tmp;

	while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nbytes] = '\0';
		if (!rem_txt[fd])
		{
			rem_txt[fd] = ft_strdup(buffer);
			if (!rem_txt[fd])
				return (ERROR);
		}
		else
		{
			tmp = ft_strjoin(rem_txt[fd], buffer);
			if (!tmp)
				return (ERROR);
			free(rem_txt[fd]);
			rem_txt[fd] = NULL;
			rem_txt[fd] = tmp;
		}
		if (ft_strchr(rem_txt[fd], '\n'))
			break ;
	}
	return (nbytes);
}

int				get_next_line(int fd, char **line)
{
	char			*buffer;
	ssize_t			read_ret;
	static char		*rem_txt[FD_LIMIT];

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || FD_LIMIT < fd)
		return (ERROR);
	buffer = (char *)malloc(sizeof(char) * (size_t)(BUFFER_SIZE) + 1);
	if (!buffer)
		return (ERROR);
	read_ret = read_fd(fd, buffer, rem_txt);
	free(buffer);
	buffer = NULL;
	if (read_ret < 0)
		return (free_remtxt(rem_txt));
	else if (!read_ret && !rem_txt[fd])
	{
		*line = ft_strdup("");
		if (!*line)
			return (ERROR);
		return (0);
	}
	else
		return (make_line(&rem_txt[fd], line));
}
