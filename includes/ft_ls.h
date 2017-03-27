#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# define USAGE "Usage: ./ft_ls [-lRart] [file...]\n"


typedef struct	s_flags
{
	int			long_list;
	int			recursive;
	int			hide;
	int			reverse;
	int			sort_modif;
}				t_flags;

typedef struct	s_path
{
	char		*name;
}				t_path;

typedef struct	s_env
{
	t_flags		flag;
	t_list		*args;
}				t_env;

void			init_ls(t_env *env, char **av);

#endif
