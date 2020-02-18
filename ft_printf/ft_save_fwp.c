/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_fwp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:10:36 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/18 11:18:15 by mpark-ki         ###   ########.fr       */
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
		tmp->specif = 1;
	}
	(*format)++;
	return (tmp);
}

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

void			ft_save_fwp(t_printf **prototyp, const char **format,
				va_list args)
{
	*prototyp = ft_init_prot(&(*format));
	if (**format == '-' || **format == '+' ||
			**format == ' ' || **format == '#' ||
			**format == '0')
	{
		(*prototyp)->flags = save_flags(((*prototyp)->flags), *format);
		*format += ft_strlen((*prototyp)->flags);
	}
	if (ft_isdigit(**format) || **format == '*')
	{
		(*prototyp)->width = (**format == '*') ?
			(va_arg(args, int)) : ft_atoi(*format);
		while (ft_isdigit(**format) || **format == '*')
			(*format)++;
	}
	while (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format) || **format == '*')
			(*prototyp)->prec = (**format == '*') ?
				(va_arg(args, int)) : ft_atoi(*format);
		while (ft_isdigit(**format) || **format == '*')
			(*format)++;
	}
}
