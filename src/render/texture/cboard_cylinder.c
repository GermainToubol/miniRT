#include <math.h>
#include "light_contribution.h"
#include "scene.h"
#include "t_math.h"
#include "texture.h"

int	cboard_cylinder(t_color *color, t_intersection *intersection)
{
	t_pos	cartesian;
	t_pos	cylindrical;
	t_vect	ux;
	t_vect	uy;

	ux = v_cross_product(intersection->obj_seen->cylinder.dir,
			(t_vect){1, 0, 0});
	if (v_dot_product(ux, ux) == 0)
		ux = v_cross_product(intersection->obj_seen->cylinder.dir,
				(t_vect){0, 1, 0});
	uy = v_cross_product(intersection->obj_seen->cylinder.dir, ux);
	cartesian = v_sub(intersection->pos, intersection->obj_seen->cylinder.pos);
	cartesian = (t_pos){v_dot_product(cartesian, ux),
						v_dot_product(cartesian, uy),
						v_dot_product(cartesian, intersection->obj_seen->cylinder.dir)};
	cylindrical.x = sqrtf(cartesian.x * cartesian.x + cartesian.y * cartesian.y);
	cylindrical.y = atan2f(cartesian.x / cylindrical.x, cartesian.y / cylindrical.x);
	cylindrical.z = v_dot_product(cartesian, intersection->obj_seen->cylinder.dir);
	if ((int)(roundf(cylindrical.z + 0.0001f) + roundf(cylindrical.y * 5 / 3.142f)) % 2 == 0)
	{
		color->r *= intersection->obj_seen->color.r;
		color->g *= intersection->obj_seen->color.g;
		color->b *= intersection->obj_seen->color.b;
	}
	else
	{
		color->r *= 0.1 * intersection->obj_seen->color.r;
		color->g *= 0.1 * intersection->obj_seen->color.g;
		color->b *= 0.1 * intersection->obj_seen->color.b;
	}
	return (0);
}
