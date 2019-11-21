/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:00:50 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/21 16:10:04 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	first_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			len++;
		while (*s != c && *s)
			s++;
	}
	return (len);
}

static char		**freeme(char **result, size_t k)
{
	while (k)
		free(result[k--]);
	free(result[k]);
	return (0);
}

static char		**second_len(char const *s, char c, size_t i, char **result)
{
	size_t	j;
	size_t	k;

	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i] != c && s[i])
		{
			i++;
			j++;
		}
		if (j)
		{
			if (!(result[k] = (char *)ft_calloc(sizeof(char), j)))
				return (freeme(result, k));
			result[k] = ft_substr(s, i - j, j);
		}
		k++;
	}
	return (result);
}

char			**ft_split(char const *s, char c)
{
	char	**result;

	if (!s || !c)
		return ((char**)s);
	if (!(result = (char**)ft_calloc(sizeof(char*), (first_len(s, c) + 1))))
		return (0);
	second_len(s, c, 0, result);
	return (result);
}
