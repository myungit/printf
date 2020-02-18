/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 01:20:20 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/18 10:29:13 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_inf_nan(float n)
{
	if (n == (1 / 0.0))
		return (ft_strdup("inf"));
	else if (n == (-1 / 0.0))
		return (ft_strdup("-inf"));
	else if (n != n)
		return (ft_strdup("nan"));
	else
		return (0);
}

static char	*ft_decimal(long long int cp_n, int i)
{
	char	*start;
	char	*num;

	if (!(num = (char*)ft_calloc(sizeof(char), i + 2)))
		return (NULL);
	start = num;
	if (cp_n < 0)
		cp_n = -cp_n;
	while (i)
	{
		*num++ = (cp_n / ft_power(10, i) + 48);
		cp_n -= (cp_n / ft_power(10, i) * ft_power(10, i));
		i--;
	}
	*num = (cp_n % 10 + 48);
	return (start);
}

char		*ft_joinall(char *before, char *after, int sign)
{
	char	*before_tmp;
	char	*tmp;
	char	*result;

	if (sign)
	{
		before_tmp = ft_strjoin("-", before);
		free(before);
	}
	else
		before_tmp = before;
	tmp = ft_strjoin(before_tmp, ".");
	result = ft_strjoin(tmp, after);
	ft_free(3, before_tmp, tmp, after);
	return (result);
}

char		*ft_ftoa(float n)
{
	char		*decimal;
	char		*before;
	long int	cp_n;
	char		*result;
	int			sign;

	if (!(result = ft_inf_nan(n)))
	{
		//printf("\nfirst: %f\n", n);
		sign = 0;
		if (n < 0)
		{
			n = -n;
			sign = 1;
		}
		//cp_n = (n * (ft_power(10, 6))) - (((long int)n) * ft_power(10, 6));
		cp_n = n * ft_power(10, 6) - (long int)n * (ft_power(10, 6));
		if ((((long int)(n * ft_power(10, 7))) % 10) >= 5)
			cp_n++;
		before = ft_ltoa(n);
		decimal = ft_decimal(cp_n, 5);
		result = ft_joinall(before, decimal, sign);
	}
	return (result);
}
