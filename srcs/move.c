/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:21:41 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/12 14:50:46 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_data *data)
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

void	ft_move_f(t_data *data)
{
	if (data->map[(data->y_player - 1)]
		[(data->x_player)] != '1')
	{
		data->y_player -= 1;
		game_message(data);
	}
}

void	ft_move_b(t_data *data)
{
	if (data->map[(data->y_player + 1)]
		[(data->x_player)] != '1')
	{
		data->y_player += 1;
		game_message(data);
	}
}

void	ft_move_r(t_data *data)
{
	if (data->map[(data->y_player)]
		[(data->x_player + 1)] != '1')
	{
		data->x_player += 1;
		game_message(data);
	}
}

void	ft_move_l(t_data *data)
{
	if (data->map[(data->y_player)]
		[(data->x_player - 1)] != '1')
	{
		data->x_player -= 1;
		game_message(data);
	}
}
