/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:46:40 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/21 18:24:13 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	if ((tmp = (t_list *)malloc(sizeof(t_list))))
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}
