/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 19:18:03 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/04/29 19:18:04 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		arg_swap(t_args **alst, t_args *curr, t_args *comp)
{
	t_args *tmp;

	(*alst == curr) && (*alst = comp);
	(curr->prev != NULL) && (curr->prev->next = comp);
	(comp->next != NULL) && (comp->next->prev = curr);
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
