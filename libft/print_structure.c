/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:33:59 by vpalamar          #+#    #+#             */
/*   Updated: 2019/04/26 18:34:01 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	no_flag_minus(t_type *v, t_field *f)
{
	if (((f->type == 1 || f->type == 2) && f->flags[4] &&
		(f->width > ft_llintlen(v->sign) && !f->flags[5])) ||
		((f->type == 5 || f->type == 6) && f->width > ft_strlen(v->t_str)
			&& f->flags[4] && !f->flags[5]))
	{
		print_sign(v, f);
		print_flag_minus(v, f);
		print_value(v, f);
	}
	else
	{
		print_flag_minus(v, f);
		print_sign(v, f);
		print_value(v, f);
	}
}

static void	print_else(t_type *v, t_field *f)
{
	if ((f->type == 1 || f->type == 2) && (f->flags[3] || f->flags[5]) &&
		!f->flags[1] && f->width == 0)
	{
		print_sign(v, f);
		print_flag_minus(v, f);
		print_value(v, f);
	}
	else
	{
		print_sign(v, f);
		print_value(v, f);
		print_flag_minus(v, f);
	}
}

void		print_structure(va_list args, t_field *f)
{
	t_type	v;

	check_arr(f);
	get(args, &v, f);
	if (((f->flags[4] && !f->flags[0]) ||
		(f->flags[2] && f->flags[0] &&
		((f->type == 5 || f->type == 6) && f->width < ft_strlen(v.t_str))))
		&& f->type != 7 && !f->flags[3] && (f->width <= f->precision ||
			!f->flags[5]))
	{
		print_sign(&v, f);
		print_flag_minus(&v, f);
		print_value(&v, f);
	}
	else if (!f->flags[0])
		no_flag_minus(&v, f);
	else
		print_else(&v, f);
	if (f->type == 3 || f->type == 5 || f->type == 6 || f->type == 9)
		free(v.t_str);
}
