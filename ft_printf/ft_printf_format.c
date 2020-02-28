/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:50:39 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/28 01:04:45 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_ishex(char *str)
{
	if (ft_strlen(str) >= 2)
		return (str[0] == '0' && ft_isx(str[1]));
	return (0);
}

static char		*ft_getdecimals(char *value, int prec)
{
	char	*num;
	char	*decimal;
	char	*result;

	num = ft_itoa(ft_atoi(value));
	decimal = ft_substr(ft_strchr(value, '.'), 0, prec);
	result = ft_strjoin(num, decimal);
	ft_free(2, num, decimal);
	return (result);
}

static char		*ft_join_zero(char specif, char *sign, char *value, int len)
{
	char	*result;
	char	*fill_it;
	int		prec;

	prec = (len - (ft_strlen(value) + ft_strlen(sign)));
	if (ft_isdi(specif) || ft_iso(specif) ||
			ft_isu(specif) || ft_isx(specif) || ft_isp(specif))
	{
		fill_it = (char*)ft_calloc(sizeof(char), len + 1);
		(*sign == '-') ? len++ : len;
		ft_ishex(sign) ? len += 2 : len;
		ft_memset(fill_it, '0', len);
		result = ft_strjoin(fill_it, value);
		free(fill_it);
	}
	else if (ft_ise(specif) || ft_isf(specif))
		result = ft_getdecimals(value, prec);
	else
		return (value);
	return (result);
}

static char		*ft_prec(int prec, char specif, char *value, char *sign)
{
	char	*tmp;
	int		len;

	if (prec == 0) 
	{
		free(value);
		value = ft_strdup(sign);
	}
	else if (prec >= 0 &&(ft_iss(specif) ||
			(len = prec - (ft_strlen(value) + ft_strlen(sign))) > 0 ))
	{
		if (ft_iss(specif))
		{
			if (ft_strnstr(value, "(null)", 6))
				tmp = (prec >= 6) ? (ft_substr(value, 0, prec)) : ft_strdup("");
			else
				tmp = (ft_substr(value, 0, prec));
		}
		else
			tmp = ft_join_zero(specif, sign, value, len);
		free(value);
		value = tmp;
	}
	return (value);
}

static int		print_w_flags(t_printf *prototyp, int len, char *sign, char *value)
{
	char	*fill_it;
	char	with_this;
	int		result;

	fill_it = (char*)ft_calloc(sizeof(char), len + 1);
	with_this = ((ft_strchr(prototyp->flags, '0') &&
			prototyp->prec == -1)  && (!(ft_strchr(prototyp->flags, '-')))
			&& !(ft_iss(prototyp->specif)))
		? '0' : ' ';
	ft_memset(fill_it, with_this, len);
	if (ft_strchr(prototyp->flags, '-'))
	{
		ft_putstr(sign);
		(prototyp->specif == 'c') ? ft_putchar(*value) : ft_putstr(value);
		ft_putstr(fill_it);
	}
	else
	{
		if (with_this == '0')
		{
			ft_putstr(sign);
			ft_putstr(fill_it);
			(prototyp->specif == 'c') ? ft_putchar(*value) : ft_putstr(value);
		}
		else
		{
			ft_putstr(fill_it);
			ft_putstr(sign);
			(prototyp->specif == 'c') ? ft_putchar(*value) : ft_putstr(value);
		}
	}
	result = ft_strlen(sign) + ft_strlen(value) + ft_strlen(fill_it);
	free(fill_it);
	return (result);
}

int			ft_flags(t_printf *prototyp, char *value)
{
	int		result;
	int		len;
	char	*sign;

	sign = ft_getsign(prototyp->flags, prototyp->specif, &value);
	value = ft_prec(prototyp->prec, prototyp->specif, value, sign);
	if (prototyp->prec == 0)
		sign = "";
	len = prototyp->width - (ft_strlen(value) + ft_strlen(sign));
	if (prototyp->specif == 'c' && *value == 0)
		len--;
	if (len > 0 && !ft_ispercent(prototyp->specif))
		result = print_w_flags(prototyp, len, sign, value);
	else if ((!(prototyp->width) && prototyp->prec == -1 &&
			ft_isc(prototyp->specif)))
		ft_putchar(*value);
	else
	{
		ft_putstr(sign);
		ft_putstr(value);
		result = ft_strlen(sign) + ft_strlen(value);
	}
	free(value);
	return (result);
}
