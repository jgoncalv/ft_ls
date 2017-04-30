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
	len.block = 0;
	return (len);
}

static int		len_nbr(unsigned int nbr)
{
	int len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static t_length	len_bonus_option(t_env *e, t_args *arg, t_length len)
{
	int size;

	size = 0;
	if (e->flag.show_size)
	{
		while (arg)
		{
			size = len_nbr(arg->block);
			if (len.block < size)
				len.block = size;
			arg = arg->next;
		}
	}
	return (len);
}

t_length		len_for_option(t_env *e, t_args *arg)
{
	t_length len;

	len = init_length();
	len = len_bonus_option(e, arg, len);
	if (e->flag.long_list)
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
