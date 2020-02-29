/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_percentspeciflagwp.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:38:44 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/29 19:43:00 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ispercent(char c)
{
	return (c == '%');
}

int		ft_isspecif(char c)
{
	return ((c == 'd' || c == 'i' || c == 'u' ||
			c == 'o' || c == 'x' || c == 'X' ||
			c == 'f' || c == 'F' || c == 'e' ||
			c == 'E' || c == 'g' || c == 'G' ||
			c == 'a' || c == 'A' || c == 'c' ||
			c == 's' || c == 'p' || c == 'n' ||
			c == '%'));
}

int		ft_isflag(char c)
{
	return ((c == '-' || c == '+' ||
				c == ' ' || c == '#' ||
				c == '0'));
}

int		ft_is_num_asterisk(char c)
{
	return ((ft_isdigit(c) || c == '*'));
}

int		ft_get_num_asterisk(char *str, va_list args)
{
	if (*str == '*')
		return ((va_arg(args, int)));
	else
		return (ft_atoi(str));
}
