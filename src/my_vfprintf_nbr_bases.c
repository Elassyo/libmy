/*
** my_vfprintf_nbr_bases.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Tue Nov 15 22:46:47 2016 Arthur Melin
** Last update Thu Nov 17 00:30:48 2016 Arthur Melin
*/

#include "my_vfprintf.h"

int			my_vfprintf_nbr_oct(int fd, t_vfprintf_fmt *fmt,
					   va_list *args, int *written)
{
  uintmax_t		nbr;
  t_vfprintf_nbr_fmt	nbr_fmt;

  nbr = va_arg(*args, uintmax_t) & my_vfprintf_arg_mask(fmt->length_modifier);
  nbr_fmt.fmt = fmt;
  nbr_fmt.base = "01234567";
  nbr_fmt.prefix = "0";
  return (my_vfprintf_nbr(fd, &nbr_fmt, nbr, written));
}

int			my_vfprintf_nbr_bin(int fd, t_vfprintf_fmt *fmt,
					   va_list *args, int *written)
{
  uintmax_t		nbr;
  t_vfprintf_nbr_fmt	nbr_fmt;

  nbr = va_arg(*args, uintmax_t) & my_vfprintf_arg_mask(fmt->length_modifier);
  nbr_fmt.fmt = fmt;
  nbr_fmt.base = "01";
  nbr_fmt.prefix = "0b";
  return (my_vfprintf_nbr(fd, &nbr_fmt, nbr, written));
}

int			my_vfprintf_nbr_hex_l(int fd, t_vfprintf_fmt *fmt,
					     va_list *args, int *written)
{
  uintmax_t		nbr;
  t_vfprintf_nbr_fmt	nbr_fmt;

  nbr = va_arg(*args, uintmax_t) & my_vfprintf_arg_mask(fmt->length_modifier);
  nbr_fmt.fmt = fmt;
  nbr_fmt.base = "0123456789abcdef";
  nbr_fmt.prefix = "0x";
  return (my_vfprintf_nbr(fd, &nbr_fmt, nbr, written));
}

int			my_vfprintf_nbr_hex_u(int fd, t_vfprintf_fmt *fmt,
					     va_list *args, int *written)
{
  uintmax_t		nbr;
  t_vfprintf_nbr_fmt	nbr_fmt;

  nbr = va_arg(*args, uintmax_t) & my_vfprintf_arg_mask(fmt->length_modifier);
  nbr_fmt.fmt = fmt;
  nbr_fmt.base = "0123456789ABCDEF";
  nbr_fmt.prefix = "0X";
  return (my_vfprintf_nbr(fd, &nbr_fmt, nbr, written));
}
