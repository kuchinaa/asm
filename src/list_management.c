/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:19:21 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/21 19:06:51 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_list	*list_init(char *line)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->content = line;
	new->content_size = 0;
	return (new);
}

t_list	*list_add(t_list *list, char *line)
{
	t_list *new;

	while (list->next)
		list = list->next;
	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->next = new;
	new->prev = list;
	new->next = NULL;
	new->content = line;
	new->content_size = 0;
	return (new);
}

t_list	*list_add_data(t_list *list, char *line)
{
	if (!list)
	{
		if ((list = list_init(line)) == NULL)
			error_exit("Error allocate memory");
	}
	else
	{
		if (list_add(list, line) == NULL)
			error_exit("Error allocate memory");
	}
	return (list);
}

t_list	*list_insert(t_list *list, char *line)
{
	t_list	*new;
	t_list	*tmp;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		error_exit("Error allocate memory");
	tmp = list->next;
	list->next = new;
	if (tmp)
		tmp->prev = new;
	new->prev = list;
	new->next = tmp;
	new->content = line;
	new->content_size = 0;
	return (new);
}

t_list	*list_free(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (list->prev && list->next)
	{
		tmp = list->prev;
		tmp->next = list->next;
		tmp = list->next;
		tmp->prev = list->prev;
	}
	else if (!list->prev && list->next)
	{
		tmp = list->next;
		tmp->prev = NULL;
		g_head = tmp;
	}
	else if (list->prev && !list->next)
	{
		tmp = list->prev;
		tmp->next = NULL;
		tmp = tmp->next;
	}
	free(list->content);
	free(list);
	return (tmp);
}
