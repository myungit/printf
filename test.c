/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:41:39 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/26 00:41:42 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	int i;

	i = 0;
	i = printf("5d:%5d.\n5d:%5d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("+5d:%+5d.\n+5d:%+5d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf(" 5d:% 5d.\n 5d:% 5d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("05d:%05d.\n05d:%05d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("+05d:%+05d.\n+05d:%05d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf(" 05d:% 05d.\n 05d:% 05d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("005d:%005d.\n005d:%005d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("5x:%5x.\n5x:%5x.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("+5x:%+5x.\n+5x:%+5x.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf(" 5x:% 5x.\n 5x:% 5x.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("05x:%05x.\n05x:%05x.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("+05x:%+05x.\n+05x:%05x.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf(" 05x:% 05x.\n 05x:% 05x.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("005x:%005x.\n005x:%005x.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#05x:%#05x.\n#05x:%#05x.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#05x:%#05x.\n#05x:%#05x.\n", 0, -0);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#05x:%#x.\n#05x:%#x.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#05x:%#x.\n#05x:%#x.\n", 0, -0);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#0.5x:%#0.5x.\n#0.5x:%#0.5x.\n", 0, -0);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#0.5x:%#0.5x.\n#0.5x:%#0.5x.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#0.5d:%#0.5d.\n#0.5d:%#0.5d.\n", 0, -0);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#0.5d:%#0.5d.\n#0.5d:%#0.5d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#0.5d:%+0.5d.\n#0.5d:%+0.5d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#0.5d:%0.5d.\n#0.5d:%0.5d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#0.5d:% 0.5d.\n#0.5d:% 0.5d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#0.d:% 0.d.\n#0.d:% 0.d.\n", 1, -1);
	printf("i:%d\n", i);
	i = 0;
	i = printf(".d:% .d.\n.d:% .d.\n", 0, -0);
	printf("i:%d\n", i);
	i = 0;
	/*
	i = printf("d:%+5d\n", 0);
	printf("i:%d\n", i);
	i = 0;
	i = printf("d:% 5d\n", 0);
	printf("i:%d\n", i);
	i = 0;
	i = printf("d:%05d\n", 0);
	printf("i:%d\n", i);
	i = 0;
	i = printf("+d:%+*d\n", 1, 1);
	printf("i:%d\n", i);
	i = 0;
	i = printf(" d:% *d\n", 1, 1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("0d:%0*d\n", 1, 1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("+d:%+*d\n", 1, 0);
	printf("i:%d\n", i);
	i = 0;
	i = printf(" d:% *d\n", 1, 0);
	printf("i:%d\n", i);
	i = 0;
	i = printf("0d:%0*d\n", 1, 0);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#x:%#0*x\n", 3, 1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#x:%#0*x\n", 3, 0);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#x:%#*x\n", 3, 1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#x:%#*x\n", 3, 0);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#x:%#x\n", 1);
	printf("i:%d\n", i);
	i = 0;
	i = printf("#x:%#x\n", 0);
	printf("i:%d\n", i);
	i = 0;
	*/
	
	/*
	   printf("d:%+5d\n", 234);
	printf("d:% 5d\n", 234);
	printf("d:%#5d\n", 234);
	printf("d:%05d\n", 234);
	printf("d:%+2d\n", 233);
	printf("d:% 2d\n", 233);
	printf("d:%#2d\n", 233);
	printf("d:%02d\n", 233);
	printf("x:%+5x\n", 232);
	printf("x:% 5x\n", 232);
	printf("x:%#5x\n", 232);
	printf("x:%05x\n", 232);
	printf("x:%+2x\n", 231);
	printf("x:% 2x\n", 231);
	printf("x:%#2x\n", 231);
	printf("x:%02x\n", 231);
	printf("X:%+5X\n", 232);
	printf("X:% 5X\n", 232);
	printf("X:%#5X\n", 232);
	printf("X:%05X\n", 232);
	printf("X:%+2X\n", 231);
	printf("X:% 2X\n", 231);
	printf("X:%#2X\n", 231);
	printf("X:%02X\n", 231);
	printf("f:%+5f\n", 238);
	printf("f:% 5f\n", 238);
	printf("f:%#5f\n", 238);
	printf("f:%05f\n", 238);
	printf("f:%+2f\n", 230);
	printf("f:% 2f\n", 230);
	printf("f:%#2f\n", 230);
	printf("f:%02f\n", 230);
	printf("F:%+5F\n", 238);
	printf("F:% 5F\n", 238);
	printf("F:%#5F\n", 238);
	printf("F:%05F\n", 238);
	printf("F:%+2F\n", 230);
	printf("F:% 2F\n", 230);
	printf("F:%#2F\n", 230);
	printf("F:%02F\n", 230);
	*/
}
