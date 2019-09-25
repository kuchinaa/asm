/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:10:27 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/16 17:13:25 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbwords(char *s, char c)
{
	size_t	i;
	size_t	marker;

	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		marker = 0;
		while (*s && *s != c)
		{
			s++;
			marker++;
		}
		while (*s && *s == c)
			s++;
		if (marker > 0)
			i++;
	}
	return (i);
}
