/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:07:15 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/19 15:45:56 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list1;
	t_list	*list2;

	if (!lst || !(f))
		return (NULL);
	list1 = f(lst);
	list2 = list1;
	lst = lst->next;
	while (lst)
	{
		list1->next = f(lst);
		lst = lst->next;
		list1 = list1->next;
	}
	list1->next = NULL;
	return (list2);
}
