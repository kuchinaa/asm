/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:34:15 by vpalamar          #+#    #+#             */
/*   Updated: 2019/04/26 18:34:16 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	flag_minus_di(t_type *v, t_field *f, ssize_t diff)
{
	size_t	len;

	len = (v->sign > 0 && f->flags[1]) ?
		ft_llintlen(v->sign) + 1 : ft_llintlen(v->sign);
	if (ft_llintlen(v->sign) > f->precision)
		diff = f->width - len;
	else
		diff = f->width - f->precision;
	if (f->flags[1] &&
	((v->sign >= 0 && (!f->flags[3] || !f->flags[2])) ||
	(v->sign < 0 && !f->flags[0] && f->precision >= len)) &&
	f->flags[5] && f->precision >= ft_llintlen(v->sign))
		diff--;
	diff = (f->flags[1] && v->sign == 0) ? diff - 1 : diff;
	diff = (diff < 0 && f->flags[2]) ? 1 : diff;
	if (f->flags[2] &&
		(((v->sign == 0 && (!f->flags[0] || (f->flags[5] && f->width == 0)))) ||
		(v->sign != 0 && !f->flags[0])))
		f->arr[ft_strlen(f->arr)] = ' ';
	diff = (f->flags[2]) ? diff - 1 : diff;
	if (f->flags[4] && f->width > f->precision && f->flags[5]
		&& v->sign >= 0 && diff > 0)
		put_symbol(diff, ' ', f);
	else if (diff > 0)
		put_symbol(diff, 0, f);
}

static void	flag_minus_o(t_type *v, t_field *f, ssize_t diff)
{
	if (f->width > f->precision)
	{
		if (f->precision > ft_strlen(v->t_str))
			diff = f->width - f->precision;
	}
	if (f->flags[3] && v->unsign != 0 && (!f->flags[5] ||
		f->precision <= ft_strlen(v->t_str)))
		diff--;
	put_symbol(diff, 0, f);
}

static void	flag_minus_x(t_type *v, t_field *f, ssize_t diff)
{
	if ((f->type == 5 || f->type == 6) && f->width > f->precision)
		if (f->precision > ft_strlen(v->t_str))
			diff = f->width - f->precision;
	if ((f->type == 5 || f->type == 6) &&
		f->flags[3] && v->unsign == 0 && (!f->flags[0] || !f->flags[5]))
		diff += 2;
	if ((f->type == 5 || f->type == 6) && f->flags[3] && v->unsign != 0
		&& f->flags[5])
		diff -= 2;
	put_symbol(diff, 0, f);
}

static void	flag_minus_s(t_type *v, t_field *f)
{
	ssize_t	diff;

	diff = f->width - ft_strlen(v->t_str);
	if (f->flags[5] && f->precision < ft_strlen(v->t_str))
		diff = f->width - f->precision;
	if (f->flags[0] && f->flags[5] && f->precision > 2)
		diff--;
	put_symbol(diff, 0, f);
}

void		print_flag_minus(t_type *v, t_field *f)
{
	ssize_t	diff;

	diff = ((ssize_t)f->width > diff_width(f, v)) ?
	f->width - diff_width(f, v) : 0;
	if ((f->type >= 1 && f->type <= 2))
		flag_minus_di(v, f, diff);
	else if (f->type == 3)
		flag_minus_o(v, f, diff);
	else if (f->type == 4)
		put_symbol(diff, 0, f);
	else if (f->type == 5 || f->type == 6)
		flag_minus_x(v, f, diff);
	else if (f->type == 7 && f->width > 1)
		put_symbol(f->width - 1, 0, f);
	else if (f->type == 9 && diff > 0)
	{
		if (f->flags[4] && f->width > ft_strlen(v->t_str))
		{
			f->arr[ft_strlen(f->arr)] = '0';
			f->arr[ft_strlen(f->arr)] = 'x';
		}
		put_symbol(diff, 0, f);
	}
	else if (f->type == 8)
		flag_minus_s(v, f);
}
