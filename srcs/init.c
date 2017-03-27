#include "ft_ls.h"

static int	add_arg(t_flags *flag, char c)
{
	if (c == 'l')
		return (flag->long_list = 1);
	else if (c == 'R')
		return (flag->reverse = 1);
	else if (c == 'a')
		return (flag->hide = 1);
	else if (c == 'r')
		return (flag->reverse = 1);
	else if (c == 't')
		return (flag->sort_modif = 1);
	return (0);
}

static int	check_arg(t_flags *flag, char *arg)
{
	if (*arg != '-' || !ft_strcmp(arg, "-") || !ft_strcmp(arg, "--"))
		return (0);
	arg++;
	while (add_arg(flag, *arg))
		arg++;
	if (*arg)
	{
		ft_putstr_fd("Error: option not recognize |", 2);
		ft_putchar_fd(*arg, 2);
		ft_putstr_fd("|\n", 2);
		ft_putstr_fd(USAGE, 2);
		exit(1);
	}
	return (1);
}

void	init_ls(t_env *env, char **av)
{
	int	i;

	i = 1;
	env->flag = (t_flags){0, 0, 0, 0, 0};
	while (av[i] && check_arg(&env->flag, av[i]))
		i++;
	if (av[i] && !ft_strcmp(av[i], "--"))
		i++;
	if (!av[i])
		ft_lstadd(&env->args, ft_lstnew(".", 2));
	while (av[i])
	{
		ft_lstadd(&env->args, ft_lstnew(av[i], ft_strlen(av[i]) + 1));
		i++;
	}
}
