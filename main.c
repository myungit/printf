/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:08:47 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/10 23:02:01 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./src/libft.h"

int		testft(int i, int x, int y)
{
	if (x != y)
	{
		printf("Mistmatch in : i = %d result = %d %d\n", i, x, y);
		return (1);
	}
	return (0);
}

void	checkok(char *name, int *i, int *j)
{
	if (*j == 0)
		printf("[OK] ");
	else
		printf("[FAIL] ");
	printf("%s\n", name);
	*i = -1;
	*j = 0;
}

int		main(void)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (i++ < 500)
		j += testft(i, isalpha(i), ft_isalpha(i));
	checkok("isalpha", &i, &j);
	while (i++ < 500)
		j += testft(i, isdigit(i), ft_isdigit(i));
	checkok("isdigit", &i, &j);
	while (i++ < 500)
		j += testft(i, isalnum(i), ft_isalnum(i));
	checkok("isalnum", &i, &j);
	while (i++ < 500)
		j += testft(i, isascii(i), ft_isascii(i));
	checkok("isascii", &i, &j);
	while (i++ < 500)
		j += testft(i, isspace(i), ft_isspace(i));
	checkok("isspace", &i, &j);
	while (i++ < 500)
		j += testft(i, toupper(i), ft_toupper(i));
	checkok("toupper", &i, &j);
	while (i++ < 500)
		j += testft(i, tolower(i), ft_tolower(i));
	checkok("tolower", &i, &j);
	char atoistr[127] = "";
	while (i++ <= 127)
		atoistr[i] = i;
	i = 0;
	testft(i, atoi(atoistr), ft_atoi(atoistr));
	checkok("atoi", &i, &j);
	if (
			atoi("0  asd") != ft_atoi("0  asd") ||
			atoi("  127") != ft_atoi("  127") ||
			atoi("500") != ft_atoi("500") ||
			atoi("48") != ft_atoi("48") ||
			atoi("     97") != ft_atoi("     97") ||
			atoi("32") != ft_atoi("     32") ||
			atoi("			-10") != ft_atoi("			-10") ||
			atoi("	-+9") != ft_atoi("	-+9") 
	   )
	{
		printf("ERROR\n");
		printf(" %d\n", atoi("0  asd") == ft_atoi("0  asd"));
		printf(" %d\n", atoi("  127") == ft_atoi("  127"));
		printf(" %d\n", atoi("500") == ft_atoi("500"));
		printf(" %d\n", atoi("48") == ft_atoi("48"));
		printf(" %d\n", atoi("     97") == ft_atoi("     97"));
		printf(" %d\n", atoi("32") == ft_atoi("     32"));
		printf(" %d\n", atoi("			-10") == ft_atoi("			-10"));
		printf(" %d\n", atoi("	-+9") == ft_atoi("	-+9"));
	}
	else
		printf("[OK] atoi additional tests\n");
	char	hi1[] = "hi man, how are you? ";
	char	hi2[] = "hi man, how are you? ";
	printf("bzero\n");
	bzero(hi1, 5);
	ft_bzero(hi2, 5);
	while (i++ < 5)
	{
		printf("%c", hi1[i]);
	}
	printf("\n");
	i = -1;
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
	printf("equal? %d\n", memccpy(hi7+5, hi7, 'e', 5) == ft_memccpy(hi8+5, hi8, 'e', 5));
	printf("%s\n%s\n", hi7, hi8);
	printf("%s\n", memccpy(hi7+7, hi7, 'd', 5));
	printf("%s\n", ft_memccpy(hi8+7, hi8, 'd', 5));
	printf("equal? %d\n", memccpy(hi7+7, hi7, 'd', 5) == ft_memccpy(hi8+7, hi8, 'd', 5));
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
	printf("\nmemchr\n");
	char chrme[] = "Geepksfor";
	printf("%s\n", chrme);
	i = -1;
	while (i++ < 500)
		j += testft(i, (int)memchr(chrme, i, i), (int)ft_memchr(chrme, i, i));
	checkok("memchr", &i, &j);
	i = -1;
	j = 0;
	while (i++ < 500)
		if (memchr(chrme, i, j) != ft_memchr(chrme, i, j))
			printf("%s %s\n", memchr(chrme, i, j), ft_memchr(chrme, i, j));
	i = 0;
	j = -1;
	while (j++ < 500)
		if (memchr(chrme, chrme[i], j) != ft_memchr(chrme, chrme[i], j))
			printf("%s %s\n", memchr(chrme, i, j), ft_memchr(chrme, i, j));
	i = ft_strlen(chrme) + 1;
	if (
			memchr(chrme, chrme[i], 50) != ft_memchr(chrme, chrme[i], 50) ||
			memchr(chrme, chrme[i] + i, 50) != ft_memchr(chrme, chrme[i] + i, 50) ||
			memchr(chrme, chrme[i] - i, 50) != ft_memchr(chrme, chrme[i] - i, 50) ||
			memchr(chrme, chrme[i] * i, 50) != ft_memchr(chrme, chrme[i] * i, 50)
	   )
	{
		printf("ERRROR\n");
		printf("%s %s\n", memchr(chrme, chrme[i], 50), ft_memchr(chrme, chrme[i], 50));
		printf("%s %s\n", memchr(chrme, chrme[i] + i, 50), ft_memchr(chrme, chrme[i] + i, 50));
		printf("%s %s\n", memchr(chrme, chrme[i] - i, 50), ft_memchr(chrme, chrme[i] - i, 50));
		printf("%s %s\n", memchr(chrme, chrme[i] * i, 50), ft_memchr(chrme, chrme[i] * i, 50));
	}
	else
		printf("[OK] memchr\n");
	if (
			memchr(chrme, 'a', 127), ft_memchr(chrme, 'a', 127) ||
			memchr(chrme, 'k', 500), ft_memchr(chrme, 'k', 500) ||
			memchr(chrme, 'o', 48), ft_memchr(chrme, 'o', 48) ||  			
			memchr(chrme, 115, 48), ft_memchr(chrme, 115, 48) ||
			memchr(chrme, 0, 48), ft_memchr(chrme, 0, 48) 
	   )
	{
		printf("ERRROR\n");
		printf("%s %s\n", memchr(chrme, 'a', 127), ft_memchr(chrme, 'a', 127));
		printf("%s %s\n", memchr(chrme, 'k', 500), ft_memchr(chrme, 'k', 500));
		printf("%s %s\n", memchr(chrme, 'o', 48), ft_memchr(chrme, 'o', 48));
		printf("%s %s\n", memchr(chrme, 115, 48), ft_memchr(chrme, 115, 48));
		printf("%s %s\n", memchr(chrme, 0, 48), ft_memchr(chrme, 0, 48));
	}
	else
		printf("[OK] memchr additional tests\n");
	printf("%s\n", chrme);
	char cmp1[] = "hi";
	char cmp2[] = "hi ";
	char cmp3[] = "hello";
	char cmp4[] = " hello";
	char cmp5[] = "    5rownawe;ls";
	char cmp6[] = "5hi";
	char cmp7[] = " ffPo";
	char cmp8[] = "   awjewowP";
	if (
			memcmp(cmp1, cmp1, 50) != ft_memcmp(cmp1, cmp1, 50) ||
			memcmp(cmp1, cmp2, 50) != ft_memcmp(cmp1, cmp2, 50) ||
			memcmp(cmp2, cmp1, 50) != ft_memcmp(cmp2, cmp1, 50) ||
			memcmp(cmp2, cmp2, 50) != ft_memcmp(cmp2, cmp2, 50) ||
			memcmp(cmp3, cmp3, 50) != ft_memcmp(cmp3, cmp3, 50) ||
			memcmp(cmp3, cmp4, 50) != ft_memcmp(cmp3, cmp4, 50) ||
			memcmp(cmp4, cmp3, 50) != ft_memcmp(cmp4, cmp3, 50) ||
			memcmp(cmp4, cmp4, 50) != ft_memcmp(cmp4, cmp4, 50) ||
			memcmp(cmp5, cmp5, 50) != ft_memcmp(cmp5, cmp5, 50) ||
			memcmp(cmp5, cmp6, 50) != ft_memcmp(cmp5, cmp6, 50) ||
			memcmp(cmp6, cmp5, 50) != ft_memcmp(cmp6, cmp5, 50) ||
			memcmp(cmp6, cmp6, 50) != ft_memcmp(cmp6, cmp6, 50) ||
			memcmp(cmp7, cmp7, 50) != ft_memcmp(cmp7, cmp7, 50) ||
			memcmp(cmp7, cmp8, 50) != ft_memcmp(cmp7, cmp8, 50) ||
			memcmp(cmp8, cmp7, 50) != ft_memcmp(cmp8, cmp7, 50) ||
			memcmp(cmp8, cmp8, 50) != ft_memcmp(cmp8, cmp8, 50)
	   )
	{
		printf("ERROR\n");
		printf("%d %d\n", memcmp(cmp1, cmp1, 50), ft_memcmp(cmp1, cmp1, 50));
		printf("%d %d\n", memcmp(cmp1, cmp2, 50), ft_memcmp(cmp1, cmp2, 50));
		printf("%d %d\n", memcmp(cmp2, cmp1, 50), ft_memcmp(cmp2, cmp1, 50));
		printf("%d %d\n", memcmp(cmp2, cmp2, 50), ft_memcmp(cmp2, cmp2, 50));
		printf("%d %d\n", memcmp(cmp3, cmp3, 50), ft_memcmp(cmp3, cmp3, 50));
		printf("%d %d\n", memcmp(cmp3, cmp4, 50), ft_memcmp(cmp3, cmp4, 50));
		printf("%d %d\n", memcmp(cmp4, cmp3, 50), ft_memcmp(cmp4, cmp3, 50));
		printf("%d %d\n", memcmp(cmp4, cmp4, 50), ft_memcmp(cmp4, cmp4, 50));
		printf("%d %d\n", memcmp(cmp5, cmp5, 50), ft_memcmp(cmp5, cmp5, 50));
		printf("%d %d\n", memcmp(cmp5, cmp6, 50), ft_memcmp(cmp5, cmp6, 50));
		printf("%d %d\n", memcmp(cmp6, cmp5, 50), ft_memcmp(cmp6, cmp5, 50));
		printf("%d %d\n", memcmp(cmp6, cmp6, 50), ft_memcmp(cmp6, cmp6, 50));
		printf("%d %d\n", memcmp(cmp7, cmp7, 50), ft_memcmp(cmp7, cmp7, 50));
		printf("%d %d\n", memcmp(cmp7, cmp8, 50), ft_memcmp(cmp7, cmp8, 50));
		printf("%d %d\n", memcmp(cmp8, cmp7, 50), ft_memcmp(cmp8, cmp7, 50));
		printf("%d %d\n", memcmp(cmp8, cmp8, 50), ft_memcmp(cmp8, cmp8, 50));
	}
	else
		printf("[OK] memcmp\n");
}
