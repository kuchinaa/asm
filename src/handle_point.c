/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:18:14 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/21 19:21:58 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_valid_point(char *line)
{
	int		i;
	int		j;
	bool	correct;

	i = 0;
	while (line[i] && line[i] != LABEL_CHAR)
	{
		correct = false;
		j = -1;
		while (LABEL_CHARS[++j])
			if (line[i] == LABEL_CHARS[j])
			{
				correct = true;
				break ;
			}
		if (correct == false)
			error_exit("Lexical error");
		i++;
	}
}

static void	check_valid_point_in_operation(char *line)
{
	int		i;
	int		j;
	bool	correct;

	i = -1;
	while (line[++i] && line[i] == SEPARATOR_CHAR)
	{
		correct = false;
		j = -1;
		while (LABEL_CHARS[++j])
		{
			if (line[i] == LABEL_CHARS[j])
			{
				correct = true;
				break ;
			}
		}
		if (correct == false)
			error_exit("Lexical error");
	}
}

bool		handle_point(t_list *list, char *line, int i, bool marker)
{
	while (line[++i])
		if (line[i] == LABEL_CHAR)
		{
			if (i == 0)
				error_exit("Lexical error");
			else if (line[i - 1] != DIRECT_CHAR &&
			line[i - 1] != ' ' && line[i - 1] != SEPARATOR_CHAR)
			{
				check_valid_point(line);
				marker = true;
				break ;
			}
			else if (line[i - 1] == DIRECT_CHAR &&
			line[i - 1] == ' ' && line[i - 1] == SEPARATOR_CHAR)
				check_valid_point_in_operation(&line[i + 1]);
		}
	if (marker != true || !line[i + 1])
		return (false);
	list = list_insert(list, ft_strdup(&line[i + 1]));
	line[i + 1] = '\0';
	return (true);
}
