/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pencs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:38:09 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/26 00:38:13 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isp(char c)
{
	return (c == 'p');
}

int		ft_ise(char c)
{
	return (c == 'e' || c == 'E');
}

int		ft_isn(char c)
{
	return (c == 'n');
}

int		ft_isc(char c)
{
	return (c == 'c');
}

int		ft_iss(char c)
{
	return (c == 's');
}
