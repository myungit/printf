/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:51:51 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/18 09:54:30 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_free(int i, ...)
{
	va_list	args;

	va_start(args, i);
	while (i--)
		free(va_arg(args, void*));
	va_end(args);
}
