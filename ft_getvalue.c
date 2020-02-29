/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:44:36 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/29 22:42:16 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*check_null(char *str)
{
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

static char		*diuoxfp(char specif, va_list args)
{
	char	*value;

	value = "";
	if (ft_isdi(specif))
		value = ft_itoa(va_arg(args, int));
	else if (ft_isu(specif))
		value = ft_uitoa(va_arg(args, unsigned int));
	else if (ft_iso(specif))
		value = ft_ouitoa(va_arg(args, unsigned int));
	else if (ft_isx(specif))
		value = ft_xitoa(va_arg(args, unsigned int));
	else if (ft_isp(specif))
		value = ft_xitoa(va_arg(args, unsigned long int));
	else if (ft_isf(specif))
		value = ft_ftoa(va_arg(args, double));
	return (value);
}

char			*ft_getvalue(char specif, va_list args)
{
	char	*value;

	value = diuoxfp(specif, args);
	if (ft_ise(specif))
		return (0);
	else if (ft_isn(specif))
		return (0);
	else if (ft_isc(specif))
	{
		value = (char*)ft_calloc(sizeof(char), 2);
		*value = va_arg(args, int);
	}
	else if (ft_iss(specif))
	{
		value = va_arg(args, char*);
		value = check_null(value);
	}
	else if (specif == '%')
		value = ft_strdup("%");
	if (ft_iscaps(specif))
		value = ft_allcaps(value);
	return (value);
}
