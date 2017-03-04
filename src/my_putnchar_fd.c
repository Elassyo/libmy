/*
** my_putnchar_fd.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sun Feb 19 22:55:05 2017 Arthur Melin
** Last update Sat Mar  4 14:13:42 2017 Arthur Melin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	my_putnchar_fd(int fd, char c, int n)
{
  char	*buffer;

  buffer = malloc(n);
  my_memset(buffer, c, n);
  write(fd, buffer, n);
  free(buffer);
}
