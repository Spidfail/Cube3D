#include "../../inc/leader.h"

double	ft_proportion(double bvalue, double nvalue)
{
	if (bvalue < 0 || nvalue < 0)
		return (E_ERROR);
	nvalue = nvalue / bvalue;
	return (nvalue);
}
