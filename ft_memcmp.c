/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 22:03:36 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/10 22:36:59 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *cp_s1;
	unsigned const char *cp_s2;

	cp_s1 = s1;
	cp_s2 = s2;
	while (n--)
	{
		if (*cp_s1 != *cp_s2)
			return (*cp_s1 - *cp_s2);
		cp_s1++;
		cp_s2++;
	}
	return (0);
}
