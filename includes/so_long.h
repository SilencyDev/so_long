/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:07:45 by kmacquet          #+#    #+#             */
/*   Updated: 2021/06/11 19:18:41 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define SIZE 40
# define BORDER 2
# define FORWARD 13
# define LEFT 0
# define BACKWARD 1
# define RIGHT 2
# define RLEFT 123
# define RRIGHT 124
# define ESCAPE 53

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			rgb;
}				t_color;

typedef struct	s_data
{
	int			collect;
	int			map_set;
	int			parsing;
	int			n;
	int			offset;
	int			f;
	int			c;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map;
	int			one;
	char		player;
	int			nb_player;
	int			width;
	int			height;
	int			y_player;
	int			x_player;
	int			mxmap;
	int			mymap;
	int			forward;
	int			left;
	int			backward;
	int			right;
	int			rleft;
	int			rright;
	t_color		color;
}				t_data;

void	ft_init(t_data *data);
void	ft_init_ptr(t_data *data);
int		set_map(char *line, t_data *data, int y);
void	ft_parsing_map(t_data *data, int fd);
void	ft_parsing_setting(t_data *data, int fd);
int		is_map_valid(t_data *data);
char	is_charset(char c, char *charset);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_memdel(void **ptr);
void	*ft_memset(void *s, int c, size_t n);
void	ft_mlx(t_data *data);
int		key_release(int keycode, t_data *data);
int		key_press(int keycode, t_data *data);
char	*ft_memalloc(size_t size);
int		get_next_line(int fd, char **line);
int		ft_strlen(char *s);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
void	ft_error(char *s, t_data *data);
void	ft_square(t_data *data, int x, int y, int color);
void	ft_player(t_data *data, int x, int y, int color);
int		ft_minimap(t_data *data);
int		count_max_map(char *line, t_data *data, int y);
int		ft_exit(t_data *data, int i);
void	ft_exit2(t_data *data, int i);
void	ft_move(t_data *data);
void	ft_move_f(t_data *data);
void	ft_move_b(t_data *data);
void	ft_move_r(t_data *data);
void	ft_move_l(t_data *data);
int		is_ber(char *s, t_data *data);

#endif