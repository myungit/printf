/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 22:06:48 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/11 23:16:48 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cp_s;

	cp_s = (char *)s + ft_strlen(s);
	if ((*cp_s == 0) && (*cp_s == (unsigned char)c))
		return (0);
	while (*cp_s != *s && *cp_s != (unsigned char)c)
		cp_s--;
	return ((char *)cp_s);
	
	/*size_t	i;

	i = ft_strlen(s);
	while (i > 0 && s[i] != (unsigned char)c)
		i--;
	if ((s[i] == 0) && (s[i] == (unsigned char)c))
		return (0);
	return ((char *)&s[i]);
	*/
}
