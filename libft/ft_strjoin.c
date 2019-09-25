/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:43:59 by akuchina          #+#    #+#             */
/*   Updated: 2018/11/08 13:54:36 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	n;
	char			*s;

	if (s1 && s2)
	{
		n = ft_strlen(s1) + ft_strlen(s2);
		if (!(s = (char *)malloc(n + 1)))
			return (NULL);
		i = 0;
		while (*s1)
			s[i++] = *s1++;
		while (*s2)
			s[i++] = *s2++;
		s[i] = '\0';
		return (s);
	}
	return (NULL);
}
