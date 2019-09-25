/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:53:15 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/19 18:17:00 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_atoi(const char *tmp)
{
	unsigned long long	rez;
	int					sign;

	rez = 0;
	sign = 1;
	while (*tmp == ' ' || *tmp == '\n' || *tmp == '\r' || *tmp == '\v' ||
			*tmp == '\t' || *tmp == '\f')
		tmp++;
	if (*tmp == '+' || *tmp == '-')
		if (*tmp++ == '-')
			sign = -1;
	while (*tmp && (*tmp >= '0' && *tmp <= '9'))
	{
		rez = rez * 10 + (*tmp++ - '0');
		if (rez >= 9223372036854775808uLL)
			return (sign == -1) ? 0 : (-1);
	}
	return (rez * sign);
}
