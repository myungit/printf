/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:02:16 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/18 11:37:52 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

enum			e_list
{
	e_list_val1 = 7,
	e_list_val2 = 7,
	e_list_val3
};

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

#include <stdio.h>
int		main(void)
{
	/*
	enum e_list a;
	t_point am;
	t_point b;
	t_point *ptr;

	am.x = 10;
	am.y = 42;
	b = am;
	ptr = &am;
	ptr->x = 11;
	ptr->x = 12;
	a = e_list_val3;
	*/

	ft_printf("1:%+10d\n", 123);
	printf("2:%+10d\n", 123);
	ft_printf("1:%---++---5d\n", 123);
	printf("2:%---++---5d\n", 123);
	ft_printf("1:%0+005d\n", 123);
	printf("2:%0+005d\n", 123);
	ft_printf("1:%0005d\n", 123);
	printf("2:%0005d\n", 123);
	ft_printf("%+-20d\n", 222);
	printf("%+-20d\n", 222);
	ft_printf("%+020d\n", 222);
	printf("%+020d\n", 222);
	ft_printf("%0+20d\n", 222);
	printf("%0+20d\n", 222);
	ft_printf("% -20d\n", 333);
	printf("% -20d\n", 333);
	ft_printf("% 020d\n", 333);
	printf("% 020d\n", 333);
	ft_printf("%0 20d\n", 333);
	printf("%0 20d\n", 333);
	ft_printf("%+-20d\n", -222);
	printf("%+-20d\n", -222);
	ft_printf("%+020d\n", -222);
	printf("%+020d\n", -222);
	ft_printf("%0+20d\n", -222);
	printf("%0+20d\n", -222);
	ft_printf("% -20d\n", -333);
	printf("% -20d\n", -333);
	ft_printf("% 020d\n", -333);
	printf("% 020d\n", -333);
	ft_printf("%0 20d\n", -333);
	printf("%0 20d\n", -333);
	printf("%0*d\n", 20, 333);
	ft_printf("%0*d\n", 20, 333);
	ft_printf("% *d\n", ' ', 444);
	printf("% *d\n", ' ', 444);
	ft_printf("% *d\n", '-', 444);
	printf("% *d\n", '-', 444);
	
	printf("\nX x o:\n");
	ft_printf("%#20x\n", 123);
	printf("%#20x\n", 123);
	ft_printf("%#20X\n", 123);
	printf("%#20X\n", 123);
	ft_printf("%#020x\n", 123);
	printf("%#020x\n", 123);
	ft_printf("%#20x\n", -123);
	printf("%#20x\n", -123);
	ft_printf("%#20X\n", -123);
	printf("%#20X\n", -123);
	ft_printf("%#020x\n", -123);
	printf("%#020x\n", -123);
	ft_printf("%#020x\n", 0);
	printf("%#020x\n", 0);
	ft_printf("%#0x\n", 0);
	printf("%#0x\n", 0);
	ft_printf("%-       --    5d\n", 123);
	printf("%-       --    5d\n", 123);
	ft_printf("%+5d\n", 123);
	printf("%+5d\n", 123);
	ft_printf("%+0d\n", 123);
	printf("%+0d\n", 123);
	ft_printf("%+-5d\n", 123);
	printf("%+-5d\n", 123);
	ft_printf("%-+5d\n", 123);
	printf("%-+5d\n", 123);
	ft_printf("% 5d\n", 123);
	printf("% 5d\n", 123);
	ft_printf("%05d\n", 123);
	printf("%05d\n", 123);
	ft_printf("%-*d\n", 5, 123);
	printf("%-*d\n", 5, 123);
	ft_printf("%-*d\n", 5, 123);
	printf("%-*d\n", 5, 123);
	ft_printf("%*d\n", 5, 123);
	printf("%*d\n", 5, 123);
	ft_printf("%*d\n", '%', 123);
	printf("%*d\n", '%', 123);
	ft_printf("%10%\n");
	printf("%10%\n");
	ft_printf("%-10%\n");
	printf("%-10%\n");

	char hi[] = "tests";
	ft_printf("2:%s.\n", ft_allcaps(hi));
	printf("1:%s.\n", ft_allcaps(hi));
	ft_printf("2:%.0s.\n", ft_allcaps(hi));
	printf("1:%.0s.\n", ft_allcaps(hi));
	ft_printf("2:%.2s.\n", ft_allcaps(hi));
	printf("1:%.2s.\n", ft_allcaps(hi));
	printf("1:%05.6d.\n", 124);
	ft_printf("2:%05.6d.\n", 124);
	printf("1:%-.5d.\n", 123);
	ft_printf("2:%-.5d.\n", 123);
	printf("1:%-5.5d.\n", 125);
	ft_printf("2:%-5.5d.\n", 125);
	printf("1:%5.5d.\n", 125);
	ft_printf("2:%5.5d.\n", 125);
	printf("1:%-7.5d.\n", 126);
	ft_printf("2:%-7.5d.\n", 126);
	printf("1:%7.5d.\n", 127);
	ft_printf("2:%7.5d.\n", 127);
	printf("1:%7.0d.\n", 128);
	ft_printf("2:%7.0d.\n", 128);
	printf("1:%-7..5d.\n", 126);
	ft_printf("2:%-7..5d.\n", 126);
	system("leaks a.out");
	/*
	printf("%-4.0d\n", 123);
	ft_printf("1:%+10.0d\n", 123);
	printf("2:%+10.0d\n", 123);
	ft_printf("1:%---++---5.0d\n", 123);
	printf("2:%---++---5.0d\n", 123);
	*/
	/*
	printf("other\n");
	printf("%+c\n", 'H');
	printf("%+s\n", "H");
	printf("%+d\n", 111);
	printf("%+u\n", 111);
	printf("%+o\n", 111);
	printf("%+x\n", 111);

	printf("%+10.15d\n", 123);
	printf("%+15.10d\n", 123);
	printf("%-5.*x", 0, 123);
	printf("%10d\n", 123);
	printf("%*.*d\n", 10, 0, 123);
	printf("%10.0d\n", 123);
	*/
	return (0);
}

