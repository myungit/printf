/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 03:51:01 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/27 04:17:02 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(int i, ...)
{
	va_list	args;
	char	*tmp;
	char	*str;
	char	*result;

	va_start(args, i);
	result = ft_strdup("");
	while (i--)
	{
		str = va_arg(args, char*);
		tmp = ft_strjoin(result, str);
		free(result);
		result = ft_strdup(tmp);
		free(tmp);
	}
	return (result);
}
