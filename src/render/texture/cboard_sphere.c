#include <math.h>
#include "light_contribution.h"
#include "scene.h"
#include "texture.h"

int	cboard_sphere(t_color *color, t_intersection *intersection)
{
	t_pos	tmp;
	float	theta;
	float	phi;

	tmp.x = intersection->pos.x - intersection->obj_seen->sphere.pos.x;
	tmp.y = intersection->pos.y - intersection->obj_seen->sphere.pos.y;
	tmp.z = intersection->pos.z - intersection->obj_seen->sphere.pos.z;
	theta = acosf(tmp.z / intersection->obj_seen->sphere.r);
	phi = atan2f(tmp.x, tmp.y);
	if ((int)(roundf(theta / 3.142f * SPHERE_PART)
			+ roundf(phi / 3.142f * SPHERE_PART)) % 2 == 0)
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
