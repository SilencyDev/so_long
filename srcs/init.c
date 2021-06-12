/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:25:40 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/12 11:16:36 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *data)
{
	data->i_x = 0;
	data->i_y = 0;
	data->nb_move = 0;
	data->left = 0;
	data->rleft = 0;
	data->right = 0;
	data->rright = 0;
	data->forward = 0;
	data->backward = 0;
	data->x_player = 0;
	data->y_player = 0;
	data->player = 0;
	data->mymap = 0;
	data->mxmap = 0;
	data->one = 0;
	data->nb_player = 0;
	data->width = 0;
	data->height = 0;
	data->collect = 0;
	ft_init_ptr(data);
}

void	ft_init_ptr(t_data *data)
{
	data->img = NULL;
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->map = NULL;
	data->parsing = 0;
	data->map_set = 0;
}

char	is_charset(char c, char *charset)
{
	while (*charset)
		if (*charset++ == c)
			return (c);
	return (0);
}