/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:48:11 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/29 20:48:12 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	newton(t_fractol fract, int x, int y)
{
	t_complex	z;
	t_complex	temp;
	int			i;
	double		tmp;

	i = 0;
	tmp = 1.0;
	z.r = fract.dots.min_x + x * (fract.dots.max_x - fract.dots.min_x) / (W);
	z.i = fract.dots.min_y + y * (fract.dots.max_y - fract.dots.min_y) / (H);
	while (i < fract.iterations && tmp > 0.000001)
	{
		temp.r = z.r;
		temp.i = z.i;
		tmp = pow((pow(z.r, 2.0) + pow(z.i, 2.0)), 2.0);
		z.r = (2.0 * z.r * tmp + pow(z.r, 2.0) - pow(z.i, 2.0)) / (3.5 * tmp);
		z.i = (2.0 * z.i * (tmp - temp.r)) / (3.5 * tmp);
		tmp = (z.r - temp.r) * (z.r - temp.r) + (z.i - temp.i) * (z.i - temp.i);
		i++;
	}
	fract.nu = (i + 1.0 - (log(log(sqrt(pow(z.r, 2.0) + pow(z.i, 2.0)))))
																	/ log(2.0));
	fract.co.co = set_color(fract, i);
	*(int*)(fract.mlx.img_string + (x + y * W) * 4) =
	(fract.co.co.red << 16 | fract.co.co.green << 8 | fract.co.co.blue);
}

void	newton_defaults(t_fractol *fract)
{
	fract->draw = newton;
	fract->dots.min_x = -1;
	fract->dots.min_y = -1;
	fract->dots.max_x = 1;
	fract->dots.max_y = 1;
	fract->animation = 1;
	fract->zoom = 2;
	fract->iterations = 100;
	fract->co.co_type = 2;
}
