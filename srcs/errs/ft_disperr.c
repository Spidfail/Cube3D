#include "../../inc/leader.h"
#include "../../inc/global_error.h"
#include "../../inc/global_strct.h"

char	*ft_disperr_mlx(int wh)
{
	char	*sterr[10];

	sterr[0] = "[MLX] Connexion with display failed ";
	sterr[1] = "[MLX] Window creation failed ";
	sterr[2] = "[MLX] Failed to generate image texture ";
	return (sterr[wh]);
}

void	ft_print_log(char *str)
{
	printf("\n-------------------------------------------------------");
	printf("\n\n [LOG] %s\n\n", str);
	printf("-------------------------------------------------------\n");
}
