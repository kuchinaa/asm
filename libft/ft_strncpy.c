/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:13:58 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/10 14:46:26 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destptr, const char *srcptr, size_t num)
{
	size_t	i;

	i = 0;
	while (srcptr[i] && (num > i))
	{
		destptr[i] = srcptr[i];
		i++;
	}
	while (num > i)
	{
		destptr[i] = '\0';
		i++;
	}
	return (destptr);
}
