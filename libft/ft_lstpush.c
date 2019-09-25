/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:02:30 by akuchina          #+#    #+#             */
/*   Updated: 2019/08/09 15:02:48 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **h, t_list **t, t_list *new)
{
	if (!new)
		return ;
	if (!(*h))
	{
		(*h) = new;
		(*t) = new;
		(*h)->next = NULL;
		(*h)->prev = NULL;
	}
	else
	{
		new->prev = (*t);
		(*t)->next = new;
		(*t) = (*t)->next;
	}
}
