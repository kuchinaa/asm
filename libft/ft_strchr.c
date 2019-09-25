/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:00:04 by akuchina          #+#    #+#             */
/*   Updated: 2018/11/06 18:11:20 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int val)
{
	int		i;
	int		n;

	i = -1;
	n = ft_strlen(str);
	while (++i < n)
		if (str[i] == (char)val)
			return ((char *)(str + i));
	if (str[i] == (char)val)
		return ((char *)(str + i));
	return (NULL);
}
