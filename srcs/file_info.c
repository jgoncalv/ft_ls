/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:39:55 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/04/22 16:39:59 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	type_of_file(struct stat *buf)
{
	if (S_ISREG(buf->st_mode))
		return ('-');
	else if (S_ISDIR(buf->st_mode))
		return ('d');
	else if (S_ISCHR(buf->st_mode))
		return ('c');
	else if (S_ISBLK(buf->st_mode))
		return ('b');
	else if (S_ISFIFO(buf->st_mode))
		return ('p');
	else if (S_ISLNK(buf->st_mode))
		return ('l');
	else if (S_ISSOCK(buf->st_mode))
		return ('s');
	return ('-');
}

static void	get_file_right(t_args *arg, struct stat *buf, char *path)
{
	arg->mode[1] = (S_IRUSR & buf->st_mode) ? 'r' : '-';
	arg->mode[2] = (S_IWUSR & buf->st_mode) ? 'w' : '-';
	arg->mode[3] = (S_IXUSR & buf->st_mode) ? 'x' : '-';
	arg->mode[4] = (S_IRGRP & buf->st_mode) ? 'r' : '-';
	arg->mode[5] = (S_IWGRP & buf->st_mode) ? 'w' : '-';
	arg->mode[6] = (S_IXGRP & buf->st_mode) ? 'x' : '-';
	arg->mode[7] = (S_IROTH & buf->st_mode) ? 'r' : '-';
	arg->mode[8] = (S_IWOTH & buf->st_mode) ? 'w' : '-';
	arg->mode[9] = (S_IXOTH & buf->st_mode) ? 'x' : '-';
	if (S_ISUID & buf->st_mode)
		arg->mode[3] = (S_IXUSR & buf->st_mode ? 's' : 'S');
	if (S_ISGID & buf->st_mode)
		arg->mode[6] = (S_IXGRP & buf->st_mode ? 's' : 'S');
	if (S_ISVTX & buf->st_mode)
		arg->mode[9] = (S_IXOTH & buf->st_mode ? 't' : 'T');
	arg->mode[10] = get_acl(path);
	arg->mode[11] = '\0';
}

static void	timestamp_l(t_args *arg, long mtime)
{
	long	six_month_before;
	long	one_hour_after;
	char	*str_time;

	str_time = ctime(&mtime);
	one_hour_after = time(NULL) + (3600);
	six_month_before = time(NULL) - (365 * 12 * 3600);
	ft_strncpy(arg->time, str_time + 4, 7);
	if (mtime < six_month_before || mtime > one_hour_after)
		ft_strncpy(arg->time + 7, str_time + 19, 5);
	else
		ft_strncpy(arg->time + 7, str_time + 11, 5);
}

void		get_file_info(t_env *e, t_args *arg, char *file_path)
{
	struct stat		buf;
	struct passwd	*user;
	struct group	*group;
	char			link[2048];

	if ((e->flag.long_list == 1 || e->flag.time == 1) &&
		lstat_args(file_path, &buf, e))
	{
		user = getpwuid(buf.st_uid);
		group = getgrgid(buf.st_gid);
		timestamp_l(arg, buf.st_mtime);
		if ((arg->mode[0] = type_of_file(&buf)) == 'l')
		{
			ft_bzero(link, 2048);
			readlink(file_path, link, sizeof(link) - 1);
			ft_strcpy(arg->link, link);
		}
		get_file_right(arg, &buf, file_path);
		arg->nlink = ft_itoa(buf.st_nlink);
		arg->size = ft_itoa(buf.st_size);
		ft_strcpy(arg->userid, user->pw_name);
		ft_strcpy(arg->groupid, group->gr_name);
		arg->timespend = buf.st_mtime;
		arg->block = buf.st_blocks;
	}
}
