/*
** my_iobuf.h for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Fri Dec 16 16:18:52 2016 Arthur Melin
** Last update Fri Dec 16 16:18:58 2016 Arthur Melin
*/

#ifndef MY_IOBUF_H_
# define MY_IOBUF_H_

typedef struct	s_iobuf
{
  char		*buf;
  int		fd;
  int		off;
  int		size;
}		t_iobuf;

#endif /* !IOBUF_H_ */
