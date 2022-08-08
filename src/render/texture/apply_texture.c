#include "light_contribution.h"
#include "scene.h"
#include "texture.h"

int	apply_texture(t_color *color, t_ray *ray, t_intersection *intersection)
{
	const t_cboard	cboard[] = {cboard_sphere, cboard_plane, cboard_cylinder};
	(void)ray;
	if (intersection->obj_seen->tag <= cylinder_tag)
		(*cboard[intersection->obj_seen->tag])(color, intersection);
	else
	{
		color->r *= intersection->obj_seen->color.r;
		color->g *= intersection->obj_seen->color.g;
		color->b *= intersection->obj_seen->color.b;
	}
	return (0);
}
