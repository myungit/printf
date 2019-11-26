/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:42:36 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/26 13:41:24 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newcont;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		if ((newcont = ft_lstnew(f(lst->content))))
		{
			ft_lstadd_back(&newlst, newcont);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
	}
	return (newlst);
}
