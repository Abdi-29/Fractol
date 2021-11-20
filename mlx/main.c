#include <mlx.h>

int main()
{
	void	*mlx;
	void	*mlx_win;

	mlk = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world!");
	mlk_loop(mlx);
}
