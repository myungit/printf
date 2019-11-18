/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:00:50 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/18 23:24:40 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	first_len(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && i < ft_strlen(s))
			i++;
		while (s[i] != c && i < ft_strlen(s))
			i++;
		j++;
	}
	return (j);
}

static char		**second_len(char const *s, char c, char **result)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && i < ft_strlen(s))
			i++;
		j = 0;
		while (s[i] != c && i < ft_strlen(s))
		{
			i++;
			j++;
		}
		if (!(result[k] = (char *)ft_calloc(sizeof(char), (j))))
			return (0);
		k++;
	}
	return (result);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	j;
	size_t	k;

	if (!s || !c)
		return ((char**)s);
	if (!(result = (char**)ft_calloc(sizeof(char*), (first_len(s, c) + 1))))
		return (0);
	if (!(result = second_len(s, c, result)))
		return (0);
	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		k = 0;
		while (*s != c && *s)
		{
			result[j][k] = *s++;
			k++;
		}
		j++;
	}
	return (result);
}
