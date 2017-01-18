/*
** my_get_next_line.c for libmy in /home/arthur.melin/Code/libmy/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Jan 18 13:56:33 2017 Arthur Melin
** Last update Wed Jan 18 14:05:09 2017 Arthur Melin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int	gnl_linelen(const char *s, int n)
{
  int		i;

  i = -1;
  while (++i < n)
    if (s[i] == '\n')
      return (i);
  return (-1);
}

static char	*gnl_strrealloc(char *src, int old_sz, int new_sz)
{
  char		*buf;

  if (!(buf = malloc(new_sz)))
    return (NULL);
  my_strncpy(buf, src, old_sz);
  free(src);
  return (buf);
}

static char	*gnl_loop(int fd, char *buf, int *buf_sz)
{
  int		read_sz;

  while (gnl_linelen(buf, *buf_sz) < 0)
    {
      if (!(buf = gnl_strrealloc(buf, *buf_sz, *buf_sz + GNL_READ_SIZE)) ||
	  (read_sz = read(fd, buf + *buf_sz, GNL_READ_SIZE)) == -1)
	return (NULL);
      if (read_sz == 0)
	{
	  if (*buf_sz == 0)
	    {
	      free(buf);
	      return (NULL);
	    }
	  buf[(*buf_sz)++ + read_sz] = '\n';
	}
      *buf_sz += read_sz;
    }
  return (buf);
}

char		*my_get_next_line(int fd)
{
  char		*buf;
  int		buf_sz;
  static char	st_buf[GNL_READ_SIZE];
  static int	st_buf_sz = 0;

  buf = NULL;
  if ((buf_sz = st_buf_sz))
    {
      if (!(buf = malloc(st_buf_sz)))
	return (NULL);
      my_strncpy(buf, st_buf, st_buf_sz);
    }
  if (!(buf = gnl_loop(fd, buf, &buf_sz)))
    return (NULL);
  st_buf_sz = buf_sz - (gnl_linelen(buf, buf_sz) + 1);
  my_strncpy(st_buf, buf + gnl_linelen(buf, buf_sz) + 1, st_buf_sz);
  buf[gnl_linelen(buf, buf_sz)] = 0;
  return (buf);
}
