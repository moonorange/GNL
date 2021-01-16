#include "get_next_line.h"
#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>


int main()
{
	int fd;
	char *line;
	int ret_gnl;

	fd = open("a.out", O_RDONLY);
	while ((ret_gnl = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	printf("%d\n", ret_gnl);
	printf("%s\n", line);
	return (0);
}
