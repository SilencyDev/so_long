/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:06:15 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/11 18:59:33 by kmacquet         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	ft_init(&data);
	if (argc == 2 && is_ber(argv[1], &data))
	{
		if ((fd = open(argv[1], O_DIRECTORY)) != -1)
			ft_error("This is a directory, not a .ber file", &data);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
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
