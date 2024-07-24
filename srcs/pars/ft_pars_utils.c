#include "../../inc/pars.h"

size_t	ft_space_escape(char *s, size_t i)
{
	while (s[i] == ' ')
		i++;
	return (i);
}

t_error	ft_isemptyline(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (E_STOP);
		i++;
	}
	return (E_TRUE);
}

char	*ft_check_open(char *s)
{
	int	tfd;

	if (s == NULL)
	{
		ft_error_node(PS_GEN, EG_FD, 1, "ft_check_open");
		return (NULL);
	}
	tfd = open(s, O_RDONLY);
	if (-1 == tfd)
	{
		ft_error_node(PS_GEN, EG_FD, 1, "ft_check_open");
		return (NULL);
	}
	else
		close(tfd);
	return (s);
}

char	*ft_check_rdwr(char *s)
{
	int	tfd;

	if (s == NULL)
	{
		ft_error_print("[BMP] Error, save.bmp doesn't exist ",
			"ft_check_rdwr", E_ERROR);
		return (NULL);
	}
	tfd = open(s, O_RDWR);
	if (-1 == tfd)
	{
		ft_error_print("[BMP] Error, save.bmp is not readable or writable ",
			"ft_check_rdwr", E_ERROR);
		return (NULL);
	}
	else
		close(tfd);
	return (s);
}

int	ft_print_line(char *s, size_t ln)
{
	printf("	|%zu| - %s\n", ln, s);
	return (ln);
}
