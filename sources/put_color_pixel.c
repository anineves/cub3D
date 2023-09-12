#include "../cub3d.h"


int	extract_pixel_from_image(t_img *img,
		int px, int py)
{
	return (*(unsigned int *)(img->addr
		+ (py * img->size_line) + (px * img->pixel_bits / 8)));
}


unsigned int	get_type_wall(t_data *data, t_ray *ray)
{
	if (!ray->side)
	{
		if (data->player.px> ray->map_x)
			return (extract_pixel_from_image(&data->west_img,
					ray->tex_x, ray->tex_y));
		return (extract_pixel_from_image(&data->east_img,
				ray->tex_x, ray->tex_y));
	}
	if (data->player.py > ray->map_y)
		return (extract_pixel_from_image(&data->north_img,
				ray->tex_x, ray->tex_y));
	return (extract_pixel_from_image(&data->south_img,
			ray->tex_x, ray->tex_y));
}