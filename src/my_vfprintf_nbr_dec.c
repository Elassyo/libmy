/*
** my_vfprintf_nbr_dec.c for libmy in /home/arthur.melin/Code/libmy
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Tue Nov 15 20:21:08 2016 Arthur Melin
** Last update Wed Nov 16 18:54:59 2016 Arthur Melin
*/

#include <my_vfprintf.h>

static intmax_t		signed_nbr_to_intmax(int size, va_list *args)
{
  intmax_t		res;
  intmax_t		sign;

  res = va_arg(*args, intmax_t) & my_vfprintf_arg_mask(size);
  sign = res & (1 << (size * 8 - 1));
  if (sign)
    {
      res ^= my_vfprintf_arg_mask(size);
      res = -res - 1;
    }
  return (res);
}

int			my_vfprintf_nbr_dec_s(int fd, t_vfprintf_fmt *fmt,
					     va_list *args, int *written)
{
  intmax_t		nbr;
  t_vfprintf_nbr_fmt	nbr_fmt;

  nbr = signed_nbr_to_intmax(fmt->length_modifier, args);
  nbr_fmt.fmt = fmt;
  nbr_fmt.base = "0123456789";
  if (nbr < 0 || fmt->flag_plus || fmt->flag_space)
    {
      nbr_fmt.prefix = nbr < 0 ? "-" : (fmt->flag_plus ? "+" : " ");
      fmt->flag_hash = 1;
    }
  else
    nbr_fmt.prefix = "";
  return (my_vfprintf_nbr(fd, &nbr_fmt, MY_ABS(nbr), written));
}

int			my_vfprintf_nbr_dec_u(int fd, t_vfprintf_fmt *fmt,
					     va_list *args, int *written)
{
  uintmax_t		nbr;
  t_vfprintf_nbr_fmt	nbr_fmt;

  nbr = va_arg(*args, uintmax_t) & my_vfprintf_arg_mask(fmt->length_modifier);
  nbr_fmt.fmt = fmt;
  nbr_fmt.base = "0123456789";
  nbr_fmt.prefix = "";
  return (my_vfprintf_nbr(fd, &nbr_fmt, nbr, written));
}
