/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_p <max_p@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:56:57 by mpetruse          #+#    #+#             */
/*   Updated: 2019/06/02 17:33:46 by max_p            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int		ft_atoi(const char *str)
{
	int long	res;
	int			neg;
	const char	*s;

	s = str;
	while (*s && ft_isspace(*s))
		s++;
	neg = 1;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			neg = -1;
	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + neg * (*s++ - 48);
	}
	return ((int)res);
}
