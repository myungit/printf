/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:27:29 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/29 18:50:19 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	return ((c == '\t' || c == '\n'
				|| c == '\v' || c == '\r'
				|| c == '\f' || c == ' '));
}
