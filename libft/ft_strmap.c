/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:12:06 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/12 18:36:39 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rez;
	size_t	i;

	if (!s)
		return (NULL);
	rez = ft_strnew(ft_strlen(s));
	if (!rez)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (f(s[i]))
			rez[i] = f(s[i]);
		i++;
	}
	rez[i] = '\0';
	return (rez);
}
