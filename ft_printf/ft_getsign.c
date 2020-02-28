/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:47:00 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/27 22:47:11 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_move_one(char *str)
{
	char	*result;

	result = ft_substr(str, 1, ft_strlen(str));
	free(str);
	return (result);
}

static int	ft_iszero(char *str)
{
	if (*str)
		return ((*str == '0' && ft_strlen(str) == 1));
	return (0);
}

static char	*ft_getprefix(char specif, char *str)
{
	char	*sign;

	sign = "";
	if (!ft_iszero(str))
	{
		if (ft_isx(specif) || ft_isp(specif))
			sign = (specif == 'X') ? "0X" : "0x";
		if (ft_iso(specif))
			sign = "0"; } return (sign);
}

char		*ft_getsign(char *flag, char specif, char **str)
{
	char	*sign;

	sign = "";
	if (ft_isdi(specif))
	{
		if (**str == '-')
		{
			*str = ft_move_one(*str);
			sign = "-";
		}
		else if ((ft_strchr(flag, '+') || ft_strchr(flag, ' ')))
			sign = (ft_strchr(flag, '+')) ? "+" : " ";
	}
	else if (ft_strchr(flag, '#') || ft_isp(specif))
	{
		if ((ft_ise(specif) || ft_isf(specif)))
			sign = ".";
		else
			sign = ft_getprefix(specif, *str);
	}
	return (sign);
}
