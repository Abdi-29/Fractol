#include <mlx.h>
#include "fractol.h"

void	ft_move_b(t_vars *vars, int direction)
{
	double	step;

	step = fabs(vars->zoom.z_iny - vars->zoom.z_outy) * 0.1;
	if (direction)
	{
		vars->zoom.z_outy -= step;
		vars->zoom.z_iny -= step;
	}
	else
	{
		vars->zoom.z_outy += step;
		vars->zoom.z_iny += step;
	}
}

void	ft_move_a(t_vars *vars, int direction)
{
	double	step;
	
	step = fabs(vars->zoom.z_inx - vars->zoom.z_outx) * 0.1;
	if (direction)
	{
		vars->zoom.z_outx -= step;
		vars->zoom.z_inx -= step;
	}
	else
	{
		vars->zoom.z_outx += step;
		vars->zoom.z_inx += step;
	}
}

void	ft_move(t_vars *vars, int xy, int direction)
{
	if (!xy)
		ft_move_a(vars, direction);
	else
		ft_move_b(vars, direction);
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (EXIT_SUCCESS);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		ft_close(vars);
	else if (keycode == KEY_LEFT)
		ft_move(vars, 0, 0);
	else if (keycode == KEY_RIGHT)
		ft_move(vars, 0, 1);
	else if (keycode == KEY_DOWN)
		ft_move(vars, 1, 0);
	else if (keycode == KEY_UP)
		ft_move(vars, 1, 1);
	return (0);
}

void	ft_mandel_alg(t_vars *vars)
{
	double			aa;
	double			bb;
	double			tmp;

	tmp = (vars->zoom.a * vars->zoom.a) - (vars->zoom.b * vars->zoom.b);
	bb = 2 * vars->zoom.a * vars->zoom.b;
	vars->zoom.a = tmp + vars->zoom.a_cpy;
	vars->zoom.b = bb + vars->zoom.b_cpy;
}

double	ft_map(double i, double size, double start, double end)
{
	double	result;

	result = i / size * (end - start) + start;
	return (result);
}

void	ft_put_colour(t_vars *vars, int n, int i, int j)
{
	if (n < 100)
		mlx_pixel_put(vars->mlx, vars->win, i, j, 0);
	else
		mlx_pixel_put(vars->mlx, vars->win, i, j, 150);
}

void	ft_get_map(t_vars *vars, int i, int j)
{
	vars->zoom.a = ft_map(i, WIN_SIZE, vars->zoom.z_outx, vars->zoom.z_inx);
	vars->zoom.b = ft_map(j, WIN_SIZE, vars->zoom.z_outy, vars->zoom.z_iny);
	vars->zoom.a_cpy = vars->zoom.a;
	vars->zoom.b_cpy = vars->zoom.b;
}

void	ft_draw_pixel(t_vars *vars)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			n = 0;
			ft_get_map(vars, i, j);
			while (n < 100)
			{
				ft_mandel_alg(vars);
				if (vars->zoom.a * vars->zoom.a + \
			 		vars->zoom.b * vars->zoom.b > 4)
					break ;
				n++;
			}
			ft_put_colour(vars, n, i, j);
			j++;
		}
		i++;
	}
}

void	set_cor(t_cor *cor, double value)
{
	cor->a = value;
	cor->a_cpy = value;
	cor->b = value;
	cor->b_cpy = value;
	cor->z_inx = 1;
	cor->z_outx = -1;
	cor->z_iny = 1;
	cor->z_outy = -1;
}

int	ft_zoom(int keycode, int x, int y, t_vars *vars)
{
	double	step_x;
	double	step_y;

	if (keycode == 4)
	{
		step_x = fabs(vars->zoom.z_inx - vars->zoom.z_outx);
		step_y = fabs(vars->zoom.z_iny - vars->zoom.z_outy);
		vars->zoom.z_inx -= step_x * 0.1;
		vars->zoom.z_outx += step_x * 0.1;
		vars->zoom.z_iny -= step_y * 0.1;
		vars->zoom.z_outy += step_y * 0.1;
	}
	if (keycode == 5)
	{
		step_x = fabs(vars->zoom.z_inx - vars->zoom.z_outx);
		step_y = fabs(vars->zoom.z_iny - vars->zoom.z_outy);
		vars->zoom.z_inx += step_x * 0.1;
		vars->zoom.z_outx -= step_x * 0.1;
		vars->zoom.z_iny += step_y * 0.1;
		vars->zoom.z_outy -= step_y * 0.1;
	}
}

int	loop(t_vars *vars)
{
	t_cor	cor;

	ft_draw_pixel(vars);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_SIZE, WIN_SIZE, "let'start");
	set_cor(&vars.zoom, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, ft_zoom, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_loop_hook(vars.mlx, loop, &vars);
	ft_draw_pixel(&vars);
	mlx_loop(vars.mlx);
}
