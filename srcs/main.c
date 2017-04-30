/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:05:10 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/28 20:05:11 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_env(t_env *env)
{
	env->args = NULL;
	env->flag = (t_flags){0, 0, 0, 0, 0, 0, 0, 0, 0};
	env->args_alone = 0;
	env->buf[0] = '\0';
	env->buflen = 0;
}

int			main(int ac, char **av)
{
	t_env	env;

	(void)ac;
	init_env(&env);
	init_ls(&env, av);
	arg_sort(&env.args, &env);
	if (env.args == NULL)
		return (1);
	env.args_alone = (env.args->next != NULL ? 0 : 1);
	ls_output(&env);
	return (0);
}
