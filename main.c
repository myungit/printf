/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:08:47 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/10 19:47:08 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./src/libft.h"

int		main(void)
{
	printf("isalpha\n");
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
	char	hi1[] = "hi man, how are you? ";
	char	hi2[] = "hi man, how are you? ";
	int		i = 0;
	bzero(hi1, 5);
	ft_bzero(hi2, 5);
	printf("bzero\n");
	while (i++ < 5)
	{
		printf("%c", hi1[i]);
	}
	printf("\n");
	i = 0;
	while (i++ < 5)
	{
		printf("%c", hi2[i]);
	}
	printf("\n");
	char hi3[] = "hi man, how are you?";
	char hi4[] = "hi man, how are you?";
	printf("memcpy\n");
	char string[] = "stackoverflow";
	char string2[] = "stackoverflow";
	char string3[] = "stackoverflow";
	char string4[] = "stackoverflow";
	char *first, *second, *third, *fourth;
	first = string;
	second = string2;
	third = string3;
	fourth = string4;
	puts(string);

	memcpy(first+5, first, 7);
	puts(first);
	ft_memcpy(second+5, second, 7);
	puts(second);

	printf("%s\n", memcpy(hi3+6, hi3, 7));
	printf("%s\n", ft_memcpy(hi4+6, hi4, 7));

	char hi7[] = "abcdefghijklmnopqrstuvwxyz";
	char hi8[] = "abcdefghijklmnopqrstuvwxyz";
	printf("memccpy\n");
	printf("%s\n", memccpy(hi7+5, hi7, 'e', 5));
	printf("%s\n", ft_memccpy(hi8+5, hi8, 'e', 5));
	printf("%s\n%s\n", hi7, hi8);
	printf("%s\n", memccpy(hi7+7, hi7, 'd', 5));
	printf("%s\n", ft_memccpy(hi8+7, hi8, 'd', 5));
	printf("%s\n%s\n", hi7, hi8);
	char hi5[] = "abcdefghijklmnopqrstuvwxyz";
	char hi6[] = "abcdefghijklmnopqrstuvwxyz";
	printf("--------------------memmove\n");
	printf("%s\n", memmove(hi5+5, hi5, 5));
	printf("%s\n", ft_memmove(hi6+5, hi6, 5));
	printf("---------------------hi5 and hi6\n%s\n%s\n", hi5, hi6);
	printf("---------------------second test\n");
	printf("%s\n", memmove(hi5+7, hi5, 5));
	printf("%s\n", ft_memmove(hi6+7, hi6, 5));
	printf("---------------------hi5 and hi6\n%s\n%s\n", hi5, hi6);
	char csrc[100] = "Geeksfor";
	char csrc1[100] = "Geeksfor";
	printf("%s\n", memmove(csrc+5, csrc, strlen(csrc)+1));
	printf("%s\n", csrc);
	printf("%s\n", ft_memmove(csrc1+5, csrc1, strlen(csrc1)+1));
	printf("%s\n", csrc1);
	printf("memchr\n");
	char chrme[] = "Geeksfor";
	printf("%s\n", chrme);
	printf("%s %s\n", memchr(chrme, 'k', 0), ft_memchr(chrme, 'k', 0));
	printf("%s %s\n", memchr(chrme, 'a', 127), ft_memchr(chrme, 'a', 127));
	printf("%s %s\n", memchr(chrme, 'k', 500), ft_memchr(chrme, 'k', 500));
	printf("%s %s\n", memchr(chrme, 'o', 48), ft_memchr(chrme, 'o', 48));
	printf("%s %s\n", memchr(chrme, 115, 48), ft_memchr(chrme, 115, 48));
	printf("%s %s\n", memchr(chrme, 0, 48), ft_memchr(chrme, 0, 48));
	printf("%s\n", chrme);

}
