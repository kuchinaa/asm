/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonglong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:38:55 by vpalamar          #+#    #+#             */
/*   Updated: 2019/04/23 13:38:56 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putlonglong(ssize_t n, t_field *f)
{
	size_t	div;
	int		i;
	char	rez;

	i = 1;
	div = 1;
	if (n < 0)
		n *= (-1);
	while (n / (div * 10) != 0)
	{
		div *= 10;
		i++;
	}
	if (n < 0)
	{
		f->arr[ft_strlen(f->arr)] = '-';
		n *= (-1);
	}
	while (i-- > 0)
	{
		rez = n / div % 10 + '0';
		f->arr[ft_strlen(f->arr)] = rez;
		div /= 10;
	}
}

static int	ft_putulonglong_exit(t_field *f)
{
	if (f->type == 4 && f->flags[5] && f->precision == 0 && f->width == 0)
		return (1);
	if ((f->type == 3 && f->flags[5] && f->precision == 0 &&
		(!f->flags[3] || f->flags[4])))
	{
		if (f->width > 0)
			f->arr[ft_strlen(f->arr)] = ' ';
		return (1);
	}
	return (0);
}

void		ft_putulonglong(size_t n, t_field *f)
{
	ssize_t		i;
	char		*res;
	uintmax_t	tmp;

	if (ft_putulonglong_exit(f) == 1)
		return ;
	i = 0;
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	res = ft_strnew(i);
	i--;
	f->arr[ft_strlen(f->arr)] = (n == 0) ? '0' : f->arr[ft_strlen(f->arr)];
	while (i >= 0)
	{
		res[i--] = '0' + n % 10;
		n /= 10;
	}
	i = 0;
	while (res[i])
		f->arr[ft_strlen(f->arr)] = res[i++];
	ft_strdel(&res);
}

size_t		ft_llintlen(ssize_t nb)
{
	size_t		i;

	i = 0;
	if (nb < 0)
	{
		nb *= (-1);
		i++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

size_t		ft_ullintlen(size_t nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
