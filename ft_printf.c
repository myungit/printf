/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:33:34 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/29 01:16:30 by mpark-ki         ###   ########.fr       */
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
	int			len;
	t_printf	*prototyp;

	prototyp = ft_init_prot(&(*format));
	if (ft_save_format(prototyp, &(*format), args))
	{
		len = ft_print_all(prototyp);
		if (!ft_isc(prototyp->specif))
			result += len;
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
