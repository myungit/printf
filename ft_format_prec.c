/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 00:24:34 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/29 21:02:51 by mpark-ki         ###   ########.fr       */
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
		len = ft_fixlen(sign, len);
		first_str = (char*)ft_calloc(sizeof(char), len + 1);
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

static int		check_o(t_printf *tmp)
{
	if (ft_iszero(tmp->value))
	{
		if (ft_iso(tmp->specif) && ft_strchr(tmp->flags, '#'))
			return (1);
	}
	return (0);
}

void			ft_format_prec(t_printf *tmp, char **sign)
{
	int		len;
	char	*str;

	len = tmp->prec - (ft_strlen(tmp->value) + ft_strlen(*sign));
	if (tmp->prec == 0)
	{
		if (check_o(tmp))
			*sign = "0";
		free(tmp->value);
		tmp->value = ft_strdup(*sign);
		*sign = "";
	}
	else if (tmp->prec >= 0)
	{
		if (ft_iss(tmp->specif))
		{
			str = ft_substr(tmp->value, 0, tmp->prec);
			free(tmp->value);
			tmp->value = str;
		}
		else if (len > 0)
			tmp->value = ft_join_zero(tmp, *sign, len);
	}
}
