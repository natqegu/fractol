/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:47:28 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/29 20:47:30 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_rgb	pink(int depth, int iterations, double nu)
{
	t_rgb	rgb;

	if (depth == iterations)
		return (new_rgb(230, 210, 217));
	rgb.red = sin(0.34 * nu + 1) * 126 + 129;
	rgb.blue = sin(0.34 * nu + 2) * 126 + 129;
	rgb.green = sin(0.034 * 2) * 127 + 128;
	return (rgb);
}

t_rgb	fire(int depth, int iterations, double nu)
{
	t_rgb	rgb;

	if (depth == iterations)
		return (new_rgb(0, 0, 0));
	rgb.red = 255;
	rgb.blue = sin(0.34 * nu) * 12 + 129;
	rgb.green = sin(0.034 * nu * 2) * 127 + 129;
	return (rgb);
}

t_rgb	dark_blue(int depth, int iterations)
{
	t_rgb	rgb;
	double	t;

	t = (double)depth / (double)iterations;
	rgb.red = (int)(35 * (1 - t) * t * t * t * 255);
	rgb.green = (int)(20 * (1 - t) * (1 - t) * t * t * 255);
	rgb.blue = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (rgb);
}

t_rgb	nice_white(int depth, int iterations, double nu)
{
	t_rgb	rgb;

	if (depth == iterations)
		return (new_rgb(240, 230, 255));
	rgb.red = sin(0.064 * nu + 1.9) * 127 + 127.5;
	rgb.blue = sin(0.064 * nu + 1.3) * 127 + 127.5;
	rgb.green = sin(0.064 * nu + 0.8) * 127 + 127.5;
	return (rgb);
}
