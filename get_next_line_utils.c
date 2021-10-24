/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/26 16:29:45 by mkootstr      #+#    #+#                 */
/*   Updated: 2021/10/14 14:23:11 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<stdio.h>

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc((n + 1) * sizeof(char));
	//printf("%d\n", 10);
	if (dest)
	{
		//printf("%d\n", 11);
		while (src[i] != '\0' && src[i] != '\n')
		{
			dest[i] = src[i];
			i++;
		}
		//printf("%d\n", 12);
		dest[i] = '\0';
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*flpfrt;

	i = 0;
	//printf("%d\n", 13);
	flpfrt = (unsigned char *)dest;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			flpfrt[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	else if (src > dest)
	{
		while (i < n)
		{
			flpfrt[i] = ((unsigned char *)src)[i];
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
	{
		i++;
	}
	return (i);
}

char	*ft_join(char *s1, char *s2, char *s3, size_t l)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	//printf("%d\n", 16);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	//printf("%d\n", 22);
	while (j <= l && s2 != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	//printf("%d\n", 17);
	free(s1);
	return (s3);
}

char	*ft_strfrjoin(char *s1, char *s2, size_t l)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	size;

	//printf("%d\n", 14);
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + l;
	s3 = malloc((size + 1) * sizeof(char));
	s3[size] = '\0';
	//printf("%d\n", 15);
	if (!s3)
		return (NULL);
	else
		s3 = ft_join(s1, s2, s3, l);
	//printf("%d\n", 18);
	return (s3);
}
