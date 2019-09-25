/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:49:08 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/21 19:41:21 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_exit(char *line)
{
	ft_printf(RED"%s\n"RESET, line);
	exit(1);
}

bool	delete_empty_lines(char *line)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			counter++;
		i++;
	}
	return ((counter) ? false : true);
}

int		parse2(t_list *list)
{
	if (delete_empty_lines(list->content))
		return (1);
	delete_comment(list->content);
	delete_tabs(list->content);
	delete_spaces(list->content);
	if (!ft_strlen(list->content))
		return (1);
	if (handle_point(list, list->content, 0, false))
		return (2);
	return (0);
}

t_list	*parse(t_list *list)
{
	int		i;

	while (list)
	{
		if (!g_name.end || !g_comment.end)
		{
			handle_name_comment(list->content);
			list = list_free(list);
			continue ;
		}
		else if ((i = parse2(list)) > 0)
		{
			list = (i == 1) ? list_free(list) : list;
			continue ;
		}
		list = list->next;
	}
	if (!g_name.end || !g_comment.end)
		error_exit("Syntax error");
	put_space_after_operation(g_head);
	return (g_head);
}

t_list	*get_content(t_list *list, char *file)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_printf(RED"Can't read source file %s\n"RESET, file);
	line = NULL;
	while (get_next_line(fd, &line))
		list = list_add_data(list, line);
	g_head = list;
	if ((i = -1) == -1 && !line)
	{
		ft_printf(RED"Syntax error - unexpected end of input ");
		ft_printf("Perhaps you forgot to end with a newline?)\n"RESET);
		exit(1);
	}
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\t')
			if (line[i] != COMMENT_CHAR && line[i] != ALT_COMMENT_CHAR)
			{
				ft_printf(RED"Syntax error - unexpected end of input ");
				ft_printf("Perhaps you forgot to end with a newline?)\n"RESET);
				exit(1);
			}
	return (list);
}
