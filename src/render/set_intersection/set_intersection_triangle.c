#include "intersection.h"
#include "scene.h"
#include "ray.h"
#include "t_math.h"

float	set_intersection_triangle(t_obj *obj, t_ray *ray)
{
	float		i[4];
	t_vect		v[3];
	t_triangle	*triangle;

	triangle = &obj->triangle;
	v[0] = v_sub(triangle->edge[1], triangle->edge[0]);
	v[1] = v_sub(triangle->edge[2], triangle->edge[0]);
	v[2] = v_sub(ray->pos, triangle->edge[0]);
	i[0] = v_dot_product(triangle->normal, ray->dir);
	i[3] = -v_dot_product(triangle->normal, v[2]) / i[0];
	if (i[3] < 0)
		return (-1.0f);
	i[1] = v_dot_product(v_cross_product(v[2], v[1]), ray->dir) / i[0];
	if (i[1] < 0)
		return (-1.0f);
	i[2] = v_dot_product(v_cross_product(v[0], v[2]), ray->dir) / i[0];
	if (i[2] < 0 || i[1] + i[2] > 1)
		return (-1.0f);
	return (i[3]);
}