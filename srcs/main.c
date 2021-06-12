/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:06:15 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/12 14:53:41 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *s, t_data *data)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\n", 1);
	ft_exit(data, 1);
}

void	ft_parsing_setting(t_data *data, int fd)
{
	int		ret;
	char	*l;

	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(fd, &l) > 0;
		data->mymap = count_max_map(l, data, data->mymap);
		ft_memdel((void **)&l);
	}
	close(fd);
}

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

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	ft_init(&data);
	if (argc == 2 && is_ber(argv[1], &data))
	{
		fd = open(argv[1], O_DIRECTORY);
		if (fd != -1)
			ft_error("This is a directory, not a .ber file", &data);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_error(".ber invalid", &data);
		ft_parsing_setting(&data, fd);
		fd = open(argv[1], O_RDONLY);
		ft_parsing_map(&data, fd);
		if (!is_map_valid(&data))
			ft_error("map is invalid", &data);
		ft_mlx(&data);
	}
	ft_error("wrong arguments", NULL);
	return (0);
}
