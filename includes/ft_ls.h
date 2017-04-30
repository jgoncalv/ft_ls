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
# include <sys/acl.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# define USAGE "Usage: ./ft_ls [-lRartfsoA] [file...]\n"
# define DISPLAY_SIZE 2048

typedef struct		s_length
{
	int				nlink;
	int				size;
	int				userid;
	int				groupid;
	int				block;
}					t_length;

typedef struct		s_flags
{
	int				long_list;
	int				recursive;
	int				hide;
	int				reverse;
	int				time;
	int				dont_sort;
	int				show_size;
	int				without_gid;
	int				restr_hide;
}					t_flags;

typedef struct		s_args
{
	char			name[256];
	int				type_dir;
	char			mode[12];
	char			*nlink;
	char			*size;
	char			userid[256];
	char			groupid[256];
	char			time[13];
	unsigned int	timespend;
	unsigned int	block;
	unsigned int	last_access;
	char			link[2048];
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
int					stat_args(char *name, struct stat *statbuf, t_env *e);
int					lstat_args(char *name, struct stat *statbuf, t_env *e);
void				ls_output(t_env *env);
void				get_file_info(t_env *e, t_args *arg, char *file_name);
/*
**	ARGS LST
*/
t_args				*args_maillon(char *name);
void				args_del_list(t_args **args);
void				args_del_maillon(t_args **args);
void				argslst(t_args **alst, t_args *nargs);
void				arg_sort(t_args **alst, t_env *e);
/*
**	DISPLAY
*/
void				display_buf(t_env *e);
void				add_file_to_buf(t_env *e, t_args *arg, t_length len);
void				add_str_to_buf(t_env *e, char *str);
t_length			len_for_option(t_env *e, t_args *arg);
void				open_dir(t_args *l_args, t_env *e, char *path);
char				*strjoin_path(char *s1, char *s2);
void				arg_swap(t_args **alst, t_args *curr, t_args *comp);
char				get_acl(char *path);

#endif
