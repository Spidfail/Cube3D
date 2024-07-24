#include "../../inc/mlx_setup.h"
#include "../../inc/leader.h"
#include "../../inc/global_strct.h"
#include "../../inc/global_enum.h"
#include "../../inc/global_error.h"

static void	ft_write_per_byte(int fd, int content, int n_byte)
{
	char	buffer;

	while (--n_byte >= 0)
	{
		buffer = content & 0xFF;
		content = content >> 8;
		write(fd, &buffer, 1);
	}
	return ;
}

static void	ft_make_bmp_pixels(int fd, t_image *img)
{
	int		x;
	int		y;

	y = img->size[1];
	while (--y >= 0)
	{
		x = -1;
		while (++x < img->size[0])
			ft_write_per_byte(fd, *ft_get_pixel_address(img, x, y), 3);
	}
	return ;
}

static void	ft_make_bmp_header(int fd, t_image *img)
{
	write(fd, "BM", 2);
	ft_write_per_byte(fd, 3 * img->size[0] * img->size[1] + 54, 4);
	ft_write_per_byte(fd, 0, 2);
	ft_write_per_byte(fd, 0, 2);
	ft_write_per_byte(fd, 54, 4);
	ft_write_per_byte(fd, 40, 4);
	ft_write_per_byte(fd, img->size[0], 4);
	ft_write_per_byte(fd, img->size[1], 4);
	ft_write_per_byte(fd, 1, 2);
	ft_write_per_byte(fd, 24, 2);
	ft_write_per_byte(fd, 0, 4);
	ft_write_per_byte(fd, 3 * img->size[0] * img->size[1], 4);
	ft_write_per_byte(fd, 0, 4);
	ft_write_per_byte(fd, 0, 4);
	ft_write_per_byte(fd, 0, 4);
	ft_write_per_byte(fd, 0, 4);
}

t_error	ft_make_bmp(char *bmp, t_image *img, t_rsrcs *rsrcs)
{
	int		fd;

	fd = open(bmp, O_CREAT | O_RDWR, 0666);
	if (fd == -1)
		return (ft_error_arg());
	img->size[0] = rsrcs->dspl->res[0];
	img->size[1] = rsrcs->dspl->res[1];
	ft_make_bmp_header(fd, img);
	ft_make_bmp_pixels(fd, img);
	if (close(fd) == E_ERROR)
		return (ft_error_print("[BMP] Error while closing the bmp file ",
				"ft_make_bmp", E_ERROR));
	return (E_TRUE);
}
