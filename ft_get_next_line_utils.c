/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:52:07 by jfritz            #+#    #+#             */
/*   Updated: 2021/06/24 10:53:44 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*g;
	int		t;

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
		{
			g = (char *) &s[i];
			return (g);
		}
	}
	return (0);
}
