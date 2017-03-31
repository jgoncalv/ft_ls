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

/*
**	env->nb_args est un flag permettant de savoir si il y a plus de 1 args
**	ce qui permet de faire le premier affichage comme le vrai ls	
*/

char	*strjoin_path(char *s1, char *s2)
{
	char	*path;
	int		len;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	path = ft_strnew(len);
	if (!path)
		return (NULL);
	path = ft_strcpy(path, s1);
	path[ft_strlen(path)] = '/';
	path[ft_strlen(path) + 1 ] = '\0';
	path = ft_strcat(path, s2);
	return (path);
}

static void	ft_read_dir(t_args *l_args, t_env *e, char *path)
{
	DIR				*dirp;
	struct dirent	*rddir;
	t_args			*arg;

	dirp = opendir(path);
	if (dirp == NULL)
		perror(l_args->name);
	else
	{
		while ((rddir = readdir(dirp)) != NULL)
		{
			if (e->flag.hide == 0 && *rddir->d_name == '.')
				;
			else
			{
				arg = args_maillon(rddir->d_name);
				if (rddir->d_type == DT_DIR)
					arg->type_dir = 1;
				argslst(&l_args->args_son, arg);
			}
		}
		closedir(dirp);
	}
}

void	open_dir(t_args *l_args, t_env *e, char *path)
{
		if (l_args->type_dir == 1)
		{
			ft_read_dir(l_args, e, path);
			arg_sort(&l_args->args_son, e);
		}
}

void	output_file(t_args *lst, int first, t_env *e)
{
	static int i= 0;

	i++;
	while (lst)
	{
		if (first == 1 && e->args_alone == 0)
		{
			if (lst->type_dir == 0)
			{
				add_file_to_buf(e, lst->name);
				add_file_to_buf(e, " ");
			}
		}
		else if (first == 0)
		{
			add_file_to_buf(e, lst->name);
			add_file_to_buf(e, " ");
		}
		lst = lst->next;
	}
	add_file_to_buf(e, "\n");
}

static void	browse(t_args *lst, int first, char *mpath, t_env *e)
{
	char	*path;
	t_args	*tmp;

	while (lst)
	{
		if (lst->type_dir && ((ft_strcmp(lst->name, ".") != 0
			&& ft_strcmp(lst->name, "..") != 0) || first == 1))
		{
			path = strjoin_path(mpath, lst->name);
			if (e->args_alone == 0)
			{
				add_file_to_buf(e, path);
				add_file_to_buf(e, ":\n");
			}
			else
				e->args_alone = 0;
			if (first == 0)
				open_dir(lst, e, path);
			output_file(lst->args_son, 0, e);
			add_file_to_buf(e, "\n");
			if (e->flag.recursive == 1)
				browse(lst->args_son, 0, path, e);
			ft_strdel(&path);
		}
		tmp = lst;
		lst = lst->next;
		args_del_maillon(&tmp);
	}
}

void	ls_output(t_env *env)
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
}
