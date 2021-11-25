#include <mlx.h>
#include <fractol.h>

int	ft_get_colour(int range)
{
	int	colour[16];

	colour[0] = (66 << 16) + (30 << 8) + 15;
	colour[1] = (25 << 16) + (7 << 8) + 26;
	colour[2] = (9 << 16) + (1 << 8) + 47;
	colour[3] = (4 << 16) + (4 << 8) + 73;
	colour[4] = (0 << 16) + (7 << 8) + 100;
	colour[5] = (12 << 16) + (44 << 8) + 138;
	colour[6] = (24 << 16) + (82 << 8) + 177;
	colour[7] = (57 << 16) + (125 << 8) + 209;
	colour[8] = (134 << 16) + (181 << 8) + 229;
	colour[9] = (211 << 16) + (236 << 8) + 248;
	colour[10] = (241 << 16) + (233 << 8) + 191;
	colour[11] = (248 << 16) + (201 << 8) + 95;
	colour[12] = (255 << 16) + (170 << 8) + 0;
	colour[13] = (204 << 16) + (128 << 8) + 0;
	colour[14] = (153 << 16) + (87 << 8) + 0;
	colour[15] = (105 << 16) + (52 << 8) + 3;
	return (colour[range % 16]);
}

void	ft_put_colour(t_vars *vars, int n, int i, int j)
{
	if (n == MAX_ITER)
		mlx_pixel_put(vars->mlx, vars->win, i, j, 0);
	else
		mlx_pixel_put(vars->mlx, vars->win, i, j, ft_get_colour(n));
}
