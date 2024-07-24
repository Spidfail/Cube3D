#include "libft.h"

static int	ft_dblfree(void **pt, int nb)
{
	int		i;

	i = 0;
	if (pt == NULL || nb == 0)
		return (-1);
	while (i <= nb)
	{
		pt[i] = ft_free(pt[i]);
		i++;
	}
	pt = ft_free(pt);
	return (-1);
}

char	**ft_dbl_chrcalloc(size_t count1, size_t count2)
{
	char	**rtn;
	size_t	i;

	i = 0;
	rtn = NULL;
	if (count1 < 1)
		return (NULL);
	if (count2 == 0)
		return (rtn);
	rtn = ft_calloc(count1, (sizeof(char *)));
	if (rtn == NULL)
		return (NULL);
	while (i < count1)
	{
		rtn[i] = ft_calloc(count2, (sizeof(char)));
		if (rtn[i] == NULL)
			ft_dblfree((void **)rtn, i - 1);
		i++;
	}
	return (rtn);
}
