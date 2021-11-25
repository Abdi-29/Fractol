#include "mlx.h"
#include "fractol.h"

void	ft_mandel_alg(t_vars *vars)
{
	double			bb;
	double			tmp;

	tmp = (vars->zoom.a * vars->zoom.a) - (vars->zoom.b * vars->zoom.b);
	bb = (2 * vars->zoom.a * vars->zoom.b);
	if (vars->j_set.check)
	{
		vars->zoom.a = tmp + vars->j_set.x1;
		vars->zoom.b = bb + vars->j_set.x2;
	}
	else
	{
		vars->zoom.a = tmp + vars->zoom.a_cpy;
		vars->zoom.b = bb + vars->zoom.b_cpy;
	}
}

double	ft_map(double i, double size, double start, double end)
{
	double	result;

	result = i / size * (end - start) + start;
	return (result);
}

void	ft_get_map(t_vars *vars, int i, int j)
{
	vars->zoom.a = ft_map(i, WIN_SIZE_X, vars->zoom.z_outx, vars->zoom.z_inx);
	vars->zoom.b = ft_map(j, WIN_SIZE_Y, vars->zoom.z_outy, vars->zoom.z_iny);
	vars->zoom.a_cpy = vars->zoom.a;
	vars->zoom.b_cpy = vars->zoom.b;
}

void	ft_draw_pixel(t_vars *vars)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (i < WIN_SIZE_X)
	{
		j = 0;
		while (j < WIN_SIZE_Y)
		{
			n = 0;
			ft_get_map(vars, i, j);
			while (n < MAX_ITER)
			{
				ft_mandel_alg(vars);
				if (vars->zoom.a * vars->zoom.a + \
			 		vars->zoom.b * vars->zoom.b > 4.0)
					break ;
				n++;
			}
			ft_put_colour(vars, n, i, j);
			j++;
		}
		i++;
	}
}
