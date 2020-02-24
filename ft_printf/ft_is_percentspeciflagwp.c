/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_percentspeciflagwp.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myntcake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:50:46 by myntcake          #+#    #+#             */
/*   Updated: 2020/02/24 21:53:01 by myntcake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ispercent(char c)
{
	return (c == '%');
}

int		ft_isspecif(char c)
{
	return ((c == 'd' || c == 'i' || c == 'u' ||
			c == 'o' || c == 'x' || c == 'X' ||
			c == 'f' || c == 'F' || c == 'e' ||
			c == 'E' ||	c == 'g' || c == 'G' ||
			c == 'a' || c == 'A' ||	c == 'c' ||
		   	c == 's' || c == 'p' ||	c == 'n' ||
			c == '%'));
}

int		ft_isflag(char c)
{
	return ((c == '-' || c == '+' ||
				c == ' ' || c == '#' ||
				c == '0'));
}

int		ft_iswp(char c)
{
	return ((ft_isdigit(c) || c == '*'));
}
