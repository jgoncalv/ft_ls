/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 20:10:23 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/04/29 20:10:24 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	get_acl(char *path)
{
	ssize_t		xattr;
	acl_t		acl;

	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		return ('@');
	else
	{
		acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
		if (acl)
		{
			acl_free((void *)acl);
			acl = NULL;
			return ('+');
		}
		else
			return (' ');
	}
}
