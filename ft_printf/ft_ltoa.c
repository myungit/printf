/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 03:07:38 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/12 08:56:06 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(long int n)
{
	long int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_ltoa(long int n)
{
	char		*num;
	long int	i;
	long int	cp_n;

	cp_n = (long int)n;
	i = ft_count(cp_n);
	if (!(num = (char*)ft_calloc(sizeof(char), i + 2)))
		return (NULL);
	if (cp_n < 0)
	{
		*num++ = '-';
		cp_n = -cp_n;
		i--;
	}
	while (i)
	{
		*num++ = (cp_n / ft_power(10, i) + 48);
		cp_n -= (cp_n / ft_power(10, i) * ft_power(10, i));
		i--;
	}
	*num = cp_n % 10 + 48;
	return (num - ft_count(n));
}
