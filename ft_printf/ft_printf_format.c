/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:50:39 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/16 22:16:34 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_checksign(char *flags, char specif, char **value, int *len)
{
	char	*sign;
	char	*tmp;

	if ((ft_strchr(flags, '+') || ft_strchr(flags, ' ')) && (**value != '-')
			&& (specif == 'd' || specif == 'i'))
	{
		sign = ft_strchr(flags, '+') ? ft_strdup("+") : ft_strdup(" ");
		tmp = ft_strjoin(sign, *value);
		free(*value);
		free(sign);
		*value = tmp;
		*len = *len - 1;
	}
}

static void	ft_fix_sign(char **value, char **fill_it, char with_this)
{
	if (!(ft_isdigit(**value)))
	{
		**fill_it = **value;
		**value = with_this;
	}
}

char		*ft_flags(char *flags, int width, char specif, char *value)
{
	char	*fill_it;
	char	with_this;
	char	*result;
	int		len;

	len = width - ft_strlen(value);
	ft_checksign(flags, specif, &value, &len);
	if (len > 0)
	{
		fill_it = (char*)ft_calloc(sizeof(char), len + 1);
		with_this = ft_strchr(flags, '0') ? '0' : ' ';
		ft_memset(fill_it, with_this, len);
		if (ft_strchr(flags, '-'))
			result = ft_strjoin(value, fill_it);
		else
		{
			ft_fix_sign(&value, &fill_it, with_this);
			result = ft_strjoin(fill_it, value);
		}
		free(value);
		free(fill_it);
		value = result;
	}
	free(flags);
	return (value);
}
