/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:47:00 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/29 21:03:20 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_iszero(char *str)
{
	if (*str)
		return ((*str == '0' && ft_strlen(str) == 1));
	return (0);
}

static char	*ft_move_one(char *str)
{
	char	*result;

	result = ft_substr(str, 1, ft_strlen(str));
	free(str);
	return (result);
}

static char	*ft_getprefix(char specif, char *str)
{
	char	*sign;

	sign = "";
	if (ft_isp(specif))
		sign = "0x";
	else if (!ft_iszero(str))
	{
		if (ft_isx(specif))
			sign = (specif == 'X') ? "0X" : "0x";
		if (ft_iso(specif))
			sign = "0";
	}
	return (sign);
}

char		*ft_getsign(t_printf *tmp)
{
	char	*sign;

	sign = "";
	if (ft_isdi(tmp->specif))
	{
		if (tmp->value[0] == '-')
		{
			tmp->value = ft_move_one(tmp->value);
			sign = "-";
		}
		else if ((ft_strchr(tmp->flags, '+') || ft_strchr(tmp->flags, ' ')))
			sign = (ft_strchr(tmp->flags, '+')) ? "+" : " ";
	}
	else if (ft_strchr(tmp->flags, '#') || ft_isp(tmp->specif))
	{
		if ((ft_ise(tmp->specif) || ft_isf(tmp->specif)))
			sign = ".";
		else
			sign = ft_getprefix(tmp->specif, tmp->value);
	}
	return (sign);
}
