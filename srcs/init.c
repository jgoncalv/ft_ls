/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:05:18 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/28 20:05:21 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		add_arg(t_flags *flag, char c)
{
	if (c == 'l')
		return (flag->long_list = 1);
	else if (c == 'R')
		return (flag->recursive = 1);
	else if (c == 'a')
		return (flag->hide = 1);
	else if (c == 'r')
		return (flag->reverse = 1);
	else if (c == 't')
		return (flag->time = 1);
	return (0);
}

static int		check_arg(t_flags *flag, char *arg)
{
	if (*arg != '-' || !ft_strcmp(arg, "-") || !ft_strcmp(arg, "--"))
		return (0);
	arg++;
	while (add_arg(flag, *arg))
		arg++;
	if (*arg)
	{
		ft_putstr_fd("Error: option not recognized |", 2);
		ft_putchar_fd(*arg, 2);
		ft_putstr_fd("|\n", 2);
		ft_putstr_fd(USAGE, 2);
		exit(1);
	}
	return (1);
}


void			init_ls(t_env *env, char **av)
{
	int			i;
	t_args		*args;
	struct stat	statbuf;

	i = 1;
	while (av[i] && check_arg(&env->flag, av[i]))
		i++;
	if (av[i] && !ft_strcmp(av[i], "--"))
		i++;
	if (!av[i])
	{
		stat_args(".", &statbuf);
		args = args_maillon(".");
		if (S_ISDIR(statbuf.st_mode))
			args->type_dir = 1;
		argslst(&env->args, args);
	}
	while (av[i])
	{
		if (stat_args(av[i], &statbuf))
		{
			args = args_maillon(av[i]);
			if (S_ISDIR(statbuf.st_mode))
				args->type_dir = 1;
			argslst(&env->args, args);
		}
		i++;
	}
}
