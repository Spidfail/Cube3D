#include "libft.h"

void	ft_lstdelone_lst(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst);
}
