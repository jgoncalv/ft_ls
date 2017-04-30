#include "libft.h"
#include <stdio.h>


void test_memalloc()
{
	char test[] = "Krystalz";
	int i;
	ft_putstr("\n=== TEST STRCLR ===\n\n \"Krystalz\"\n");
	i = 0;
	while (test[i])
	{
		ft_putnbr(test[i]);
		i++;
		ft_putchar(' ');
	}
	ft_putchar('\n');
	ft_strclr(test);
	i = 0;
	while (test[i] == 0)
	{
		ft_putnbr(test[i]);
		i++;
		ft_putchar(' ');
	}
	ft_putstr("\n\n=== FIN STRCLR === \n\n");
}

void test_strtrim()
{
	ft_putstr("=== TEST STRTRIM ===\n\nTest \" 	lol mais lol  	\"\n");
	ft_putstr(ft_strtrim("   lol mais lol  		"));
	ft_putstr("-Fin-\n\n=== FIN STRTRIM ===\n\n");
}
void test_strsplit()
{
	char **tab;
	int i;
	char *s = "jginitgpagmegptingdegvar";
	ft_putstr("=== TEST STRSPLIT ===\n\n test de: jginitgpagmegptingdegvar\nAvec le char:'g'\n");
	tab = ft_strsplit(s, 'g');
	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("=== FIN STRSPLIT ===\n\n");
}
void test_itoa()
{
	ft_putstr("=== TEST ITOA ===\n\nTest0: 0\nTest1: -2147483648\nTest2: 2147483647\n");
	
	ft_putstr(ft_itoa(0));
	ft_putchar('\n');
	ft_putstr(ft_itoa(-2147483648));
	ft_putchar('\n');
	ft_putstr(ft_itoa(2147483647));
	ft_putstr("\n\n=== FIN ITOA ===\n\n");
}	

int main ()
{
	test_memalloc();
	test_strtrim();
	test_strsplit();
	test_itoa();
//	test_striter();
	return (0);
}

