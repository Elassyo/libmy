/*
** my_vfprintf_misc.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Thu Nov 17 00:20:27 2016 Arthur Melin
** Last update Thu Nov 17 00:34:33 2016 Arthur Melin
*/

#include "my_vfprintf.h"

int			my_vfprintf_ptr(int fd, t_vfprintf_fmt *fmt,
				       va_list *args, int *written_ptr)
{
  uintmax_t		ptr;
  t_vfprintf_nbr_fmt	nbr_fmt;

  ptr = va_arg(*args, uintmax_t);
  nbr_fmt.fmt = fmt;
  nbr_fmt.base = "0123456789abcdef";
  if (ptr == 0)
    {
      nbr_fmt.prefix = "(nil)";
      fmt->precision = 0;
    }
  else if (fmt->flag_plus)
    nbr_fmt.prefix = "+0x";
  else if (fmt->flag_space)
    nbr_fmt.prefix = " 0x";
  else
    nbr_fmt.prefix = "0x";
  fmt->flag_hash = 1;
  return (my_vfprintf_nbr(fd, &nbr_fmt, ptr, written_ptr));
}

int		my_vfprintf_wrt(int fd __attribute__ ((__unused__)),
			       t_vfprintf_fmt *fmt, va_list *args,
			       int *written_ptr)
{
  intmax_t	written;
  void		*ptr;

  ptr = va_arg(*args, void *);
  if (ptr == NULL)
    return (0);
  written = *written_ptr;
  if (fmt->length_modifier == 0)
    fmt->length_modifier = sizeof(int);
  my_memcpy(ptr, &written, fmt->length_modifier);
  return (0);
}

int		my_vfprintf_pct(int fd,
			       t_vfprintf_fmt *fmt __attribute__ ((__unused__)),
			       va_list *args __attribute__ ((__unused__)),
			       int *written_ptr)
{
  my_putchar_fd(fd, '%');
  (*written_ptr)++;
  return (0);
}
