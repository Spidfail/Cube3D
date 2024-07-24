#include "../../inc/mlx_setup.h"

char	*ft_pixel_put(t_image *image, int color, int x, int y)
{
	char	*dst;

	dst = NULL;
	if (x < 0 || y < 0 || image == NULL || color < 0 || color > 0xFFFFFF)
		return (NULL);
	dst = image->area + (y * image->size_line + x
			* (char)(image->bit_pix * 0.125));
	*(unsigned int *)dst = color;
	return (dst);
}

unsigned int	ft_get_pixel_color(t_image *image, int x, int y)
{
	char	*dst;

	dst = 0;
	if (image == NULL || x < 0 || y < 0)
		return (E_ERROR);
	dst = image->area + (y * image->size_line + x
			* (char)(image->bit_pix * 0.125));
	return (*(unsigned int *)dst);
}

unsigned int	*ft_get_pixel_address(t_image *image, int x, int y)
{
	char	*dst;

	dst = 0;
	dst = image->area + (y * image->size_line + x
			* (char)(image->bit_pix * 0.125));
	return ((unsigned int *)dst);
}
