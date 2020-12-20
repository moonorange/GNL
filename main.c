#include "gnl_code/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int   main(int ac, char **av)
{
  char  *line;
  int   fd1;
  int   fd2;

  ac = 0;
  fd1 = open("text.txt", O_RDONLY);
  fd2 = open(av[1], O_RDONLY);
  while (get_next_line(fd1, &line)> 0)
    printf("%s\n", line);
  printf("--------------test 2\n");
  while (get_next_line(fd2, &line)> 0)
    printf("%s\n", line);
  return (0);
}
