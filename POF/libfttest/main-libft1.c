#include "libft.h"
#include <stdio.h>

void test_bzero()
{
	char test[] = "ByeE";
	int i;

	i = 0;
	ft_putstr("=== TEST BZERO ===\n\n");
	while (test[i])
	{
		ft_putnbr(test[i]);
		i++;
		ft_putchar('\n');
	}
	ft_bzero(test, 3);
	i = 0;
	ft_putstr("- 3 Premier en 0\n");
	while (i < 4)
	{
		ft_putnbr(test[i]);
		i++;
		ft_putchar('\n');
	}
	ft_putstr("=== FIN BZERO ===\n\n");

}
void test_memset()
{
	char test[] = "ByeE";
	int i;	

	i = 0;
	ft_putstr("=== TEST MEMSET ===\n\n");
	while (test[i])
	{
		ft_putchar(test[i]);
		i++;
		ft_putchar('\n');
	}
	ft_memset(test, '@', 3);
	i = 0;
	ft_putstr("- 3 Premier en '@'\n");
	while (i < 4)
	{
		ft_putchar(test[i]);
		i++;
		ft_putchar('\n');
	}
	ft_putstr("=== FIN MEMSET ===\n\n");

}
void test_memcpy()
{
	char test1[] = "Aurevoir les enfants";
	char test2[] = "Bonjour,";
	ft_putstr("=== TEST MEMCPY ===\n\n");
	ft_putstr("SRC = Bonjour, DEST = Aurevoir les enfants\n");
	ft_memcpy(test1, test2, 8);
	ft_putstr(test1);
	ft_putstr("\n=== FIN MEMCPY ===\n\n");
}
void test_memccpy()
{
	char test1[] = "Stop the Porn";
	char test2[] = "Feed the troll";

	ft_putstr("=== TEST MEMCCPY ===\n\n");
	printf("SRC = %s\nDEST = %s\nchar = P\nsize_t = 13\n", test1, test2);
	ft_memccpy(test2, test1, 80, 13);
	ft_putstr(test2);
	ft_putstr("\n=== FIN MEMCCPY ===\n\n");

}
void test_memmove()
{
	char test1[] = "aUrEvOiR";
	char test2[] = "Aurevoir";
	ft_putstr("=== TEST MEMMOVE ===\n\n");
	printf("SRC = %s\nDEST = %s\nsize_t = 8 puis 4\n",test2 ,test1);
	ft_memmove(test1, test2, 8);
	ft_putstr(test1);
	ft_putchar('\n');
	char test3[] = "aUrEvOiR";
	char test4[] = "Aurevoir";
	ft_memmove(test3, test4, 4);
	ft_putstr(test3);
	ft_putchar('\n');
	ft_putstr("=== FIN MEMMOVE ===\n\n");
	
}
void test_strcmp()
{
	char test1[] = "Bonjour";
	char test2[] = "Bonjour";
	char test3[] = "Aurevoir";
	int i;

	ft_putstr("=== TEST STRCMP ===\n\n");
	printf("test1 = Bonjour, test2 = Bonjour, test3 = Aurevoir\n");
	ft_putstr("1er test = 1 / 2\n2eme test = 2 / 3\n");
	i = ft_strcmp(test1, test2);
	ft_putnbr(i);
	ft_putchar('\n');
	i = ft_strcmp(test2, test3);
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putstr("=== FIN STRCMP ===\n\n");	
}
void test_strncmp()
{
	char test1[] = "Salut les enfants";
	char test2[] = "Salut les enfoire";
	int i;
	ft_putstr("=== TEST STRNCMP ===\n\n");
	printf("test1 = Salut les enfants \ntest2 = Salut les enfoire\n");
	printf("1er test: 5 \n2eme test: 17 (le tout)\n");
	i = ft_strncmp(test1, test2, 5);
	ft_putnbr(i);
	ft_putchar('\n');
	i = ft_strncmp(test1, test2, 17);
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putstr("=== FIN STRNCMP ===\n\n");
}
void test_strlen()
{
	char test1[] = "HUITHUIT";
	char test2[] = "SIXSIX";
	int i;

	ft_putstr("=== TEST STRLEN ===\n\n");
	ft_putstr(test1);
	i = ft_strlen(test1);
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putstr(test2);
	ft_putchar('\n');
	i = ft_strlen(test2);
	ft_putnbr(i);
	ft_putstr("\n=== FIN STRLEN ===\n\n");
}
void test_strdup()
{
	char test[] = "Je vais etre copier";
	char *test1;
	ft_putstr("=== TEST STRDUP ===\n\n");
	ft_putstr(test);
	ft_putchar('\n');
	test1 = ft_strdup(test);
	ft_putstr(test1);
	ft_putchar('\n');
	ft_putstr("\n=== FIN STRDUP ===\n\n");
}
void test_strcpy()
{
	char test1[10];
	char *test3 = "Copie jusqu'aaaaaaaaaa";
	char *test4;
	ft_putstr("=== TEST STRCPY ===\n\n");
	ft_putstr("Copie de - Moi aussi");
	ft_putchar('\n');
	ft_strcpy(test1, "Moi aussi");
	ft_putstr(test1);
	ft_putchar('\n');
	ft_putstr("=== FIN STRCPY === \n\n=== TEST STRNCPY ===\n\n");
	ft_putstr(test3);
	ft_putchar('\n');
	ft_strncpy(test4, test3, 13);
	ft_putstr(test4);
	ft_putchar('\n');
	ft_putstr("=== FIN STRNCPY ===\n\n");
	test4 = NULL;
}

