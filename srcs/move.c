/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:21:41 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/12 12:24:52 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_message(t_data *data)
{
	if (data->map[data->y_player][data->x_player] == 'C')
	{
		data->collect -= 1;
		data->map[data->y_player][data->x_player] = '0';
	}
	if (data->map[data->y_player][data->x_player] == 'E')
	{
		if (!data->collect)
		{
			ft_putstr_fd("Congratulation ! Game Over !\n", 1);
			ft_exit(data, 0);
		}
		if (data->collect)
			ft_putstr_fd("Not enough collectible !\n", 1);
	}
	data->nb_move += 1;
	ft_putnum(data->nb_move);
	ft_putstr_fd("\n", 1);
}

void	reset_key(t_data *data)
{
	data->forward = 0;
	data->backward = 0;
	data->left = 0;
	data->right = 0;
}

void		ft_move(t_data *data)
{
	if (data->forward)
		ft_move_f(data);
	if (data->backward)
		ft_move_b(data);
	if (data->left)
		ft_move_l(data);
	if (data->right)
		ft_move_r(data);
	reset_key(data);
}

void		ft_move_f(t_data *data)
{
	if (data->map[(data->y_player - 1)]
		[(data->x_player)] != '1')
	{
		data->y_player -= 1;
		game_message(data);
	}
}

void		ft_move_b(t_data *data)
{
	if (data->map[(data->y_player + 1)]
		[(data->x_player)] != '1')
	{
		data->y_player += 1;
		game_message(data);
	}
}

void		ft_move_r(t_data *data)
{
	if (data->map[(data->y_player)]
		[(data->x_player + 1)] != '1')
	{
		data->x_player += 1;
		game_message(data);
	}
}

void		ft_move_l(t_data *data)
{
	if (data->map[(data->y_player)]
		[(data->x_player - 1)] != '1')
	{
		data->x_player -= 1;
		game_message(data);
	}
}
