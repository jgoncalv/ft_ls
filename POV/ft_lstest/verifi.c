/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:00:28 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/04 16:09:54 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		myfd;
	int		lsfd;
	int		bmy;
	int		bls;
	char	*my;
	char	*ls;
	int		ok;
	int		nbr;
	int		count;
	int		i;
	int		wait;
	int		ret;
	float	good;
	float	bad;
	char	*buf;

	buf = ft_strnew(10);
	wait = ac != 2 ? 0 : ft_atoi(av[1]);
	myfd = open("/tmp/myout001001", O_RDONLY);
	lsfd = open("/tmp/lsout001001", O_RDONLY);

	bmy = ft_gnl(myfd, &my);
	bls = ft_gnl(lsfd, &ls);

	good = 0;
	bad = 0;
	nbr = bls == 1 ? 1 : 0;
	ok = 1;
	while ((bmy != 0 || bls != 0))
	{
		if(bmy == -1)
		{
			PYEL("error from user output\n")
				ok = 0;
		}
		if(bmy == -1)
		{
			PYEL("error from ls output\n")
				ok = 0;
		}
		if (ft_strcmp(my, ls))
		{
			bad++;
			if (wait != 2)
			{
				PWARN PRED(" ERROR DETECTED ") PWARN NL
			}
				END(ls)
				i = 0;
			while(my[i])
			{
				if (my[i] != ls[i])
				{
					write(1,my , i);
					STR(RED)
						ft_putchar(my[i]);
					STR(RST)
					my += i + 1;
					ls += i + 1;
					i = 0;
				}
				i += my[i] ? 1 : 0;
			}
			write(1, my , i);NL
			ok = 0;
			if (wait == 1)
			{
				NL PYEL("PRESS RETURN TO CONTINUS")NL
				ret = 0;
				while (ret == 0)
					ret = read(0 , buf, 10);
			}
		}
		else
		{
			good++;
			PGRN(my) NL
		}

		bmy = ft_gnl(myfd, &my);
		bls = ft_gnl(lsfd, &ls);
		nbr = bls == 1 ? 1 : 0;
	}
	NL NL STR("RESULT : ")
	if (ok)
	{
		PGRN("100% Great work !")
	}
	else
	{
		STR(RED)NBR(((int)(100 * good/(good+bad))))STR("% not really perfect")STR(RST)
	}
	NL
	return (1);
}
