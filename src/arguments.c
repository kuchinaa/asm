/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:12:37 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/21 16:12:39 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_evidence_in_arr(t_operation *oper, int arg, int number_arg)
{
	int		i;
	bool	marker;

	i = -1;
	marker = false;
	while (++i < 3)
	{
		if (oper->arr[number_arg][i] == arg)
		{
			marker = true;
			break ;
		}
	}
	if (!marker)
		error_exit("Syntax error");
}

int			check_reg(char *line, t_operation *oper, int arg, int number_arg)
{
	int		value;

	check_evidence_in_arr(oper, arg, number_arg);
	value = ft_atoi(&line[1]);
	if (value < 1 || value > 16)
		error_exit("Syntax error");
	return (ft_intlen((ssize_t)value) + 1);
}

static int	check_point(char *line)
{
	unsigned int	i;
	t_list			*list;
	bool			marker;

	i = 0;
	while (line[i] && line[i] != SEPARATOR_CHAR && line[i] != ' ')
		i++;
	marker = false;
	list = g_head;
	while (list)
	{
		if (((char *)list->content)[0] != ' ')
			if ((!ft_strncmp(line, list->content, i) &&
			i == (ft_strlen(list->content) - 1)) ||
			!ft_strncmp(line, "live", i))
				marker = true;
		list = list->next;
	}
	if (!marker)
		error_exit("Syntax error");
	return (i);
}

int			check_dir(char *line, t_operation *oper, int arg, int number_arg)
{
	check_evidence_in_arr(oper, arg, number_arg);
	if ((line[1] >= '0' && line[1] <= '9') || line[1] == '-')
		return (ft_intlen((ssize_t)ft_atoi(&line[1])) + 1);
	else if (line[1] == LABEL_CHAR)
		return (check_point(&line[2]) + 2);
	else
		error_exit("Syntax error");
	return (0);
}

int			check_ind(char *line, t_operation *oper, int arg, int number_arg)
{
	check_evidence_in_arr(oper, arg, number_arg);
	if ((line[0] >= '1' && line[0] <= '9') || line[0] == '-')
		return (ft_intlen((ssize_t)ft_atoi(&line[0])));
	else if (line[0] == LABEL_CHAR)
		return (check_point(&line[1]) + 1);
	else
		error_exit("Syntax error");
	return (0);
}
