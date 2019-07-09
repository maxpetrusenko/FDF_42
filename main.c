/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_p <max_p@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:59:06 by max_p             #+#    #+#             */
/*   Updated: 2019/06/02 18:22:23 by max_p            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		drawline(t_info *info, int one, int two, t_point *point)
{
	int x0 = point[one].x + info->step_x;
	int x1 = point[two].x + info->step_x;
	int y0 = point[one].y + info->step_y;
	int y1 = point[two].y + info->step_y;
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x1 >= x0 ? 1 : -1;
	int sy = y1 >= y0 ? 1 : -1;
    int qwe = 400;
	if (dy <= dx)
{


		int d = (dy << 1) - dx;
	    int d1 = dy << 1;
	    int d2 = (dy - dx) << 1;
	    mlx_pixel_put(info->mlx_ptr, info->win_ptr,
			x0 + qwe, y0, 0xb4354f);
	    int x = x0 + sx;
	int y = y0;
	int i = 1;
	while (i <= dx)
	{
		if (d > 0)
		{
			d += d2;
			y += sy;
		}
		else
			d += d1;
		mlx_pixel_put(info->mlx_ptr, info->win_ptr,
				x+ qwe, y, 0xb4354f);
		i++;
	    x += sx;
	}
}
	else
    {
        int d = (dx << 1) - dy;
	    int d1 = dx << 1;
	    int d2 = (dx - dy) << 1;
	int y = y0 + sy;
	int i = 1;
	int x = x0;
	mlx_pixel_put(info->mlx_ptr, info->win_ptr,
			x0+ qwe, y0, 0xb4354f);
	while (i <= dy)
	{
		if (d > 0)
		{
			d += d2;
			x += sx;
		}
		else
			d += d1;
		mlx_pixel_put(info->mlx_ptr, info->win_ptr,
			x+ qwe, y, 0xb4354f);
		y += sy;
		i++;
	}
    }
}

void	to_coordinates(int number, t_info *info, int i, t_point *point)
{	
    point[i].x = (info->x_now - info->y_now+
	info->step_x) * cos(0.523599);
	point[i].y = -(number * 7)
		+ (info->x_now + info->y_now) * sin(0.523599);
    //mlx_pixel_put(info->mlx_ptr, info->win_ptr,500+point[i].x,500+point[i].y, 0xb4354f);
	info->x_now += info->step_x;
}

void color_stuff(t_info *info)
{
    int color;
    int change;
    
    color =  0x00ffff;
    change = 5;
    if (change > 0)
    {
        color = 0xff0000;
    }
    else if (change == 5)
    {
        color = 0x4b0082;
    }
    else
        color = 0x7a7a7a;
    free(info);
}

int main(int ac, char **av)
{
    t_info *info;
    if ( ac < 2)
        ft_printf("USAGE: specify the name of the map");
    if (ac == 2)
    {
        info = malloc(sizeof(t_info));
        info->mlx_ptr = mlx_init();
        info->win_ptr = mlx_new_window(info->mlx_ptr,1000,1000, "fdf");
        map_info(av[1], info);
        mlx_hook(info->win_ptr, 2, 5, close_app, info);
        mlx_loop(info->mlx_ptr);
        free(info);
    }
    return (0);
}


void clean_all_stuff(t_point *point)
{
    free(point);
}

int close_app(int key)
{
    if (key == 53)
        exit(0);
    return (0);
}
