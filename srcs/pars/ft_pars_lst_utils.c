#include "../../inc/pars.h"

static char	**ft_clean_copy_list(t_list **lst, char **buff,
		void (*del)(void *))
{
	ft_error_node(PS_MAP, EM_WEOF, 0, "ft_map_copy_lsize");
	ft_lstclear(lst, del);
	ft_dblfree((void **)buff, ft_count_split((void **)buff));
	return (NULL);
}

char	**ft_map_copy_list(t_map *map, t_list **lstmap)
{
	size_t	ln;
	char	**buff;
	t_list	*templist;

	ln = 0;
	templist = *lstmap;
	buff = NULL;
	buff = ft_calloc(map->m_y[1] + 2, sizeof(char *));
	if (buff == NULL)
		return (ft_clean_copy_list(lstmap, buff, free));
	buff[map->m_y[1] + 1] = NULL;
	while (ln <= map->m_y[1] && templist)
	{	
		buff[ln] = ft_strdup(templist->content);
		if (buff[ln] == NULL)
			return (ft_clean_copy_list(lstmap, buff, free));
		templist = templist->next;
		ln++;
	}
	map->lnu = ln;
	ft_lstclear(lstmap, free);
	return (buff);
}
