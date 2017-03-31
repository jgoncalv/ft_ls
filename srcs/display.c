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

void	add_file_to_buf(t_env *e, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (e->buflen + len + 1 < DISPLAY_SIZE)
	{
		ft_strcpy(e->buf + e->buflen, str);
		e->buflen += len;
	}
	else
	{
		write(1, e->buf, e->buflen);
		e->buf[0] = '\0';
		ft_strcpy(e->buf, str);
		e->buflen = len;
	}
}

void	display_buf(t_env *e)
{
	write(1, e->buf, e->buflen);
	e->buf[0] = '\0';
	e->buflen = 0;
}
