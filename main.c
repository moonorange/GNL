#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "gnl_code/get_next_line.h"


int main()
{
	int fd;
	char *line;
	int ret_gnl;

	fd = open("no_nl.txt", O_RDONLY);
	while ((ret_gnl = get_next_line(fd, &line)) > 0)
	{
		printf("ret_gnl: %d\n", ret_gnl);
		printf("line: %s\n", line);
	}
	printf("----after while loop-----\n");
	printf("ret_gnl: %d\n", ret_gnl);
	printf("line: %s\n", line);
	return (0);
}
