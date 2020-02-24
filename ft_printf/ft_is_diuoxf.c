/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_diuoxf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myntcake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:44:25 by myntcake          #+#    #+#             */
/*   Updated: 2020/02/24 21:44:28 by myntcake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdi(char c)
{
	return (c == 'd' || c == 'i');
}

int		ft_isu(char c)
{
	return (c == 'u');
}

int		ft_iso(char c)
{
	return (c == 'o');
}

int		ft_isx(char c)
{
	return (c == 'x' || c == 'X');
}

int		ft_isf(char c)
{
	return (c == 'f' || c == 'F');
}
