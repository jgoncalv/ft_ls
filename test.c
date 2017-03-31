#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int ac, char **av)
{
	DIR *dirp;
	struct dirent *sd;
	struct stat statbuf;

	if (ac == 1)
		return 0;
	if ((stat(av[1], &statbuf)) == -1)
		perror("Error");
	if (!(dirp = opendir(av[1])))
	{
		perror("Error");
		return (0);
	}
	while ((sd = readdir(dirp)) != NULL)
	{
	if (DT_DIR == sd->d_type)
		printf("OUIII\n");
		if ((lstat(sd->d_name, &statbuf)) == -1)
				perror("Error");
		printf("File_name = |%c|, stat |%d|\n", sd->d_type, statbuf.st_dev);
	}
	closedir(dirp);
	return 0;
}
