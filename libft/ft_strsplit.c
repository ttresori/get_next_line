/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:29:10 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/03/08 17:37:48 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**tabmalloc(const char *s, char c)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * ft_count_words(s, c) + 1)))
		return (NULL);
	return (tab);
}

char				**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		y;
	int		start;

	y = 0;
	i = 0;
	if (!s || !c || !(tab = tabmalloc(s, c)))
		return (NULL);
	while (s[i] && c)
	{
		if (s[i] && s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			tab[y] = ft_strsub(s, start, i - start);
			y++;
		}
	}
	tab[y] = NULL;
	return (tab);
}
