/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:33:34 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/27 22:45:54 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static t_printf	*ft_init_prot(const char **format)
{
	t_printf	*tmp;

	if ((tmp = (t_printf *)malloc(sizeof(t_printf))))
	{
		tmp->flags = ft_strdup("");
		tmp->width = 0;
		tmp->prec = -1;
		tmp->specif = 0;
		tmp->value = "";
	}
	if (ft_strlen(*format) > 1)
		(*format)++;
	return (tmp);
}

static int		convert_all(const char **format,
		va_list args, int result)
{
	int			tmp;
	t_printf	*prototyp;

	prototyp = ft_init_prot(&(*format));
	ft_save_fwp(prototyp, &(*format), args);
	if (*format && ft_isspecif(**format))
	{
		prototyp->specif = **format;
		prototyp->value = ft_getvalue(prototyp->specif, args);
		tmp = ft_flags(prototyp, prototyp->value);
		if (!ft_isc(prototyp->specif) && prototyp->specif)
			result += (tmp);
		else if (prototyp->width)
			result += prototyp->width;
		else
			result++;
	}
	ft_free(2, prototyp->flags, prototyp);
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
