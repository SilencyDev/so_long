/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:04:10 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/12 14:33:10 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	is_ber(char *s, t_data *data)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i >= 5 && s[i - 1] == 'r' && s[i - 2] == 'e'
		&& s[i - 3] == 'b' && s[i - 4] == '.')
		return (1);
	ft_error("The argument don't end with .ber", data);
	return (0);
}

void	ft_putnum(int nb)
{
	char	c;

	c = 0;
	if (nb > 9)
		ft_putnum(nb / 10);
	c = nb % 10 + '0';
	write(STDOUT_FILENO, &c, 1);
}
