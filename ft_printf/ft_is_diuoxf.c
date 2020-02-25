/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_diuoxf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:38:18 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/26 00:38:23 by mpark-ki         ###   ########.fr       */
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
