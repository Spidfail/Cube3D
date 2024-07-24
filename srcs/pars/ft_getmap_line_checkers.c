#include "../../inc/leader.h"
#include "../../inc/pars.h"

t_error	ft_ismap(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'W' || c == 'S'
		|| c == 'E' || c == ' ')
		return (E_TRUE);
	return (E_ERROR);
}

t_error	ft_getmap_line_exam(char *s, t_map *map, bool *berr)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_ismap(s[i]) == E_ERROR)
		{
			if (*berr == true)
			{
				ft_error_node(PS_MAP, EM_WMAP, 0, "ft_getmap_line_exam");
				printf("\n==============================================\n");
				printf("	===> Incorrect map lines :\n\n");
				*berr = false;
			}
			ft_print_line(map->buff, map->lnu + 1);
			*berr = false;
			return (E_TRUE);
		}
		i++;
	}
	return (E_TRUE);
}
