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

static void	arg_swap(t_args **alst, t_args *curr, t_args *comp)
{
	t_args *tmp;

	if (*alst == curr)
		*alst = comp;
	if (curr->prev != NULL)
		curr->prev->next = comp;
	if (comp->next != NULL)
		comp->next->prev = curr;
	if (curr->next == comp)
	{
		curr->next = comp->next;
		comp->next = curr;
		comp->prev = curr->prev;
		curr->prev = comp;
	}
	else
	{
		comp->prev->next = curr;
		curr->next->prev = comp;
		tmp = curr->prev;
		curr->prev = comp->prev;
		comp->prev = tmp;
		tmp = curr->next;
		curr->next = comp->next;
		comp->next = tmp;
	}
}

void		arg_sort(t_args **alst, t_env *e)
{
	t_args	*curr;
	t_args	*comp;
	t_args	*tmp;

	(void)e;
	curr = *alst;
	tmp = NULL;
	while (curr)
	{
		comp = curr->next;
		while (comp)
		{
			if (ft_strcmp(curr->name, comp->name) > 0)
			{
				if (!tmp)
					tmp = comp;
				else if (ft_strcmp(tmp->name, comp->name) > 0)
					tmp = comp;
			}
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
