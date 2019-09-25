/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:24:26 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/03 21:30:59 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *destptr, const char *srcptr)
{
	char	*tmp;

	tmp = destptr;
	while (*tmp)
		tmp++;
	while (*srcptr)
	{
		*tmp = *srcptr;
		tmp++;
		srcptr++;
	}
	*tmp = '\0';
	return (destptr);
}
