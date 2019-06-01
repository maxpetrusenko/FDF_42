/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_p <max_p@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:59:06 by max_p             #+#    #+#             */
/*   Updated: 2019/04/12 21:29:07 by max_p            ###   ########.fr       */
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

void find_dot(int number, t_info *info, int i)
{
    
}

void map_info(char *map, t_info *info,char *line)
{
    while(get_next_line(info->fd, line) ==  1)
    {
        info->width = ft_cnt_words(map, ' ');
        info->height++;
    }

    close(info->fd);
}

void read_map(char *map, t_info *info)
{
    char    *line;
    char    **arr;
    int     i;

    i = 0;
    info->fd = open(map,O_RDONLY);
    map_info(map, info,line);
    while(get_next_line(info->fd, line) == 1)
    {
        arr = ft_strsplit(line, ' ');
        while(i < info->width)
        {
            //cast str to int
            //find_dot(arr[i], info, i)
        }
    }
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
        read_map(av[1], info);
        mlx_loop(info->mlx_ptr);
    }

}