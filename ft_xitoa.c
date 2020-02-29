/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:39:28 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/29 02:31:44 by myntcake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	while (n /= 16)
		i++;
	return (i);
}

char		*ft_xitoa(unsigned long int n)
{
	char				*num;
	unsigned long int	i;
	unsigned long int	cp_n;

	cp_n = (unsigned long int)n;
	i = ft_count(cp_n);
	if (!(num = (char*)ft_calloc(sizeof(char), i + 2)))
		return (NULL);
	while (i)
	{
		*num = (cp_n / ft_power(16, i) + 48);
		if (*num > '9')
			*num += 39;
		num++;
		cp_n -= (cp_n / ft_power(16, i) * ft_power(16, i));
		i--;
	}
	*num = cp_n % 16 + 48;
	if (*num > '9')
		*num += 39;
	return (num - ft_count(n));
}
