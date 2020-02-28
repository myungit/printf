/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_fwp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:10:36 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/27 23:05:37 by mpark-ki         ###   ########.fr       */
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

	i = 0;
	free(flags);
	while (ft_isflag(format[i]))
		i++;
	result = (char*)ft_calloc(sizeof(char), i + 1);
	start = result;
	while (ft_isflag(*format))
		*result++ = *format++;
	return (start);
}

static void		ft_save_w(t_printf *prototyp, const char *format, va_list args)
{
	if (*format == '*')
		prototyp->width = va_arg(args, int);
	else
		prototyp->width = ft_atoi(format);
	if (prototyp->width < 0)
	{
		prototyp->flags = ft_addb((prototyp->flags), "-");
		prototyp->width *= -1;
	}
}

static void		ft_save_prec(t_printf *prototyp, const char **format,
				va_list args)
{
	while (**format == '.')
	{
		(*format)++;
		if (ft_is_num_asterisk(**format))
			prototyp->prec = (**format == '*') ?
				(va_arg(args, int)) : ft_positiv(ft_atoi(*format));
		else
			prototyp->prec = 0;
		while (ft_is_num_asterisk(**format))
			(*format)++;
	}
}


void			ft_save_fwp(t_printf *prototyp, const char **format,
				va_list args)
{
	if (ft_isflag(**format))
	{
		prototyp->flags = ft_save_flags((prototyp->flags), *format);
		*format += ft_strlen(prototyp->flags);
	}
	if (ft_is_num_asterisk(**format))
	{
		ft_save_w(prototyp, *format, args);
		while (ft_is_num_asterisk(**format))
			(*format)++;
	}
	ft_save_prec(prototyp, &(*format), args);
}
