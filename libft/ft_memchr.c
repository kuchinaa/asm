/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:35:02 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/10 14:57:40 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t num)
{
	char		*tmp;
	size_t		i;

	tmp = (char *)ptr;
	i = 0;
	while (num > 0)
	{
		if (tmp[i] == (char)c)
			return ((void *)&tmp[i]);
		num--;
		i++;
	}
	return (NULL);
}
