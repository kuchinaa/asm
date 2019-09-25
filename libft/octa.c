/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:39:14 by vpalamar          #+#    #+#             */
/*   Updated: 2019/04/23 13:39:16 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_octa_len(size_t n)
{
	size_t	len_v;

	len_v = 0;
	while (n > 0)
	{
		len_v++;
		n /= 8;
	}
	return (len_v);
}

char		*ft_octa(size_t n, t_field *field)
{
	char	*res;
	size_t	tmp;
	size_t	i;

	tmp = n;
	if (n == 0)
	{
		res = ft_strnew(1);
		res[0] = (field->flags[5] && field->precision == 0 && !field->flags[3])
		? ' ' : '0';
		return (res);
	}
	i = 0;
	res = ft_strnew(ft_octa_len(n));
	while (tmp > 0)
	{
		res[i++] = '0' + tmp % 8;
		tmp /= 8;
	}
	res[i] = '\0';
	return ((ft_strlen(res) > 1) ? ft_strrev(res) : res);
}

static char	*put_hex(char *res, size_t i, size_t n, t_field *field)
{
	while (n > 0)
	{
		if ((n % 16) >= 10 && (n % 16) <= 16)
		{
			if (field->type == 5 || field->type == 9)
				res[i] = 'a' + (n % 16) - 10;
			else if (field->type == 6)
				res[i] = 'A' + (n % 16) - 10;
		}
		else
			res[i] = (n % 16) + '0';
		n /= 16;
		i++;
	}
	if (i > 0)
		res[i] = '\0';
	return (res);
}

char		*ft_hex(size_t n, t_field *field)
{
	char	*res;
	size_t	tmp;
	size_t	i;

	i = 0;
	tmp = n;
	while (tmp > 0 && i++)
		tmp /= 16;
	res = ft_strnew(i);
	i = 0;
	if (n == 0)
	{
		if (field->flags[5] && field->precision == 0 && field->width > 0)
			res[i] = ' ';
		else if (!field->flags[5])
			res[i] = '0';
	}
	res = put_hex(res, i, n, field);
	return ((ft_strlen(res) > 1) ? ft_strrev(res) : res);
}
