/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:42:04 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/06 22:09:25 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

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
	printf("space\n");
	printf("%d %d\n", isspace(0), ft_isspace(0));
	printf("%d %d\n", isspace(127), ft_isspace(127));
	printf("%d %d\n", isspace(500), ft_isspace(500));
	printf("%d %d\n", isspace(48), ft_isspace(48));
	printf("%d %d\n", isspace(97), ft_isspace(97));
	printf("%d %d\n", isspace(32), ft_isspace(32));
	printf("%d %d\n", isspace(10), ft_isspace(10));
	printf("%d %d\n", isspace(9), ft_isspace(9));
	printf("atoi\n");
	printf("%d %d\n", atoi("0"), ft_atoi("0"));
	printf("%d %d\n", atoi("127"), ft_atoi("127"));
	printf("%d %d\n", atoi("500"), ft_atoi("500"));
	printf("%d %d\n", atoi("48"), ft_atoi("48"));
	printf("%d %d\n", atoi("     97"), ft_atoi("     97"));
	printf("%d %d\n", atoi("32"), ft_atoi("     32"));
	printf("%d %d\n", atoi("			-10"), ft_atoi("			-10"));
	printf("%d %d\n", atoi("	-+9"), ft_atoi("	-+9"));
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
	char	hi[] = "hi man, how are you? ";
	char	hi2[] = "hi man, how are you? ";
	int		i = 0;
	bzero(hi, 5);
	ft_bzero(hi2, 5);
	printf("bzero\n");
	while (i++ < 5)
	{
		printf("%c", hi[i]);
	}
	printf("\n");
	i = 0;
	while (i++ < 5)
	{
		printf("%c", hi2[i]);
	}
	printf("\n");
	char hi3[] = "hi man, how are you?";
	char hi4[] = "123456";
	char hi5[] = "hi man, how are you?";
	char hi6[] = "123456";
	printf("memcpy\n");
	char string [] = "stackoverflow";
    char *first, *second;
    first = string;
    second = string;

    puts(string);
    memcpy(first+5, first, 7);
    puts(first);
    ft_memcpy(second+5, second, 7);
    puts(second);
	
	printf("%s\n", ft_memcpy(&hi3[4], hi3, 4));
	printf("%s\n", memcpy(&hi5[1], hi5, 4));
}
