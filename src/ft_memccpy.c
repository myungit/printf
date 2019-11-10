/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:56:47 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/08 19:47:25 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*cp_dst;
	unsigned const char	*cp_src;

	cp_dst = dst;
	cp_src = src;
	while (n--)
	{
		*cp_dst = *cp_src;
		if (*cp_src == (unsigned char)c)
			return ((void*)++cp_dst);
		cp_dst++;
		cp_src++;
	}
	return (0);
}
