/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:05:41 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/29 16:05:42 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_total_blocks(t_env *e, t_args *lst, int first)
{
	unsigned int	blocks;
	char			*total_blocks;
	t_args			*tmp;

	if (e->flag.long_list && first == 0 && lst)
	{
		blocks = 0;
		tmp = lst;
		while (tmp)
		{
			blocks += tmp->block;
			tmp = tmp->next;
		}
		total_blocks = ft_itoa(blocks);
		add_str_to_buf(e, "total ");
		add_str_to_buf(e, total_blocks);
		add_str_to_buf(e, "\n");
		ft_strdel(&total_blocks);
	}
}

static void	output_file(t_args *lst, int first, t_env *e)
{
	t_length		len;
	t_args			*tmp;

	len = len_for_option(e, lst);
	ft_total_blocks(e, lst, first);
	while (lst)
	{
		if (first && !lst->type_dir)
		{
			add_file_to_buf(e, lst, len);
			add_str_to_buf(e, "\n");
		}
		else if (!first)
		{
			add_file_to_buf(e, lst, len);
			add_str_to_buf(e, "\n");
		}
		tmp = lst;
		lst = lst->next;
	}
}

static void	browse(t_args *lst, int first, char *mpath, t_env *e)
{
	char		*path;

	while (lst)
	{
		if (lst->type_dir && ((ft_strcmp(lst->name, ".")
			&& ft_strcmp(lst->name, "..")) || first))
		{
			path = strjoin_path(mpath, lst->name);
			if (!e->args_alone)
			{
				add_str_to_buf(e, "\n");
				add_str_to_buf(e, path);
				add_str_to_buf(e, ":\n");
			}
			else
				e->args_alone = 0;
			if (!first)
				open_dir(lst, e, path);
			output_file(lst->args_son, 0, e);
			if (e->flag.recursive)
				browse(lst->args_son, 0, path, e);
			ft_strdel(&path);
		}
		lst = lst->next;
	}
}

void		ls_output(t_env *env)
{
	t_args		*l_curr;

	l_curr = env->args;
	while (l_curr)
	{
		open_dir(l_curr, env, l_curr->name);
		l_curr = l_curr->next;
	}
	output_file(env->args, 1, env);
	browse(env->args, 1, NULL, env);
	display_buf(env);
	args_del_list(&env->args);
}
