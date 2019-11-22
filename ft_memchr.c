/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 00:12:06 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/11 19:03:31 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char *cp_s;

	cp_s = s;
	while (n--)
	{
		if (*cp_s == (unsigned char)c)
		{
			return ((void*)cp_s);
		}
		cp_s++;
	}
	return (0);
}
