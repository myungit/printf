/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:21:03 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/04 18:00:00 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int		ft_toupper(int c);
int		ft_tolower(int c);

int		main(void)
{
	printf("toupper:\n");
	printf("%d %d\n", toupper(0), ft_toupper(0));
	printf("%d %d\n", toupper(127), ft_toupper(127));
	printf("%d %d\n", toupper(500), ft_toupper(500));
	printf("%d %d\n", toupper(48), ft_toupper(48));
	printf("%d %d\n", toupper(97), ft_toupper(97));
	printf("%d %d\n", toupper(122), ft_toupper(122));
	printf("%d %d\n", toupper(66), ft_toupper(66));
	printf("tolower:\n");
	printf("%d %d\n", tolower(0), ft_tolower(0));
	printf("%d %d\n", tolower(127), ft_tolower(127));
	printf("%d %d\n", tolower(500), ft_tolower(500));
	printf("%d %d\n", tolower(48), ft_tolower(48));
	printf("%d %d\n", tolower(97), ft_tolower(97));
	printf("%d %d\n", tolower(122), ft_tolower(122));
	printf("%d %d\n", tolower(66), ft_tolower(66));
}
