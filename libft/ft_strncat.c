/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:00:00 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/03 18:07:29 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destptr, char *srcptr, size_t num)
{
	unsigned long	i;
	unsigned long	j;

	j = 0;
	i = 0;
	while (destptr[i])
		i++;
	while (srcptr[j] && (j < num))
	{
		destptr[i] = srcptr[j];
		i++;
		j++;
	}
	destptr[i] = '\0';
	return (destptr);
}
