/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:08:54 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/27 04:18:05 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		main(void)
{
	char	*a;
	char	*b;
	char	*tmp;

	a = ft_strdup("hi");
	b = ft_strdup("MAN!");
	tmp = ft_join(3, a, b, "what");
	ft_free(2, a, b);
	ft_printf("%s\n", tmp);
	free(tmp);
	return (0);
}
