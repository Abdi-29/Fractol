#include <mlx.h>
#include "fractol.h"
#include "libft.h"

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
	ft_draw_pixel(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if ((argc < 2 || argc > 4) || (ft_strcmp(argv[1], "m") != 0 \
		&& ft_strcmp(argv[1], "j") != 0))
	{
		printf("USAGE: ./fracol j <decimal> <decimal> \n \
		./fractol m");
		exit (1);
	}
	if (ft_strcmp(argv[1], "j") == 0 && ft_j_check(argv, argc))
		ft_convert(argv, &vars.j_set);
	else if (ft_strcmp(argv[1], "m") != 0 || argc != 2)
		exit(1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_SIZE, WIN_SIZE, "let'start");
	set_cor(&vars.zoom, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 4, 0, ft_zoom, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_loop_hook(vars.mlx, loop, &vars);
	ft_draw_pixel(&vars);
	mlx_loop(vars.mlx);
}