void test_is()
{
	ft_putstr("=== TEST ISALPHA ==\n\n");
	ft_putstr("Test A -> ");
	ft_putnbr(ft_isalpha('A'));
	ft_putstr("\nTest r ->");
	ft_putnbr(ft_isalpha('r'));
	ft_putstr("\nTest 7 ->");
	ft_putnbr(ft_isalpha('7'));
ft_putstr("\n\n=== FIN ISLAPHA ===\n\n=== TEST ISDIGIT ===\n\n");
	ft_putstr("Test A -> ");
	ft_putnbr(ft_isdigit('A'));
	ft_putstr("\nTest r ->");
	ft_putnbr(ft_isdigit('r'));
	ft_putstr("\nTest 7 ->");
	ft_putnbr(ft_isdigit('7'));
	ft_putstr("\n\n=== FIN ISDIGIT ===\n\n=== TEST ISALNUM ===\n\n");
	ft_putstr("Test A -> ");
	ft_putnbr(ft_isalnum('A'));
	ft_putstr("\nTest r ->");
	ft_putnbr(ft_isalnum('r'));
	ft_putstr("\nTest 7 ->");
	ft_putnbr(ft_isalnum('7'));
	ft_putstr("\n\n=== FIN ISALNUM ===\n\n=== TEST ISPRINT ===\n\n");
	ft_putstr("\nTest ~ ->");
	ft_putnbr(ft_isprint('~'));
	ft_putstr("\nTest ' ' ->");
	ft_putnbr(ft_isprint(' '));
	ft_putstr("\n\n=== FIN ISPRINT ===\n\n=== TEST ISASCII ===\n\nLa flem\n\n=== FIN ISASCII ===\n\n");
}
void test_to()
{
	ft_putstr("=== TEST TOUPPER/TOLOWER ===\n\n");
	ft_putstr("Test toupper de 'a': ");
	ft_putchar(ft_toupper('a'));
	ft_putstr("\nTest tolower de 'Z': ");
	ft_putchar(ft_tolower('Z'));
	ft_putstr("\n\n=== FIN TOUPPER/TOLOWER ===\n\n");
}
void test_strcat()
{
	char *src = "des bananes";
	char dest[30] = "Je mange ";
	char *src1 = "des bananes";
	char dest1[30] = "Je mange ";
	ft_strcat(dest, src);
	ft_putstr("=== TEST STRCAT ===\n\n\"des bananes\" dans \"Je mange \"\n");
	ft_putstr(dest);
	ft_putstr("\n\n=== FIN STRCAT ===\n\n=== TEST STRNCAT ===\n\n");
	ft_strncat(dest1, src1, 3);
	ft_putstr("Test du meme exemple avec que '3' charactères\n");
	ft_putstr(dest1);
	ft_putstr("\n\n=== FIN STRNCAT ===\n\n");
	
}
void test_strchr()
{
	ft_putstr("=== TEST STRCHR ===\n\n Cherche 'j' dans \"bonjour\"\n");
	ft_putstr(ft_strchr("bonjour", 'j'));
	ft_putstr("\n\n=== FIN STRCHR ===\n\n=== TEST STRRCHR ===\n\n Cherche'P' dans \"PifPafPouf\"\n");
	ft_putstr(ft_strrchr("PifPafPouf", 'P'));
	ft_putstr("\n\n=== FIN STRRCHR ===\n\n");	
}
void test_strstr()
{
	ft_putstr("=== TEST STRSTR  ===\n\nOn cherche \"<3\" dans \"</3 LeagueOfLegend <3 DotA\"\n");
	ft_putstr(ft_strstr("</3 LeagueOfLegend  <3 DotA", "<3"));
	ft_putstr("\n\n=== FIN STRSTR ===\n\n");
}
void test_atoi()
{
	ft_putstr("=== TEST ATOI ===\n\n1er test : 1\n2eme test: -2147483648\n");
	ft_putnbr(ft_atoi("1"));
	ft_putchar('\n');
	ft_putnbr(ft_atoi("-2147483648"));
	ft_putstr("\n\n=== FIN ATOI ===\n\n");
}
int main()
{
	test_bzero();
	test_memset();
	test_memcpy();
	test_memccpy();
	test_memmove();
	test_strlen();
	test_strdup();
	test_strcpy();
	test_strcat();
	test_strchr();
	test_strstr();
	test_strcmp();
	test_strncmp();
	test_atoi();
	test_is();
	test_to();
	return (0);
}
