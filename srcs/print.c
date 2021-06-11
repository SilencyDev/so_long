/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:55:40 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/11 19:24:07 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		ft_square(t_data *data, int x, int y, int color)
{
	int	x_max;
	int	y_max;
	int	i;
	int	j;

	x_max = x * SIZE;
	y_max = y * SIZE;
	i = 0;
	j = 0;
	while (i < SIZE)
	{
		while (j < SIZE)
		{
			my_mlx_pixel_put(data, x_max + j, y_max + i, color);
			if (i < BORDER || i > SIZE - BORDER || j < BORDER || j > SIZE - BORDER)
				my_mlx_pixel_put(data, x_max + j, y_max + i, 0x40000000);
			j++;
		}
		j = 0;
		i++;
	}
}

void		ft_player(t_data *data, int x, int y, int color)
{
	int	x_max;
	int	y_max;
	int	i;
	int	j;

	x_max = x * SIZE;
	y_max = y * SIZE;
	i = 0;
	j = 0;
	while (i < SIZE)
	{
		while (j < SIZE)
		{
			my_mlx_pixel_put(data, x_max + j, y_max + i, color);
			if (i < BORDER || i > SIZE - BORDER || j < BORDER || j > SIZE - BORDER)
				my_mlx_pixel_put(data, x_max + j, y_max + i, 0x00000000);
			j++;
		}
		j = 0;
		i++;
	}
}

int		ft_minimap(t_data *data)
{
	int	y;
	int	x;
	int	offset;

	y = 0;
	x = 0;
	offset = 1;
	ft_move(data);
	if (data->map[data->y_player][data->x_player] == 'C')
	{
		data->collect -= 1;
		data->map[data->y_player][data->x_player] = '0';
	}
	if (data->map[data->y_player][data->x_player] == 'E')
	{
		if (!data->collect)
		{
			ft_putstr_fd("Congratulation ! Game Over !", 1);
			ft_exit(data, 0);
		}
		if (data->collect)
			ft_putstr_fd("Not enough collectible !\n", 1);
	}
	while (data->mymap > y && data->map[y][x])
	{
		while (data->mxmap > x && data->map[y][x])
		{
			if (data->map[y][x] == 'E')
				ft_square(data, x + offset, y + offset, 0xF900FF00);
			if (data->map[y][x] == '0')
				ft_square(data, x + offset, y + offset, 0xF9FF00FF);
			if (data->map[y][x] == 'C')
				ft_square(data, x + offset, y + offset, 0xF9FF0000);
			if (data->map[y][x] == '1')
				ft_square(data, x + offset, y + offset, 0x00FFFFFF);
			x++;
		}
		x = 0;
		y++;
	}
	ft_player(data, data->x_player + offset, data->y_player + offset, 0x00FFFF00);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	return (1);
}