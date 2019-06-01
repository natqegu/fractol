/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:21:16 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/31 16:05:57 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		escape(void)
{
	exit(0);
	return (0);
}

int		print_usage(void)
{
	ft_putendl("");
	ft_putendl("USAGE: ./fractol [choose your fighter]");
	ft_putendl("");
	ft_putendl("1. Mandelbrot");
	ft_putendl("2. Julia");
	ft_putendl("3. Tricorn");
	ft_putendl("4. Tunel");
	ft_putendl("5. Burning ship");
	ft_putendl("6. Newton");
	ft_putendl("7. Church");
	ft_putendl("8. Balloons");
	return (0);
}

int		check_name(int *type, char *arg)
{
	*type = ft_atoi(arg);
	if (*type < 1 || *type > 8)
		return (0);
	return (1);
}

void	helper(void)
{
	ft_putendl("");
	ft_putendl("Enter - change fractal");
	ft_putendl("Space - make Julia and Balloons alive");
	ft_putendl("Shift - color SHIFT");
	ft_putendl("A - move image to the left");
	ft_putendl("D - move image to the right");
	ft_putendl("W - move image to the top");
	ft_putendl("S - move image to the bottom");
	ft_putendl("+ - +10 iterations");
	ft_putendl("- - -10 iterations");
	ft_putendl("Scroll mouse wheel to zoom in and out");
}

int		main(int argc, char **argv)
{
	t_fractol fract;

	if (argc != 2)
		return (print_usage());
	if (!check_name(&(fract.type), argv[1]))
		return (print_usage());
	fract.mlx.init = mlx_init();
	fract.mlx.win = mlx_new_window(fract.mlx.init, W, H, "Frucktal");
	fract.mlx.img = mlx_new_image(fract.mlx.init, W, H);
	fract.mlx.img_string = mlx_get_data_addr(fract.mlx.img, &fract.mlx.bpp,
									&fract.mlx.line_size, &fract.mlx.endian);
	set_defaults(&fract);
	helper();
	mlx_hook(fract.mlx.win, 2, 5, keys, &fract);
	mlx_hook(fract.mlx.win, 6, 1L << 6, mouse_motion, &fract);
	mlx_hook(fract.mlx.win, 17, 0, escape, &fract);
	mlx_mouse_hook(fract.mlx.win, mouse_zoom, &fract);
	mlx_loop(fract.mlx.init);
	return (0);
}
