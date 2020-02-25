/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixthings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:38:31 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/26 00:38:33 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_get_num_asterisk(char *str, va_list args)
{
	if (*str == '*')
		return ((va_arg(args, int)));
	else
		return  (ft_atoi(str));
}

static char	*ft_move_one(char *str)
{
	char	*result;

	result = ft_substr(str, 1, ft_strlen(str));
	free(str);
	return (result);
}

char		*ft_getsign(char *flags, char specif, char *str)
{
	char	*sign;

	sign = "";
	if (ft_isdi(specif))
	{
		if (*str != '-' && (ft_strchr(flags, '+') || ft_strchr(flags, ' ')))
			sign = (ft_strchr(flags, '+')) ? "+" : " ";
		else if (*str == '-')
		{
			str = ft_move_one(str);
			sign = "-";
		}
	}
	else if (((ft_isx(specif) || ft_iso(specif)) && ft_strchr(flags, '#') &&
			(*str != '0' && ft_strlen(str) > 1)) || ft_isp(specif))
		sign = (specif == 'X') ? "0X" : "0x";
	return (sign);
}

