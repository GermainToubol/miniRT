#include "intersection.h"
#include "ray.h"
#include "scene.h"
#include "t_math.h"

float	set_distance_sqr_lines(t_obj *obj, t_ray *ray)
{
	t_vect	ortho;
	float	dist;

	ortho = v_cross_product(obj->cylinder.dir, ray->dir);
	if (v_dot_product(ortho, ortho) == 0)
		return (-1.0f);
	dist = v_dot_product(ortho, v_sub(obj->cylinder.pos, ray.pos));
	return (dist * dist / v_dot_product(ortho, ortho));
}

float	set_intersection_cylinder(t_obj *obj, t_ray *ray)
{
	float	distance_sqr;

	if (dist_2 > obj->cylinder.r * obj->cylinder.r)
		return (-1.0f);

}
