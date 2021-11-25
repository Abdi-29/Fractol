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
	(void)x;
	(void)y;
	return (0);
}
