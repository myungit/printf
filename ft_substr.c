/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:22:02 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/19 14:46:37 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s || !(result = (char*)ft_calloc(sizeof(char), len + 1)))
		return (0);
	i = 0;
	while (len-- && start <= ft_strlen(s))
	{
		result[i++] = s[start++];
	}
	return (result);
}
