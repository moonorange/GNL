/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkida <kkida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 08:41:03 by kkida             #+#    #+#             */
/*   Updated: 2020/12/10 20:39:48 by kkida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_all(char **str)
{
	if (*str)
		SAFE_FREE(*str);
	return (-1);
}

static int	join_line(char **rem_txt, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*rem_txt)[len] != '\n' && (*rem_txt)[len] != '\0')
		len++;
	if ((*rem_txt)[len] == '\n')
	{
		*line = ft_substr(*rem_txt, 0, len);
		tmp = ft_strdup(&((*rem_txt)[len + 1]));
		SAFE_FREE(*rem_txt);
		*rem_txt = tmp;
		if ((*rem_txt)[0] == '\0')
			free_all(rem_txt);
	}
	else
	{
		*line = ft_strdup(*rem_txt);
		free_all(rem_txt);
	}
	return (OK);
}

ssize_t		read_fd(int fd, char *buffer, char **rem_txt)
{
	ssize_t		nbytes;
	char		*tmp;

	while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nbytes] = '\0';
		if (rem_txt[fd] == NULL)
			rem_txt[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(rem_txt[fd], buffer);
			SAFE_FREE(rem_txt[fd]);
			rem_txt[fd] = tmp;
		}
		if (ft_strchr(rem_txt[fd], '\n'))
			break ;
	}
	return (nbytes);
}

int			get_next_line(int fd, char **line)
{
	char			*buffer;
	ssize_t			read_ret;
	static char		*rem_txt[FD_LIMIT];

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !buffer)
		return (ERROR);
	read_ret = read_fd(fd, buffer, rem_txt);
	if (read_ret < 0)
		return (ERROR);
	else if (read_ret == 0 && rem_txt[fd] == NULL)
		return (EOF);
	else return (join_line(&rem_txt[fd], line));
}
