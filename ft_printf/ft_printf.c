/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:33:34 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/23 20:15:40 by mpark-ki         ###   ########.fr       */
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

static char		*save_value(char spec, va_list args)
{
	char	*value;

	diuoxfp(spec, args, &value);
	if (spec == 'e' || spec == 'E')
		exit(1);
	else if (spec == 'n')
		exit(1);
	else if (spec == 'c')
	{
		value = (char*)ft_calloc(sizeof(char), 2);
		*value = va_arg(args, int);
	}
	else if (spec == 's')
	{
		value = va_arg(args, char*);
		value = (value == NULL) ? ft_strdup("(null)") :
				ft_strdup(value);
	}
	else if (spec == '%')
		value = ft_strdup("%");
	return (value);
}

static void		ft_printstr(char specif, char *str, int len)
{
	/*
	int i;

	i = 0;
	if (specif == 'c')
	{
		len--;
		while (str[i] || len--)
		{
			write(1, &(str[i]), 1);
			str++;
		}
	}
	else
	*/
	if (specif && len)
		ft_putstr_fd(str, 1);
}

static int		convert_all(const char **format,
		va_list args, int result)
{
	char		*tmp;
	t_printf	*prototyp;

	ft_save_fwp(&prototyp, &(*format), args);
	if (format && (**format == 'd' || **format == 'i' || **format == 'u' ||
			**format == 'o' || **format == 'x' || **format == 'X' ||
			**format == 'f' || **format == 'F' || **format == 'e' ||
			**format == 'c' || **format == 's' || **format == 'p' ||
			**format == 'n' || **format == '%'))
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
		ft_printstr(prototyp->specif, tmp, result);
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
