/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:09:57 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/16 21:22:27 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cp_dst;
	unsigned const char	*cp_src;

	cp_dst = dst;
	cp_src = src;
	if (cp_dst == cp_src)
		return (dst);
	while (n--)
		*cp_dst++ = *cp_src++;
	return (dst);
}
