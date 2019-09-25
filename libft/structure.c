/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:39:35 by vpalamar          #+#    #+#             */
/*   Updated: 2019/04/23 13:39:36 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_flags(const char *format, t_field *field)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '-')
			field->flags[0] = 1;
		else if (format[i] == '+')
			field->flags[1] = 1;
		else if (format[i] == ' ')
			field->flags[2] = 1;
		else if (format[i] == '#')
			field->flags[3] = 1;
		else if (format[i] == '0')
			field->flags[4] = 1;
		else
			break ;
		i++;
	}
	return (i);
}

int			ft_width_precision(const char *format, va_list args, t_field *field)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	if (format[-1] == '.')
		field->flags[5] = 1;
	if (format[i] == '*')
		res = (int)va_arg(args, int);
	else
	{
		while (format[i] && (format[i] >= '0' && format[i] <= '9'))
			res = res * 10 + (format[i++] - '0');
	}
	if (format[-1] == '.')
	{
		field->precision = res;
	}
	else
		field->width = res;
	return (i);
}

static void	ft_size_1356(int i, const char *c, t_field *field)
{
	field->size = (c[0] == 'l' || c[0] == 'h') ? 1 : field->size;
	if (i == 1 || i == 3)
	{
		if (i == 3)
		{
			if (c[0] == c[-1] && c[-1] == c[-2] && c[0] == 'h')
				field->size = 3;
			else
				field->size = 1;
		}
		else
			field->size = (c[0] == 'h') ? 3 : field->size;
	}
	field->size = (c[0] == 'j') ? 5 : field->size;
	field->size = (c[0] == 'z') ? 6 : field->size;
}

int			ft_size(const char *format, t_field *field)
{
	int	i;

	i = 0;
	while (format[i] && (format[i] == 'l' || format[i] == 'h' ||
		format[i] == 'j' || format[i] == 'z'))
		i++;
	if (i > 2)
		ft_size_1356(i, &format[2], field);
	else if (i == 2)
		if (format[0] == format[1])
		{
			field->size = (format[1] == 'l') ? 2 : field->size;
			field->size = (format[1] == 'h') ? 4 : field->size;
			field->size = (format[1] == 'j') ? 5 : field->size;
			field->size = (format[1] == 'z') ? 6 : field->size;
		}
		else
			ft_size_1356(i, &format[1], field);
	else if (i == 1)
		ft_size_1356(i, &format[0], field);
	return (i);
}

void		ft_type(char c, t_field *field)
{
	if (c == 'd' || c == 'D')
	{
		field->size = (c == 'D') ? 2 : field->size;
		field->type = 1;
	}
	else if (c == 'o' || c == 'O')
	{
		if (c == 'O')
			field->size = 1;
		field->type = 3;
	}
	else if (c == 'u' || c == 'U')
	{
		if (c == 'U')
			field->size = 1;
		field->type = 4;
	}
	field->type = (c == 'i') ? 2 : field->type;
	field->type = (c == 'x') ? 5 : field->type;
	field->type = (c == 'X') ? 6 : field->type;
	field->type = (c == 'c') ? 7 : field->type;
	field->type = (c == 's') ? 8 : field->type;
	field->type = (c == 'p') ? 9 : field->type;
	field->type = (c == 'f') ? 10 : field->type;
	field->type = (c == '%') ? 11 : field->type;
}
