/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:49:14 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/08 15:54:26 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (!tmp)
		return (NULL);
	ft_memset(tmp, 0, size);
	return (tmp);
}
