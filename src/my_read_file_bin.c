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
#include "my.h"

char	*my_read_file_bin(int fd, int *off)
{
  int	rsz;
  int	buf_off;
  char	*buffer;

  if (!(buffer = malloc(65536)))
    return (NULL);
  *off = 0;
  buf_off = 0;
  while ((rsz = read(fd, buffer + *off, 65536 - buf_off)) > 0)
    {
      *off += rsz;
      buf_off += rsz;
      if (buf_off == 65536)
	{
	  if (!(buffer = my_realloc(buffer, *off, *off + 65536, sizeof(char))))
	    return (NULL);
	  buf_off = 0;
	}
    }
  return (buffer);
}
