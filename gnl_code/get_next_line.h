/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkida <kkida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 08:41:05 by kkida             #+#    #+#             */
/*   Updated: 2020/12/06 20:13:14 by kkida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32
# define ERROR -1
# define FD_LIMIT 1092

# include <unistd.h>
# include <stdlib.h>

#define SAFE_FREE(ptr)	if(ptr != NULL ){ free(ptr); ptr = NULL; }

int		get_next_line(int fd, char **line);

#endif
