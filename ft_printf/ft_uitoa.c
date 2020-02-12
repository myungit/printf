/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:37:01 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/12 09:32:52 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	unsigned int	i;

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

char		*ft_uitoa(unsigned int n)
{
	char			*num;
	unsigned int	i;
	unsigned int	cp_n;

	cp_n = (unsigned int)n;
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
