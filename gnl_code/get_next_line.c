/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkida <kkida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 08:41:03 by kkida             #+#    #+#             */
/*   Updated: 2021/01/14 21:52:15 by kkida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		free_all(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (-1);
}

int				get_last_line(char **rem_txt, char **line)
{
	if (ft_strchr(*rem_txt, '\0'))
	{
		*line = ft_strdup(*rem_txt);
		free(*rem_txt);
		*rem_txt = NULL;
	}
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
		new_rem = ft_strdup(tmp + 1);
		free(*rem_txt);
		*rem_txt = NULL;
		*rem_txt = new_rem;
		return (1);
	}
	else
		return (get_last_line(&*rem_txt, &*line));
}

ssize_t			read_fd(int fd, char *buffer, char **rem_txt)
{
	ssize_t		nbytes;
	char		*tmp;

	while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nbytes] = '\0';
		if (!rem_txt[fd])
			rem_txt[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(rem_txt[fd], buffer);
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

	buffer = (char *)malloc(sizeof(char) * (size_t)(BUFFER_SIZE) + 1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !buffer || FD_LIMIT < fd)
		return (ERROR);
	read_ret = read_fd(fd, buffer, rem_txt);
	free(buffer);
	buffer = NULL;
	if (read_ret < 0)
	{
		free_all(rem_txt);
		return (ERROR);
	}
	else if (!read_ret && !rem_txt[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (make_line(&rem_txt[fd], line));
}
