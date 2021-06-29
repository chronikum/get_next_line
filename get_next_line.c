/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:16:19 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/29 13:44:25 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_freeprogress(char *rprogress)
{
	if (rprogress)
	{
		free(rprogress);
		rprogress = NULL;
	}
	return (rprogress);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (s[t] != '\0')
		t++;
	t++;
	while (t != i)
	{
		if ((s[i] != c))
			i++;
		else
			return ((char *) &s[i]);
	}
	return (0);
}

static char	*ft_next_line(char *rprogress, char **line, int *result_int)
{
	int		i;
	char	*temp;

	i = 0;
	while (rprogress[i] && (rprogress[i] != '\n'))
		i++;
	*line = ft_substr(rprogress, 0, i);
	if (rprogress[i] == '\n')
	{
		temp = ft_strdup(rprogress + i + 1);
		free(rprogress);
		rprogress = temp;
		*result_int = 1;
		if (rprogress[0] == '\0')
			rprogress = ft_freeprogress(rprogress);
		return (rprogress);
	}
	*result_int = 0;
	rprogress = ft_freeprogress(rprogress);
	return (rprogress);
}

int			get_next_line(int fd, char **line)
{
	static char	*rprogress[MAX_FILEDESCRIPTOR];
	int			result_int;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if ((!line) || (!(buffer)))
		return (-1);
	while ((result_int = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[result_int] = '\0';
		if (!rprogress[fd])
			rprogress[fd] = ft_strdup(buffer);
		else
			rprogress[fd] = ft_strjoin(rprogress[fd], buffer);
		if (ft_strchr(rprogress[fd], '\n'))
			break ;
	}
	free(buffer);
	if ((result_int == 0 && !rprogress[fd]))
	{
		*line = ft_strdup("");
		return (0);
	}
	if (result_int < 0)
		return (-1);
	rprogress[fd] = ft_next_line(rprogress[fd], line, &result_int);
	return (result_int);
}
