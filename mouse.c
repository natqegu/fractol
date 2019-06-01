/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:59:40 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/31 16:01:28 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include "stdio.h"

void	calculate_zoom(t_fractol *fract, t_complex wh,
								double top, double bottom)
{
	if (fract->zoom * top > 0 && fract->zoom * top < 3)
	{
		fract->zoom *= top;
		fract->dots.max_x = fract->dots.max_x * top + wh.r * bottom;
		fract->dots.min_x = fract->dots.min_x * top + wh.r * bottom;
		fract->dots.max_y = fract->dots.max_y * top + wh.i * bottom;
		fract->dots.min_y = fract->dots.min_y * top + wh.i * bottom;
	}
}

int		mouse_zoom(int keycode, int x, int y, t_fractol *fract)
{
	t_complex wh;

	wh.r = x * ((fract->dots.max_x - fract->dots.min_x) / W) +
												fract->dots.min_x;
	wh.i = y * ((fract->dots.max_y - fract->dots.min_y) / H) +
												fract->dots.min_y;
	if (keycode == 5)
	{
		calculate_zoom(fract, wh, 0.9, 0.1);
		fract->iterations++;
	}
	if (keycode == 4)
		calculate_zoom(fract, wh, 1.1, -0.1);
	start_threads(fract);
	mlx_put_image_to_window(fract->mlx.init, fract->mlx.win,
										fract->mlx.img, 0, 0);
	return (1);
}

int		mouse_motion(int x, int y, t_fractol *fract)
{
	if (fract->animation)
	{
		fract->c.i = -1 + y * 2.0 / W;
		fract->c.r = -1 + x * 2.0 / W;
		start_threads(fract);
		mlx_put_image_to_window(fract->mlx.init, fract->mlx.win,
											fract->mlx.img, 0, 0);
	}
	return (1);
}
