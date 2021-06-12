/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:55:40 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/12 12:44:13 by kmacquet         ###   ########.fr       */
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

void	ft_print_zone(t_data *data, int y, int x, int offset)
{
	while (y < data->height - 1)
	{
		x = 0;
		while (x < data->width - 1)
			my_mlx_pixel_put(data, x++, y, 0x00000000);
		y++;
	}
	x = 0;
	y = 0;
	while (data->mymap > y + (data->i_y * 12) && data->map[y + (data->i_y * 12)][x + (data->i_x * 18)] && x < 18 && y < 12)
	{
		while (data->mxmap > x + (data->i_x * 18) && data->map[y + (data->i_y * 12)][x + (data->i_x * 18)] && x < 18 && y < 12)
		{
			if (data->map[y + (data->i_y * 12)][x + (data->i_x * 18)] == 'E')
				ft_square(data, x + offset, y + offset, 0xF900FF00);
			if (data->map[y + (data->i_y * 12)][x + (data->i_x * 18)] == '0')
				ft_square(data, x + offset, y + offset, 0xF9FF00FF);
			if (data->map[y + (data->i_y * 12)][x + (data->i_x * 18)] == 'C')
				ft_square(data, x + offset, y + offset, 0xF9FF0000);
			if (data->map[y + (data->i_y * 12)][x + (data->i_x * 18)] == '1')
				ft_square(data, x + offset, y + offset, 0x00FFFFFF);
			x++;
		}
		x = 0;
		y++;
	}
}

int		ft_display(t_data *data)
{
	int	y;
	int	x;
	int	offset;

	offset = 1;
	data->i_y = (int)(data->y_player / 12);
	data->i_x = (int)(data->x_player / 18);
	y = 0;
	x = 0;
	ft_print_zone(data, x, y, offset);
	ft_player(data, data->x_player - (data->i_x * 18) + offset,
			data->y_player - (data->i_y * 12) + offset, 0x00FFFF00);
	ft_move(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	return (1);
}