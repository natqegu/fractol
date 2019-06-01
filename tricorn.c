/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:48:25 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/29 20:48:27 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	tricorn(t_fractol fract, int x, int y)
{
	t_complex	z;
	double		tmp_zr;
	int			i;

	i = 0;
	z.r = fract.dots.min_x + x * (fract.dots.max_x - fract.dots.min_x) / (W);
	z.i = fract.dots.min_y + y * (fract.dots.max_y - fract.dots.min_y) / (H);
	fract.c.r = z.r;
	fract.c.i = z.i;
	while (i < fract.iterations && pow(z.r, 2.0) + pow(z.i, 2.0) <= 4.0)
	{
		tmp_zr = z.r;
		z.r = (pow(z.r, 2.0) - pow(z.i, 2.0)) + fract.c.r;
		z.i = tmp_zr * (-2.0 * z.i) + fract.c.i;
		i++;
	}
	fract.nu = (i + 1.0 - (log(2.0) / log(pow(z.r, 2.0) +
								pow(z.i, 2.0))) / log(2.0));
	fract.co.co = set_color(fract, i);
	*(int*)(fract.mlx.img_string + (x + y * W) * 4) =
	(fract.co.co.red << 16 | fract.co.co.green << 8 | fract.co.co.blue);
}

void	tricorn_defaults(t_fractol *fract)
{
	fract->draw = tricorn;
	fract->dots.min_x = -3;
	fract->dots.min_y = -3;
	fract->dots.max_x = 3;
	fract->dots.max_y = 3;
	fract->zoom = 2;
	fract->iterations = 100;
	fract->co.co_type = 1;
}
