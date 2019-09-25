/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:50:36 by akuchina          #+#    #+#             */
/*   Updated: 2019/09/25 14:11:40 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_code_type(int fd, char **param, uint8_t args)
{
	uint8_t	code;
	int		i;
	int		d;

	code = 0;
	d = 2;
	i = args - 1;
	while (i >= 0)
	{
		if (param[i][0] == DIRECT_CHAR)
			code |= DIR_CODE << d;
		else if (param[i][0] == 'r')
			code |= REG_CODE << d;
		else
			code |= IND_CODE << d;
		i--;
		d += 2;
	}
	write(fd, (char *)&code, 1);
}

uint8_t	find_marker(t_list *list, char *name_m)
{
	while (list)
	{
		if (!ft_strcmp(GET_MARK(list)->marker, name_m))
			return (GET_MARK(list)->size);
		list = list->next;
	}
	return (0);
}

void	write_with_size(t_asm *all, uint8_t *result, uint32_t code,
		uint8_t size)
{
	uint16_t	val16;

	if (size == 4)
		while (size--)
			*result++ = (uint8_t)(code >> (size * 8));
	else
	{
		val16 = (uint16_t)code;
		while (size--)
			*result++ = (uint8_t)(val16 >> (size * 8));
	}
}

void	write_param(t_asm *all, char *param, uint8_t size, int flag)
{
	uint32_t	code;
	uint8_t		*result;
	uint8_t		res_size;

	if (param[0] == 'r' || ft_isdigit(param[0]) ||
		(param[0] == DIRECT_CHAR && param[1] != LABEL_CHAR))
		code = ft_atoi((char *)(param + 1));
	else
		code = find_marker(all->markers, (char *)(param + 2)) - size;
	if (param[0] == 'r')
		res_size = T_REG;
	else if (param[0] == DIRECT_CHAR)
		res_size = (flag) ? T_DIR : T_IND;
	else
		res_size = T_IND;
	result = malloc(res_size);
	write_with_size(all, result, code, res_size);
	write(all->fd, result, res_size);
	free(result);
}

void	add_champion_code(t_asm *all)
{
	t_command	*comm;
	t_list		*l;
	uint8_t		size;
	int			i;

	l = all->command_start;
	size = 0;
	while (l)
	{
		comm = GET_COMM(l);
		write(all->fd, (char *)&g_op_tab[comm->command].index, 1);
		if (g_op_tab[comm->command].type_code)
			write_code_type(all->fd, comm->param,
					g_op_tab[comm->command].count_of_arg);
		i = -1;
		while (comm->param[++i])
			write_param(all, comm->param[i], size,
					g_op_tab[comm->command].dir_ind);
		size += comm->size;
		l = l->next;
	}
}
