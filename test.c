#include "mlx.h"
// #include "global_strct.h"

typedef struct		s_image
{
	void	*img_ptr;
	int		size[2];
	char	*area;
	int		bit_pix;
	int		endian;
	int		size_line;
	int		real_sline;
}					t_image;

unsigned int	*ft_get_pixel_address(t_image *image, int x, int y)
{
	char	*dst;

	dst = 0;
	dst = image->area + (y * image->size_line + x * (char)(image->bit_pix * 0.125));
	return ((unsigned int *)dst);
}

int main()
{
    int w, h;
    int x, y;
    void *mlx = mlx_init();
    void *img = mlx_xpm_file_to_image(mlx, "b757624ee66210e1d375472f7a6078c8.xpm", &w, &h);
    t_image im;
    im.img_ptr = img;
    im.area = mlx_get_data_addr(img, &im.bit_pix, &im.size_line, &im.endian);
    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            ft_get_pixel_address(&im, x, y);
        }
    };
    
}