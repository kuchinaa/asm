/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:40:48 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/05 18:35:39 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp2 = (unsigned char *)src;
	tmp1 = (unsigned char *)dest;
	if (dest > src)
	{
		tmp1 += (num - 1);
		tmp2 += (num - 1);
		while (num > 0)
		{
			*tmp1 = *tmp2;
			tmp1--;
			tmp2--;
			num--;
		}
	}
	else
		while (num > 0)
		{
			*tmp1++ = *tmp2++;
			num--;
		}
	return (dest);
}
