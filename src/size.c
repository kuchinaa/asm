/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:45:57 by akuchina          #+#    #+#             */
/*   Updated: 2019/09/25 14:13:32 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned int	take_param(char *param, unsigned int size, t_asm *all)
{
	char			*label_char;
	unsigned int	code;

	code = 0;
	if (param[0] == 'r' || (param[0] == DIRECT_CHAR && param[1] != LABEL_CHAR))
		code = ft_atoi((char *)(param + 1));
	else if (ft_isdigit(param[0]) || param[0] == '-')
		code = ft_atoi((char *)(param));
	else if ((label_char = ft_strchr((char *)param, LABEL_CHAR)))
		code = find_marker(all->markers, (char *)(label_char + 1)) - size;
	return (code);
}

int				find_command(char *name)
{
	int		i;

	i = -1;
	while (++i < 17)
		if (!ft_strcmp(g_op_tab[i].name, name))
			return (i);
	return (-1);
}

uint8_t			command_size(t_command *comm)
{
	unsigned int	i;
	uint8_t			size;

	size = 1 + g_op_tab[comm->command].type_code;
	i = -1;
	while (comm->param[++i])
	{
		if (comm->param[i][0] == 'r')
			size += 1;
		else if (comm->param[i][0] == DIRECT_CHAR)
			size += (!g_op_tab[comm->command].dir_ind) ? 4 : 2;
		else
			size += 2;
	}
	return (size);
}

t_command		*command_add(char *command_line)
{
	t_command		*comm;
	uint8_t			size;
	char			*second_space;

	comm = (t_command *)malloc(sizeof(t_command));
	second_space = ft_strchr((char *)(command_line + 1), ' ');
	size = 1;
	while (command_line[size] != ' ')
		size++;
	size--;
	comm->name = ft_strduplen((char *)(command_line + 1), size - 1);
	comm->param = ft_strsplit((char *)(second_space + 1), SEPARATOR_CHAR);
	comm->command = find_command(comm->name);
	return (comm);
}

void			add_marker(t_asm *all, t_list *list)
{
	t_marker		*mark;
	t_command		*comm;

	while (list)
	{
		if (((char *)(list->content))[0] != ' ')
		{
			mark = (t_marker *)malloc(sizeof(t_marker));
			mark->marker = ft_strduplen(list->content,
					ft_strlen((char *)(list->content)) - 2);
			mark->size = g_header.prog_size;
			ft_lstadd(&(all->markers), ft_lstnew(mark, sizeof(t_marker)));
			free(mark);
		}
		else
		{
			comm = command_add(list->content);
			comm->size = command_size(comm);
			g_header.prog_size += comm->size;
			ft_lstpush(&all->command_start, &all->command_end,
					ft_lstnew(comm, sizeof(t_command)));
			free(comm);
		}
		list = list->next;
	}
}
