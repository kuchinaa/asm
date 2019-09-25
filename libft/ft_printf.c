/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:38:09 by vpalamar          #+#    #+#             */
/*   Updated: 2019/04/23 13:38:12 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_percent(size_t detect, char c, t_field *f)
{
	if (detect == 3)
		f->c = c;
	ft_type(c, f);
}

int			fill_structure(const char *form, va_list args, t_field *f)
{
	int		i;
	size_t	detect;

	clear_field(f);
	i = 0;
	while (form[i])
	{
		detect = detection(form[i]);
		if (detect == 2)
			i += ft_flags(&form[i], f);
		else if (detect == 4)
			i += ft_width_precision(&form[i + 1], args, f) + 1;
		else if (f->width == 0 && (form[i] == '*' || detect == 5))
			i += ft_width_precision(&form[i], args, f);
		else if (detect == 6)
			i += ft_size(&form[i], f);
		else if (detect == 1 || detect == 3 || form[i] == '%')
		{
			fill_percent(detect, form[i], f);
			break ;
		}
		else
			i++;
	}
	return (i + 1);
}

static int	manage_is_null(size_t res, t_field *f)
{
	if (f->flags[0] && f->width > 0)
	{
		ft_putchar(0);
		ft_putstr(f->arr);
		res += ft_strlen(f->arr) + 1;
		ft_bzero(f->arr, f->buff_size);
	}
	else
	{
		ft_putstr(f->arr);
		res += ft_strlen(f->arr) + 1;
		ft_bzero(f->arr, f->buff_size);
		ft_putchar(0);
	}
	return (res);
}

int			manage(const char *form, va_list a, int *i, t_field *f)
{
	size_t	res;

	res = 0;
	while (form[i[0]])
	{
		if (ft_strlen(f->arr) > f->buff_size && (i[1] = 1) == 1)
		{
			increase_arr(100, f);
		}
		if (form[i[0]] == '%')
		{
			if (!form[++i[0]])
				return (0);
			i[0] += ((i[1] = fill_structure(&form[i[0]], a, f)) > 0) ? i[1] : 1;
			print_structure(a, f);
			if (f->is_null && !(ft_strlen(f->arr) == 1 && f->arr[0] == '%'))
				res += manage_is_null(res, f);
			continue;
		}
		f->arr[ft_strlen(f->arr)] = form[i[0]++];
	}
	return (res);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_field		field;
	int			res;
	int			ij[2];

	ij[0] = 0;
	ij[1] = 0;
	va_start(args, format);
	field.buff_size = 200;
	field.arr = ft_strnew(field.buff_size);
	res = manage(format, args, ij, &field);
	ft_putstr(field.arr);
	res += ft_strlen(field.arr);
	ft_strdel(&field.arr);
	free(field.arr);
	va_end(args);
	return (res);
}
