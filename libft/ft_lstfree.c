/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:37:32 by akuchina          #+#    #+#             */
/*   Updated: 2019/02/13 12:37:53 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*lstfree(t_list **list)
{
	t_list	*next;

	while (*list)
	{
		next = (*list)->next;
		ft_memdel(&((*list)->content));
		ft_memdel((void **)list);
		(*list) = next;
	}
	return (NULL);
}
