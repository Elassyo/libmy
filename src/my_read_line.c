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

static int		my_linelen(const char *s, size_t n)
{
  register size_t	i;

  i = 0;
  while (i < n)
    {
      if (s[i] == '\n')
	return (i);
      i++;
    }
  return (-1);
}

static char	*my_read_line_loop(int fd, char *buf, size_t *buf_sz)
{
  int		rd_sz;

  while (my_linelen(buf, *buf_sz) < 0)
    {
      if (!(buf = my_realloc(buf, *buf_sz, *buf_sz + 4096, 1)) ||
	  (rd_sz = read(fd, buf + *buf_sz, 4096)) == -1)
	return (NULL);
      if (rd_sz == 0)
	{
	  if (*buf_sz == 0)
	    {
	      free(buf);
	      return (NULL);
	    }
	  buf[(*buf_sz)++ + rd_sz] = '\n';
	}
      *buf_sz += rd_sz;
    }
  return (buf);
}

char			*my_read_line(int fd)
{
  char			*buf;
  size_t		len;
  size_t		buf_sz;
  static int		st_fd = -1;
  static char		st_buf[4096];
  static size_t		st_buf_sz = 0;

  buf = NULL;
  buf_sz = fd == st_fd ? st_buf_sz : 0;
  if (buf_sz)
    {
      if (!(buf = malloc(st_buf_sz)))
	return (NULL);
      my_strncpy(buf, st_buf, st_buf_sz);
    }
  if (!(buf = my_read_line_loop(fd, buf, &buf_sz)))
    return (NULL);
  st_fd = fd;
  len = my_linelen(buf, buf_sz);
  st_buf_sz = buf_sz - len - 1;
  my_strncpy(st_buf, buf + len + 1, st_buf_sz);
  buf[len] = 0;
  return (buf);
}
