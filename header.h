/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_p <max_p@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:59:53 by max_p             #+#    #+#             */
/*   Updated: 2019/06/02 16:26:02 by max_p            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft/header/libft.h"
# include "libft/header/ft_printf.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct  s_info
{
    void        *mlx_ptr;
    void        *win_ptr;
    int         width;
    int         height;
    int         fd;
    int         x_now;
    int         y_now;
    int         step_x;
    int         step_y;
    int x;
    int y;
    int total;
}               t_info;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	draw_x(t_point *point, int i, t_info *info);
void	to_coordinates(int number, t_info *info, int i, t_point *point);
void read_map(char *map, t_info *info, char *line);
void map_info(char *map, t_info *info);
void		drawline(t_info *info, int one, int two, t_point *point);
void connect_line(t_point *point, int i, t_info *info, int prev_x, int prev_y);
void		connect_dots(t_info *info, t_point *point);

#endif