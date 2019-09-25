/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:23:16 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/07 18:33:32 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	char	*tmp;
	char	*str;

	str = (char *)string;
	tmp = NULL;
	while (*str)
	{
		if (*str == (char)symbol)
			tmp = str;
		str++;
	}
	if (*str == (char)symbol)
		tmp = str;
	return (tmp);
}
