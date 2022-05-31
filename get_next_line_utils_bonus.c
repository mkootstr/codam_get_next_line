/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 17:11:33 by mkootstr      #+#    #+#                 */
/*   Updated: 2021/10/25 18:10:19 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc((n + 1) * sizeof(char));
	if (dest)
	{
		while (src && i < n)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)dest;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			ptr[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	else if (src > dest)
	{
		while (i < n)
		{
			ptr[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_append(char **line, char *buf, size_t l)
{
	char	*new_line;
	size_t	line_size;

	line_size = ft_strlen(*line);
	new_line = malloc((line_size + 1 + l) * sizeof(char));
	if (!new_line)
	{
		free(*line);
		*line = NULL;
		return ;
	}
	new_line[line_size + l] = '\0';
	while (l--)
		new_line[line_size + l] = buf[l];
	while (line_size--)
		new_line[line_size] = (*line)[line_size];
	free(*line);
	*line = new_line;
}
