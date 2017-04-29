/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:19:58 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/29 16:19:59 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			stat_args(char *name, struct stat *statbuf, t_env *e)
{
	struct stat buf;

	if (stat(name, &buf) == -1)
	{
		display_buf(e);
		ft_putstr_fd("ft_ls: ", 2);
		perror(name);
		return (0);
	}
	*statbuf = buf;
	return (1);
}

int			lstat_args(char *name, struct stat *statbuf, t_env *e)
{
	struct stat buf;

	if (lstat(name, &buf) == -1)
	{
		display_buf(e);
		ft_putstr_fd("ft_ls: ", 2);
		perror(name);
		return (0);
	}
	*statbuf = buf;
	return (1);
}
