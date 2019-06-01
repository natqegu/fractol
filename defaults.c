/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:47:35 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/29 20:47:39 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	*draw_fractal(void *data_ptr)
{
	int				i;
	int				j;
	t_fractol		*fract;

	fract = (t_fractol*)data_ptr;
	i = 0;
	while (i < H)
	{
		j = fract->min;
		while (j < fract->max)
		{
			fract->draw(*fract, j, i);
			j++;
		}
		i++;
	}
	pthread_exit(0);
}

void	start_threads(t_fractol *fract)
{
	pthread_t		threads[THREADS];
	t_fractol		fracts[THREADS];
	int				i;

	i = 0;
	while (i < THREADS)
	{
		fracts[i].min = i * (W / THREADS);
		fracts[i].max = (i + 1) * (W / THREADS);
		fracts[i].dots = fract->dots;
		fracts[i].iterations = fract->iterations;
		fracts[i].co = fract->co;
		fracts[i].draw = fract->draw;
		fracts[i].mlx.img_string = fract->mlx.img_string;
		fracts[i].zoom = fract->zoom;
		fracts[i].c = fract->c;
		pthread_create(&threads[i], NULL, draw_fractal, &fracts[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

t_rgb	set_color(t_fractol fract, int depth)
{
	t_rgb rgb;

	rgb = new_rgb(0, 0, 0);
	if (fract.co.co_type == 0)
		rgb = pink(depth, fract.iterations, fract.nu);
	if (fract.co.co_type == 1)
		rgb = fire(depth, fract.iterations, fract.nu);
	if (fract.co.co_type == 2)
		rgb = dark_blue(depth, fract.iterations);
	if (fract.co.co_type == 3)
		rgb = nice_white(depth, fract.iterations, fract.nu);
	return (rgb);
}

t_rgb	new_rgb(int red, int green, int blue)
{
	t_rgb col;

	col.red = red;
	col.blue = blue;
	col.green = green;
	return (col);
}

void	set_defaults(t_fractol *fract)
{
	if (fract->type == 1)
		mandelbrot_defaults(fract);
	else if (fract->type == 2)
		julia_defaults(fract);
	else if (fract->type == 3)
		tricorn_defaults(fract);
	else if (fract->type == 8)
		balloon_defaults(fract);
	else if (fract->type == 5)
		burning_ship_defaults(fract);
	else if (fract->type == 6)
		newton_defaults(fract);
	else if (fract->type == 7)
		church_defaults(fract);
	else if (fract->type == 4)
		tunel_defaults(fract);
	start_threads(fract);
	mlx_put_image_to_window(fract->mlx.init, fract->mlx.win,
										fract->mlx.img, 0, 0);
}
