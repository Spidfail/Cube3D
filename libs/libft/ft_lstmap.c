/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:07:23 by guhernan          #+#    #+#             */
/*   Updated: 2020/12/09 14:57:37 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*simlst;
	t_list	*templst;

	simlst = lst;
	nlst = NULL;
	while (simlst != NULL)
	{
		templst = ft_lstnew(f(simlst->content));
		if (!templst)
		{
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, templst);
		simlst = simlst->next;
	}
	return (nlst);
}
