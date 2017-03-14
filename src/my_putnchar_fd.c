/*
** my_putnchar_fd.c for libmy in /home/arthur.melin/Code/libmy
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

void	my_putnchar_fd(int fd, char c, int n)
{
  char	*buffer;

  if (n < 0)
    return ;
  if (!(buffer = malloc(n)))
    {
      while (n--)
	write(fd, &c, 1);
    }
  else
    {
      my_memset(buffer, c, n);
      write(fd, buffer, n);
      free(buffer);
    }
}
