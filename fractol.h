#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# define WIN_SIZE 300

typedef enum e_keys
{
	KEY_ESC = 53,
	KEY_LEFT = 124,
	KEY_RIGHT = 123,
	KEY_DOWN = 125,
	KEY_UP = 126,
	MAX_ITER = 100,
	KEY_PLUS = 0,
	KEY_MINUS = 1,
}			t_keys;

typedef struct s_cor
{
	double	a_cpy;
	double	b_cpy;
	double	a;
	double	b;
	double	z_inx;
	double	z_outx;
	double	z_iny;
	double	z_outy;
}			t_cor;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_cor	zoom;
}			t_vars;

void	ft_draw_pixel(t_vars *vars);
void	ft_get_map(t_vars *vars, int i, int j);
void	ft_put_colour(t_vars *vars, int n, int i, int j);
double	ft_map(double i, double size, double start, double end);
void	ft_mandel_alg(t_vars *vars);
int		ft_zoom(int keycode, int x, int y, t_vars *vars);
void	ft_move(t_vars *vars, int xy, int direction);
void	ft_move_a(t_vars *vars, int direction);
void	ft_move_b(t_vars *vars, int direction);

#endif