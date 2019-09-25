/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:02:07 by akuchina          #+#    #+#             */
/*   Updated: 2019/02/07 11:55:49 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_of(__int128 n, int base)
{
	unsigned int	i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(__int128 n, int base, char *tab)
{
	unsigned int	i;
	__int128		sign;
	char			*s;

	if (!(s = (char *)malloc(count_of(n, base) + 1)))
		return (NULL);
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	s[i++] = tab[n % base];
	while ((n /= base) > 0)
		s[i++] = tab[n % base];
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	s = ft_strrev(s);
	return (s);
}
