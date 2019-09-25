/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:17:36 by akuchina          #+#    #+#             */
/*   Updated: 2018/11/08 13:43:45 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*s1;

	if (!s)
		return (NULL);
	if (!(s1 = (char *)malloc(len + 1)))
		return (NULL);
	i = -1;
	while (++i < len && s[start])
		s1[i] = s[start++];
	s1[i] = '\0';
	return (s1);
}
