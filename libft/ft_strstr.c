/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:28:45 by akuchina          #+#    #+#             */
/*   Updated: 2018/11/07 12:35:37 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	if (!s1[0] && !s2[0])
		return ((char*)s1);
	i = -1;
	while (s1[++i])
	{
		j = -1;
		while (s1[i] == s2[++j] && s2[j])
			i++;
		if ((size_t)j == ft_strlen(s2))
			return ((char *)(s1 + i - j));
		else
			i -= j;
	}
	return (NULL);
}
