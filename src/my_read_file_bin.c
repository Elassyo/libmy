/*
** my_read_file_bin.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Thu Dec  8 21:17:54 2016 Arthur Melin
** Last update Thu Dec  8 21:21:34 2016 Arthur Melin
*/

#include <stdlib.h>
#include <unistd.h>
#include <my.h>

char	*my_read_file_bin(int fd, size_t *n)
{
  int	rd_sz;
  int	buf_off;
  char	*buf;

  if (!(buf = malloc(65536)))
    return (NULL);
  *n = 0;
  buf_off = 0;
  while ((rd_sz = read(fd, buf + *n, 65536 - buf_off)) > 0)
    {
      *n += rd_sz;
      buf_off += rd_sz;
      if (buf_off == 65536)
	{
	  if (!(buf = my_realloc(buf, *n, *n + 65536, 1)))
	    return (NULL);
	  buf_off = 0;
	}
    }
  return (buf);
}
