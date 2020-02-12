/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:39:11 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/12 09:33:19 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n /= 16)
		i++;
	return (i);
}

char		*ft_xitoa(unsigned long int n)
{
	char				*num;
	int					i;
	unsigned long int	cp_n;

	cp_n = (unsigned long int)n;
	i = ft_count(cp_n);
	if (!(num = (char*)ft_calloc(sizeof(char), i + 2)))
		return (NULL);
	if (cp_n < 0)
		i--;
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
