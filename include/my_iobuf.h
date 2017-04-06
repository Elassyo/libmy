/*
** my_iobuf.h for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Fri Dec 16 16:18:52 2016 Arthur Melin
** Last update Tue Mar 14 22:14:48 2017 Arthur Melin
*/

#ifndef MY_IOBUF_H_
# define MY_IOBUF_H_

# include <my.h>

# define IOBUF_SZ 65536

struct		s_iobuf
{
  char		*buf;
  int		fd;
  size_t	off;
  size_t	size;
};

#endif /* !IOBUF_H_ */
