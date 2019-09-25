/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:03:47 by akuchina          #+#    #+#             */
/*   Updated: 2018/11/09 19:09:36 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find(t_list *alst, void const *content)
{
	t_list	*i;

	i = alst;
	while (i)
	{
		if (!ft_strcmp(content, i->content))
			return (i);
		i = i->next;
	}
	return (NULL);
}
