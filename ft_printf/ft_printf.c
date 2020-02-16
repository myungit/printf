/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:33:34 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/16 22:20:15 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static t_printf *ft_init_prot(void)
{
	t_printf	*tmp;

	if ((tmp = (t_printf *)malloc(sizeof(t_printf))))
	{
		tmp->flags = ft_strdup("");
		tmp->width = 0;
		tmp->precision = 0;
		tmp->specif = 1;
	}
	return (tmp);
}
#include <stdio.h>
static char		*save_flags(char *flags, const char *format)
{
	int		i;
	char	*result;
	char	*start;

	i = 0;
	free(flags);
	while ((format[i] == '-' || format[i] == '+' ||
			format[i] == ' ' || format[i] == '#' ||
			format[i] == '0'))
		i++;
	result = (char*)ft_calloc(sizeof(char), i + 1);
	start = result;
	while (*format == '-' || *format == '+' ||
			*format == ' ' || *format == '#' ||
			*format == '0')
		*result++ = *format++;
	return (start);
}
int				ft_printf(const char *format, ...)
{
	va_list		args;
	char		*value;
	char		*tmp;
	int			result;
	int			i;
	t_printf		*prototyp;

	va_start(args, format);
	result = 0;
	i = 0;

	while (*format)
	{
		if (*format == '%')
		{
			prototyp = ft_init_prot();
			format++;
			if (*format == '-' || *format == '+' ||
					*format == ' ' || *format == '#' ||
					*format == '0')
			{
				prototyp->flags = save_flags(prototyp->flags, format);
				format += ft_strlen(prototyp->flags);
			}
			if (ft_isdigit(*format) || *format == '*')
			{
				prototyp->width = (*format == '*') ?
					(va_arg(args, int)) : ft_atoi(format);
				while (ft_isdigit(*format) || *format == '*')
					format++;
			}
			if (*format == '.')
			{
				format++;
				if (ft_isdigit(*format) || *format == '*')
					prototyp->precision = (*format == '*') ?
						(va_arg(args, int)) : ft_atoi(format);
				while (ft_isdigit(*format) || *format == '*')
					format++;
			}
			if (*format == 'd' || *format == 'i' || *format == 'u' ||
					*format == 'o' || *format == 'x' || *format == 'X' ||
					*format == 'f' || *format == 'F' || *format == 'e' ||
					*format == 'c' || *format == 's' || *format == 'p' ||
					*format == 'n' || *format == '%')
				prototyp->specif = *format;

			if (prototyp->specif == 'd' || prototyp->specif == 'i')
			{
				value = ft_itoa(va_arg(args, int));
			}
			else if (prototyp->specif == 'u')
			{
				value = ft_uitoa(va_arg(args, unsigned int));
			}
			else if (prototyp->specif == 'o')
			{
				value = ft_ouitoa(va_arg(args, unsigned int));
			}
			else if (prototyp->specif == 'x' || prototyp->specif == 'X')
			{
				value = (prototyp->specif == 'X') ?
					ft_allcaps(ft_xitoa(va_arg(args, unsigned int))) :
					ft_xitoa(va_arg(args, unsigned int));
			}
			else if (prototyp->specif == 'f' || prototyp->specif == 'F')
			{
				value = ((prototyp->specif == 'F') ?
					ft_allcaps(ft_ftoa(va_arg(args, double))) :
					ft_ftoa(va_arg(args, double)));
				/*
				value = ft_ftoa(va_arg(args, double));
				  if (prototyp->specif == 'F')
				  ft_putstr_fd(ft_allcaps(value), 1);
				  else
				  ft_putstr_fd(value, 1);
				  */
			}
			else if (prototyp->specif == 'p')
			{
				tmp = ft_xitoa(va_arg(args, unsigned long int));
				value = ft_strjoin("0x", tmp);
				free(tmp);
			}
			else if (prototyp->specif == 'e' || prototyp->specif == 'E')
			{
				exit(1);
			}
			else if (prototyp->specif == 'n')
			{
				exit(1);
			}
			else if (prototyp->specif == 'c')
			{
				value = (char*)ft_calloc(sizeof(char), 2);
				*value = va_arg(args, int);
				result++;
			}
			else if (prototyp->specif == 's')
			{
				value = va_arg(args, char*);
			}
			else if (prototyp->specif == '%')
			{
				value = ft_strdup("%");
			}
			if (prototyp->specif != 'c')
				result += ft_strlen(value);
			tmp = ft_flags(prototyp->flags, prototyp->width, prototyp->specif, value);
			ft_putstr_fd(tmp, 1);
			free(tmp);
			/*
			if (prototyp->specif == 'd' || prototyp->specif == 'i' || prototyp->specif == 'u' ||
					prototyp->specif == 'o' || prototyp->specif == 'x' || prototyp->specif == 'X' ||
					prototyp->specif == 'f' || prototyp->specif == 'F' || prototyp->specif == 'p') 
				free(value);
				*/
			free(prototyp);
		}
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
