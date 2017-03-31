/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:05:28 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/28 20:05:30 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <sys/types.h> 
# include <sys/stat.h> 
# include <unistd.h>
# include <dirent.h>

# define USAGE "Usage: ./ft_ls [-lRart] [file...]\n"
# define DISPLAY_SIZE 1024

typedef struct		s_flags
{
	int				long_list;
	int				recursive;
	int				hide;
	int				reverse;
	int				time;
}					t_flags;

typedef struct		s_args
{
	char			name[256];
	int				type_dir;
	struct stat		buf_stat;
	struct s_args	*args_son;
	struct s_args	*next;
	struct s_args	*prev;
}					t_args;

typedef struct		s_env
{
	t_flags			flag;
	t_args			*args;
	int				args_alone;
	char			buf[DISPLAY_SIZE];
	int				buflen;
}					t_env;

void				init_ls(t_env *env, char **av);
int					stat_args(char *name, struct stat *statbuf);
int					lstat_args(char *name, struct stat *statbuf);
void				ls_output(t_env *env);

/*
**	ARGS LST
*/

t_args				*args_maillon(char *name);
void				args_del(t_args **args);
void				args_del_maillon(t_args **args);
void				argslst(t_args **alst, t_args *nargs);
void				arg_sort(t_args **alst, t_env *e);

/*
**	DISPLAY
*/

void				display_buf(t_env *e);
void				add_file_to_buf(t_env *e, char *str);

#endif
