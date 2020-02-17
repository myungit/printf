/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:50:39 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/17 20:38:56 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		ft_checksign(char *flags, char specif, char **value, int *len)
{
	char	*sign;
	char	*tmp;

	sign = "";
	if (ft_strchr(flags, '+') || ft_strchr(flags, ' ') || ft_strchr(flags, '#'))
	{
		if ((ft_strchr(flags, '+') || ft_strchr(flags, ' ')) && (**value != '-')
				&& (specif == 'd' || specif == 'i'))
			sign = (ft_strchr(flags, '+')) ? "+" : " ";
		else if (ft_strchr(flags, '#'))
		{
			if ((specif == 'x' || specif == 'X' || specif == 'o')
					&& (**value != '0' && ft_strlen(*value) > 1))
				sign = (specif == 'X') ? "0X" : "0x";
			else if ((specif == 'a' || specif == 'A' || specif == 'e' ||
					specif == 'E' || specif == 'f' || specif == 'F' ||
					specif == 'g' || specif == 'G')
					&& (!ft_strchr(*value, '.')))
				sign = ".";
		}
		tmp = ft_strjoin(sign, *value);
		free(*value);
		*value = tmp;
		*len = *len - ft_strlen(sign);
	}
}

static void		ft_fix_sign(char **value, char **fill_it, char with_this)
{
	char	*tmp;

	if (with_this == '0')
	{
		if (**value == '+' || **value == '-' || **value == ' ')
		{
			**fill_it = **value;
			**value = with_this;
		}
		else if (**value == '0'
				&& (*(*value + 1) == 'x' || *(*value + 1) == 'X'))
		{
			*(*fill_it + 1) = *(*value + 1);
			*(*value + 1) = with_this;
		}
		else if (**value == '.')
		{
			tmp = ft_strtrim(*value, ".");
			free(*value);
			*value = ft_strjoin(tmp, ".");
			free(tmp);
		}
	}
}

static char		*ft_prec(int prec, char specif, char *value)
{
	char	*fill_it;
	char	*tmp;
	int		len;

	if (prec != -1)
	{
		if (specif == 's')
			tmp = ft_substr(value, 0, prec);
		if ((len = prec - ft_strlen(value)) > 0)
		{
			if (specif == 'd' || specif == 'i' || specif == 'o' ||
					specif == 'u' || specif == 'x' || specif == 'X')
			{
				fill_it = (char*)ft_calloc(sizeof(char), len + 1);
				ft_memset(fill_it, '0', len);
				tmp = ft_strjoin(fill_it, value);
				free(fill_it);
			}
			/* else if (specif == 'a' || specif == 'A' || specif == 'e' ||*/
			/* specif == 'f' || specif == 'F')*/
			/* else if (specif == 'g' || specif == 'G')*/
		}
		free(value);
		value = tmp;
	}
	return (value);
}

char			*ft_flags(t_printf *prototyp, char *value)
{
	char	*fill_it;
	char	with_this;
	char	*result;
	int		len;

	len = prototyp->width - ft_strlen(value);
	ft_checksign(prototyp->flags, prototyp->specif, &value, &len);
	if (len > 0)
	{
		fill_it = (char*)ft_calloc(sizeof(char), len + 1);
		with_this = ft_strchr(prototyp->flags, '0') ? '0' : ' ';
		ft_memset(fill_it, with_this, len);
		if (ft_strchr(prototyp->flags, '-'))
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
	free(prototyp->flags);
	return (ft_prec(prototyp->prec, prototyp->specif, value));
}
