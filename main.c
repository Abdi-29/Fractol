#include <mlx.h>
#include "fractol.h"

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
