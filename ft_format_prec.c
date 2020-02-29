/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 00:24:34 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/29 19:38:31 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isdiouxp(char specif)
{
	return ((ft_isdi(specif) || ft_iso(specif) ||
				ft_isu(specif) || ft_isx(specif) ||
				ft_isp(specif)));
}

static int		ft_fixlen(char *str, int len)
{
	if (*str == '-' || *str == '+' || *str == ' ')
		len++;
	else if (ft_strlen(str) >= 2 && (str[0] == '0' && ft_isx(str[1])))
		len += 2;
	return (len);
}

static char		*ft_join_zero(t_printf *tmp, char *sign, int len)
{
	char	*first_str;
	char	*decimal;
	char	*result;

	if (ft_isdiouxp(tmp->specif))
	{
		first_str = (char*)ft_calloc(sizeof(char), len + 1);
		len = ft_fixlen(sign, len);
		ft_memset(first_str, '0', len);
		result = ft_strjoin(first_str, tmp->value);
	}
	else if (ft_ise(tmp->specif) || ft_isf(tmp->specif))
	{
		first_str = ft_itoa(ft_atoi(tmp->value));
		decimal = ft_substr(ft_strchr(tmp->value, '.'), 0, tmp->prec);
		result = ft_strjoin(first_str, decimal);
		free(decimal);
	}
	else
		return (tmp->value);
	ft_free(2, first_str, tmp->value);
	return (result);
}

static char		*ft_getprec_s(t_printf *tmp)
{
	char	*result;

	if (ft_strnstr(tmp->value, "(null)", 6))
	{
		if (tmp->prec >= 6)
			result = ft_substr(tmp->value, 0, tmp->prec);
		else
			result = ft_strdup("");
	}
	else
		result = (ft_substr(tmp->value, 0, tmp->prec));
	free(tmp->value);
	return (result);
}

void			ft_format_prec(t_printf *tmp, char **sign)
{
	int		len;

	len = tmp->prec - (ft_strlen(tmp->value) + ft_strlen(*sign));
	if (tmp->prec == 0 && !ft_isp(tmp->specif))
	{
		free(tmp->value);
		tmp->value = ft_strdup(*sign);
		*sign = "";
	}
	else if (tmp->prec >= 0)
	{
		if (ft_iss(tmp->specif))
			tmp->value = ft_getprec_s(tmp);
		else if (len > 0)
			tmp->value = ft_join_zero(tmp, *sign, len);
	}
}
