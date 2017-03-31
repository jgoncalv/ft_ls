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
/*
static void	type_of_file(t_args *arg)
{
	struct stat	buf;

	buf = arg->buf_stat;
	if (S_ISREG(buf->st_mode))
		arg->type = '-';
	else if (S_ISDIR(buf->st_mode))
	else if (S_ISCHR(buf->st_mode))
	else if (S_ISBLK(buf->st_mode))
	else if (S_ISFIFO(buf->st_mode))
	else if (S_ISLNK(buf->st_mode))
	else if (S_ISSOCK(buf->st_mode))
}
*/
int	stat_args(char *name, struct stat *statbuf)
{
	struct stat buf;

	if (stat(name, &buf) == -1)
	{
		perror(name);
		return (0);
	}
	*statbuf = buf;
	return (1);
}

int	lstat_args(char *name, struct stat *statbuf)
{
	struct stat buf;

	if (lstat(name, &buf) == -1)
	{
		perror(name);
		return (0);
	}
	*statbuf = buf;
	return (1);
}
