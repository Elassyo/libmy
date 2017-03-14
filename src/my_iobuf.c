/*
** my_iobuf.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Fri Dec 16 16:36:12 2016 Arthur Melin
** Last update Fri Dec 16 16:36:13 2016 Arthur Melin
*/

#include <stdlib.h>
#include <unistd.h>
#include <my.h>
#include <my_iobuf.h>

t_iobuf		*my_iobuf_init(int fd)
{
  t_iobuf	*iobuf;

  if (!(iobuf = malloc(sizeof(t_iobuf))))
    return (NULL);
  iobuf->size = IOBUF_SZ;
  if (!(iobuf->buf = malloc(iobuf->size)))
    {
      free(iobuf);
      return (NULL);
    }
  iobuf->fd = fd;
  iobuf->off = 0;
  return (iobuf);
}

void	my_iobuf_free(t_iobuf *iobuf)
{
  if (!iobuf)
    return ;
  my_iobuf_flush(iobuf);
  free(iobuf->buf);
  free(iobuf);
}

void	my_iobuf_flush(t_iobuf *iobuf)
{
  int	off;
  int	write_sz;

  if (!iobuf || !iobuf->buf)
    return ;
  off = 0;
  while (off != iobuf->off &&
	 (write_sz = write(iobuf->fd, iobuf->buf + off, iobuf->off - off)) > 0)
    off += write_sz;
  iobuf->off = 0;
}

void	my_iobuf_putchar(t_iobuf *iobuf, char c)
{
  if (!iobuf || !iobuf->buf)
    return ;
  if (iobuf->off + 1 > iobuf->size)
    my_iobuf_flush(iobuf);
  iobuf->buf[iobuf->off++] = c;
  if (iobuf->off >= iobuf->size)
    my_iobuf_flush(iobuf);
}

void	my_iobuf_putstr(t_iobuf *iobuf, char *str)
{
  int	offset;
  int	length;
  int	write_sz;

  if (!iobuf || !iobuf->buf || !str)
    return ;
  length = my_strlen(str);
  if (iobuf->off + length > iobuf->size)
    my_iobuf_flush(iobuf);
  offset = 0;
  if (length >= iobuf->size)
    {
      while (offset != length &&
	     (write_sz =  write(iobuf->fd, str + offset, length - offset)) > 0)
	offset += write_sz;
    }
  else
    {
      my_memcpy(iobuf->buf + iobuf->off, str, length);
      iobuf->off += length;
      if (iobuf->off >= iobuf->size)
	my_iobuf_flush(iobuf);
    }
}
