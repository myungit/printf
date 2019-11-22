/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:15:29 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/21 16:46:30 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_firstset(char *cp_s1, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set) && *cp_s1)
	{
		while (*cp_s1 == set[i])
		{
			cp_s1++;
			i = 0;
		}
		i++;
	}
	return (cp_s1);
}

static int		ft_lastset(char *cp_s1, char const *set, size_t j)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set) && j)
	{
		while (cp_s1[j] == set[i])
		{
			j--;
			i = 0;
		}
		i++;
	}
	return (j);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*cp_s1;
	char	*result;
	size_t	i;
	size_t	j;

	if (!set || !s1)
		return (ft_strdup(""));
	cp_s1 = (char *)s1;
	cp_s1 = ft_firstset(cp_s1, set);
	if (*cp_s1)
		j = ft_strlen(cp_s1) - 1;
	else
		return (cp_s1);
	j = ft_lastset(cp_s1, set, j);
	if (!(result = (char *)ft_calloc(sizeof(char), j + 2)))
		return (0);
	i = 0;
	while (i <= j)
	{
		result[i++] = *cp_s1++;
	}
	return (result);
}
