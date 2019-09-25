/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:24:22 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/12 18:36:36 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skip(char const *s)
{
	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	return ((char *)s);
}

static int	ft_length(char const *s)
{
	int	i;

	if (!s)
		return (0);
	s = ft_skip(s);
	i = 0;
	while (s[i])
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	if (i < 0)
		return (0);
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	char	*cp_str;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_length(s);
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	cp_str = str;
	s = ft_skip(s);
	while ((i-- + 1) > 0)
		*str++ = *s++;
	*str = '\0';
	return (cp_str);
}
