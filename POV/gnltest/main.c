/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:33:27 by jgraille          #+#    #+#             */
/*   Updated: 2016/12/13 12:06:45 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR
# define COLOR

# define RED ft_putstr("\033[31m");
# define BLUE ft_putstr("\033[34m");
# define CYAN ft_putstr("\033[36m");
# define GREEN ft_putstr("\033[32m");
# define YELLOW ft_putstr("\033[33m");
# define CANCEL ft_putstr("\033[00m");

#endif

#include	"libft/libft.h"
#include	"get_next_line.h"
#include	<fcntl.h>
#include	<unistd.h>

void		testMulti2(int ac, char **av)
{
	int i;
	int	getline;
	int	fd[ac -1];
	char *line;
	int	requestNb;
	int	countEND;

	i = 0;
	countEND = 0;
	while (++i < ac)
		fd[i -1] = open(av[i], O_RDONLY);
	i = 0;
	ft_putstr("\n------  TEST NON CHAINED GNL FILE(S) REQUEST ------\n");
	requestNb = -1;
	while (countEND != ac -1)
	{
		requestNb++;
		countEND = 0;
		ft_putstr("\n");
		ft_putstr("----------     ");
		ft_putnbr(requestNb + 1);
		ft_putstr("e request :     ----------");
		i = 0;
		while(++i < ac)
		{
			getline = get_next_line(fd[i - 1], &line);
			ft_putchar('\n');
			ft_putstr(" file [");
			ft_putstr(av[i]);
			ft_putstr("] return ");
			if (getline == 1)
			{
				GREEN
				ft_putnbr(getline);
				CANCEL
				ft_putstr("  :  \"");
				GREEN
				ft_putstr(line);
				CANCEL
				ft_putchar('"');
			}
			else
			{
				YELLOW
				ft_putnbr(getline);
				CANCEL
				ft_putstr("  :  ");
				YELLOW
				ft_putstr(getline == 0 ? "FILE END" : "ERROR");
				CANCEL
				countEND++;
			}
		}
		ft_putchar('\n');
	}
	i = 0;
	while (++i < ac)
		close(fd[i -1]);
}


int		main(int ac, char **av)
{
	if (ac > 1)
	{
		testMulti2(ac, av);
		//if(testMultiFile(ac, av))
		//	ft_putstr("[Multi error for chained GNL]\n");
	}
	else
		ft_putstr_fd("Usage : ./test_gnl file_A file_B etc...\n", 2);
	return (0);
}
