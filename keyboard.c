/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:59:34 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/29 22:07:29 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	switch_keys(int keycode, t_fractol *fract)
{
	if (keycode == 69 || keycode == 24)
		fract->iterations += 10;
	if (keycode == 78 || keycode == 27)
		fract->iterations -= 10;
	if (keycode == 36)
	{
		fract->type = (fract->type + 1) % 9;
		set_defaults(fract);
	}
	if (keycode == 257 || keycode == 258)
	{
		if (fract->draw == newton || fract->draw == tunel)
			fract->co.co_type = 2;
		else
			fract->co.co_type = (fract->co.co_type + 1) % 4;
	}
	if (keycode == 49)
		fract->animation = !fract->animation;
}

void	some_keys(int keycode, t_fractol *fract)
{
	if (keycode == 0 && fract->dots.min_x > -5)
	{
		fract->dots.min_x += 0.1 * fract->zoom;
		fract->dots.max_x += 0.1 * fract->zoom;
	}
	if (keycode == 2 && fract->dots.max_x < 5)
	{
		fract->dots.min_x -= 0.1 * fract->zoom;
		fract->dots.max_x -= 0.1 * fract->zoom;
	}
	if (keycode == 13 && fract->dots.min_y > -5)
	{
		fract->dots.min_y += 0.1 * fract->zoom;
		fract->dots.max_y += 0.1 * fract->zoom;
	}
	if (keycode == 1 && fract->dots.max_y < 5)
	{
		fract->dots.min_y -= 0.1 * fract->zoom;
		fract->dots.max_y -= 0.1 * fract->zoom;
	}
}

int		keys(int keycode, t_fractol *fract)
{
	if (keycode == 53)
		escape();
	if (keycode == 15)
	{
		set_defaults(fract);
		start_threads(fract);
		mlx_put_image_to_window(fract->mlx.init, fract->mlx.win,
											fract->mlx.img, 0, 0);
	}
	some_keys(keycode, fract);
	switch_keys(keycode, fract);
	start_threads(fract);
	mlx_put_image_to_window(fract->mlx.init, fract->mlx.win,
										fract->mlx.img, 0, 0);
	return (1);
}
