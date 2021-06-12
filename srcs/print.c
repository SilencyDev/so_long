/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:55:40 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/12 14:56:08 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_square(t_data *data, int x, int y, int color)
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
			if (i < BOR || i > SIZE - BOR || j < BOR || j > SIZE - BOR)
				my_mlx_pixel_put(data, x_max + j, y_max + i, 0x40000000);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_player(t_data *data, int x, int y, int color)
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
			if (i < BOR || i > SIZE - BOR || j < BOR || j > SIZE - BOR)
				my_mlx_pixel_put(data, x_max + j, y_max + i, 0x00000000);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_print_back(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->height - 1)
	{
		x = 0;
		while (x < data->width - 1)
			my_mlx_pixel_put(data, x++, y, 0x00000000);
		y++;
	}
}

void	ft_print_zone(t_data *data, int y, int x, int offset)
{
	ft_print_back(data);
	while (data->mymap > y + (data->i_y * 12) && data->map[y + (data->i_y * 12)]
		[x + (data->i_x * 18)] && x < 18 && y < 12)
	{
		while (data->mxmap > x + (data->i_x * 18) && data->map[y
				+ (data->i_y * 12)][x + (data->i_x * 18)] && x < 18 && y < 12)
		{
			if (data->map[y + (data->i_y * 12)][x + (data->i_x * 18)] == 'E')
				ft_square(data, x + offset, y + offset, 0x0000FF00);
			if (data->map[y + (data->i_y * 12)][x + (data->i_x * 18)] == '0')
				ft_square(data, x + offset, y + offset, 0xD9FF00FF);
			if (data->map[y + (data->i_y * 12)][x + (data->i_x * 18)] == 'C')
				ft_square(data, x + offset, y + offset, 0x00FF0000);
			if (data->map[y + (data->i_y * 12)][x + (data->i_x * 18)] == '1')
				ft_square(data, x + offset, y + offset, 0x00FFFFFF);
			x++;
		}
		x = 0;
		y++;
	}
}
