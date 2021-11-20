#include "mlx.h"
#include "fractol.h"

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
