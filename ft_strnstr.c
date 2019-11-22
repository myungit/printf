/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:28:46 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/21 17:45:21 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t need_len;

	need_len = ft_strlen(needle);
	if (!need_len)
		return ((char *)haystack);
	if (need_len > ft_strlen(haystack))
		return (0);
	while (*haystack && need_len <= len--)
		if (ft_strncmp(haystack, needle, need_len))
			haystack++;
		else
			return ((char *)haystack);
	return (0);
}
