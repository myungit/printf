/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:47:04 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/10 19:14:16 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cp_dst;
	unsigned const char	*cp_src;

	cp_dst = dst;
	cp_src = src;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			cp_dst[len] = cp_src[len];
	return (dst);
}
