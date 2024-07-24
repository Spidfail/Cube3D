#include "libft.h"
#include <stdio.h>

void	ft_lstcleanlst(t_list **lst, void (*del)(void *))
{
	t_list		*tmp;

	tmp = NULL;
	if (lst == NULL || *lst == NULL)
		return ;
	tmp = *lst;
	while (tmp)
	{
		tmp = (*lst)->next;
		del(*lst);
		*lst = tmp;
	}
	return ;
}
