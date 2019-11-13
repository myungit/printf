/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:24:47 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/13 23:07:11 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char *cp_s1 = (unsigned const char *)s1;
	unsigned const char *cp_s2 = (unsigned const char *)s2;

	while (n-- && (*cp_s1 || *cp_s2))
	{
		if (*cp_s1 != *cp_s2)
			return (*cp_s1 - *cp_s2);
		cp_s1++;
		cp_s2++;
	}
	return (0);
}
