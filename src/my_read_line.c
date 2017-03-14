/*
** my_read_line.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Wed Jan 18 13:56:33 2017 Arthur Melin
** Last update Thu Feb  9 17:53:41 2017 Arthur Melin
*/

#include <stdlib.h>
#include <unistd.h>
#include <my.h>

static int	my_linelen(const char *s, int n)
{
  int		i;

  i = -1;
  while (++i < n)
    if (s[i] == '\n')
      return (i);
  return (-1);
}

static char	*my_strrealloc(char *src, int old_sz, int new_sz)
{
  char		*buf;

  if (!(buf = malloc(new_sz)))
    return (NULL);
  my_strncpy(buf, src, old_sz);
  free(src);
  return (buf);
}

static char	*read_line_loop(int fd, char *buf, int *buf_sz)
{
  int		read_sz;

  while (my_linelen(buf, *buf_sz) < 0)
    {
      if (!(buf = my_strrealloc(buf, *buf_sz, *buf_sz + 4096)) ||
	  (read_sz = read(fd, buf + *buf_sz, 4096)) == -1)
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

char		*my_read_line(int fd)
{
  char		*buf;
  int		buf_sz;
  static char	st_buf[4096];
  static int	st_buf_sz = 0;

  buf = NULL;
  if ((buf_sz = st_buf_sz))
    {
      if (!(buf = malloc(st_buf_sz)))
	return (NULL);
      my_strncpy(buf, st_buf, st_buf_sz);
    }
  if (!(buf = read_line_loop(fd, buf, &buf_sz)))
    return (NULL);
  st_buf_sz = buf_sz - (my_linelen(buf, buf_sz) + 1);
  my_strncpy(st_buf, buf + my_linelen(buf, buf_sz) + 1, st_buf_sz);
  buf[my_linelen(buf, buf_sz)] = 0;
  return (buf);
}
