/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balloons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:47:16 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/29 20:47:20 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	balloon(t_fractol fract, int x, int y)
{
	t_complex	z;
	double		tmp_zr;
	double		divisor;
	int			i;

	i = 0;
	z.r = fract.dots.min_x + x * (fract.dots.max_x - fract.dots.min_x) / (W);
	z.i = fract.dots.min_y + y * (fract.dots.max_y - fract.dots.min_y) / (H);
	while (i < fract.iterations && pow(z.r, 2.0) + pow(z.i, 2.0) <= 4)
	{
		tmp_zr = z.r;
		divisor = (pow(z.r, 2.0) * (pow(z.r, 2.0) + 2.0 * pow(z.i, 2.0) +
		2.0 * fract.c.r)) + (pow(z.i, 2.0) * (pow(z.i, 2.0) -
		(2.0 * fract.c.r))) + (4.0 * (z.r * z.i * fract.c.i) +
		pow(fract.c.i, 2.0) + pow(fract.c.r, 2.0));
		z.r = (pow(z.r, 2.0) - pow(z.i, 2.0) + fract.c.r) / divisor;
		z.i = -(2.0 * tmp_zr * z.i + fract.c.i) / divisor;
		i++;
	}
	fract.nu = (i + 1.0 - (log(log(sqrt(pow(z.r, 2.0) + pow(z.i, 2.0)))))
	/ log(2.0));
	fract.co.co = set_color(fract, i);
	*(int*)(fract.mlx.img_string + (x + y * W) * 4) =
	(fract.co.co.red << 16 | fract.co.co.green << 8 | fract.co.co.blue);
}

void	balloon_defaults(t_fractol *fract)
{
	fract->draw = balloon;
	fract->c.i = 0.17;
	fract->c.r = 0.57;
	fract->animation = 0;
	fract->dots.min_x = -2;
	fract->dots.min_y = -2.2;
	fract->dots.max_x = 2;
	fract->dots.max_y = 2.2;
	fract->zoom = 2;
	fract->iterations = 100;
	fract->co.co_type = 0;
}
