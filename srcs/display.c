/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 22:14:49 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/30 22:14:50 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		add_str_to_buf(t_env *e, char *str)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = 0;
	while (i < len && i + e->buflen < DISPLAY_SIZE - 1)
	{
		e->buf[e->buflen + i] = str[i];
		i++;
	}
	e->buflen += i;
	if (i < len)
	{
		display_buf(e);
		add_str_to_buf(e, str + i);
	}
}

static void	add_str_to_buf_align(t_env *e, char *str, int len, int align)
{
	int i;
	int	space;

	i = 0;
	if (align == 1)
	{
		space = len - ft_strlen(str);
		while (i < space)
		{
			add_str_to_buf(e, " ");
			i++;
		}
		add_str_to_buf(e, str);
	}
	else
	{
		add_str_to_buf(e, str);
		i = ft_strlen(str);
		while (i < len)
		{
			add_str_to_buf(e, " ");
			i++;
		}
	}
}

void		add_file_to_buf(t_env *e, t_args *arg, t_length len)
{
	if (e->flag.long_list == 1)
	{
		add_str_to_buf(e, arg->mode);
		add_str_to_buf(e, " ");
		add_str_to_buf_align(e, arg->nlink, len.nlink, 1);
		add_str_to_buf(e, " ");
		add_str_to_buf_align(e, arg->userid, len.userid, 0);
		add_str_to_buf(e, "  ");
		add_str_to_buf_align(e, arg->groupid, len.groupid, 0);
		add_str_to_buf(e, "  ");
		add_str_to_buf_align(e, arg->size, len.size, 1);
		add_str_to_buf(e, " ");
		add_str_to_buf(e, arg->time);
		add_str_to_buf(e, " ");
	}
	add_str_to_buf(e, arg->name);
	if (e->flag.long_list && arg->mode[0] == 'l')
	{
		add_str_to_buf(e, " -> ");
		add_str_to_buf(e, arg->link);
	}
}

void		display_buf(t_env *e)
{
	write(1, e->buf, e->buflen);
	e->buf[0] = '\0';
	e->buflen = 0;
}
