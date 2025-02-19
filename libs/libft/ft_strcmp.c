#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (s1[i])
	{
		if (us1[i] != us2[i] || !us1[i] || !us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (s1[i] != s2[i])
		return (us1[i] - us2[i]);
	return (0);
}
