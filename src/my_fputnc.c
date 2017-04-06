/*
** my_fputnc.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sun Feb 19 22:55:05 2017 Arthur Melin
** Last update Tue Mar  7 10:59:55 2017 Arthur Melin
*/

#include <stdlib.h>
#include <unistd.h>
#include <my.h>

void	my_fputnc(int fd, int c, size_t n)
{
  char	_c;
  char	*buf;

  if (!(buf = malloc(n)))
    {
      _c = c;
      while (n--)
	write(fd, &_c, 1);
    }
  else
    {
      my_memset(buf, c, n);
      write(fd, buf, n);
      free(buf);
    }
}
