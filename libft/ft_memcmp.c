/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:42:44 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/07 19:07:06 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*n_ptr1;
	unsigned char	*n_ptr2;
	size_t			i;

	n_ptr1 = (unsigned char *)ptr1;
	n_ptr2 = (unsigned char *)ptr2;
	i = 0;
	while (num > i)
	{
		if (n_ptr1[i] != n_ptr2[i])
			return ((int)n_ptr1[i] - (int)n_ptr2[i]);
		if (n_ptr1[i] == n_ptr2[i])
			i++;
	}
	return (0);
}
