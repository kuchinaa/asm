/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:05:33 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/05 18:07:14 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	tmp1 = (char *)dest;
	tmp2 = (char *)source;
	i = 0;
	while (count > 0)
	{
		if (tmp2[i] == (char)ch)
		{
			tmp1[i] = tmp2[i];
			i++;
			return (&tmp1[i]);
		}
		tmp1[i] = tmp2[i];
		i++;
		count--;
	}
	return (NULL);
}
