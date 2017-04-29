/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:17:10 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/30 18:17:12 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_args	*do_the_comp(t_env *e, t_args *tmp, t_args *curr, t_args *comp)
{
	if (e->flag.time)
	{
		if (curr->timespend < comp->timespend ||
			(curr->timespend == comp->timespend &&
				ft_strcmp(curr->name, comp->name) > 0))
		{
			if (!tmp)
				tmp = comp;
			else if (tmp->timespend < comp->timespend ||
				(tmp->timespend == comp->timespend &&
					ft_strcmp(tmp->name, comp->name) > 0))
				tmp = comp;
		}
	}
	else
	{
		if (ft_strcmp(curr->name, comp->name) > 0)
		{
			if (!tmp)
				tmp = comp;
			else if (ft_strcmp(tmp->name, comp->name) > 0)
				tmp = comp;
		}
	}
	return (tmp);
}

static void		reverse_list(t_args **alst)
{
	t_args	*curr;
	t_args	*last;
	t_args	*tmp;

	last = *alst;
	curr = *alst;
	tmp = NULL;
	while (last && last->next)
		last = last->next;
	while (curr && curr != last)
	{
		tmp = last;
		arg_swap(alst, curr, last);
		last = curr;
		curr = tmp;
		if (curr->next == last)
			break ;
		curr = curr->next;
		last = last->prev;
	}
}

static void		sort_list(t_args **alst, t_env *e)
{
	t_args	*curr;
	t_args	*comp;
	t_args	*tmp;

	curr = *alst;
	tmp = NULL;
	while (curr)
	{
		comp = curr->next;
		while (comp)
		{
			tmp = do_the_comp(e, tmp, curr, comp);
			comp = comp->next;
		}
		if (tmp)
		{
			arg_swap(alst, curr, tmp);
			curr = tmp;
			tmp = NULL;
		}
		curr = curr->next;
	}
}

void			arg_sort(t_args **alst, t_env *e)
{
	sort_list(alst, e);
	if (e->flag.reverse)
		reverse_list(alst);
}
