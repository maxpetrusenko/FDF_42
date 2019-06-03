/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_p <max_p@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:26:23 by mpetruse          #+#    #+#             */
/*   Updated: 2019/06/01 19:05:42 by max_p            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		len1;
// 	int		len2;
// 	char	*dst;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	dst = (char *)malloc(len1 + len2 + 2);
// 	ft_bzero(dst, len1 + len2 + 2);
// 	if (!dst)
// 		return (NULL);
// 	ft_strcpy(dst, s1);
// 	ft_strcat(dst, s2);
// 	ft_memdel((void **)&s1);
// 	ft_memdel((void **)&s2);
// 	return (dst);
// }

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = (char *)malloc(sizeof(*s) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	while (*s1 != '\0')
		s[i++] = *s1++;
	while (*s2 != '\0')
		s[i++] = *s2++;
	s[i] = '\0';
	return (s);
}
