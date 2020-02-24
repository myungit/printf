/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixthings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myntcake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:52:37 by myntcake          #+#    #+#             */
/*   Updated: 2020/02/24 21:55:04 by myntcake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fixsign(char *flags, char c, char specif)
{
	if ((specif != 'c' || specif != 'u' || specif != 's' ||
			specif != 'p' || specif != 'n' || specif != '%'))
		return ((c == '+' || c == ' '));
	return (0);
}
char	ft_fixhash(char *flags, char specif, char *str)
{
	if (ft_strchr(flags, '#'))
	{
		if ((specif == 'x' || specif == 'X') &&
			(*str != '0' && ft_strlen(value) > 1))
			return ((c == '#'));
	}
	return (0);
}
