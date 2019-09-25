/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:27:56 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/23 21:27:58 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, int len)
{
	int		i;
	char	*dup;

	i = ft_strlen(str);
	i = (len < i) ? len : i;
	dup = ft_strnew(i);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
