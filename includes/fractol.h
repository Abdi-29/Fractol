#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# define WIN_SIZE 400
# define MAX_ITER 100

typedef enum e_keys
{
	KEY_ESC = 53,
	KEY_LEFT = 124,
	KEY_RIGHT = 123,
	KEY_DOWN = 125,
	KEY_UP = 126,
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

typedef struct s_dbt
{
	double	x1;
	double	x2;
	int		check;
}			t_dbt;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_cor	zoom;
	t_dbt	j_set;
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
void	ft_convert(char **n, t_dbt *ptr);
int		ft_j_check(char **argv, int len);
int		ft_control(char *str);
int		ft_get_colour(int range);
void	ft_put_colour(t_vars *vars, int n, int i, int j);

#endif