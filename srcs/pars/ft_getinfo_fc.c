#include "../../inc/pars.h"

static t_error	ft_chk_rgbnum(char **arr)
{
	int			i;
	t_error		e;

	i = 0;
	e = 0;
	if (arr == NULL)
		return (ft_error_node(PS_GEN, 2, 0, "ft_chk_rgbnum"));
	else if (*(arr[0]) == '-' || *(arr[1]) == '-' || *(arr[2]) == '-')
		return (ft_error_node(PS_INF, 14, 0, "ft_chk_rgbnum"));
	while (arr[i])
	{
		e = ft_isstr(arr[i], IS_DIGIT);
		if (!e)
			return (e);
		i++;
	}
	return (E_TRUE);
}

static int	ft_cvert_rgbhex(char **arr)
{
	int		rtn;
	int		r;
	int		g;
	int		b;

	if (arr == NULL || ft_count_split((void **)arr) != 3)
		return (ft_error_node(PS_INF, 8, 0, "ft_chk_rgbhex"));
	if (!ft_isstr(arr[0], IS_DIGIT) || !ft_isstr(arr[1], IS_DIGIT)
		|| !ft_isstr(arr[2], IS_DIGIT))
		return (ft_error_print(" [PARS] Only numbers are available as colors",
				"ft_cvert_rgbhex", E_ERROR));
	r = ft_atoi(arr[0]);
	g = ft_atoi(arr[1]);
	b = ft_atoi(arr[2]);
	if (r > 255 || g > 255 || b > 255)
		return (ft_error_node(PS_INF, 14, 0, "ft_chk_rgbhex"));
	if (r < 0 || g < 0 || b < 0)
		return (ft_error_node(PS_INF, 14, 0, "ft_chk_rgbhex"));
	rtn = r * 0x10000 + g * 0x100 + b * 0x1;
	return (rtn);
}

static t_error	ft_get_rgb(char *src, int *dst)
{
	char	**clrtemp;

	clrtemp = ft_split(src, ',');
	if (clrtemp == NULL)
		return (E_ERROR);
	if (ft_count_split((void **)clrtemp) != 3)
	{
		ft_error_node(PS_INF, 8, 0, "ft_chk_rgbhex");
		return (ft_dblfree((void **)clrtemp,
				ft_count_split((void **)clrtemp)));
	}
	else if (E_ERROR == ft_chk_rgbnum(clrtemp))
		return (ft_dblfree((void **)clrtemp,
				ft_count_split((void **)clrtemp)));
	*dst = ft_cvert_rgbhex(clrtemp);
	if (*dst == E_ERROR)
		return (ft_dblfree((void **)clrtemp,
				ft_count_split((void **)clrtemp)));
	ft_dblfree((void **)clrtemp, ft_count_split((void **)clrtemp));
	return (E_TRUE);
}

t_error	ft_is_color_or_texture(t_error color, t_error texture)
{
	if (color == E_ERROR || texture == E_ERROR)
		return (E_ERROR);
	if ((color == E_TRUE && texture == E_TRUE)
		|| (color != E_TRUE && texture != E_TRUE))
		return (E_ERROR);
	return (E_TRUE);
}

t_error	ft_get_color(void *stct, char *s)
{
	char	**temp;

	temp = NULL;
	if (ft_strnstr_nb(s, "./", ft_strlen(s)) > 0)
		return (E_STOP);
	if (ft_strnstr_nb(s, ",", ft_strlen(s)) != 2)
		return (E_STOP);
	temp = ft_split(s, ' ');
	if (temp == NULL)
		return (E_ERROR);
	if (ft_count_split((void **)temp) != 2)
		return (ft_dblfree((void **)temp, ft_count_split((void **)temp)));
	if (ft_get_rgb(temp[1], (int *)stct) == E_ERROR)
		return (ft_dblfree((void **)temp, ft_count_split((void **)temp)));
	ft_dblfree((void **)temp, ft_count_split((void **)temp));
	return (E_TRUE);
}
