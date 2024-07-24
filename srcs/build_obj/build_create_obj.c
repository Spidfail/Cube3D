#include "../../inc/build.h"

t_plist	*ft_create_sprite(t_oinfo *info)
{
	t_plist		*tmp;

	tmp = NULL;
	tmp = ft_raylst_new();
	if (tmp == NULL)
	{
		ft_error_node(4, 1, 0, "ft_create_wall");
		return (NULL);
	}
	ft_set_things_point(tmp, info);
	return (tmp);
}

t_plist	*ft_raylst_new(void)
{
	t_plist		*link;

	link = ft_calloc(1, sizeof(t_plist));
	if (!link)
		return (NULL);
	return (link);
}
