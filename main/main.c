/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:25:26 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/27 20:23:38 by myntcake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "../ft_printf.h"

int		main(void)
{
	long int z;
	long int y;
	int		 d = 0;
	int		 i = 0;
	int		 u = 0;
	int		 c = 0;
	int		 f = 0;
	int		 w = 0;
	int		 o = 0;
	int		 x = 0;
	int		 s = 0;
	int		 p = 0;
	char *ss;

	ss = ft_strdup("Hello how are you?");
	z = -4294967295;
	y = 4294967295;

	while (z <= 4294967295)
	{
		if (ft_printf("Hola %d %d\n", (int)z, (int)y)
				!= printf("Hola %d %d\n", (int)z, (int)y))
		{
			printf("[FAIL] with %%d at i = %d\n", (int)z);
			d++;
		}
		if (ft_printf("Hola %i %i\n", (int)z, (int)y)
				!= printf("Hola %i %i\n", (int)z, (int)y))
		{
			printf("[FAIL] with %%i at i = %d\n", (int)z);
			i++;
		}
		if (ft_printf("Hola %u %c %u\n", (int)z, (char)z, (int)y)
				!= printf("Hola %u %c %u\n", (int)z, (char)z, (int)y))
		{
			printf("[FAIL] with %%u at i = %d\n", (int)z);
			u++;
		}
		z += 654321;
		y -= 654321;
	}
	z = 0;
	while (z < 255)
	{
		if (ft_printf("Hola %c %d\n", (char)z, (int)z)
				!= printf("Hola %c %d\n", (char)z, (int)z))
		{
			printf("[FAIL] with %%d at c = %d\n", (int)z);
			c++;
		}
		z++;
	}
	if (ft_printf("Hola %%\n")
			!= printf("Hola %%\n"))
	{
		printf("[FAIL] with %%");
		w++;
	}
	z = -4294967295;
	while (z <= 4294967295)
	{
		if (ft_printf("Hola %o\n", (int)z)
				!= printf("Hola %o\n", (int)z))
		{
			printf("[FAIL] with %%o at i = %d\n", (int)z);
			o++;
		}
		z += 654321;
	}
	z = -4294967295;
	y = 4294967295;
	while (z <= 4294967295)
	{
		if (ft_printf("Hola %x %x %X %X\n", (int)z, (int)y, (int)z, (int)y)
				!= printf("Hola %x %x %X %X\n", (int)z, (int)y, (int)z, (int)y))
		{
			printf("[FAIL] with %%x or %%X at i = %d\n", (int)z);
			x++;
		}
		z += 654321;
		y -= 654321;
	}
	z = -4294967295;
	y = 4294967295;
	while (z <= 4294967295)
	{
		if (ft_printf("Hola %p %d %p %d\n", &(z), (int)(y), &y, (int)(y))
			!= printf("Hola %p %d %p %d\n", &(z), (int)(y), &y, (int)(y)))
		{
			printf("[FAIL] with %%p at i = %d\n", (int)z);
			p++;
		}
		z += 654321;
		y -= 654321;
	}
	z = 0;
	float	a;
	float	b;
	a = -3.0123f;
	b = 10.51f;
	while (a <= 1.5)
	{
		if (ft_printf("Hola %f %F\n", a, b)
				!= printf("Hola %f %F\n", a, b))
		{
			printf("[FAIL] with %%f or %%F at i = %f\n", a);
			f++;
		}
		a += 0.10f;
		b -= 0.1f;
	}

	a = -200.1;
	b = 10.2;
	while (a <= 12345678911234378)
	{
		if (ft_printf("Hola %f %F\n", a, b)
				!= printf("Hola %f %F\n", a, b))
		{
			printf("[FAIL] with %%f or %%F at i = %f\n", a);
			f++;
		}
		a += 123123451212900.112908123;
		b -= 123512905100.129052123;
	}
	if (ft_printf("Hola %f %F\n", a / 0.0, b / 0.0)
			!= printf("Hola %f %F\n", a / 0.0, b / 0.0))
	{
		printf("[FAIL] with %%f or %%F at i = %f\n", a);
		f++;
	}
	z = 0;
	while (ss[z])
	{
		if (ft_printf("Hola %s\n", ss)
				!= printf("Hola %s\n", ss))
		{
			printf("[FAIL] with %%s at i = %s\n", ss);
			s++;
		}
		ss[z] += 1;
		z++;
	}
	if (!d && !i && !u && !c && !w && !o && !x && !f && !s && !p)
		printf( "[OK] %%d\n"
				"[OK] %%i\n"
				"[OK] %%u\n"
				"[OK] %%c\n"
				"[OK] %%o\n"
				"[OK] %%x\n"
				"[OK] %%f\n"
				"[OK] %%f inf && nan\n"
				"[OK] %%s\n"
				"[OK] %%p\n"
				"[OK] %% \n");
	else
		printf( "[FAIL] %d times %%d\n" 
				"[FAIL] %d times %%i\n" 
				"[FAIL] %d times %%u\n" 
				"[FAIL] %d times %%c\n" 
				"[FAIL] %d times %%o\n" 
				"[FAIL] %d times %%x\n" 
				"[FAIL] %d times %%f\n" 
				"[FAIL] %d times %%f inf || nan\n" 
				"[FAIL] %d times %%s\n" 
				"[FAIL] %d times %%p\n" 
				"[FAIL] %d times %% \n", d, i, u, c, o, x, f, f, s, p, w);
	free(ss);
	return (0);
}
