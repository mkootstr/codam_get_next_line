/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 11:14:17 by mkootstr      #+#    #+#                 */
/*   Updated: 2021/10/14 14:23:11 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int	fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			**line;
	ssize_t			br;
	char			*lline;

	lline = NULL;
	line = &lline;
	br = 0;
	//printf("%d\n", 1);
	while (buf[0] != '\0' || br == 0)
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br == 0)
		{
			//printf("%d\n", 2);
			return (NULL);
		}
		else if (br < 0)
		{
			//printf("%d\n", 3);
			if (*line)
			{
				free(*line);
				//printf("%d\n", 4);
			}
			return (NULL);
		}
		else if (br > 0)
		{
			//printf("%d\n", 5);
			ft_prcsbuf(line, buf, br);
		}
		if (buf[0] == '\n' || *line == NULL)
			break ;
	}
	return (*line);
}

char	*ft_prcsbuf(char **line, char *buf, ssize_t br)
{
	ssize_t	n;
	size_t	i;
	size_t	nl;

	n = br;
	i = 0;
	nl = 0;
	//printf("%d\n", 6);
	while (n > 0 && buf[i] != '\n')
	{
		i++;
		n--;
	}
	if (!*line)
	{
		*line = ft_strndup(buf, i);
		//printf("%d\n", 7);
	}
	else if (*line)
	{
		*line = ft_strfrjoin(*line, buf, i);
		//printf("%d\n", 8);
	}
	ft_memmove(&buf[i + 1], &buf[0], (br - i));
	//printf("%d\n", 9);
	return (buf);
}
