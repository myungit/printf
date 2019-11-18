/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:08:47 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/18 23:26:44 by mpark-ki         ###   ########.fr       */
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
	printf("\nmemcpy\n");
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

	memcpy(first + 5, first, 7);
	puts(first);
	ft_memcpy(second + 5, second, 7);
	puts(second);

	printf("%s\n", memcpy(hi3 + 6, hi3, 7));
	printf("%s\n", ft_memcpy(hi4 + 6, hi4, 7));

	char hi7[] = "abcdefghijklmnopqrstuvwxyz";
	char hi8[] = "abcdefghijklmnopqrstuvwxyz";
	printf("\nmemccpy\n");
	printf("%s\n", memccpy(hi7 + 5, hi7, 'e', 5));
	printf("%s\n", ft_memccpy(hi8 + 5, hi8, 'e', 5));
	printf("%s\n%s\n", hi7, hi8);
	printf("%s\n", memccpy(hi7 + 7, hi7, 'd', 5));
	printf("%s\n", ft_memccpy(hi8 + 7, hi8, 'd', 5));
	printf("%s\n%s\n", hi7, hi8);
	char hi5[] = "abcdefghijklmnopqrstuvwxyz";
	char hi6[] = "abcdefghijklmnopqrstuvwxyz";
	printf("\n--------------------memmove\n");
	printf("%s\n", memmove(hi5 + 5, hi5, 5));
	printf("%s\n", ft_memmove(hi6 + 5, hi6, 5));
	printf("---------------------hi5 and hi6\n%s\n%s\n", hi5, hi6);
	printf("---------------------second test\n");
	printf("%s\n", memmove(hi5+7, hi5, 5));
	printf("%s\n", ft_memmove(hi6+7, hi6, 5));
	printf("---------------------hi5 and hi6\n%s\n%s\n", hi5, hi6);
	char csrc[100] = "Geeksfor";
	char csrc1[100] = "Geeksfor";
	printf("%s\n", memmove(csrc + 5, csrc, strlen(csrc)+1));
	printf("%s\n", csrc);
	printf("%s\n", ft_memmove(csrc1 + 5, csrc1, strlen(csrc1)+1));
	printf("%s\n", csrc1);
	printf("\nmemchr\n");
	char chrme[] = "Geepksfor";
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
			memchr(chrme, 'a', 127) != ft_memchr(chrme, 'a', 127) ||
			memchr(chrme, 'k', 500) != ft_memchr(chrme, 'k', 500) ||
			memchr(chrme, 'o', 48) != ft_memchr(chrme, 'o', 48) ||  			
			memchr(chrme, 115, 48) != ft_memchr(chrme, 115, 48) ||
			memchr(chrme, 0, 48) != ft_memchr(chrme, 0, 48) 
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
	char	cmp1[] = "hi		i";
	char	cmp2[] = "hi oa	";
	char	cmp3[] = "hellohi.QWRQR-0292";
	char	cmp4[] = " hellor ";
	char	cmp5[] = "    5rownawe;ls";
	char	cmp6[] = "5hi np";
	char	cmp7[] = " ffPo rr";
	char	cmp8[] = "   awjewowP";
	char	cmp9[] = "";
	char	cmp10[50] = "Hem bro's, 'sWhat's up?i ey";
	char	cmp11[50] = "ey ";
	char	cmp12[50] = "there is no stars in the sky";
	char	cmp13[50] = "the cake is a lie!\0I'm hidden ol\r\n";
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
	if (
			strlen(cmp1) != ft_strlen(cmp1) ||
			strlen(cmp2) != ft_strlen(cmp2) ||
			strlen(cmp3) != ft_strlen(cmp3) ||
			strlen(cmp4) != ft_strlen(cmp4) ||
			strlen(cmp5) != ft_strlen(cmp5) ||
			strlen(cmp6) != ft_strlen(cmp6) ||
			strlen(cmp7) != ft_strlen(cmp7) ||
			strlen(cmp8) != ft_strlen(cmp8)
	   )
	{
		printf("ERROR\n");
		printf("%lu %lu\n", strlen(cmp1), ft_strlen(cmp1));
		printf("%lu %lu\n", strlen(cmp2), ft_strlen(cmp2));
		printf("%lu %lu\n", strlen(cmp3), ft_strlen(cmp3));
		printf("%lu %lu\n", strlen(cmp4), ft_strlen(cmp4));
		printf("%lu %lu\n", strlen(cmp5), ft_strlen(cmp5));
		printf("%lu %lu\n", strlen(cmp6), ft_strlen(cmp6));
		printf("%lu %lu\n", strlen(cmp7), ft_strlen(cmp7));
		printf("%lu %lu\n", strlen(cmp8), ft_strlen(cmp8));
	}
	else
		printf("[OK] strlen\n");
	if (
			strlcpy(cmp1, cmp2, 5) != ft_strlcpy(cmp1, cmp2, 5) ||
			strlcpy(cmp2, cmp1, 5) != ft_strlcpy(cmp2, cmp1, 5) ||
			strlcpy(cmp3, cmp4, 5) != ft_strlcpy(cmp3, cmp4, 5) ||
			strlcpy(cmp4, cmp3, 5) != ft_strlcpy(cmp4, cmp3, 5) ||
			strlcpy(cmp5, cmp6, 5) != ft_strlcpy(cmp5, cmp6, 5) ||
			strlcpy(cmp6, cmp5, 5) != ft_strlcpy(cmp6, cmp5, 5) ||
			strlcpy(cmp7, cmp8, 5) != ft_strlcpy(cmp7, cmp8, 5) ||
			strlcpy(cmp8, cmp7, 5) != ft_strlcpy(cmp8, cmp7, 5)
	   )
	{
		printf("ERROR\n");
		printf("%lu %lu\n", strlcpy(cmp1, cmp2, 5), ft_strlcpy(cmp1, cmp2, 5));
		printf("%lu %lu\n", strlcpy(cmp2, cmp1, 5), ft_strlcpy(cmp2, cmp1, 5));
		printf("%lu %lu\n", strlcpy(cmp3, cmp4, 5), ft_strlcpy(cmp3, cmp4, 5));
		printf("%lu %lu\n", strlcpy(cmp4, cmp3, 5), ft_strlcpy(cmp4, cmp3, 5));
		printf("%lu %lu\n", strlcpy(cmp5, cmp6, 5), ft_strlcpy(cmp5, cmp6, 5));
		printf("%lu %lu\n", strlcpy(cmp6, cmp5, 5), ft_strlcpy(cmp6, cmp5, 5));
		printf("%lu %lu\n", strlcpy(cmp7, cmp8, 5), ft_strlcpy(cmp7, cmp8, 5));
		printf("%lu %lu\n", strlcpy(cmp8, cmp7, 5), ft_strlcpy(cmp8, cmp7, 5));
	}
	else
		printf("[OK] strlcpy\n");
	i = -1;
	while (i++ < 5)
	{
		if (
				strlcat(cmp1, cmp2, i) != ft_strlcat(cmp1, cmp2, i) ||
				strlcat(cmp2, cmp3, i) != ft_strlcat(cmp2, cmp3, i) ||
				strlcat(cmp3, cmp4, i) != ft_strlcat(cmp3, cmp4, i) ||
				strlcat(cmp4, cmp5, i) != ft_strlcat(cmp4, cmp5, i) ||
				strlcat(cmp5, cmp6, i) != ft_strlcat(cmp5, cmp6, i) ||
				strlcat(cmp6, cmp7, i) != ft_strlcat(cmp6, cmp7, i) ||
				strlcat(cmp7, cmp8, i) != ft_strlcat(cmp7, cmp8, i) ||
				strlcat(cmp8, cmp9, i) != ft_strlcat(cmp8, cmp9, i) ||
				strlcat(cmp10, cmp11, i) != ft_strlcat(cmp10, cmp11, i) ||
				strlcat(cmp12, cmp13, i) != ft_strlcat(cmp12, cmp13, i)
		   )
		{
			printf("ERROR i: %d\n", i);
			printf("%lu %lu %s\n", strlcat(cmp1, cmp2, i), ft_strlcat(cmp1, cmp2, i), cmp1);
			printf("%lu %lu %s\n", strlcat(cmp2, cmp3, i), ft_strlcat(cmp2, cmp3, i), cmp2);
			printf("%lu %lu %s\n", strlcat(cmp3, cmp4, i), ft_strlcat(cmp3, cmp4, i), cmp3);
			printf("%lu %lu %s\n", strlcat(cmp4, cmp5, i), ft_strlcat(cmp4, cmp5, i), cmp4);
			printf("%lu %lu %s\n", strlcat(cmp5, cmp6, i), ft_strlcat(cmp5, cmp6, i), cmp5);
			printf("%lu %lu %s\n", strlcat(cmp6, cmp7, i), ft_strlcat(cmp6, cmp7, i), cmp6);
			printf("%lu %lu %s\n", strlcat(cmp7, cmp8, i), ft_strlcat(cmp7, cmp8, i), cmp7);
			printf("%lu %lu %s\n", strlcat(cmp8, cmp9, i), ft_strlcat(cmp8, cmp9, i), cmp8);
			printf("%lu %lu %s\n", strlcat(cmp10, cmp11, i), ft_strlcat(cmp10, cmp11, i), cmp10);
			printf("%lu %lu %s\n", strlcat(cmp12, cmp13, i), ft_strlcat(cmp12, cmp13, i), cmp12);
		}
		else
			printf("[OK] strlcat%d\n", i);
	}
	i = 0;
	char schrme[] = "Great I amgG reat";
	while (i <= ft_strlen(schrme))
	{
		if (
				strchr(schrme, schrme[i]) != ft_strchr(schrme, schrme[i]) ||
				strchr(schrme, schrme[i + i]) != ft_strchr(schrme, schrme[i + i]) ||
				strchr(schrme, schrme[i - i]) != ft_strchr(schrme, schrme[i - i]) ||
				strchr(schrme, schrme[i * i]) != ft_strchr(schrme, schrme[i * i])
		   )
		{
			printf("ERRROR i: %d\n", i);
			printf("%s %s\n", strchr(schrme, schrme[i]), ft_strchr(schrme, schrme[i]));
			printf("%s %s\n", strchr(schrme, schrme[i + i]), ft_strchr(schrme, schrme[i + i]));
			printf("%s %s\n", strchr(schrme, schrme[i - i]), ft_strchr(schrme, schrme[i - i]));
			printf("%s %s\n", strchr(schrme, schrme[i * i]), ft_strchr(schrme, schrme[i * i]));
		}
		else
			printf("[OK] strchr%d\n", i);
		i++;
	}
	if (
			strchr(schrme, 'a') != ft_strchr(schrme, 'a') ||
			strchr(schrme, 107) != ft_strchr(schrme, 107) ||
			strchr(schrme, 'o') != ft_strchr(schrme, 'o') ||  			
			strchr(schrme, 115) != ft_strchr(schrme, 115) ||
			strchr(schrme, 0) != ft_strchr(schrme, 0) 
	   )
	{
		printf("ERRROR\n");
		printf("%s %s\n", strchr(schrme, 'a'), ft_strchr(schrme, 'a'));
		printf("%s %s\n", strchr(schrme, 109), ft_strchr(schrme, 109));
		printf("%s %s\n", strchr(schrme, 'o'), ft_strchr(schrme, 'o'));
		printf("%s %s\n", strchr(schrme, 115), ft_strchr(schrme, 115));
		printf("%s %s\n", strchr(schrme, 0), ft_strchr(schrme, 0));
	}
	else
		printf("[OK] strchr additional tests\n");
	i = 0;
	while (i <= ft_strlen(schrme))
	{
		if (
				strrchr(schrme, schrme[i]) != ft_strrchr(schrme, schrme[i]) ||
				strrchr(schrme, schrme[i + i]) != ft_strrchr(schrme, schrme[i + i]) ||
				strrchr(schrme, schrme[i - i]) != ft_strrchr(schrme, schrme[i - i]) ||
				strrchr(schrme, schrme[i * i]) != ft_strrchr(schrme, schrme[i * i])
		   )
		{
			printf("ERRROR i: %d %c\n", i,schrme[i]);
			printf("%s %s\n", strrchr(schrme, schrme[i]), ft_strrchr(schrme, schrme[i]));
			printf("%s %s\n", strrchr(schrme, schrme[i + i]), ft_strrchr(schrme, schrme[i + i]));
			printf("%s %s\n", strrchr(schrme, schrme[i - i]), ft_strrchr(schrme, schrme[i - i]));
			printf("%s %s\n", strrchr(schrme, schrme[i * i]), ft_strrchr(schrme, schrme[i * i]));
		}
		else
			printf("[OK] strrchr%d\n", i);
		i++;
	}
	if (
			strrchr(schrme, 'a') != ft_strrchr(schrme, 'a') ||
			strrchr(schrme, 'G') != ft_strrchr(schrme, 'G') ||
			strrchr(schrme, 73) != ft_strrchr(schrme, 73) ||  			
			strrchr(schrme, 115) != ft_strrchr(schrme, 115) ||
			strrchr(schrme, 0) != ft_strrchr(schrme, 0) 
	   )
	{
		printf("ERRROR\n");
		printf("%s %s\n", strrchr(schrme, 'a'), ft_strrchr(schrme, 'a'));
		printf("%s %s\n", strrchr(schrme, 'G'), ft_strrchr(schrme, 'G'));
		printf("%s %s\n", strrchr(schrme, 'I'), ft_strrchr(schrme, 'I'));
		printf("%s %s\n", strrchr(schrme, 115), ft_strrchr(schrme, 115));
		printf("%s %s\n", strrchr(schrme, 0), ft_strrchr(schrme, 0));
	}
	else
		printf("[OK] strrchr additional tests\n");
	i = 0;
	while (i <= 50)
	{
		if (
				strnstr(cmp1, cmp1, i) != ft_strnstr(cmp1, cmp1, i) ||
				strnstr(cmp1, cmp2, i) != ft_strnstr(cmp1, cmp2, i) ||
				strnstr(cmp2, cmp1, i) != ft_strnstr(cmp2, cmp1, i) ||
				strnstr(cmp2, cmp2, i) != ft_strnstr(cmp2, cmp2, i) ||
				strnstr(cmp3, cmp3, i) != ft_strnstr(cmp3, cmp3, i) ||
				strnstr(cmp3, cmp4, i) != ft_strnstr(cmp3, cmp4, i) ||
				strnstr(cmp4, cmp3, i) != ft_strnstr(cmp4, cmp3, i) ||
				strnstr(cmp4, cmp4, i) != ft_strnstr(cmp4, cmp4, i) ||
				strnstr(cmp5, cmp5, i) != ft_strnstr(cmp5, cmp5, i) ||
				strnstr(cmp5, cmp6, i) != ft_strnstr(cmp5, cmp6, i) ||
				strnstr(cmp6, cmp5, i) != ft_strnstr(cmp6, cmp5, i) ||
				strnstr(cmp6, cmp6, i) != ft_strnstr(cmp6, cmp6, i) ||
				strnstr(cmp7, cmp7, i) != ft_strnstr(cmp7, cmp7, i) ||
				strnstr(cmp7, cmp8, i) != ft_strnstr(cmp7, cmp8, i) ||
				strnstr(cmp8, cmp7, i) != ft_strnstr(cmp8, cmp7, i) ||
				strnstr(cmp8, cmp8, i) != ft_strnstr(cmp8, cmp8, i) ||
				strnstr(cmp8, cmp9, i) != ft_strnstr(cmp8, cmp9, i) ||
				strnstr(cmp9, cmp8, i) != ft_strnstr(cmp9, cmp8, i) ||
				strnstr(cmp9, cmp9, i) != ft_strnstr(cmp9, cmp9, i) ||
				strnstr(cmp9, cmp10, i) != ft_strnstr(cmp9, cmp10, i) ||
				strnstr(cmp10, cmp9, i) != ft_strnstr(cmp10, cmp9, i) ||
				strnstr(cmp10, cmp10, i) != ft_strnstr(cmp10, cmp10, i) ||
				strnstr(cmp10, cmp11, i) != ft_strnstr(cmp10, cmp11, i) ||
				strnstr(cmp11, cmp10, i) != ft_strnstr(cmp11, cmp10, i) ||
				strnstr(cmp11, cmp11, i) != ft_strnstr(cmp11, cmp11, i)
		   )
		{
			printf("ERROR i: %d\n", i);
			printf("%s %s\n", strnstr(cmp1, cmp1, i), ft_strnstr(cmp1, cmp1, i));
			printf("%s %s\n", strnstr(cmp1, cmp2, i), ft_strnstr(cmp1, cmp2, i));
			printf("%s %s\n", strnstr(cmp2, cmp1, i), ft_strnstr(cmp2, cmp1, i));
			printf("%s %s\n", strnstr(cmp2, cmp2, i), ft_strnstr(cmp2, cmp2, i));
			printf("%s %s\n", strnstr(cmp3, cmp3, i), ft_strnstr(cmp3, cmp3, i));
			printf("%s %s\n", strnstr(cmp3, cmp4, i), ft_strnstr(cmp3, cmp4, i));
			printf("%s %s\n", strnstr(cmp4, cmp3, i), ft_strnstr(cmp4, cmp3, i));
			printf("%s %s\n", strnstr(cmp4, cmp4, i), ft_strnstr(cmp4, cmp4, i));
			printf("%s %s\n", strnstr(cmp5, cmp5, i), ft_strnstr(cmp5, cmp5, i));
			printf("%s %s\n", strnstr(cmp5, cmp6, i), ft_strnstr(cmp5, cmp6, i));
			printf("%s %s\n", strnstr(cmp6, cmp5, i), ft_strnstr(cmp6, cmp5, i));
			printf("%s %s\n", strnstr(cmp6, cmp6, i), ft_strnstr(cmp6, cmp6, i));
			printf("%s %s\n", strnstr(cmp7, cmp7, i), ft_strnstr(cmp7, cmp7, i));
			printf("%s %s\n", strnstr(cmp7, cmp8, i), ft_strnstr(cmp7, cmp8, i));
			printf("%s %s\n", strnstr(cmp8, cmp7, i), ft_strnstr(cmp8, cmp7, i));
			printf("%s %s\n", strnstr(cmp8, cmp8, i), ft_strnstr(cmp8, cmp8, i));
			printf("%s %s\n", strnstr(cmp8, cmp9, i), ft_strnstr(cmp8, cmp9, i));
			printf("%s %s\n", strnstr(cmp9, cmp8, i), ft_strnstr(cmp9, cmp8, i));
			printf("%s %s\n", strnstr(cmp9, cmp9, i), ft_strnstr(cmp9, cmp9, i));
			printf("%s|%s\n", strnstr(cmp9, cmp10, i), ft_strnstr(cmp9, cmp10, i));
			printf("%s|%s\n", strnstr(cmp10, cmp9, i), ft_strnstr(cmp10, cmp9, i));
			printf("%s|%s\n", strnstr(cmp10, cmp10, i), ft_strnstr(cmp10, cmp10, i));
			printf("%s|%s\n", strnstr(cmp10, cmp11, i), ft_strnstr(cmp10, cmp11, i));
			printf("%s|%s\n", strnstr(cmp11, cmp10, i), ft_strnstr(cmp11, cmp10, i));
			printf("%s|%s\n", strnstr(cmp11, cmp11, i), ft_strnstr(cmp11, cmp11, i));
		}
		else
			printf("[OK] strnstr%d\n", i);
		i++;
	}
	i = 0;
	while (i <= 50)
	{
		if (
				strncmp(cmp1, cmp1, i) != ft_strncmp(cmp1, cmp1, i) ||
				strncmp(cmp1, cmp2, i) != ft_strncmp(cmp1, cmp2, i) ||
				strncmp(cmp2, cmp1, i) != ft_strncmp(cmp2, cmp1, i) ||
				strncmp(cmp2, cmp2, i) != ft_strncmp(cmp2, cmp2, i) ||
				strncmp(cmp3, cmp3, i) != ft_strncmp(cmp3, cmp3, i) ||
				strncmp(cmp3, cmp4, i) != ft_strncmp(cmp3, cmp4, i) ||
				strncmp(cmp4, cmp3, i) != ft_strncmp(cmp4, cmp3, i) ||
				strncmp(cmp4, cmp4, i) != ft_strncmp(cmp4, cmp4, i) ||
				strncmp(cmp5, cmp5, i) != ft_strncmp(cmp5, cmp5, i) ||
				strncmp(cmp5, cmp6, i) != ft_strncmp(cmp5, cmp6, i) ||
				strncmp(cmp6, cmp5, i) != ft_strncmp(cmp6, cmp5, i) ||
				strncmp(cmp6, cmp6, i) != ft_strncmp(cmp6, cmp6, i) ||
				strncmp(cmp7, cmp7, i) != ft_strncmp(cmp7, cmp7, i) ||
				strncmp(cmp7, cmp8, i) != ft_strncmp(cmp7, cmp8, i) ||
				strncmp(cmp8, cmp7, i) != ft_strncmp(cmp8, cmp7, i) ||
				strncmp(cmp8, cmp8, i) != ft_strncmp(cmp8, cmp8, i) ||
				strncmp(cmp8, cmp9, i) != ft_strncmp(cmp8, cmp9, i) ||
				strncmp(cmp9, cmp8, i) != ft_strncmp(cmp9, cmp8, i) ||
				strncmp(cmp9, cmp9, i) != ft_strncmp(cmp9, cmp9, i) ||
				strncmp(cmp9, cmp10, i) != ft_strncmp(cmp9, cmp10, i) ||
				strncmp(cmp10, cmp9, i) != ft_strncmp(cmp10, cmp9, i) ||
				strncmp(cmp10, cmp10, i) != ft_strncmp(cmp10, cmp10, i) ||
				strncmp(cmp10, cmp11, i) != ft_strncmp(cmp10, cmp11, i) ||
				strncmp(cmp11, cmp10, i) != ft_strncmp(cmp11, cmp10, i) ||
				strncmp(cmp11, cmp11, i) != ft_strncmp(cmp11, cmp11, i)
		   )
		{
			printf("ERROR i: %d\n", i);
			printf("%d %d\n", strncmp(cmp1, cmp1, i), ft_strncmp(cmp1, cmp1, i));
			printf("%d %d\n", strncmp(cmp1, cmp2, i), ft_strncmp(cmp1, cmp2, i));
			printf("%d %d\n", strncmp(cmp2, cmp1, i), ft_strncmp(cmp2, cmp1, i));
			printf("%d %d\n", strncmp(cmp2, cmp2, i), ft_strncmp(cmp2, cmp2, i));
			printf("%d %d\n", strncmp(cmp3, cmp3, i), ft_strncmp(cmp3, cmp3, i));
			printf("%d %d\n", strncmp(cmp3, cmp4, i), ft_strncmp(cmp3, cmp4, i));
			printf("%d %d\n", strncmp(cmp4, cmp3, i), ft_strncmp(cmp4, cmp3, i));
			printf("%d %d\n", strncmp(cmp4, cmp4, i), ft_strncmp(cmp4, cmp4, i));
			printf("%d %d\n", strncmp(cmp5, cmp5, i), ft_strncmp(cmp5, cmp5, i));
			printf("%d %d\n", strncmp(cmp5, cmp6, i), ft_strncmp(cmp5, cmp6, i));
			printf("%d %d\n", strncmp(cmp6, cmp5, i), ft_strncmp(cmp6, cmp5, i));
			printf("%d %d\n", strncmp(cmp6, cmp6, i), ft_strncmp(cmp6, cmp6, i));
			printf("%d %d\n", strncmp(cmp7, cmp7, i), ft_strncmp(cmp7, cmp7, i));
			printf("%d %d\n", strncmp(cmp7, cmp8, i), ft_strncmp(cmp7, cmp8, i));
			printf("%d %d\n", strncmp(cmp8, cmp7, i), ft_strncmp(cmp8, cmp7, i));
			printf("%d %d\n", strncmp(cmp8, cmp8, i), ft_strncmp(cmp8, cmp8, i));
			printf("%d %d\n", strncmp(cmp8, cmp9, i), ft_strncmp(cmp8, cmp9, i));
			printf("%d %d\n", strncmp(cmp9, cmp8, i), ft_strncmp(cmp9, cmp8, i));
			printf("%d %d\n", strncmp(cmp9, cmp9, i), ft_strncmp(cmp9, cmp9, i));
			printf("%d|%d\n", strncmp(cmp9, cmp10, i), ft_strncmp(cmp9, cmp10, i));
			printf("%d|%d\n", strncmp(cmp10, cmp9, i), ft_strncmp(cmp10, cmp9, i));
			printf("%d|%d\n", strncmp(cmp10, cmp10, i), ft_strncmp(cmp10, cmp10, i));
			printf("%d|%d\n", strncmp(cmp10, cmp11, i), ft_strncmp(cmp10, cmp11, i));
			printf("%d|%d\n", strncmp(cmp11, cmp10, i), ft_strncmp(cmp11, cmp10, i));
			printf("%d|%d\n", strncmp(cmp11, cmp11, i), ft_strncmp(cmp11, cmp11, i));
		}
		else
			printf("[OK] strncmp%d\n", i);
		i++;
	}
	char subme[] = "hello how are you";
	printf("%s||%s\n", subme, ft_substr(subme, 10, 50));
	printf("%s||%s\n", &subme[3], ft_substr(subme, 3, 5));
	printf("%s||%s\n", &subme[7], ft_substr(subme, 7, ft_strlen(subme)));
	printf("%s\n", ft_substr(0, 7, ft_strlen(subme)));
	char *hw = "안 Đihi how are youdㅇㅓ";
	char *set = "안 Đdㅇㅓu";
	printf("strtrim:%s\n", ft_strtrim(hw, set));
	char splitme[] = "hi how are you";
	char **result;
	result = ft_split(splitme, ' ');
	char *s = "      split       this for   me  !       ";
	char *s1 = "split  ||this|for|me|||||!|";
	i = 0;
	while (result[i])
	{
		printf("%s,", result[i++]);
	}
	result = ft_split(s, ' ');
	printf("\n\n");
	while (*result)
		printf("%s/", *result++);
	result = ft_split(s1, '|');
	printf("\n\n");
	while (*result)
		printf("%s,", *result++);
}
