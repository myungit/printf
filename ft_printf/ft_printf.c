/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:33:34 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/18 15:51:14 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		diuoxfp(char specif, va_list args, char **value)
{
	char	*tmp;

	if (specif == 'd' || specif == 'i')
		*value = ft_itoa(va_arg(args, int));
	else if (specif == 'u')
		*value = ft_uitoa(va_arg(args, unsigned int));
	else if (specif == 'o')
		*value = ft_ouitoa(va_arg(args, unsigned int));
	else if (specif == 'x' || specif == 'X')
		*value = (specif == 'X') ?
			ft_allcaps(ft_xitoa(va_arg(args, unsigned int))) :
			ft_xitoa(va_arg(args, unsigned int));
	else if (specif == 'f' || specif == 'F')
		*value = ((specif == 'F') ?
				ft_allcaps(ft_ftoa(va_arg(args, double))) :
				ft_ftoa(va_arg(args, double)));
	else if (specif == 'p')
	{
		tmp = ft_xitoa(va_arg(args, unsigned long int));
		*value = ft_strjoin("0x", tmp);
		free(tmp);
	}
}

static char		*save_value(char specif, va_list args)
{
	char	*value;

	diuoxfp(specif, args, &value);
	if (specif == 'e' || specif == 'E')
		exit(1);
	else if (specif == 'n')
		exit(1);
	else if (specif == 'c')
	{
		value = (char*)ft_calloc(sizeof(char), 2);
		*value = va_arg(args, int);
	}
	else if (specif == 's')
	{
		value = va_arg(args, char*);
		value = (value == NULL) ? ft_strdup("(null)") :
				ft_strdup(value);
	}
	else if (specif == '%')
		value = ft_strdup("%");
	return (value);
}

static int		convert_all(const char **format,
		va_list args, int result)
{
	char		*tmp;
	char		*value;
	t_printf	*prototyp;

	ft_save_fwp(&prototyp, &(*format), args);
	if (**format == 'd' || **format == 'i' || **format == 'u' ||
			**format == 'o' || **format == 'x' || **format == 'X' ||
			**format == 'f' || **format == 'F' || **format == 'e' ||
			**format == 'c' || **format == 's' || **format == 'p' ||
			**format == 'n' || **format == '%')
	{
		prototyp->specif = **format;
		value = save_value(prototyp->specif, args);
		tmp = ft_flags(&prototyp, value);
		if (prototyp->specif != 'c')
			result += ft_strlen(tmp);
		else
			result++;
		ft_putstr_fd(tmp, 1);
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
		if (*format == '%')
			result = convert_all(&format, args, result);
		else
		{
			ft_putchar_fd((char)*format, 1);
			result++;
		}
		format++;
	}
	va_end(args);
	return (result);
}
