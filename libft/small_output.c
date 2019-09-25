/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:39:28 by vpalamar          #+#    #+#             */
/*   Updated: 2019/04/23 13:39:30 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		diff_width(t_field *f, t_type *v)
{
	if (f->type == 4)
	{
		if (ft_ullintlen(v->unsign) > (size_t)f->precision)
			return (ft_ullintlen(v->unsign));
		else
			return (f->precision);
	}
	else if (f->type == 1 || f->type == 2)
	{
		if (f->flags[1])
			return ((ft_llintlen(v->sign) > (size_t)f->precision + 1)) ?
			ft_llintlen(v->sign) : f->precision + 1;
		else
			return ((ft_llintlen(v->sign) > (size_t)f->precision)) ?
				ft_llintlen(v->sign) : f->precision;
	}
	else if ((f->type == 3 || f->type == 5 || f->type == 6) && v->t_str)
		return (ft_strlen(v->t_str));
	else if (f->type == 9)
		return (ft_strlen(v->t_str) + 2);
	else if (f->type == 10)
		return (f->width - ft_llintlen(v->t_ldouble) + 6);
	return (0);
}

void		print_sign(t_type *v, t_field *f)
{
	if ((f->type == 1 || f->type == 2) &&
		(f->size == 1 || f->size == 2 || f->size == 5
			|| f->size == 6)
		&& v->sign == INTMAX_MIN)
		return ;
	if (f->flags[3] == 1)
	{
		if (v->unsign != 0)
		{
			if (f->type == 3 || f->type == 5 || f->type == 6)
				f->arr[ft_strlen(f->arr)] = ('0');
			if (f->type == 5 || f->type == 6)
				f->arr[ft_strlen(f->arr)] = (f->type == 5) ? 'x' : 'X';
		}
	}
	if (f->type == 1 || f->type == 2)
	{
		if (f->flags[1] == 1 && v->sign >= 0)
			f->arr[ft_strlen(f->arr)] = '+';
		else if (v->sign < 0)
			f->arr[ft_strlen(f->arr)] = '-';
	}
}

static void	print_precision_dio(t_type *v, t_field *f)
{
	ssize_t	len;

	if (f->type == 1 || f->type == 2)
	{
		if (f->flags[0] && f->flags[2] &&
			((f->precision > ft_llintlen(v->sign) && f->width > f->precision) ||
				(!f->flags[5] && v->sign != 0)))
			f->arr[ft_strlen(f->arr)] = ' ';
		f->precision = (v->sign < 0) ? f->precision + 1 : f->precision;
		if ((len = f->precision - ft_llintlen(v->sign)) > 0)
			put_symbol(len, '0', f);
	}
	else if (f->type == 3)
	{
		len = f->precision - ft_strlen(v->t_str);
		if (f->flags[3] && f->flags[5] && v->unsign != 0)
			len--;
		if (len > 0)
			put_symbol(len, '0', f);
	}
}

void		print_precision(t_type *v, t_field *f)
{
	ssize_t	len;

	if (f->type == 1 || f->type == 2 || f->type == 3)
		print_precision_dio(v, f);
	else if (f->type == 5 || f->type == 6)
	{
		len = f->precision - ft_strlen(v->t_str);
		if (len > 0)
			put_symbol(len, '0', f);
	}
	else if ((f->type == 4) &&
		(len = f->precision - ft_ullintlen(v->unsign)) > 0)
		put_symbol(len, '0', f);
	else if (f->type == 9)
	{
		if (!f->flags[4] || f->width < ft_strlen(v->t_str))
		{
			f->arr[ft_strlen(f->arr)] = '0';
			f->arr[ft_strlen(f->arr)] = 'x';
		}
		if ((len = f->precision - (ft_strlen(v->t_str))) > 0)
			put_symbol(len, '0', f);
	}
}
