#include "../../inc/mlx_setup.h"

t_error	ft_build_choosen_texture(void *init, char *path, t_image *image)
{
	image->img_ptr = mlx_xpm_file_to_image(init, path, &image->size[0],
			&image->size[1]);
	if (!image->img_ptr)
		return (ft_error_node(5, 2, 0, path));
	image->area = mlx_get_data_addr(image->img_ptr, &image->bit_pix,
			&image->size_line, &image->endian);
	image->real_sline = image->size_line / 4;
	return (E_TRUE);
}

static char	*ft_build_images_path(int wh, t_displ *dspl)
{
	char		*arr[7];

	arr[0] = dspl->no;
	arr[1] = dspl->so;
	arr[2] = dspl->we;
	arr[3] = dspl->ea;
	arr[4] = dspl->spr;
	return (arr[wh]);
}

static void	ft_allocate_images_struct(t_rsrcs *rsrcs)
{
	rsrcs->mlx->img_north = ft_calloc(1, sizeof(t_image));
	rsrcs->mlx->img_south = ft_calloc(1, sizeof(t_image));
	rsrcs->mlx->img_west = ft_calloc(1, sizeof(t_image));
	rsrcs->mlx->img_east = ft_calloc(1, sizeof(t_image));
	rsrcs->mlx->img_sprite = ft_calloc(1, sizeof(t_image));
}

static t_image	*ft_build_images_struct(int wh, t_mlxset *mlx_set)
{
	t_image		*arr[7];

	arr[0] = mlx_set->img_north;
	arr[1] = mlx_set->img_south;
	arr[2] = mlx_set->img_west;
	arr[3] = mlx_set->img_east;
	arr[4] = mlx_set->img_sprite;
	return (arr[wh]);
}

t_error	ft_mlx_build_images(t_rsrcs *rscrcs)
{
	char		*path;
	t_image		*image;
	int			limite;
	int			i;

	i = -1;
	limite = 5;
	path = NULL;
	image = NULL;
	ft_allocate_images_struct(rscrcs);
	while (++i < limite)
	{
		path = ft_build_images_path(i, rscrcs->dspl);
		image = ft_build_images_struct(i, rscrcs->mlx);
		if (image == NULL)
			return (ft_setup_clean_images(rscrcs->mlx, E_ERROR));
		if (ft_build_choosen_texture(rscrcs->mlx->init, path, image) == E_ERROR)
			return (ft_setup_clean_images(rscrcs->mlx, E_ERROR));
	}
	if (ft_mlx_build_images_ceil_floor(rscrcs) == E_ERROR)
		return (E_ERROR);
	return (E_TRUE);
}
