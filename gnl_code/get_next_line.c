/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkida <kkida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 08:41:03 by kkida             #+#    #+#             */
/*   Updated: 2020/12/06 20:56:10 by kkida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		has_new_line(char **st_array)
{

}

int		get_next_line(int fd, char **line)
{
	char			*buffer;
	ssize_t			nbytes;
	static char		**st_array[FD_LIMIT];

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !buffer)
		return (ERROR);
	while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nbytes] = '\0';
		if (*st_array)
		{
			
		}
	}
}
