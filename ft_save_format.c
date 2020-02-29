/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:18:55 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/29 01:43:22 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_addb(char *str, char *c)
{
	char	*tmp;
	
	tmp = ft_strjoin(str, c);
	free(str);
	return (tmp);
}

static char		*ft_save_flags(char *flags, const char *format)
{
	int		i;
	char	*result;
	char	*start;

	free(flags);
	i = 0;
	while (ft_isflag(format[i]))
		i++;
	result = (char*)ft_calloc(sizeof(char), i + 1);
	start = result;
	while (ft_isflag(*format))
		*result++ = *format++;
	return (start);
}

static void		ft_save_w(t_printf *tmp, const char *format, va_list args)
{
	if (*format == '*')
		tmp->width = va_arg(args, int);
	else
		tmp->width = ft_atoi(format);
	if (tmp->width < 0)
	{
		tmp->flags = ft_addb((tmp->flags), "-");
		tmp->width *= -1;
	}
}

static void		ft_save_prec(t_printf *tmp, const char **format,
				va_list args)
{
	while (**format == '.')
	{
		(*format)++;
		if (ft_is_num_asterisk(**format))
			tmp->prec = (**format == '*') ?
				(va_arg(args, int)) : ft_positiv(ft_atoi(*format));
		else
			tmp->prec = 0;
		while (ft_is_num_asterisk(**format))
			(*format)++;
	}
}


int			ft_save_format(t_printf *tmp, const char **format,
				va_list args)
{
	if (ft_isflag(**format))
	{
		tmp->flags = ft_save_flags(tmp->flags, *format);
		*format += ft_strlen(tmp->flags);
	}
	if (ft_is_num_asterisk(**format))
	{
		ft_save_w(tmp, *format, args);
		while (ft_is_num_asterisk(**format))
			(*format)++;
	}
	if (**format == '.')
		ft_save_prec(tmp, &(*format), args);
	if (*format && ft_isspecif(**format))
	{
		tmp->specif = **format;
		tmp->value = ft_getvalue(tmp->specif, args);
		if (tmp->value)
			return (1);
	}
	return (0);
}
