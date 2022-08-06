#include <math.h>
#include "light_contribution.h"
#include "t_math.h"

float	set_specular_contribution(
		t_intersection	*intersection,
		t_vect			*intersect_light
	)
{
	t_vect	reflexion;
	float	pw;

	v_normalize(intersect_light);
	v_normalize(&intersection->ray->dir);
	reflexion = v_sub(
		*intersect_light,
		v_scalar(
			2 * v_dot_product(*intersect_light, intersection->norm),
			intersection->norm
			)
		);
	pw = v_dot_product(reflexion, intersection->ray->dir);
	if (pw < 0)
		return (0.0f);
	pw = powf(pw, BRIGHTNESS);
	return (pw);
}
