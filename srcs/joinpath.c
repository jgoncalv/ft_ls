/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 18:50:38 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/04/29 18:50:39 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*strjoin_path(char *s1, char *s2)
{
	char	*path;
	int		len;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	path = ft_strnew(len);
	if (!path)
		return (NULL);
	path = ft_strcpy(path, s1);
	path[ft_strlen(path)] = '/';
	path[ft_strlen(path) + 1] = '\0';
	path = ft_strcat(path, s2);
	return (path);
}
