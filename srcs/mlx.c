/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:14:29 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/12 14:52:16 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == FORWARD)
		data->forward = 1;
	else if (keycode == LEFT)
		data->left = 1;
	else if (keycode == BACKWARD)
		data->backward = 1;
	else if (keycode == RIGHT)
		data->right = 1;
	else if (keycode == ESCAPE)
		ft_exit(data, 0);
	return (1);
}

int	ft_exit(t_data *data, int i)
{
	if (data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
	{
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	ft_exit2(data, i);
	exit(i);
	return (i);
}

void	ft_exit2(t_data *data, int i)
{
	int	y;

	y = 0;
	if (data->map)
	{
		while (y < data->mymap)
		{
			free(data->map[y]);
			data->map[y++] = NULL;
		}
		free(data->map);
		data->map = NULL;
		y = 0;
	}
	y = data->width;
	exit(i);
}

void	ft_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->width = 800;
	data->height = 600;
	data->mlx_win
		= mlx_new_window(data->mlx_ptr, data->width, data->height, "so_long");
	data->img = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
	mlx_loop_hook(data->mlx_ptr, ft_display, data);
	mlx_loop(data->mlx_ptr);
}

int	ft_display(t_data *data)
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
