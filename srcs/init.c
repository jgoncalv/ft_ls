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
	else if (c == 'f')
	{
		flag->hide = 1;
		return (flag->dont_sort = 1);
	}
	else if (c == 's')
		return (flag->show_size = 1);
	else if (c == 'A')
		return (flag->restr_hide = 1);
	else if (c == 'o')
	{
		flag->without_gid = 1;
		return (flag->long_list = 1);
	}
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

static void		nothing(t_env *e, t_args *arg)
{
	struct stat	statbuf;

	stat_args(".", &statbuf, e);
	arg = args_maillon(".");
	if (S_ISDIR(statbuf.st_mode))
		arg->type_dir = 1;
	argslst(&e->args, arg);
}

void			init_ls(t_env *e, char **av)
{
	int			i;
	t_args		*arg;
	struct stat	statbuf;

	i = 1;
	arg = NULL;
	while (av[i] && check_arg(&e->flag, av[i]))
		i++;
	if (av[i] && !ft_strcmp(av[i], "--"))
		i++;
	if (!av[i])
		nothing(e, arg);
	while (av[i])
	{
		if (stat_args(av[i], &statbuf, e))
		{
			arg = args_maillon(av[i]);
			if (S_ISDIR(statbuf.st_mode))
				arg->type_dir = 1;
			get_file_info(e, arg, av[i]);
			argslst(&e->args, arg);
		}
		i++;
	}
}
