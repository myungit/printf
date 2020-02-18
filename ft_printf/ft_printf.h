/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:27:27 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/18 11:21:02 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>

char			*ft_uitoa(unsigned int n);
char			*ft_ouitoa(unsigned int n);
char			*ft_xitoa(unsigned long int n);
char			*ft_ltoa(long int n);
char			*ft_ftoa(float n);
int				ft_sqrt(int nb);
typedef struct	s_printf
{
	char				*flags;
	int					width;
	int					prec;
	char				specif;
}				t_printf;
int				ft_printf(const char *format, ...);
char			*ft_flags(t_printf **prototyp, char *value);
void			ft_save_fwp(t_printf **prototyp, const char **format,
				va_list args);
#endif
