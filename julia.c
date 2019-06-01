/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:47:49 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/29 20:47:52 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	julia(t_fractol fract, int x, int y)
{
	t_complex	z;
	double		tmp_zr;
	int			i;

	i = 0;
	z.r = fract.dots.min_x + x * (fract.dots.max_x - fract.dots.min_x) / (W);
	z.i = fract.dots.min_y + y * (fract.dots.max_y - fract.dots.min_y) / (H);
	while (i < fract.iterations && pow(z.r, 2.0) + pow(z.i, 2.0) <= 4.0)
	{
		tmp_zr = z.r;
		z.r = (pow(z.r, 2.0) - pow(z.i, 2.0)) + fract.c.r;
		z.i = 2.0 * tmp_zr * z.i + fract.c.i;
		i++;
	}
	fract.nu = (i + 1.0 - (log(log(sqrt(pow(z.r, 2.0) + pow(z.i, 2.0)))))
	/ log(2.0));
	fract.co.co = set_color(fract, i);
	*(int*)(fract.mlx.img_string + (x + y * W) * 4) =
	(fract.co.co.red << 16 | fract.co.co.green << 8 | fract.co.co.blue);
}

void	julia_defaults(t_fractol *fract)
{
	fract->draw = julia;
	fract->c.i = -0.58;
	fract->c.r = -0.7;
	fract->animation = 0;
	fract->dots.min_x = -1.8;
	fract->dots.min_y = -1.3;
	fract->dots.max_x = 1.7;
	fract->dots.max_y = 1.2;
	fract->zoom = 2;
	fract->iterations = 100;
	fract->co.co_type = 2;
}
