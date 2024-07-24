#include "../../inc/build.h"

t_error	ft_build_sprite_if_possible(t_oinfo *info, t_objlst *objlst)
{
	t_plist		*rlink;
	t_list		*tmp;

	rlink = NULL;
	tmp = NULL;
	rlink = ft_create_sprite(info);
	if (rlink == NULL)
		return (E_ERROR);
	rlink->id = PL_SPR;
	tmp = ft_lstnew(rlink);
	if (!tmp)
		return (ft_error_node(4, 3, 0, "ft_set_sprite"));
	ft_lstadd_back(&(objlst->lst_thgs), tmp);
	return (E_TRUE);
}
