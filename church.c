/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   church.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:14:26 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/31 14:14:28 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	church(t_fractol fract, int x, int y)
{
	t_complex	z;
	t_complex	power;
	double		tmp_zr;
	int			i;

	i = 0;
	z.r = fract.dots.min_x + x * (fract.dots.max_x - fract.dots.min_x) / (W);
	z.i = fract.dots.min_y + y * (fract.dots.max_y - fract.dots.min_y) / (H);
	fract.c.r = z.r;
	fract.c.i = z.i;
	while (i < fract.iterations && power.r + power.i <= 4.0)
	{
		power.r = pow(z.r, 2.0);
		power.i = pow(z.i, 2.0);
		tmp_zr = z.r;
		z.r = (power.r - power.i) + fract.c.r;
		z.i = -(2.0 * tmp_zr * fabs(z.i)) + fract.c.i;
		i++;
	}
	fract.nu = (i + 1.0 - (log(log(sqrt(power.r + power.i)))) / log(2.0));
	fract.co.co = set_color(fract, i);
	*(int*)(fract.mlx.img_string + (x + y * W) * 4) =
	(fract.co.co.red << 16 | fract.co.co.green << 8 | fract.co.co.blue);
}

void	church_defaults(t_fractol *fract)
{
	fract->draw = church;
	fract->dots.min_x = 0.155686;
	fract->dots.min_y = -0.710510;
	fract->dots.max_x = 0.462787;
	fract->dots.max_y = -0.412184;
	fract->zoom = 2;
	fract->iterations = 100;
	fract->co.co_type = 0;
}
