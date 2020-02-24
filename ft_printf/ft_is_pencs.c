/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pencs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myntcake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:43:36 by myntcake          #+#    #+#             */
/*   Updated: 2020/02/24 21:43:43 by myntcake         ###   ########.fr       */
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
