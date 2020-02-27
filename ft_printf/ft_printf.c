/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:33:34 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/27 04:29:28 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		diuoxfp(char specif, va_list args, char **value)
{
	if (ft_isdi(specif))
		*value = ft_itoa(va_arg(args, int));
	else if (ft_isu(specif))
		*value = ft_uitoa(va_arg(args, unsigned int));
	else if (ft_iso(specif))
		*value = ft_ouitoa(va_arg(args, unsigned int));
	else if (ft_isx(specif))
		*value = (specif == 'X') ?
			ft_allcaps(ft_xitoa(va_arg(args, unsigned int))) :
			ft_xitoa(va_arg(args, unsigned int));
	else if (ft_isf(specif))
		*value = ((specif == 'F') ?
				ft_allcaps(ft_ftoa(va_arg(args, double))) :
				ft_ftoa(va_arg(args, double)));
	else if (ft_isp(specif))
		*value = ft_xitoa(va_arg(args, unsigned long int));
}

static char		*save_value(char spec, va_list args)
{
	char	*value;

	diuoxfp(spec, args, &value);
	if (ft_ise(spec))
		exit(1);
	else if (ft_isn(spec))
		exit(1);
	else if (ft_isc(spec))
	{
		value = (char*)ft_calloc(sizeof(char), 2);
		*value = va_arg(args, int);
	}
	else if (ft_iss(spec))
	{
		value = va_arg(args, char*);
		value = (value == NULL) ? ft_strdup("(null)") :
				ft_strdup(value);
	}
	else if (spec == '%')
		value = ft_strdup("%");
	return (value);
}

static int		convert_all(const char **format,
		va_list args, int result)
{
	char		*tmp;
	t_printf	*prototyp;

	ft_save_fwp(&prototyp, &(*format), args);
	if (format && ft_isspecif(**format))
	{
		prototyp->specif = **format;
		prototyp->value = save_value(prototyp->specif, args);
		tmp = ft_flags(&prototyp, prototyp->value);
		if (prototyp->specif != 'c' && prototyp->specif != 0)
			result += ft_strlen(tmp);
		else if (prototyp->width)
			result += prototyp->width;
		else
			result++;
		free(tmp);
		ft_free(2, prototyp->flags, prototyp);
	}
	return (result);
}

int				ft_printf(const char *format, ...)
{
	va_list			args;
	int				result;

	va_start(args, format);
	result = 0;
	while (*format)
	{
		if (*format && *format == '%')
			result = convert_all(&format, args, result);
		else if (*format)
		{
			ft_putchar_fd((char)*format, 1);
			result++;
		}
		if (*format)
			format++;
	}
	va_end(args);
	return (result);
}
