#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
// # include "gnl_code/get_next_line.h"
# include "get_next_line.h"


int main()
{
	int fd;
	char *line;
	int ret_gnl;

	fd = open("../test.txt", O_RDONLY);
	int counter = 1;
	while ((ret_gnl = get_next_line(fd, &line)) > 0)
	{
		printf("counter　%d, ret_gnl: %d\n", counter, ret_gnl);
		printf("line: %s\n", line);
		counter++;
	}
	printf("----after while loop-----\n");
	printf("ret_gnl: %d\n", ret_gnl);
	printf("line: %s\n", line);
	ret_gnl = get_next_line(fd, &line);
	printf("ret_gnl: %d\n", ret_gnl);
	printf("line: %s\n", line);
	return (0);
}
