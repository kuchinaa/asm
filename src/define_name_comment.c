/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_name_comment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:52:11 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/21 19:41:21 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_correct_end(char *line)
{
	int	i;

	i = ft_strlen(line);
	while (i > 0 && line[i] != '"')
		i--;
	i++;
	while (line[i])
	{
		if (line[i] && line[i] != ' ' && line[i] != '\t')
			error_exit("Syntax error");
		i++;
	}
}

void	define_name_comment(char *line, t_com_name *cm, int limit, int i)
{
	int	j;

	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '"')
			error_exit("Syntax error");
		else if (line[i] == '"' && (j = -1) == -1)
		{
			i++;
			if ((cm->string = ft_strnew(limit)) == NULL)
				error_exit("Error allocate memory");
			while (line[i + ++j] && j < limit && line[i + j] != '"')
				cm->string[j] = line[i + j];
			break ;
		}
	}
	if (j == limit)
		error_exit("Too long name/comment");
	if (line[i + j] && line[i + j] == '"')
	{
		cm->string[j] = '\0';
		cm->end = true;
		check_correct_end(line);
	}
}

void	continue_define(char *line, t_com_name *cm, const int limit)
{
	int	i;
	int	j;

	j = ft_strlen(cm->string);
	i = 0;
	while (line[i] && j + i < limit && line[i] != '"')
	{
		cm->string[j + i] = line[i];
		i++;
	}
	if (j + i == limit)
		error_exit("Too long name");
	if (line[i] && line[i] == '"')
	{
		cm->string[j + i] = '\0';
		cm->end = true;
		check_correct_end(line);
	}
}

void	handle_name_comment(char *l)
{
	int		i;
	int		v[2];
	char	*s[2];

	v[0] = PROG_NAME_LENGTH;
	v[1] = COMMENT_LENGTH;
	s[0] = NAME_CMD_STRING;
	s[1] = COMMENT_CMD_STRING;
	if (!g_name.end && g_name.string)
		continue_define(l, &g_name, v[0]);
	else if (!g_comment.end && g_comment.string)
		continue_define(l, &g_comment, v[1]);
	else if (!ft_strncmp(s[0], l, ft_strlen(s[0])))
		define_name_comment(l, &g_name, v[0] + 1, ft_strlen(s[0]) - 1);
	else if (!ft_strncmp(s[1], l, ft_strlen(s[1])))
		define_name_comment(l, &g_comment, v[1] + 1, ft_strlen(s[1]) - 1);
	else if ((i = -1) == -1)
		while (l[++i] && l[i] != COMMENT_CHAR && l[i] != ALT_COMMENT_CHAR)
			if (l[i] != ' ' && l[i] != '\t')
			{
				ft_printf(RED"Missing %s or %s\n"RESET, s[0], s[1]);
				exit(1);
			}
}

void	write_name_comment()
{
	int	i;

	i = -1;
	while (g_name.string[++i])
		g_header.prog_name[i] = g_name.string[i];
	while (i <= PROG_NAME_LENGTH)
	{
		g_header.prog_name[i] = '\0';
		i++;
	}
	i = -1;
	while (g_comment.string[++i])
		g_header.comment[i] = g_comment.string[i];
	while (i <= COMMENT_LENGTH)
	{
		g_header.comment[i] = '\0';
		i++;
	}
}
