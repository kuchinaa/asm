/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:10:03 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/16 14:48:14 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t length)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (length == 0)
		return (NULL);
	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && (i < length))
	{
		j = 0;
		k = i;
		while (s2[j] && (k < length) && s1[k] == s2[j])
		{
			k++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)&s1[k - j]);
		i++;
	}
	return (NULL);
}
