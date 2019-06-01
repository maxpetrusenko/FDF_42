/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 12:02:43 by mpetruse          #+#    #+#             */
/*   Updated: 2018/08/10 14:31:43 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*color(char *fmt, t_param *p)
{
	p->printed = 5;
	if (!ft_strncmp(fmt, "{red}", ft_strlen("{red}")))
		COLOR(PF_RED, 5);
	else if (!ft_strncmp(fmt, "{green}", ft_strlen("{green}")))
		COLOR(PF_GREEN, 7);
	else if (!ft_strncmp(fmt, "{yellow}", ft_strlen("{yellow}")))
		COLOR(PF_YELLOW, 8);
	else if (!ft_strncmp(fmt, "{blue}", ft_strlen("{blue}")))
		COLOR(PF_BLUE, 6);
	else if (!ft_strncmp(fmt, "{purple}", ft_strlen("{purple}")))
		COLOR(PF_PURPLE, 8);
	else if (!ft_strncmp(fmt, "{cyan}", ft_strlen("{cyan}")))
		COLOR(PF_CYAN, 6);
	else if (!ft_strncmp(fmt, "{eoc}", ft_strlen("{eoc}")))
		COLOR(PF_EOC, 5);
	else
		p->printed = 0;
	p->l += p->printed;
	return (fmt - 1);
}

float	ft_fclamp(float n, float min, float max)
{
	if (n < min)
		return (min);
	return (n > max ? max : n);
}
