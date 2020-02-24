/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myntcake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:27:23 by myntcake          #+#    #+#             */
/*   Updated: 2020/02/24 22:36:24 by myntcake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	printf("d:%+5d\n", 1);
	printf("d:% 5d\n", 1);
	printf("d:%05d\n", 1);
	printf("+0d:%+05d\n", 1);
	printf(" 0d:% 05d\n", 1);
	printf("00d:%005d\n", 1);
	printf("d:%+5d\n", 0);
	printf("d:% 5d\n", 0);
	printf("d:%05d\n", 0);
	printf("+d:%+*d\n", 1, 1);
	printf(" d:% *d\n", 1, 1);
	printf("0d:%0*d\n", 1, 1);
	printf("+d:%+*d\n", 1, 0);
	printf(" d:% *d\n", 1, 0);
	printf("0d:%0*d\n", 1, 0);

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
