/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:59:55 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/21 19:20:22 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_amount(char *line, t_operation *oper)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (line[++i])
		if (line[i] == SEPARATOR_CHAR)
			count++;
	if (oper->num_arg != count + 1)
		error_exit("Syntax error");
}

void	check_argument(char *line, t_operation *oper, int number_arg)
{
	int	i;

	check_amount(line, oper);
	i = ft_strlen(oper->name);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != SEPARATOR_CHAR)
		{
			if (line[i] == 'r')
				i += check_reg(&line[i], oper, 1, number_arg);
			else if (line[i] == DIRECT_CHAR)
				i += check_dir(&line[i], oper, 2, number_arg);
			else if (line[i] == LABEL_CHAR ||
			(line[i] >= '1' && line[i] <= '9') || line[i] == '-')
				i += check_ind(&line[i], oper, 3, number_arg);
			else
				error_exit("Syntax error");
			number_arg++;
			continue ;
		}
		i++;
	}
}

void	check_command(char *line, t_operation *oper)
{
	bool			correct;
	unsigned int	len;

	len = 0;
	while (line[len] && line[len] != ' ' && line[len] != DIRECT_CHAR)
		len++;
	correct = false;
	while (oper)
	{
		if (!ft_strncmp(oper->name, line, len) && len == ft_strlen(oper->name))
		{
			correct = true;
			break ;
		}
		oper = oper->next;
	}
	if (!correct || (correct && line[len] != ' ' && line[len] != DIRECT_CHAR))
		error_exit("Invalid instruction");
	check_argument(line, oper, 0);
}

void	operations(t_list *list)
{
	t_operation	*operation;
	char		*line;

	operation = parse_operation(NULL);
	while (list)
	{
		line = list->content;
		if (line[0] == ' ')
			check_command(&line[1], operation);
		list = list->next;
	}
}
/*
**print_operations
**list = NULL;
**while (operation)
**{
**printf(GREEN"name = %s\n"RESET, operation->name);
**for (int k = 0; k < 3; k++)
**{
**for (int l = 0; l < 3; l++)
**printf("%d ", operation->arr[k][l]);
**printf("\n");
**}
**operation = operation->next;
**}
*/
