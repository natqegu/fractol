/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:16:16 by nnovikov          #+#    #+#             */
/*   Updated: 2019/04/09 12:16:17 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <pthread.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

# define W 1000
# define H 1000
# define THREADS 10

typedef	struct		s_comlex
{
	double			r;
	double			i;
}					t_complex;

typedef struct		s_rgb
{
	int				red;
	int				green;
	int				blue;
}					t_rgb;

typedef struct		s_fractol
{
	struct
	{
		void		*init;
		void		*win;
		void		*img;
		char		*img_string;
		int			endian;
		int			line_size;
		int			bpp;
	}				mlx;
	struct
	{
		double		min_x;
		double		min_y;
		double		max_x;
		double		max_y;
	}				dots;
	struct
	{
		t_rgb		co;
		int			co_type;
	}				co;
	t_complex		c;
	double			nu;
	double			zoom;
	double			min;
	double			max;
	int				iterations;
	int				type;
	int				animation;
	void			(*draw)(struct s_fractol data, int x, int y);
}					t_fractol;

void				mandelbrot(t_fractol fract, int x, int y);
void				julia(t_fractol fract, int x, int y);
void				balloon(t_fractol fract, int x, int y);
void				newton(t_fractol fract, int x, int y);
void				tricorn(t_fractol fract, int x, int y);
void				burning_ship(t_fractol fract, int x, int y);
void				church(t_fractol fract, int x, int y);
void				tunel(t_fractol fract, int x, int y);

void				mandelbrot_defaults(t_fractol *fract);
void				julia_defaults(t_fractol *fract);
void				tricorn_defaults(t_fractol *fract);
void				balloon_defaults(t_fractol *fract);
void				burning_ship_defaults(t_fractol *fract);
void				newton_defaults(t_fractol *fract);
void				church_defaults(t_fractol *fract);
void				tunel_defaults(t_fractol *fract);

t_rgb				pink(int depth, int iterations, double nu);
t_rgb				fire(int depth, int iterations, double nu);
t_rgb				dark_blue(int depth, int iterations);
t_rgb				nice_white(int depth, int iterations, double nu);

t_rgb				set_color(t_fractol fract, int depth);
t_rgb				new_rgb(int red, int green, int blue);

int					mouse_zoom(int keycode, int x, int y, t_fractol *fract);
int					mouse_motion(int x, int y, t_fractol *fract);
void				*draw_fractal(void *data_ptr);
void				start_threads(t_fractol *fract);
void				some_keys(int keycode, t_fractol *fract);
void				set_defaults(t_fractol *fract);

int					keys(int keycode, t_fractol *fract);
int					check_name(int *type, char *arg);
int					escape(void);
int					print_usage(void);

#endif
