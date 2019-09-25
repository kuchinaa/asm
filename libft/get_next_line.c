/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:31:35 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/02 13:31:49 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_mlist	*ft_checklst(t_mlist *list, int fd)
{
	t_mlist *r;

	r = list;
	if (list)
		while (list != NULL)
		{
			if (list->fd == fd)
				return (list);
			list = list->next;
		}
	return (r);
}

static	t_mlist	*ft_addlst(t_mlist *list, int fd, char *content)
{
	t_mlist	*next;
	t_mlist	*l;

	if ((l = ft_checklst(list, fd)))
		if (l->fd == fd)
		{
			l->content = (char*)malloc((ft_strlen(content) + 1) * sizeof(char));
			ft_strcpy(l->content, content);
			return (list);
		}
	next = (struct s_mlist*)malloc(sizeof(struct s_mlist));
	next->content = (char*)malloc((ft_strlen(content) + 1) * sizeof(char));
	ft_strcpy(next->content, content);
	next->fd = fd;
	next->next = NULL;
	if (list)
	{
		while (l->next)
			l = l->next;
		l->next = next;
	}
	else
		list = next;
	return (list);
}

static	int		ft_strline(char **line, int fd, t_mlist *list)
{
	char	*str;
	t_mlist	*l;

	*line = NULL;
	if (list)
	{
		l = ft_checklst(list, fd);
		if (l->fd == fd && l->content)
		{
			*line = ft_strdup(l->content);
			if ((str = ft_strchr(l->content, '\n')))
			{
				free(*line);
				*line = ft_strnew(str - l->content + 1);
				ft_strncpy(*line, l->content, str - l->content);
				str = ft_strdup(str + 1);
				free(l->content);
				l->content = ft_strdup(str);
				free(str);
				return (1);
			}
			ft_memdel((void**)&l->content);
		}
	}
	return (0);
}

static	int		ft_cpy(char **line, char *buf, char *kost, int ct)
{
	char	*rez;

	if (kost != NULL)
		buf[kost - buf] = '\0';
	if (!(*line))
	{
		*line = (char*)malloc(sizeof(char));
		*line[0] = '\0';
	}
	rez = ft_strdup(*line);
	ft_memdel((void**)line);
	*line = ft_strjoin(rez, buf);
	ft_memdel((void**)&rez);
	if (ct < BUFF_SIZE && buf[ct - 1] && kost == NULL)
		return (2);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static t_mlist	*list;
	int				ct;
	char			buf[BUFF_SIZE + 1];
	char			*str;

	if (!line)
		return (-1);
	if ((ft_strline(line, fd, list)) == 1)
		return (1);
	while ((ct = read(fd, buf, BUFF_SIZE)))
	{
		if (ct == -1)
			return (-1);
		buf[ct] = '\0';
		if ((str = ft_strchr(buf, '\n')))
		{
			list = ft_addlst(list, fd, str + 1);
			return (ft_cpy(line, buf, str, ct));
		}
		if ((ft_cpy(line, buf, NULL, ct)) == 2)
			return (1);
	}
	if (*line != NULL && *line[0] != '\0')
		return (1);
	return (0);
}
