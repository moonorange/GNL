/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkida <kkida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 08:41:00 by kkida             #+#    #+#             */
/*   Updated: 2020/12/20 12:49:38 by kkida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char		*ft_strdup(const char *s1)
{
	int		idx;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char		*ft_strchr(const char *s, int c)
{
	int		idx;

	idx = 0;
	while (s[idx] != (char)c)
	{
		if (!s[idx])
			return (NULL);
		idx++;
	}
	return ((char *)&s[idx]);
}

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			idx;
	unsigned char	*usrc;
	unsigned char	*udest;

	if (dest == NULL && src == NULL)
		return (NULL);
	idx = 0;
	usrc = (unsigned char *)src;
	udest = (unsigned char *)dest;
	while (idx < n)
	{
		udest[idx] = usrc[idx];
		idx++;
	}
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sum_len;
	char	*str;
	size_t	s1_len;
	size_t	s2_i;

	if (!s1 || !s2)
		return (NULL);
	sum_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((sum_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	ft_memcpy(str, s1, s1_len);
	s2_i = 0;
	while (s2[s2_i])
	{
		str[s1_len] = s2[s2_i];
		s1_len++;
		s2_i++;
	}
	str[s1_len] = '\0';
	return (str);
}
