/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:48:09 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/11 16:46:40 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putstr_fd(char *s, int fd)
{
	while (s && *s)
		ft_putchar_fd(*s++, fd);
}