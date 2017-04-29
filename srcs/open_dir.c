/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 18:33:11 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/04/29 18:33:15 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_read_dir(t_args *l_args, t_env *e, char *path, DIR *dirp)
{
	struct dirent	*rddir;
	t_args			*arg;
	char			*join_path;

	while ((rddir = readdir(dirp)))
	{
		if (e->flag.hide == 0 && *rddir->d_name == '.')
			;
		else
		{
			arg = args_maillon(rddir->d_name);
			if (rddir->d_type == DT_DIR)
				arg->type_dir = 1;
			if (e->flag.long_list || e->flag.time)
			{
				join_path = strjoin_path(path, rddir->d_name);
				get_file_info(e, arg, join_path);
				ft_strdel(&join_path);
			}
			argslst(&l_args->args_son, arg);
		}
	}
}

void		open_dir(t_args *l_args, t_env *e, char *path)
{
	DIR				*dirp;

	if (l_args->type_dir == 1)
	{
		if (!(dirp = opendir(path)))
		{
			display_buf(e);
			ft_putstr_fd("ft_ls: ", 2);
			perror(l_args->name);
		}
		else
		{
			ft_read_dir(l_args, e, path, dirp);
			arg_sort(&l_args->args_son, e);
			closedir(dirp);
		}
	}
}
