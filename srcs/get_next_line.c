/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:44:48 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/12 15:13:13 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = c;
	return (s);
}

int	ft_memdel(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int		n;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

void	set_tmp(char *tmp, char **line, int l, char c)
{
	int	i;

	i = -1;
	while (++i < l - 2)
		tmp[i] = (*line)[i];
	tmp[i] = c;
	tmp[i + 1] = 0;
	free(*line);
	*line = tmp;
}

int	get_next_line(int fd, char **line)
{
	int		l;
	int		r;
	char	c;
	char	*tmp;

	l = 1;
	*line = malloc(l);
	if (!*line)
		return (-1);
	(*line)[0] = 0;
	r = read(fd, &c, 1);
	while (r && l++ && c != '\n')
	{
		tmp = malloc(l);
		if (!tmp)
		{
			free(*line);
			return (-1);
		}
		set_tmp(tmp, line, l, c);
		r = read(fd, &c, 1);
	}
	return (r);
}
