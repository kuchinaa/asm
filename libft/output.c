/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:39:22 by vpalamar          #+#    #+#             */
/*   Updated: 2019/04/23 13:39:23 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		put_symbol(ssize_t num, char c, t_field *field)
{
	size_t	i;

	if (c == 0)
		c = (field->flags[4] && !field->flags[0]) ? '0' : ' ';
	if ((field->type == 1 || field->type == 2) && c == 0)
		c = (field->flags[4] && !field->flags[0]) ? '0' : ' ';
	if (field->type == 3 && field->flags[5] && field->precision == 0)
		c = ' ';
	if (field->type == 4 && field->flags[5] && field->precision == 0)
		c = ' ';
	i = ft_strlen(field->arr);
	if ((field->type == 5 || field->type == 6) && field->flags[3]
		&& !field->flags[5])
		num -= 2;
	if ((field->type == 5 || field->type == 6) && field->flags[5]
		&& field->precision == 0)
		c = ' ';
	if (c == '0' || (field->width > field->precision) || field->type == 1
		|| field->type == 2 || field->type == 8 || field->type == 7)
		while (num-- > 0)
			field->arr[i++] = c;
}

void		str_in_arr(char *s, t_field *field)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(field->arr);
	i = 0;
	while (s[i] && len + i < field->buff_size)
	{
		field->arr[len + i] = s[i];
		i++;
	}
}

static void	print_value_di(t_type *value_type, t_field *field)
{
	if (field->flags[2] && field->flags[0] &&
		((value_type->sign != 0 && (field->flags[5] &&
			field->precision <= ft_llintlen(value_type->sign))) ||
		(value_type->sign == 0 && !field->flags[5])))
		field->arr[ft_strlen(field->arr)] = ' ';
	if (value_type->sign != 0)
		ft_putlonglong(value_type->sign, field);
	else if (field->flags[5] && field->precision == 0)
	{
		if (field->width > 0)
			field->arr[ft_strlen(field->arr)] = ' ';
	}
	else
		field->arr[ft_strlen(field->arr)] = '0';
}

static void	print_value_xxosp(t_type *value_type, t_field *field)
{
	int	tmp_precision;

	if (field->type == 9)
		str_in_arr(value_type->t_str, field);
	else if (field->type == 3)
	{
		if (field->flags[5] && field->precision == 0 &&
			field->width == 0 && !field->flags[3])
			return ;
		str_in_arr(value_type->t_str, field);
	}
	else if (field->type == 5 || field->type == 6)
		str_in_arr(value_type->t_str, field);
	else if (field->type == 8)
	{
		if (field->flags[5] == 1)
		{
			tmp_precision = field->precision;
			if (field->precision > 0)
				while (tmp_precision-- > 0 && ft_strlen(value_type->t_str) > 0)
					field->arr[ft_strlen(field->arr)] = *(value_type->t_str)++;
		}
		else
			str_in_arr(value_type->t_str, field);
	}
}

void		print_value(t_type *value_type, t_field *field)
{
	print_precision(value_type, field);
	if (field->type == 1 || field->type == 2)
		print_value_di(value_type, field);
	else if (field->type == 4)
		ft_putulonglong(value_type->unsign, field);
	else if (field->type == 7)
	{
		if (!value_type->t_char)
			field->is_null = 1;
		else
			field->arr[ft_strlen(field->arr)] = (char)value_type->t_char;
	}
	else if (field->type == 3 || field->type == 5 || field->type == 6 ||
			field->type == 8 || field->type == 9)
		print_value_xxosp(value_type, field);
	else if (field->type == 10)
		ft_putdouble(value_type->t_ldouble, field);
}
