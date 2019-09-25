/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:02:49 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/21 19:02:49 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_operation	*operation_init(t_op tab, int arr[3][3])
{
	t_operation	*new;
	int			i;
	int			j;

	if (!(new = (t_operation *)malloc(sizeof(t_operation))))
		error_exit("Error allocate memory");
	new->next = NULL;
	new->name = tab.name;
	new->num_arg = tab.count_of_arg;
	i = -1;
	while (++i < 3 && (j = -1) == -1)
		while (++j < 3)
			new->arr[i][j] = arr[i][j];
	return (new);
}

t_operation	*operation_add(t_operation *o, t_op tab, int arr[3][3])
{
	t_operation	*new;
	int			i;
	int			j;

	while (o->next)
		o = o->next;
	if (!(new = (t_operation *)malloc(sizeof(t_operation))))
		error_exit("Error allocate memory");
	o->next = new;
	new->next = NULL;
	new->name = tab.name;
	new->num_arg = tab.count_of_arg;
	i = -1;
	while (++i < 3 && (j = -1) == -1)
		while (++j < 3)
			new->arr[i][j] = arr[i][j];
	return (new);
}
