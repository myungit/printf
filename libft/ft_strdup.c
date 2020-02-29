/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:21:03 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/12/01 17:42:11 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	s2 = ft_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (s2)
	{
		ft_memcpy(s2, s1, ft_strlen(s1));
		return (s2);
	}
	return (0);
}
