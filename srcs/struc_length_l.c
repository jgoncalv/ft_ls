/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc_length_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:26:57 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/04/22 15:27:00 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_length	init_length(void)
{
	t_length	len;

	len.size = 0;
	len.userid = 0;
	len.groupid = 0;
	len.nlink = 0;
	return (len);
}

t_length		len_for_option(t_env *e, t_args *arg)
{
	t_length len;

	len = init_length();
	if (e->flag.long_list == 1)
	{
		while (arg)
		{
			if (len.nlink < (int)ft_strlen(arg->nlink))
				len.nlink = (int)ft_strlen(arg->nlink);
			if (len.userid < (int)ft_strlen(arg->userid))
				len.userid = (int)ft_strlen(arg->userid);
			if (len.groupid < (int)ft_strlen(arg->groupid))
				len.groupid = (int)ft_strlen(arg->groupid);
			if (len.size < (int)ft_strlen(arg->size))
				len.size = (int)ft_strlen(arg->size);
			arg = arg->next;
		}
	}
	return (len);
}
