/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:21:03 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/04 18:00:31 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);

int		main(void)
{
	printf("%d %d\n", isalpha(0), ft_isalpha(0));
	printf("%d %d\n", isalpha(127), ft_isalpha(127));
	printf("%d %d\n", isalpha(500), ft_isalpha(500));
	printf("%d %d\n", isalpha(48), ft_isalpha(48));
	printf("%d %d\n", isalpha(97), ft_isalpha(97));
	printf("digit\n");
	printf("%d %d\n", isdigit(0), ft_isdigit(0));
	printf("%d %d\n", isdigit(127), ft_isdigit(127));
	printf("%d %d\n", isdigit(500), ft_isdigit(500));
	printf("%d %d\n", isdigit(48), ft_isdigit(48));
	printf("%d %d\n", isdigit(97), ft_isdigit(97));
	printf("alnum\n");
	printf("%d %d\n", isalnum(0), ft_isalnum(0));
	printf("%d %d\n", isalnum(127), ft_isalnum(127));
	printf("%d %d\n", isalnum(500), ft_isalnum(500));
	printf("%d %d\n", isalnum(48), ft_isalnum(48));
	printf("%d %d\n", isalnum(97), ft_isalnum(97));
	printf("ascii\n");
	printf("%d %d\n", isascii(0), ft_isascii(0));
	printf("%d %d\n", isascii(127), ft_isascii(127));
	printf("%d %d\n", isascii(500), ft_isascii(500));
	printf("%d %d\n", isascii(48), ft_isascii(48));
	printf("%d %d\n", isascii(97), ft_isascii(97));
}
