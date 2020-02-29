/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:32:57 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/19 16:48:48 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_power(size_t num, size_t pow)
{
	size_t	result;

	result = 1;
	if (!num)
		return (num);
	if (!pow)
		return (0);
	if (pow == 0)
		return (1);
	while (pow--)
		result *= num;
	return (result);
}
