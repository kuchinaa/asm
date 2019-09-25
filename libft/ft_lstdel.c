/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:44:09 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/19 15:42:35 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list1;
	t_list	*list2;

	if (!alst || !(*alst) || !(del))
		return ;
	list1 = *alst;
	while (list1)
	{
		list2 = list1->next;
		del(list1->content, list1->content_size);
		free(list1);
		list1 = list2;
	}
	*alst = NULL;
}
