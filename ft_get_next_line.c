/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:19:20 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/24 16:28:34 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

int get_next_line(int fd, char **line)
{
	char *buff;
	static int	position = 0;
	static int	linecounter = 0;
	int length;

	if ((fd < 0 || !line || read(fd, buff, 0) < 0))
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (length = read(fd, buff, (BUFFER_SIZE - 1)) > 0)
	{
		if (buff[position] == '\n')
		{
			linecounter++;
			position++;
			printf("%d\n", linecounter);
			// *line = &buff[position];
			return 1;
		}
		position++;
	}
	// while ((ret = read(fd, buff, (BUFFER_SIZE - 1))) > 0)
	// {
	// 	buff[ret] = '\0';
	// 	if (s[fd] == NULL)
	// 		s[fd] = ft_strdup(buff);
	// 	else
	// 	{
	// 		tmp = ft_strjoin(s[fd], buff);
	// 		free(s[fd]);
	// 		s[fd] = tmp;
	// 	}
	// 	if (ft_strchr(s[fd], '\n'))
	// 		break ;
	// }
	return 0;
}

#include <fcntl.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	int d = BUFFER_SIZE;

	// line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		write(1, '\n', 1);
		// printf("%s", line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}