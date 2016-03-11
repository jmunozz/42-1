/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 11:59:19 by jubarbie          #+#    #+#             */
/*   Updated: 2016/02/18 14:29:10 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>

# define BUF 10000

typedef struct	s_meta
{
	int	line;
	int	col;
	int left;
	int pos;
}				t_meta;

typedef struct	s_box
{
	struct s_box	*next;
	int				pos_x;
	int				pos_y;
	int				nb_left;
	int				nb_up;
}				t_box;

typedef struct	s_map
{
	t_box	*first;
	t_box	***tab;
	t_meta	*meta;
	int		width;
	int		height;
	char	blank;
	char	wall;
	char	fill;
}				t_map;

int				create_map(t_map **map, char *file_name, int fd);
t_box			*insert_sort_box(t_map **map, t_box *box);
t_box			*do_box(int pos_x, int pos_y, int nb_left, int nb_up);
void			create_meta_box(t_map **map, t_meta *meta, char c);
void			tab_init(t_map **map);
void			do_bsq(t_map **map);
int				map_print_file(t_map **map, char *file_name);
int				map_print_stdout(t_map **map);
void			map_print_debug(t_map **map);
void			free_all(t_map **map);
void			box_clear(t_map **map);
int				get_min(int a, int b);
int				ft_atoi(char *str);
void			ft_display_error(char *comand, char *param, unsigned int code);
char			*ft_strerror(unsigned int code);
void			ft_putstr(int fd, char *str);

#endif
