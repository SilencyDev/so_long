/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:26:51 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/12 15:36:18 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_map(char *line, t_data *data, int y)
{
	int	x;

	x = 0;
	data->map[y] = NULL;
	data->map[y] = malloc((int)data->mxmap + 1);
	if (!data->map[y])
		ft_error("Malloc of row's map failed", data);
	while (*line)
		data->map[y][x++] = *line++;
	data->map[y][x] = '\0';
	return (++y);
}

void	ft_parsing_map(t_data *data, int fd)
{
	int		ret;
	int		y;
	char	*l;

	ret = 1;
	y = 0;
	data->map = malloc(sizeof(char *) * (int)data->mymap);
	if (!data->map)
		ft_error("Malloc of map failed", data);
	while (ret != 0)
	{
		ret = get_next_line(fd, &l) > 0;
		y = set_map(l, data, y);
		ft_memdel((void **)&l);
	}
	close(fd);
}

int	ft_check(t_data *data, int x, int y)
{
	if (!is_charset(data->map[y][x], "01CEP"))
		return (0);
	if (is_charset(data->map[y][x], "0CEP")
		&& (y - 1 < 0 || y + 1 == data->mymap
		|| x - 1 < 0 || x + 1 == data->mxmap))
		return (0);
	if (data->map[y][x] == 'C')
		data->collect += 1;
	if (data->map[y][x] == 'P')
	{
		data->map[y][x] = '0';
		data->x_player = x;
		data->y_player = y;
		data->nb_player += 1;
	}
	return (1);
}

int	is_map_valid(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < data->mymap && data->map[y][x])
	{
		while (x < data->mxmap && data->map[y][x])
		{
			if (!ft_check(data, x, y))
				return (0);
			x++;
		}
		if (x != data->mxmap)
			return (0);
		x = 0;
		y++;
	}
	if (data->nb_player != 1)
		ft_error("number of player isn't 1", data);
	if (data->collect < 1)
		ft_error("number of collectible is inferior to 1", data);
	return (1);
}

int	count_max_map(char *line, t_data *data, int y)
{
	int	x;

	x = -1;
	data->map_set = 1;
	while (line[++x])
		;
	if (data->mxmap < x)
		data->mxmap = x;
	return (++y);
}
