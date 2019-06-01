/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:48:01 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/29 20:48:04 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	mandelbrot(t_fractol fra, int x, int y)
{
	t_complex	z;
	t_complex	power;
	double		tmp_zr;
	int			i;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	fra.c.r = fra.dots.min_x + x * (fra.dots.max_x - fra.dots.min_x) / (W);
	fra.c.i = fra.dots.min_y + y * (fra.dots.max_y - fra.dots.min_y) / (H);
	while (i < fra.iterations && power.r + power.i <= 4.0)
	{
		power.r = pow(z.r, 2.0);
		power.i = pow(z.i, 2.0);
		tmp_zr = z.r;
		z.r = (power.r - power.i) + fra.c.r;
		z.i = 2.0 * tmp_zr * z.i + fra.c.i;
		i++;
	}
	fra.nu = (i + 1.0 - (log(log(sqrt(power.r + power.i)))) / log(2.0));
	fra.co.co = set_color(fra, i);
	*(int*)(fra.mlx.img_string + (x + y * W) * 4) =
	(fra.co.co.red << 16 | fra.co.co.green << 8 | fra.co.co.blue);
}

void	mandelbrot_defaults(t_fractol *fract)
{
	fract->draw = mandelbrot;
	fract->dots.min_x = -2.0;
	fract->dots.min_y = -1.4;
	fract->dots.max_x = 0.6;
	fract->dots.max_y = 1.4;
	fract->zoom = 2.0;
	fract->iterations = 150;
	fract->co.co_type = 3;
}
