/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 16:24:04 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/04 16:48:01 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)memptr;
	while (num > 0)
	{
		*tmp = (unsigned char)val;
		tmp++;
		num--;
	}
	return (memptr);
}
