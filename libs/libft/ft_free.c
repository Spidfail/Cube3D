#include "libft.h"

void	*ft_free(void *obj)
{
	if (obj)
		free(obj);
	return (NULL);
}
