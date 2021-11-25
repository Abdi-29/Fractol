#include "fractol.h"
#include "libft.h"

int	ft_control(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	str = ft_whitespaces(str);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		i++;
	}
	if (dot > 1)
		return (0);
	return (1);
}

int	ft_j_check(char **argv, int len)
{
	if (len != 4)
		return (0);
	else if (ft_strcmp(argv[1], "j") != 0)
		return (0);
	else if (ft_control(argv[2]) == 0)
		return (0);
	else if (ft_control(argv[3]) == 0)
		return (0);
	return (1);
}

void	ft_convert(char **n, t_dbt *ptr)
{
	ptr->check = 5;
	ptr->x1 = ft_atof(n[2]);
	ptr->x2 = ft_atof(n[3]);
}

void	ft_print_error(void)
{
	ft_putendl_fd("USAGE: \n./fractol j <double> <double>", 1);
	ft_putendl_fd("./fractol m", 1);
}
