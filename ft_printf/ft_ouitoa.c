/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ouitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:24:24 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/24 20:44:34 by myntcake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n /= 8)
		i++;
	return (i);
}

char		*ft_ouitoa(unsigned int n)
{
	char			*num;
	unsigned int	i;
	unsigned int	cp_n;

	cp_n = (unsigned int)n;
	i = ft_count(cp_n);
	if (!(num = (char*)ft_calloc(sizeof(char), i + 2)))
		return (NULL);
	while (i)
	{
		*num++ = (cp_n / ft_power(8, i) + 48);
		cp_n -= (cp_n / ft_power(8, i) * ft_power(8, i));
		i--;
	}
	*num = cp_n % 8 + 48;
	return (num - ft_count(n));
}
