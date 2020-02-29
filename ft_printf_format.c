/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:50:39 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/29 02:03:23 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_format_flag(t_printf *tmp, int len)
{
	char	*fill_it;
	char	with_this;

	fill_it = (char*)ft_calloc(sizeof(char), len + 1);
	with_this = ' ';
	if (tmp->prec == -1 && !(ft_iss(tmp->specif) || ft_isc(tmp->specif)))
	{
		if (ft_strchr(tmp->flags, '0') && !(ft_strchr(tmp->flags, '-')))
			with_this = '0';
	}
	ft_memset(fill_it, with_this, len);
	return (fill_it);
}

static void		ft_checkf_zero(char specif, char *value, char *sign, char *fill)
{
	char	*result;

	if (*fill == '0')
		result = ft_strjoin(sign, fill);
	else
		result = ft_strjoin(fill, sign);
	ft_putstr(result);
	if (ft_isc(specif))
		ft_putchar(*value);
	else
		ft_putstr(value);
	free(result);
}

static int		ft_print_w_flags(t_printf *tmp, int len, char *sign)
{
	char	*fill_it;
	int		result;

	fill_it = ft_format_flag(tmp, len);
	if (ft_strchr(tmp->flags, '-'))
	{
		ft_putstr(sign);
		(ft_isc(tmp->specif)) ? ft_putchar(tmp->value[0]) : ft_putstr(tmp->value);
		ft_putstr(fill_it);
	}
	else
		ft_checkf_zero(tmp->specif, tmp->value, sign, fill_it);
	result = ft_strlen(sign) + ft_strlen(tmp->value) + ft_strlen(fill_it);
	free(fill_it);
	return (result);
}

int			ft_print_all(t_printf *tmp)
{
	int		result;
	int		len;
	char	*sign;

	sign = ft_getsign(tmp);
	ft_format_prec(tmp, &sign);
	len = tmp->width - (ft_strlen(tmp->value) + ft_strlen(sign));
	if (tmp->specif == 'c' && tmp->value[0] == 0)
		len--;
	if (len > 0 && !ft_ispercent(tmp->specif))
		result = ft_print_w_flags(tmp, len, sign);
	else if ((ft_isc(tmp->specif)))
		ft_putchar(tmp->value[0]);
	else
	{
		ft_putstr(sign);
		ft_putstr(tmp->value);
		result = ft_strlen(sign) + ft_strlen(tmp->value);
	}
	free(tmp->value);
	return (result);
}
