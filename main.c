#include "gnl_code/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int   main(int ac, char **av)
{
  char  *line;
  int   fd1;
  int   fd2;

  ac = 0;
  av = 0;
  fd1 = open("text.txt", O_RDONLY);
  fd2 = open("text2.txt", O_RDONLY);
  printf("%d\n", get_next_line(fd2, &line));
  printf("%s\n", line);
  printf("%d\n", get_next_line(fd2, &line));
  printf("%s\n", line);
  printf("%d\n", get_next_line(fd2, &line));
  printf("%s\n", line);
  printf("%d\n", get_next_line(fd2, &line));
  printf("%s\n", line);
  printf("%d\n", get_next_line(fd2, &line));
  printf("%s\n", line);
  printf("%d\n", get_next_line(fd2, &line));
  printf("%s\n", line);
  printf("%d\n", get_next_line(fd2, &line));
  printf("%s\n", line);
  return (0);
}
