#include "../../inc/leader.h"
#include "../../inc/pars.h"

static t_error	ft_get_res_convert(int *stct, char **arr)
{
	stct[0] = ft_atoi(arr[1]);
	stct[1] = ft_atoi(arr[2]);
	if (!ft_isstr(arr[1], IS_DIGIT) || !ft_isstr(arr[2], IS_DIGIT))
		return (ft_error_print(" [PARS] Only numbers are available as colors",
				"ft_cvert_rgbhex", E_ERROR));
	if (stct[0] == INT_MIN || stct[0] < RESX_MIN)
		stct[0] = RESX_MIN;
	if (stct[1] == INT_MIN || stct[1] < RESY_MIN)
		stct[1] = RESY_MIN;
	if (stct[0] == INT_MAX || stct[0] > RESX_MAX)
		stct[0] = RESX_MAX;
	if (stct[1] == INT_MAX || stct[1] > RESY_MAX)
		stct[1] = RESY_MAX;
	return (E_TRUE);
}

t_error	ft_get_res(void *stct, char *s)
{
	char		**arr;
	t_error		e;

	e = 0;
	arr = ft_split(s, ' ');
	if (arr == NULL)
		return (E_ERROR);
	if (ft_count_split((void **)arr) != 3)
		return (ft_dblfree((void **)arr, ft_count_split((void **)arr)));
	e = ft_get_res_convert(&stct[0], arr);
	if (e == E_ERROR)
		return (e);
	ft_dblfree((void **)arr, 3);
	return (E_TRUE);
}
