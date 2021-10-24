/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/26 16:30:40 by mkootstr      #+#    #+#                 */
/*   Updated: 2021/10/17 11:37:36 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

//#define BUFFER_SIZE 42

char	*get_next_line(int	fd);
char	*ft_prcsbuf(char **line, char *buf, ssize_t br);
char	*ft_strndup(const char *src, size_t n);
char	*ft_join(char *s1, char *s2, char *s3, size_t l);
char	*ft_strfrjoin(char *s1, char *s2, size_t l);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);

#endif