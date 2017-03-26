#include "ft_ls.h"


int main(int ac, char **av)
{
	t_env	env;

	(void)ac;
	init_ls(&env, av);
	return (0);
}
