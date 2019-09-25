/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:40:50 by akuchina          #+#    #+#             */
/*   Updated: 2018/11/07 11:56:18 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strduplen(const char *src, unsigned int len)
{
	unsigned int	i;
	char			*str;

	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i <= len)
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
