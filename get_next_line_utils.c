/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:04:28 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/29 18:11:07 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	e;
	unsigned char	*d;
	unsigned char	*s;

	if (dst == 0 && src == 0)
		return (0);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	e = 0;
	while (n > e)
	{
		d[e] = s[e];
		e++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*d;
	unsigned int	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	d = malloc(sizeof(char) * (size));
	if (!d)
		return (0);
	ft_memcpy(d, (const void *) s1, ft_strlen((char *) s1));
	ft_memcpy(&d[ft_strlen((char *) s1)], s2, ft_strlen((char *) s2));
	ft_memcpy(&d[ft_strlen((char *) s1)], s2, ft_strlen((char *) s2));
	d[size - 1] = '\0';
	free((char *)s1);
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	c;

	c = 0;
	d = (char *) malloc(sizeof(char) * (len + 1));
	if (!d || !s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (d);
	while (c < len)
	{
		d[c] = s[c + start];
		c++;
	}
	d[c] = '\0';
	return (d);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc(ft_strlen((char *)s1) + 1);
	if (dest)
	{
		ft_memcpy((char *) dest, (char *) s1, ft_strlen(s1));
		dest[ft_strlen(s1)] = '\0';
		return (dest);
	}
	return (0);
}
