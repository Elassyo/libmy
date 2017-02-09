/*
** my_read_file.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Thu Dec  8 21:17:54 2016 Arthur Melin
** Last update Thu Dec  8 21:18:14 2016 Arthur Melin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*my_read_file(int fd)
{
  int	rsz;
  int	off;
  int	buf_off;
  char	*buffer;

  if (!(buffer = malloc(65536)))
    return (NULL);
  off = 0;
  buf_off = 0;
  while ((rsz = read(fd, buffer + off, 65536 - buf_off)) > 0)
    {
      off += rsz;
      buf_off += rsz;
      if (buf_off == 65536)
	{
	  if (!(buffer = my_realloc(buffer, off, off + 65536, sizeof(char))))
	    return (NULL);
	  buf_off = 0;
	}
    }
  buffer[off] = 0;
  return (buffer);
}
