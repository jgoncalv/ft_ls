#include "includes/ft_printf.h"
#include "srcs/libft/libft.h"
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define _TEST_  "%c",  '&'

int main ()
{
	short s = 700;
	char c = 'e';
	long	l = LONG_MAX;
	long long ll= LLONG_MIN;
	unsigned long ul = -4294967296 ;

	char *lol;
	void *pi = (void *)&lol;
//	int test = -2147483649; 
	int i = 1;
	
	size_t ss = 42;
	
	double d = 42.42;
//	test = open("./lol", O_RDONLY);
	char *str;
	int ret;
	PYEL ft_putstr("\n----- [ SORTIE DE FT_PRINTF ] ------\n\n"); PRST
	ret = ft_printf( _TEST_ );
	ft_putchar('\n');
	ft_putnbr(ret);
	ft_putchar('\n');
	PGRN ft_putstr("\n----- [ SORTIE DE PRINTF ] ------\n\n"); PRST		
	ret = printf( _TEST_ );
	ft_putchar('\n');
	ft_putnbr(ret);
	ft_putchar('\n');

}
