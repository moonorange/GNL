/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkida <kkida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 08:41:03 by kkida             #+#    #+#             */
/*   Updated: 2020/12/06 22:57:30 by kkida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int		get_next_line(int fd, char **line)
{
	char			*buffer;
	ssize_t			nbytes;
	static char		*rem_txt[FD_LIMIT];
	char			*tmp;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !buffer)
		return (ERROR);
	while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nbytes] = '\0';
		if (rem_txt[fd] == NULL)
			rem_txt[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(rem_txt[fd], buffer);
		}

	}
}
