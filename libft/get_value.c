/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:39:04 by vpalamar          #+#    #+#             */
/*   Updated: 2019/04/23 13:39:06 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_value_unsign(va_list args, t_type *v, t_field *f)
{
	v->unsign = (f->size == 0) ? va_arg(args, unsigned int) : v->unsign;
	v->unsign = (f->size == 1) ? va_arg(args, unsigned long int) : v->unsign;
	v->unsign = (f->size == 2) ? va_arg(args, unsigned long long) : v->unsign;
	v->unsign = (f->size == 3) ? (unsigned short)va_arg(args, int) : v->unsign;
	v->unsign = (f->size == 4) ? (unsigned char)va_arg(args, int) : v->unsign;
	v->unsign = (f->size == 5) ? va_arg(args, uintmax_t) : v->unsign;
	v->unsign = (f->size == 6) ? va_arg(args, size_t) : v->unsign;
}

void	get_value_sign(va_list args, t_type *v, t_field *f)
{
	v->sign = (f->size == 0) ? va_arg(args, int) : v->sign;
	v->sign = (f->size == 1) ? va_arg(args, long int) : v->sign;
	v->sign = (f->size == 2) ? va_arg(args, long long int) : v->sign;
	v->sign = (f->size == 3) ? (short int)va_arg(args, int) : v->sign;
	v->sign = (f->size == 4) ? (signed char)va_arg(args, int) : v->sign;
	v->sign = (f->size == 5) ? va_arg(args, intmax_t) : v->sign;
	v->sign = (f->size == 6) ? va_arg(args, ssize_t) : v->sign;
}

void	get_value(va_list args, t_type *v, t_field *f)
{
	if (f->type >= 1 && f->type <= 6)
	{
		if (f->type >= 3 && f->type <= 6)
			get_value_unsign(args, v, f);
		else
			get_value_sign(args, v, f);
	}
	else if (f->type == 7)
		v->t_char = (char)va_arg(args, int);
	else if (f->type == 8)
		v->t_str = (char *)va_arg(args, char *);
	else if (f->type == 9)
		v->unsign = (unsigned long int)va_arg(args, long unsigned int);
	else if (f->type == 10)
	{
		if (f->size == 0 || f->size == 1)
			v->t_ldouble = (double)va_arg(args, double);
		else if (f->size == 5)
			v->t_ldouble = (long double)va_arg(args, double);
	}
	else if (f->type == 11)
	{
		f->type = 7;
		v->t_char = '%';
	}
}

void	get(va_list args, t_type *v, t_field *f)
{
	clear_type(v);
	get_value(args, v, f);
	if (f->type == 8 && !v->t_str)
		v->t_str = "(null)";
	v->t_str = (f->type == 3) ? ft_octa(v->unsign, f) : v->t_str;
	v->t_str = (f->type == 5 || f->type == 6 || f->type == 9) ?
		ft_hex(v->unsign, f) : v->t_str;
	f->flags[1] = ((f->type == 1 || f->type == 2) &&
		v->sign < 0) ? 1 : f->flags[1];
	f->flags[2] = (f->flags[1]) ? 0 : f->flags[2];
	if (f->type != 8 && f->type != 7 && f->type != 1 && f->type != 2)
		f->flags[4] = ((f->precision != 0 || f->flags[0] == 1 ||
			f->type == 7)) ? 0 : f->flags[4];
	if (f->type == 0 && f->c)
	{
		v->t_char = f->c;
		f->type = 7;
	}
}
