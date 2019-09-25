/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:38:37 by vpalamar          #+#    #+#             */
/*   Updated: 2019/04/23 13:38:43 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_after_dot(size_t tmp, long double n, long long div, t_field *f)
{
	size_t		res;

	res = (n * div / 10) - (tmp * div / 10);
	if (f->precision - ft_llintlen(res) == 1)
		put_symbol(1, '0', f);
	if ((int)(n * div) % 10 >= 5)
		ft_putlonglong(res + 1, f);
	else
		ft_putlonglong(res, f);
	if ((int)(n * div) == (int)(tmp * div))
		while (f->precision-- - 1 > 0)
		{
			ft_putlonglong((n * div) - (tmp * div), f);
			div /= 10;
		}
	if ((size_t)f->precision > ft_llintlen(res))
		put_symbol(f->precision - ft_llintlen(res), '0', f);
}

void		ft_putdouble(long double n, t_field *f)
{
	long long	div;
	long long	i;
	size_t		tmp;
	long double tmp_precision;

	tmp = n;
	div = 1;
	if (n < 0 && (i = 0) == 0)
	{
		f->arr[ft_strlen(f->arr)] = '-';
		n *= (-1);
	}
	if (f->flags[5] == 1 && (int)(n * 10) % 10 >= 5)
		ft_putlonglong(tmp + 1, f);
	else
		ft_putlonglong(tmp, f);
	if (f->flags[5] == 1 && f->precision == 0)
		return ;
	f->precision = (f->flags[5] == 0) ? 6 : f->precision;
	f->arr[ft_strlen(f->arr)] = (f->flags[5] != 1 &&
		f->precision != 0) ? '.' : '\0';
	tmp_precision = f->precision;
	while (tmp_precision-- + 1 > 0 && i++ < 17)
		div *= 10;
	put_after_dot(tmp, n, div, f);
}
