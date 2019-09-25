/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:49:44 by akuchina          #+#    #+#             */
/*   Updated: 2018/11/20 09:12:32 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_of(int n)
{
	int	i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*s;

	if (n == -2147483648)
		return (ft_strduplen("-2147483648", 11));
	if (!(s = (char *)malloc(count_of(n) + 1)))
		return (NULL);
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	s[i++] = n % 10 + '0';
	while ((n /= 10) > 0)
		s[i++] = n % 10 + '0';
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	s = ft_strrev(s);
	return (s);
}
