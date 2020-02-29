/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:27:27 by mpark-ki          #+#    #+#             */
/*   Updated: 2020/02/29 20:49:22 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
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
	char				*value;
}				t_printf;
int				ft_isdi(char c);
int				ft_isu(char c);
int				ft_iso(char c);
int				ft_isx(char c);
int				ft_isf(char c);
int				ft_isp(char c);
int				ft_ise(char c);
int				ft_isn(char c);
int				ft_isc(char c);
int				ft_iss(char c);
int				ft_iszero(char *str);
int				ft_ispercent(char c);
int				ft_isspecif(char c);
int				ft_isflag(char c);
int				ft_is_num_asterisk(char c);
int				ft_get_num_asterisk(char *str, va_list args);
char			*ft_getsign(t_printf *tmp);
char			*ft_getvalue(char specif, va_list args);
int				ft_save_format(t_printf *tmp, const char **format,
				va_list args);
void			ft_format_prec(t_printf *tmp, char **sign);
int				ft_print_all(t_printf *tmp);
int				ft_printf(const char *format, ...);

#endif
