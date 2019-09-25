/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:37:54 by vpalamar          #+#    #+#             */
/*   Updated: 2019/04/23 13:37:56 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		detection(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
		|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
		|| c == 'f')
		return (1);
	else if (c == '+' || c == '-' || c == '#' || c == '0' || c == ' ')
		return (2);
	else if ((c != 'c' && c != 's' && c != 'S' && c != 'p' && c != 'd'
		&& c != 'D' && c != 'i' && c != 'a' && c != 'A' && c != 'e' && c != 'E'
		&& c != 'g' && c != 'G' && c != 'o' && c != 'O' && c != 'u' && c != 'U'
		&& c != 'x' && c != 'X' && c != 'f' && c != '.'
		&& !(c >= '0' && c <= '9') && c != 'l' && c != 'h' && c != 'j'
		&& c != 'z' && c != '%' && c != 'n' && c != 'F' && c != '*'))
		return (3);
	else if (c == '.')
		return (4);
	else if (c >= '0' && c <= '9')
		return (5);
	else if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (6);
	return (0);
}

void	clear_field(t_field *field)
{
	field->flags[0] = 0;
	field->flags[1] = 0;
	field->flags[2] = 0;
	field->flags[3] = 0;
	field->flags[4] = 0;
	field->flags[5] = 0;
	field->width = 0;
	field->precision = 0;
	field->size = 0;
	field->type = 0;
	field->is_null = 0;
	field->c = 0;
}

void	clear_type(t_type *type)
{
	type->t_str = NULL;
	type->unsign = 0;
	type->sign = 0;
	type->t_char = (char)0;
	type->t_ldouble = 0;
	type->t_void = (void *)0;
}

void	increase_arr(size_t len, t_field *field)
{
	char	*new_arr;
	size_t	i;

	new_arr = ft_strnew(field->buff_size + len);
	field->buff_size += len;
	i = 0;
	while (field->arr[i])
	{
		new_arr[i] = field->arr[i];
		i++;
	}
	ft_strdel(&field->arr);
	field->arr = new_arr;
}

void	check_arr(t_field *f)
{
	size_t	wid_prec;

	wid_prec = (f->width > f->precision) ? f->width : f->precision;
	wid_prec = (wid_prec < 100) ? 100 : wid_prec;
	if (f->buff_size - ft_strlen(f->arr) < wid_prec)
		increase_arr(wid_prec + 1, f);
}
