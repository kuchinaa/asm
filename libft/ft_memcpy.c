/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:20:58 by akuchina          #+#    #+#             */
/*   Updated: 2018/10/27 13:48:48 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *des, const void *src, size_t n)
{
	int		i;

	i = -1;
	while ((size_t)(++i) < n)
		((unsigned char *)des)[i] = ((unsigned char *)src)[i];
	return (des);
}
