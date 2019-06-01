/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_p <max_p@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:59:53 by max_p             #+#    #+#             */
/*   Updated: 2019/04/12 21:17:39 by max_p            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft/header/libft.h"
# include "libft/header/ft_printf.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct  s_info
{
    void        *mlx_ptr;
    void        *win_ptr;
    int         width;
    int         height;
    int         fd;

}               t_info;

#endif