/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:56:54 by akuchina          #+#    #+#             */
/*   Updated: 2018/11/20 09:11:20 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_of_word(const char *s, char c)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] != c && (s[i - 1] == c || i == 0))
			count++;
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**mas;

	if (!s || (!(mas = (char **)malloc(sizeof(char *) *
						(count_of_word(s, c) + 1)))))
		return (NULL);
	i = -1;
	k = 0;
	while (s[++i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
		{
			j = i;
			while (s[j] != c && s[j])
				j++;
			mas[k++] = ft_strsub(s, i, j - i);
			i = j - 1;
		}
	}
	mas[k] = NULL;
	return (mas);
}
