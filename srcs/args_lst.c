/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:29:28 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/29 20:29:29 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_args	*args_maillon(char *name)
{
	t_args	*args;

	if (!(args = (t_args*)ft_memalloc(sizeof(t_args))))
		return (NULL);
	if (!name)
		return (NULL);
	ft_strcpy(args->name, name);
	args->args_son = NULL;
	args->type_dir = 0;
	args->next = NULL;
	args->prev = NULL;
	return (args);
}

void		argslst(t_args **alst, t_args *nargs)
{
	t_args	*tmp;

	if (!nargs)
		return ;
	if (!*alst)
		*alst = nargs;
	else
	{
		tmp = *alst;
		while (tmp && tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = nargs;
		nargs->prev = tmp;
		nargs->next = NULL;
	}
}

void		args_del(t_args **args)
{
	if (!*args)
		return ;
	free(*args);
	*args = NULL;
}

void		args_del_maillon(t_args **args)
{
	if (!*args)
		return ;
	if ((*args)->prev != NULL)
		(*args)->prev->next = (*args)->next;
	if ((*args)->next != NULL)
		(*args)->next->prev = (*args)->prev;
	free(*args);
	*args = NULL;
}
