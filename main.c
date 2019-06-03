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
int	ft_cnt_words(char *line, char space)
{
	int		cnt;
	int		in_substr;

	in_substr = 0;
	cnt = 0;
	while (*line != '\0')
	{
		if (in_substr == 1 && *line == space)
			in_substr = 0;
		if (in_substr == 0 && *line != space)
		{
			in_substr = 1;
			cnt++;
		}
		line++;
	}
	return (cnt);
}

void map_info(char *file, t_info *info)
{
    info->width = 0;
    info->height = 0;
    info->x_now = 0;
    info->y_now = 0;
    info->step_x = 0;
    info->step_y = 0;
    info->fd = 0;
    char *line;

    line = NULL;
    info->fd = open(file,O_RDONLY);
    while(get_next_line(info->fd, &line) > 0)
    {
        info->width = ft_cnt_words(line, ' ');
        info->height++;
    }
    ft_printf("My width %d my height %d\n", info->width, info->height);
    free(line);
    close(info->fd);
    read_map(file, info, line);
}

void read_map(char *map, t_info *info, char *line)
{
    char    **arr = NULL;
    int     i;
    int     a;
    int row = 0;
    t_point *point;
  
    

    info->step_x =  600/ info->width;
	info->step_y = 600 / info->height;
	info->x_now = 250;
	info->y_now = 250;
    info->x = 0;
    info->y = 0;
    info->total = info->width * info->height;
    point = (t_point*)malloc(sizeof(t_point) * info->total); 
    ft_printf("here total %d\n", info->total * 100);
    i = 0;
    a = 0;
    info->fd = open(map,O_RDONLY);
    while(get_next_line(info->fd, &line) > 0)
    {
        arr = ft_strsplit(line, ' ');
        while(a < info->width)
        {
            to_coordinates(ft_atoi(arr[a]), info, i, point);
            ft_printf("here1\n");
			i++;
			a++;
		}
		a = 0;
        row++;
        info->x_now = 250;
		info->y_now += info->step_y;
	}
    ft_printf("DA BLYAT\n");
    connect_dots(info, point);
}

void		connect_dots(t_info *info, t_point *point)
{
	int i;
	int j;
	int row;
	int prev_y;

	i = 0;
	j = 0;
	row = 0;
	while (i < info->total)
	{
		if (i % info->width == 0)
			row++;
		j = i % info->width;
		prev_y = j + (row * info->width);
		if (row < info->height)
			drawline(info, i, prev_y, point);
		if (j != 0 && i != 0)
			drawline(info, i, i - 1, point);
		i++;
	}
}

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
    mlx_pixel_put(info->mlx_ptr, info->win_ptr,500+point[i].x,500+point[i].y, 0xb4354f);
	info->x_now += info->step_x;
}

int main(int ac, char **av)
{
    t_info *info;
    if ( ac < 2)
    {
        ft_printf("USAGE: specify the name of the map");
        //write(1, "sdfsf", 150);
    }
    if (ac == 2)
    {
        info = malloc(sizeof(t_info));
        info->mlx_ptr = mlx_init();
        info->win_ptr = mlx_new_window(info->mlx_ptr,1000,1000, "fdf");
        map_info(av[1], info);
        ft_printf("here99\n");
        mlx_loop(info->mlx_ptr);
        free(info);
    }
}