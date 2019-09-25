/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:31:57 by akuchina          #+#    #+#             */
/*   Updated: 2019/09/13 14:21:18 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = -1;
	if (n == 0)
		return (0);
	while (s1[++i] && s2[i] && s1[i] == s2[i] && (size_t)i < n - 1)
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
