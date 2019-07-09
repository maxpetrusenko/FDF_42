/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
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
        free(line);
    }
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
    i = 0;
    a = 0;
    info->fd = open(map,O_RDONLY);
    while(get_next_line(info->fd, &line) > 0)
    {
        arr = ft_strsplit(line, ' ');
        while(a < info->width)
        {
            to_coordinates(ft_atoi(arr[a]), info, i, point);
			i++;
			a++;
		}
        free(line);
        free(arr);
		a = 0;
        row++;
        info->x_now = 250;
		info->y_now += info->step_y;
	}
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
    clean_all_stuff(point);
}

