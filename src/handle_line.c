/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:02:21 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/21 19:41:21 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		delete_comment(char *line)
{
	int		i;
	bool	marker;

	i = -1;
	marker = false;
	while (line[++i])
		if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
		{
			line[i] = '\0';
			marker = true;
			break ;
		}
	if (!marker || i == 0)
		return ;
	i--;
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
	{
		line[i] = '\0';
		i--;
	}
}

static void	move_word(char *line, int start, int shift)
{
	while (line[start + shift] && line[start + shift] != ' ')
	{
		line[start] = line[start + shift];
		line[start + shift] = ' ';
		start++;
	}
}

char		*delete_spaces(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] && (j = 0) == 0)
	{
		while (line[i + j] && line[i + j] == ' ')
			j++;
		if (i == 0 && j > 0)
			move_word(line, i, j);
		else if (j > 1 && line[i + j] != '\0')
		{
			if (i != 0 && j--)
				line[i++] = ' ';
			move_word(line, i, j);
		}
		else
			i++;
	}
	i--;
	while (i > 0 && line[i] == ' ')
		i--;
	(i != 0) ? i++ : i;
	line[i] = '\0';
	return (line);
}

char		*delete_tabs(char *line)
{
	int		i;

	i = -1;
	while (line[++i])
		if (line[i] == '\t')
			line[i] = ' ';
	return (line);
}

void		put_space_after_operation(t_list *list)
{
	char	*final_line;
	int		i;

	while (list)
	{
		list->content_size = ft_strlen(list->content);
		if (((char *)list->content)[list->content_size - 1] != LABEL_CHAR)
		{
			if (!(final_line = (char *)malloc(list->content_size + 2)))
				error_exit("Error allocate memory");
			final_line[0] = ' ';
			i = -1;
			while (((char *)list->content)[++i])
				final_line[i + 1] = ((char *)list->content)[i];
			final_line[i + 1] = '\0';
			free(list->content);
			list->content = final_line;
			list->content_size = ft_strlen(final_line);
		}
		list = list->next;
	}
	write_name_comment();
}
